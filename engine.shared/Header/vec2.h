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
	 *  @brief a vector of 2 dimensions
	 *  @author Kay Hennig
	 *  @date 11.08.2020
	 */
	class Vec2
	{
	public:

		/*! @brief the x axis component of the vector */
		real x = static_cast<real>(0.0);
		/*! @brief the y axis component of the vector */
		real y = static_cast<real>(0.0);

		/*! @brief a vector with zero length */
		static const Vec2 Zero;
		/*! @brief a vector with one length on the x axis*/
		static const Vec2 UnitX;
		/*! @brief a vector with one length on the y axis*/
		static const Vec2 UnitY;
		/*! @brief a vector with one length on all axis*/
		static const Vec2 UnitScale;

		/*! @brief copy a vector by value */
		inline Vec2(const Vec2& vec)
			: Vec2(vec.x, vec.y)
		{ }
		/*! @brief create a vector defaulting to a 0 magnitude vector */
		inline Vec2(real x = static_cast<real>(0.0)
			, real y = static_cast<real>(0.0)) :
			x(x),
			y(y)
		{ }
		/*! @brief normalizes the vector to a length of 1
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
			return x * x + y * y;
		}
		/*! @brief calculate the dot of this and another vector
		 *  @return the dot product between these vectors
		 */
		inline real Dot(Vec2 v) const
		{
			return	(x * v.x) +
					(y * v.y);
		}
		/*! @brief calculate the cross of this and another vector
		 *  @return the cross product between these vectors
		 */
		inline real Cross(Vec2 v) const
		{
			return x * v.y - y * v.x;
		}
		/*! @brief calculate the lerped vector of this and another vector between t
		 *	@param t how much the vector should be lerped
		 *  @return the new lerped vector
		 */
		inline Vec2 Lerp(Vec2 v, real t) const
		{
			return (*this) + (v - (*this)) * t;
		}
		/*! @brief calculate the distance between this and another vector
		 * @return the distance between these vectors
		 */
		inline real Distance(Vec2 v) const
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
		inline real SqrDistance(Vec2 v) const
		{
			return (v - *this).SqrMagnitude();
		}
		/*! @brief adds a vector to this vector
		 * @return the modified vector
		 */
		inline Vec2& operator+=(const Vec2& rhs)
		{
			this->x += rhs.x;
			this->y += rhs.y;
			return *this;
		}
		/*! @brief subtracts a vector to this vector
		 * @return the modified vector
		 */
		inline Vec2& operator-=(const Vec2& rhs)
		{
			this->x -= rhs.x;
			this->y -= rhs.y;
			return *this;
		}
		/*! @brief multiplies a vector to this vector
		 * @return the modified vector
		 */
		inline Vec2& operator*=(const Vec2& rhs)
		{
			this->x *= rhs.x;
			this->y *= rhs.y;
			return *this;
		}
		/*! @brief divides a vector to this vector
		 * @return the modified vector
		 */
		inline Vec2& operator/=(const Vec2& rhs)
		{
			assert(rhs != Vec2::Zero);
			this->x /= rhs.x;
			this->y /= rhs.y;
			return *this;
		}
		/*! @brief multipies this vector by a factor
		 * @return the modified vector
		 */
		inline Vec2& operator*=(const real rhs)
		{
			this->x *= rhs;
			this->y *= rhs;
			return *this;
		}
		/*! @brief divides this vector by a factor
		 * @return the modified vector
		 */
		inline Vec2& operator/=(const real rhs)
		{
			assert(rhs != static_cast<real>(0.0));
			this->x /= rhs;
			this->y /= rhs;
			return *this;
		}
		/*! @brief adds this vector to another
		 * @return return a new vector of the sum of them
		 */
		inline Vec2 operator+(const Vec2& v) const
		{
			return Vec2{ x + v.x, y + v.y};
		}
		/*! @brief subtracts this vector to another
		 * @return return a new vector of the difference of them
		 */
		inline Vec2 operator-(const Vec2& v) const
		{
			return Vec2{ x - v.x, y - v.y};
		}
		/*! @brief multiplies this vector to another
		 * @return return a new vector of the product of them
		 */
		inline Vec2 operator*(const Vec2& v) const
		{
			return Vec2{ x * v.x, y * v.y};
		}
		/*! @brief divides this vector to another
		 * @return return a new vector of the quotient of them
		 */
		inline Vec2 operator/(const Vec2& v) const
		{
			assert(v != Vec2::Zero);
			return Vec2{ x / v.x, y / v.y};
		}
		/*! @brief multiplies this vector by a factor
		 * @return return a new vector of the product of them
		 */
		inline Vec2 operator*(const real t) const
		{
			return Vec2{ x * t, y * t};
		}
		/*! @brief divides this vector by a factor
		 * @return return a new vector of the quotient of them
		 */
		inline Vec2 operator/(const real t) const
		{
			assert(t != static_cast<real>(0.0));
			return Vec2{ x / t, y / t};
		}
		/*! @brief compares this vector to another by value
		 * @return these vector are equal in value
		 */
		inline bool operator==(const Vec2& v) const
		{
			if (x == v.x && y == v.y)
				return true;
			return false;
		}
		/*! @brief compares this vector to another by value
		 * @return these vector are not equal in value
		 */
		inline bool operator!=(const Vec2& v) const
		{
			return !(*this == v);
		}
		/*! @brief gets the negativ of this vector
		 * @return a new vector of the negative of this one
		 */
		inline Vec2 operator-()
		{
			return Vec2{ -x, -y};
		}
	};
}
