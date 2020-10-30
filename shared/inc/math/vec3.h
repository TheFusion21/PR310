#pragma once

// EXTERNAL INCLUDES
#include <cassert>
#include <cfloat>
#include <cmath>
// INTERNAL INCLUDES
#include "basetypes.h"
#include "math/mathutils.h"

class Vec3
{
public:

	real x = static_cast<real>(0.0);
	real y = static_cast<real>(0.0);
	real z = static_cast<real>(0.0);

	Vec3(void) = default;
	Vec3(const real x, const real y, const real z) :
		x(x),
		y(y),
		z(z)
	{ }

	inline Vec3 operator+(const Vec3& rhs) const
	{
		return Vec3{
			this->x + rhs.x,
			this->y + rhs.y,
			this->z + rhs.z
		};
	}
	inline Vec3 operator-(const Vec3& rhs) const
	{
		return Vec3{
			this->x - rhs.x,
			this->y - rhs.y,
			this->z - rhs.z
		};
	}
	inline Vec3 operator-() const
	{
		return Vec3{
			-this->x,
			-this->y,
			-this->z
		};
	}
	inline Vec3 operator*(const real scalar) const
	{
		return Vec3{
			this->x * scalar,
			this->y * scalar,
			this->z * scalar
		};
	}
	inline Vec3 operator/(const real scalar) const
	{
		assert(scalar != static_cast<real>(0.0));
		return Vec3{
			this->x / scalar,
			this->y / scalar,
			this->z / scalar
		};
	}

	inline Vec3& operator+=(const Vec3& rhs)
	{
		this->x += rhs.x;
		this->y += rhs.y;
		this->z += rhs.z;
		return *this;
	}
	inline Vec3& operator-=(const Vec3& rhs)
	{
		this->x -= rhs.x;
		this->y -= rhs.y;
		this->z -= rhs.z;
		return *this;
	}
	inline Vec3& operator*=(const real scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;
		return *this;
	}
	inline Vec3& operator/=(const real scalar)
	{
		assert(scalar != static_cast<real>(0.0));
		this->x /= scalar;
		this->y /= scalar;
		this->z /= scalar;
		return *this;
	}
	
	inline real Magnitude(void) const
	{
		return sqrt(SquareMagnitude());
	}
	inline real SquareMagnitude(void) const
	{
		return (this->x * this->x) +
			(this->y * this->y) +
			(this->z * this->z);
	}
	inline real Distance(const Vec3& rhs) const
	{
		return ((*this) - rhs).Magnitude();
	}

	inline real Dot(const Vec3& rhs) const
	{
		return real {
			(this->x * rhs.x) +
			(this->y * rhs.y) +
			(this->z * rhs.z)
		};
	}
	inline Vec3 Cross(const Vec3& rhs) const
	{
		return Vec3{
			(this->y * rhs.z) - (this->z * rhs.y),
			(this->z * rhs.x) - (this->x * rhs.z),
			(this->x * rhs.y) - (this->y * rhs.x)
		};
	}

	inline bool Normalize(void)
	{
		const real mag = this->Magnitude();

		if (mag >= FLT_MIN)
		{
			const auto invMag = static_cast<real>(1.0) / mag;

			this->x *= invMag;
			this->y *= invMag;
			this->z *= invMag;

			return true;
		}

		return false;
	}

	inline Vec3 Lerp(const Vec3& rhs, const real alpha) const
	{
		// vector lerp: base + target * 'distance traveled'
		// where '0.0' is at the base and '1.0' is at the target
		return (*this) + (rhs - (*this)) * alpha;
	}
	inline Vec3 NLerp(const Vec3& rhs, real t) const
	{
		// create a lerped vector
		Vec3 result = this->Lerp(rhs, t);

		// normalize and return result
		// after normalization it's located on
		// the unit sphere without the expensive computation of slerp
		// but the acceleration is not constant
		if (result.Normalize())
			return result;

		// return original vector if the normalization failed
		return *this;
	}
	inline Vec3 SLerp(const Vec3& rhs, real t) const
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
		Vec3 relVec = rhs - *this * dot;
		// normalize it and apply the lerp
		if (relVec.Normalize())
			return *this * cos(theta) + relVec * sin(theta);

		// return original vector if the normalization failed
		return *this;
	}

	inline static Vec3 GetArithmeticCenter(const Vec3& lhs, const Vec3& rhs)
	{
		return {
			(lhs.x + rhs.x) * static_cast<real>(0.5),
			(lhs.y + rhs.y) * static_cast<real>(0.5),
			(lhs.z + rhs.z) * static_cast<real>(0.5)
		};
	}

	inline bool operator==(const Vec3& lhs)
	{
		return (this->x == lhs.x
			&& this->y == lhs.y
			&& this->z == lhs.z);
	}
	inline bool operator!=(const Vec3& lhs)
	{
		return !(*this == lhs);
	}
	
	static const Vec3 UnitX;
	static const Vec3 UnitY;
	static const Vec3 UnitZ;
	static const Vec3 UnitScale;
	static const Vec3 Zero;

};
