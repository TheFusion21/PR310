#pragma once

// EXTERNAL INCLUDES
#include <cmath>
#include <cfloat>
#include <cassert>
// INTERNAL INCLUDES
#include "types.h"

namespace Engine::Math
{
	/*! @class Vec2 \file vec2.h
	 *  @brief a vector of 3 dimensions
	 *  @author Kay Hennig
	 *  @date 11.08.2020
	 */
	class Vec3
	{
	public:
		
		/*! @brief the x axis component of the vector */
		real x = static_cast<real>(0.0);
		/*! @brief the y axis component of the vector */
		real y = static_cast<real>(0.0);
		/*! @brief the z axis component of the vector */
		real z = static_cast<real>(0.0);
		
		/*! @brief a vector with zero length */
		static const Vec3 Zero;
		/*! @brief a vector with one length on the x axis*/
		static const Vec3 UnitX;
		/*! @brief a vector with one length on the y axis*/
		static const Vec3 UnitY;
		/*! @brief a vector with one length on the z axis*/
		static const Vec3 UnitZ;
		/*! @brief a vector with one length on all axis*/
		static const Vec3 UnitScale;

		/*! @brief copy a vector by value */
		inline Vec3(const Vec3& vec)
			: Vec3(vec.x, vec.y, vec.z)
		{ }
		/*! @brief create a vector defaulting to a 0 magnitude vector */
		inline Vec3(real x = static_cast<real>(0.0)
			, real y = static_cast<real>(0.0)
			, real z = static_cast<real>(0.0)) :
			x(x),
			y(y),
			z(z)
		{ }
		/*! @brief normalizes the vector to a length of 1
		 *  @return normalization was successful
		 */
		inline bool Normalize()
		{
			real invMag = static_cast<real>(1.0) / Magnitude();
			
#ifdef DOUBLEPRECISION 
			if(invMag >= DBL_MIN)
#else
			if (invMag >= FLT_MIN)
#endif // DOUBLEPRECISION 
			{
				*this *= invMag;
				return true;
			}

			return false;
		}
		/*! @brief get the current length of the vector
		 *  @return the length of the vector
		 */
		inline real Magnitude() const
		{
			#ifdef DOUBLEPRECISION
				return sqrt(SqrMagnitude());
			#else
				return sqrtf(SqrMagnitude());
			#endif
		}
		/*! @brief get the current square length of the vector
		 *  @return the square length of the vector
		 */
		inline real SqrMagnitude() const
		{
			return x * x + y * y + z * z;
		}
		/*! @brief calculate the dot of this and another vector
		 *  @return the dot product between these vectors
		 */
		inline real Dot(Vec3 v) const
		{
			return	(x * v.x) +
					(y * v.y) +
					(z * v.z);
		}
		/*! @brief calculate the cross of this and another vector
		 *  @return the cross product between these vectors
		 */
		inline Vec3 Cross(Vec3 v) const
		{
			return Vec3{y * v.z - z * v.y,
						z * v.x - z * v.x,
						x * v.y - y * v.x };
		}
		/*! @brief calculate the lerped vector of this and another vector between t
		 *	@param t how much the vector should be lerped
		 *  @return the new lerped vector
		 */
		inline Vec3 Lerp(Vec3 v, real t) const
		{
			return (*this) + (v - (*this)) * t;
		}
		/*! @brief calculate the distance between this and another vector
		 * @return the distance between these vectors
		 */
		inline real Distance(Vec3 v) const
		{
#ifdef DOUBLEPRECISION
			return sqrt(SqrDistance(v));
#else
			return sqrtf(SqrDistance(v));
#endif
		}
		/*! @brief calculate the square distance between this and another vector
		 * @return the square distance between these vectors
		 */
		inline real SqrDistance(Vec3 v) const
		{
			return (v - *this).SqrMagnitude();
		}
		/*! @brief adds a vector to this vector
		 * @return the modified vector
		 */
		inline Vec3& operator+=(const Vec3& rhs)
		{
			this->x += rhs.x;
			this->y += rhs.y;
			this->z += rhs.z;
			return *this;
		}
		/*! @brief subtracts a vector to this vector
		 * @return the modified vector
		 */
		inline Vec3& operator-=(const Vec3& rhs)
		{
			this->x -= rhs.x;
			this->y -= rhs.y;
			this->z -= rhs.z;
			return *this;
		}
		/*! @brief multiplies a vector with this vector
		 * @return the modified vector
		 */
		inline Vec3& operator*=(const Vec3& rhs)
		{
			this->x *= rhs.x;
			this->y *= rhs.y;
			this->z *= rhs.z;
			return *this;
		}
		/*! @brief divides a vector with this vector
		 * @return the modified vector
		 */
		inline Vec3& operator/=(const Vec3& rhs)
		{
			assert(rhs != Vec3::Zero);
			this->x /= rhs.x;
			this->y /= rhs.y;
			this->z /= rhs.z;
			return *this;
		}
		/*! @brief multipies this vector by a factor
		 * @return the modified vector
		 */
		inline Vec3& operator*=(const real rhs)
		{
			this->x *= rhs;
			this->y *= rhs;
			this->z *= rhs;
			return *this;
		}
		/*! @brief multiplies this vector with a 4 by 4 matrix
		 *  @return the modified vector
		 */
		Vec3& operator*=(const class Mat4x4& rhs);
		/*! @brief divides this vector by a factor
		 * @return the modified vector
		 */
		inline Vec3& operator/=(const real rhs)
		{
			assert(rhs != static_cast<real>(0.0));
			this->x /= rhs;
			this->y /= rhs;
			this->z /= rhs;
			return *this;
		}
		/*! @brief adds this vector to another
		 * @return return a new vector of the sum of them
		 */
		inline Vec3 operator+(const Vec3& v) const
		{
			return Vec3{ x + v.x, y + v.y, z + v.z };
		}
		/*! @brief subtracts this vector to another
		 * @return return a new vector of the difference of them
		 */
		inline Vec3 operator-(const Vec3& v) const
		{
			return Vec3{ x - v.x, y - v.y, z - v.z };
		}
		/*! @brief multiplies this vector to another
		 * @return return a new vector of the product of them
		 */
		inline Vec3 operator*(const Vec3& v) const
		{
			return Vec3{ x * v.x, y * v.y, z * v.z };
		}
		/*! @brief divides this vector to another
		 * @return return a new vector of the quotient of them
		 */
		inline Vec3 operator/(const Vec3& v) const
		{
			assert(v != Vec3::Zero);
			return Vec3{ x / v.x, y / v.y, z / v.z };
		}
		/*! @brief multiplies this vector by a factor
		 * @return return a new vector of the product of them
		 */
		inline Vec3 operator*(const real t) const
		{
			return Vec3{ x * t, y * t, z * t };
		}
		/*! @brief divides this vector by a factor
		 * @return return a new vector of the quotient of them
		 */
		inline Vec3 operator/(const real t) const
		{
			assert(t != static_cast<real>(0.0));
			return Vec3{ x / t, y / t, z / t };
		}
		/*! @brief compares this vector to another by value
		 * @return these vector are equal in value
		 */
		inline bool operator==(const Vec3& v) const
		{
			if (x == v.x && y == v.y && z == v.z)
				return true;
			return false;
		}
		/*! @brief compares this vector to another by value
		 * @return these vector are not equal in value
		 */
		inline bool operator!=(const Vec3& v) const
		{
			return !(*this == v);
		}
		/*! @brief gets the negativ of this vector
		 * @return a new vector of the negative of this one
		 */
		inline Vec3 operator-() const
		{
			return Vec3{ -x, -y, -z };
		}
	};
}
