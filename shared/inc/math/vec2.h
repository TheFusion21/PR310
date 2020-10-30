#pragma once

// EXTERNAL INCLUDES
#include <cassert>
#include <cfloat>
#include <cmath>
// INTERNAL INCLUDES
#include "basetypes.h"
#include "math/mathutils.h"

class Vec2
{
public:

	real x = static_cast<real>(0.0);
	real y = static_cast<real>(0.0);

	Vec2(void) = default;
	Vec2(const real x, const real y) :
		x(x),
		y(y)
	{ }

	inline Vec2 operator+(const Vec2& rhs) const
	{
		return Vec2{
			this->x + rhs.x,
			this->y + rhs.y
		};
	}
	inline Vec2 operator-(const Vec2& rhs) const
	{
		return Vec2{
			this->x - rhs.x,
			this->y - rhs.y
		};
	}
	inline Vec2 operator-() const
	{
		return Vec2{
			-this->x,
			-this->y
		};
	}
	inline Vec2 operator*(const real scalar) const
	{
		return Vec2{
			this->x * scalar,
			this->y * scalar
		};
	}
	inline Vec2 operator/(const real scalar) const
	{
		assert(scalar != static_cast<real>(0.0));
		return Vec2{
			this->x / scalar,
			this->y / scalar
		};
	}

	inline Vec2& operator+=(const Vec2& rhs)
	{
		this->x += rhs.x;
		this->y += rhs.y;
		return *this;
	}
	inline Vec2& operator-=(const Vec2& rhs)
	{
		this->x -= rhs.x;
		this->y -= rhs.y;
		return *this;
	}
	inline Vec2& operator*=(const real scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		return *this;
	}
	inline Vec2& operator/=(const real scalar)
	{
		assert(scalar != static_cast<real>(0.0));
		this->x /= scalar;
		this->y /= scalar;
		return *this;
	}
	
	inline real Magnitude(void) const
	{
		return sqrt(SquareMagnitude());
	}
	inline real SquareMagnitude(void) const
	{
		return (this->x * this->x) +
			(this->y * this->y);
	}
	inline real Distance(const Vec2& rhs) const
	{
		return ((*this) - rhs).Magnitude();
	}

	inline real Dot(const Vec2& rhs) const
	{
		return real {
			(this->x * rhs.x) +
			(this->y * rhs.y)
		};
	}
	inline Vec2 Cross(const Vec2& rhs) const
	{
		return Vec2{
			(this->y * rhs.x) - (this->x * rhs.y),
			(this->x * rhs.y) - (this->y * rhs.x)
		};
	}

	inline bool Normalize(void)
	{
		const real mag = this->Magnitude();

		if (mag >= FLT_MIN)
		{
			real invMag = static_cast<real>(1.0) / mag;

			this->x *= invMag;
			this->y *= invMag;

			return true;
		}

		return false;
	}

	inline Vec2 Lerp(const Vec2& rhs, const real alpha) const
	{
		return (*this) + (rhs - (*this)) * alpha;
	}
	inline Vec2 NLerp(const Vec2& rhs, real t) const
	{
		// create a lerped vector
		Vec2 result = this->Lerp(rhs, t);

		// normalize and return result
		// after normalization it's located on
		// the unit sphere without the expensive computation of slerp
		// but the acceleration is not constant
		if (result.Normalize())
			return result;

		// return original vector if the normalization failed
		return *this;
	}
	inline Vec2 SLerp(const Vec2& rhs, real t) const
	{
		// dot product cos(angle) between the 2 vectors
		real dot = this->Dot(rhs);
		// clamp because floating point might not be in
		// range of acos which receives the dot product
		// due to precision loss of floating point numbers
		dot = Clamp(dot, static_cast<real>(-1.0), static_cast<real>(1.0));
		// get angle between vectors via acos(dot)
		const real theta = acos(dot) * t;
		// calculate relative vector
		Vec2 relVec = rhs - *this * dot;
		// normalize it and apply the lerp
		if (relVec.Normalize())
			return *this * cos(theta) + relVec * sin(theta);

		// return original vector if the normalization failed
		return *this;
	}

	inline static Vec2 GetArithmeticCenter(const Vec2& lhs, const Vec2& rhs)
	{
		return {
			(lhs.x + rhs.x) * static_cast<real>(0.5),
			(lhs.y + rhs.y) * static_cast<real>(0.5)
		};
	}

	inline bool operator==(const Vec2& lhs)
	{
		return (this->x == lhs.x
			&& this->y == lhs.y);
	}
	inline bool operator!=(const Vec2& lhs)
	{
		return !(*this == lhs);
	}


	static const Vec2 UnitX;
	static const Vec2 UnitY;
	static const Vec2 UnitScale;
	static const Vec2 Zero;

};
