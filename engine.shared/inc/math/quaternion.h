#pragma once
// EXTERNAL INCLUDES
#include <cmath>
#include <cfloat>
#include <cassert>
// INTERNAL INCLUDES
#include "types.h"
#include "vec3.h"
#include "mathutils.h"

namespace Engine::Math
{
	/*! @class Quaternion \file quaternion.h
	 *  @brief a rotational Quaternion of 4 dimensions
	 *  @author Kay Hennig
	 *  @date 11.08.2020
	 */
	class Quaternion
	{
	public:
		/*! @brief the x axis component of the quaternion */
		real x = static_cast<real>(0.0);
		/*! @brief the y axis component of the quaternion */
		real y = static_cast<real>(0.0);
		/*! @brief the z axis component of the quaternion */
		real z = static_cast<real>(0.0);
		/*! @brief the w axis component of the quaternion */
		real w = static_cast<real>(0.0);

		/*! @brief a quaternion with zero values */
		static const Quaternion Zero;

		/*! @brief copy a quaternion by value */
		inline Quaternion(const Quaternion& q)
			: Quaternion(q.x, q.y, q.z, q.w)
		{ }
		/*! @brief create a quaternion defaulting to a 0 in all components */
		inline Quaternion(real x = static_cast<real>(0.0)
			, real y = static_cast<real>(0.0)
			, real z = static_cast<real>(0.0)
			, real w = static_cast<real>(0.0)) :
			x(x),
			y(y),
			z(z),
			w(w)
		{ }
		/*! @brief normalizes the quaternion
		 *  @return normalization was successful
		 */
		inline bool Normalize()
		{
			real invMag = static_cast<real>(1.0) / Magnitude();

#ifdef DOUBLEPRECISION 
			if (invMag >= DBL_MIN)
#else
			if (invMag >= FLT_MIN)
#endif // DOUBLEPRECISION 
			{
				*this *= invMag;
				return true;
			}

			return false;
		}
		/*! @brief get the current length of the quaternion
		 *  @return the length of the quaternion
		 */
		inline real Magnitude() const
		{
#ifdef DOUBLEPRECISION
			return sqrt(SqrMagnitude());
#else
			return sqrtf(SqrMagnitude());
#endif
		}
		/*! @brief get the current square length of the quaternion
		 *  @return the square length of the quaternion
		 */
		inline real SqrMagnitude() const
		{
			return x * x + y * y + z * z + w * w;
		}
		/*! @brief calculate the dot of this and another quaternion
		 *  @return the dot product between these quaternion
		 */
		inline real Dot(Quaternion q) const
		{
			return	(x * q.x) +
				(y * q.y) +
				(z * q.z) +
				(w * q.w);
		}
		/*! @brief calculate the lerped quaternion of this and another quaternion between t
		 *	@param t how much the quaternion should be lerped
		 *  @return the new lerped quaternion
		 */
		inline Quaternion Lerp(Quaternion v, real t) const
		{
			return (*this) + (v - (*this)) * t;
		}
		/*! @brief calculate the distance between this and another quaternion
		 * @return the distance between these quaternions
		 */
		inline real Distance(Quaternion v) const
		{
#ifdef DOUBLEPRECISION
			return sqrt(SqrDistance(v));
#else
			return sqrtf(SqrDistance(v));
#endif
		}
		/*! @brief calculate the square distance between this and another quaternion
		 * @return the square distance between these quaternions
		 */
		inline real SqrDistance(Quaternion v) const
		{
			return (v - *this).SqrMagnitude();
		}

		/*! @brief adds a quaternion to this quaternion
		 * @return the modified quaternion
		 */
		inline Quaternion& operator+=(const Quaternion& rhs)
		{
			this->x += rhs.x;
			this->y += rhs.y;
			this->z += rhs.z;
			this->w += rhs.w;
			return *this;
		}
		/*! @brief subtracts a quaternion to this quaternion
		 * @return the modified quaternion
		 */
		inline Quaternion& operator-=(const Quaternion& rhs)
		{
			this->x -= rhs.x;
			this->y -= rhs.y;
			this->z -= rhs.z;
			this->w -= rhs.w;
			return *this;
		}
		/*! @brief multpies a quaternion with this quaternion
		 * @return the modified quaternion
		 */
		inline Quaternion& operator*=(const Quaternion& rhs)
		{
			Quaternion temp = *this;
			this->w = temp.w * rhs.w - temp.x * rhs.x - temp.y * rhs.y - temp.z * rhs.z;
			this->x = temp.w * rhs.x + temp.x * rhs.w + temp.y * rhs.z - temp.z * rhs.y;
			this->y = temp.w * rhs.y + temp.y * rhs.w + temp.z * rhs.x - temp.x * rhs.z;
			this->z = temp.w * rhs.z + temp.z * rhs.w + temp.x * rhs.y - temp.y * rhs.x;
			return *this;
		}
		/*! @brief divides a quaternion with this quaternion
		 * @return the modified quaternion
		 */
		inline Quaternion& operator/=(const Quaternion& rhs)
		{
			assert(rhs != Quaternion::Zero);
			this->x /= rhs.x;
			this->y /= rhs.y;
			this->z /= rhs.z;
			this->w /= rhs.w;
			return *this;
		}
		/*! @brief multiplies a quaternion by a factor
		 * @return the modified quaternion
		 */
		inline Quaternion& operator*=(const real rhs)
		{
			this->x *= rhs;
			this->y *= rhs;
			this->z *= rhs;
			this->w *= rhs;
			return *this;
		}
		/*! @brief divides a quaternion by a factor
		 * @return the modified quaternion
		 */
		inline Quaternion& operator/=(const real rhs)
		{
			assert(rhs != static_cast<real>(0.0));
			this->x /= rhs;
			this->y /= rhs;
			this->z /= rhs;
			this->w /= rhs;
			return *this;
		}
		/*! @brief adds this quaternion to another
		 * @return return a new quaternion of the sum of them
		 */
		inline Quaternion operator+(const Quaternion& q) const
		{
			return Quaternion{ x + q.x, y + q.y, z + q.z, w + q.w};
		}
		/*! @brief subtracts this quaternion to another
		 * @return return a new quaternion of the difference of them
		 */
		inline Quaternion operator-(const Quaternion& q) const
		{
			return Quaternion{ x - q.x, y - q.y, z - q.z, w - q.w};
		}
		/*! @brief multiplies this quaternion to another
		 * @return return a new quaternion of the product of them
		 */
		inline Quaternion operator*(const Quaternion& q) const
		{
			return Quaternion
			{
				this->w * q.x + this->x * q.w + this->y * q.z - this->z * q.y,
				this->w * q.y + this->y * q.w + this->z * q.x - this->x * q.z,
				this->w * q.z + this->z * q.w + this->x * q.y - this->y * q.x,
				this->w * q.w - this->x * q.x - this->y * q.y - this->z * q.z,
			};
		}
		/*! @brief multiplies this quaternion to with a vector
		 * @return return a new multiplied/rotated vector 
		 */
		inline Vec3 operator*(const Vec3& vec) const
		{
			Vec3 axis = Vec3(this->x, this->y, this->z);
			Vec3 u = axis.Cross(vec);
			Vec3 v = axis.Cross(u);
			u *= static_cast<real>(2.0) * this->w;
			v *= static_cast<real>(2.0);
			return vec + u + v;
		}
		/*! @brief divides this quaternion to another
		 * @return return a new quaternion of the quotient of them
		 */
		inline Quaternion operator/(const Quaternion& q) const
		{
			assert(q != Quaternion::Zero);
			return Quaternion{ x / q.x, y / q.y, z / q.z, w / q.w };
		}
		/*! @brief multiplies this quaternion to another
		 * @return return a new quaternion of the product of them
		 */
		inline Quaternion operator*(const real t) const
		{
			return Quaternion{ x * t, y * t, z * t, w * t };
		}
		/*! @brief divides this quaternion by a factor
		 * @return return a new quaternion of the quotient of them
		 */
		inline Quaternion operator/(const real t) const
		{
			assert(t != static_cast<real>(0.0));
			return Quaternion{ x / t, y / t, z / t, w / t };
		}
		/*! @brief compares this quaternion to another by value
		 * @return these quaternion are equal in value
		 */
		inline bool operator==(const Quaternion& q) const
		{
			if (x == q.x && y == q.y && z == q.z && w == q.w)
				return true;
			return false;
		}
		/*! @brief compares this quaternion to another by value
		 * @return these quaternion are not equal in value
		 */
		inline bool operator!=(const Quaternion& v) const
		{
			return !(*this == v);
		}
		/*! @brief compares this quaternion to another by angle and tolerance
		 * @return these quaternion are equal within tolerance
		 */
		inline bool Equals(const Quaternion& q, const real tolerance) const
		{
			real dot = this->Dot(q);
#ifdef DOUBLEPRECISION 
			real angle = acos(static_cast<real>(2.0) * dot * dot - static_cast<real>(1.0));
#else
			real angle = acosf(static_cast<real>(2.0) * dot * dot - static_cast<real>(1.0));
#endif
			return abs(angle) <= tolerance;
		}
		/*! @brief gets the negativ of this quaternion
		 * @return a new vector of the negative of this one
		 */
		inline Quaternion operator-() const
		{
			return Quaternion{ -x, -y, -z, w };
		}
		/*! @brief creates a quaternion by euler angle and axis
		 * @return a new quaternion based on euler angle
		 */
		static Quaternion FromAngleAxis(real angle, const Vec3& axis)
		{
			Vec3 normAxis = axis;
			if (!normAxis.Normalize())
			{
				return Quaternion::Zero;
			}
			real halfAngle = angle * static_cast<real>(0.5) * AngleToRad();
#ifdef DOUBLEPRECISION 
			real halfSin = sin(halfAngle);
			real halfCos = cos(halfAngle);
#else
			real halfSin = sinf(halfAngle);
			real halfCos = cosf(halfAngle);
#endif
			return Quaternion
			{
				halfSin * normAxis.x,
				halfSin * normAxis.y,
				halfSin * normAxis.z,
				halfCos
			};
		}
		/*! @brief gets the euler angles of a axis from this quaternion */
		inline void ToAngleAxis(real& angle, Vec3& axis) const
		{
			if (this->SqrMagnitude() > 0)
			{
				
#ifdef DOUBLEPRECISION 
				angle = static_cast<real>(2) * acos(this->w);
#else
				angle = static_cast<real>(2) * acosf(this->w);
#endif
				real inverse = static_cast<real>(1) - this->Magnitude();
				axis.x = this->x * inverse;
				axis.y = this->y * inverse;
				axis.z = this->z * inverse;
			}
			else
			{
				angle = static_cast<real>(0.0);
				axis = Vec3::UnitY;
			}
		}
		/*! @brief calculates the inverse quaternion of this quaternion
		 * @return a new quaternion representing the inverse of this quaternion
		 */
		inline Quaternion Inverse() const
		{
			if (this->SqrMagnitude() > 0)
			{
				real inv = static_cast<real>(1.0) / this->Magnitude();
				return Quaternion
				{
					x * inv,
					y * inv,
					z * inv,
					w * inv
				};
			}
			return Quaternion::Zero;
		}
	};
}