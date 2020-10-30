#pragma once

// EXTERNAL INCLUDES
#include <cassert>
#include <cfloat>
#include <cmath>
// INTERNAL INCLUDES
#include "basetypes.h"
#include "vec3.h"

class Quaternion
{
public:
	
	real w = static_cast<real>(0.0);
	real x = static_cast<real>(0.0);
	real y = static_cast<real>(0.0);
	real z = static_cast<real>(0.0);

	Quaternion(void) = default;
	Quaternion(real w, real x, real y, real z) :
		w(w),
		x(x),
		y(y),
		z(z)
	{ }

	inline Quaternion operator+(const Quaternion& rhs) const
	{
		return Quaternion {
			this->w + rhs.w,
			this->x + rhs.x,
			this->y + rhs.y,
			this->z + rhs.z
		};
	}
	inline Quaternion operator-(const Quaternion& rhs) const
	{
		return Quaternion {
			this->w - rhs.w,
			this->x - rhs.x,
			this->y - rhs.y,
			this->z - rhs.z
		};
	}
	inline Quaternion operator*(real scalar) const
	{
		return Quaternion {
			this->w * scalar,
			this->x * scalar,
			this->y * scalar,
			this->z * scalar
		};
	}
	inline Quaternion operator* (const Quaternion& rkQ) const
    {
        return Quaternion {
            w * rkQ.w - x * rkQ.x - y * rkQ.y - z * rkQ.z,
            w * rkQ.x + x * rkQ.w + y * rkQ.z - z * rkQ.y,
            w * rkQ.y + y * rkQ.w + z * rkQ.x - x * rkQ.z,
            w * rkQ.z + z * rkQ.w + x * rkQ.y - y * rkQ.x
		};
    }
	
	inline Quaternion operator/(real scalar) const
	{
		assert(scalar != static_cast<real>(0.0));
		return Quaternion {
			this->w / scalar,
			this->x / scalar,
			this->y / scalar,
			this->z / scalar
		};
	}

	inline Quaternion& operator+=(const Quaternion& rhs)
	{
		this->w += rhs.w;
		this->x += rhs.x;
		this->y += rhs.y;
		this->z += rhs.z;
		return *this;
	}
	inline Quaternion& operator-=(const Quaternion& rhs)
	{
		this->w -= rhs.w;
		this->x -= rhs.x;
		this->y -= rhs.y;
		this->z -= rhs.z;
		return *this;
	}
	inline Quaternion& operator*=(real scalar)
	{
		this->w *= scalar;
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;
		return *this;
	}
	inline Quaternion& operator/=(real scalar)
	{
		assert(scalar != static_cast<real>(0.0));
		this->w /= scalar;
		this->x /= scalar;
		this->y /= scalar;
		this->z /= scalar;
		return *this;
	}
	inline Quaternion operator-()
	{
		return Quaternion{ this->w, -this->x, -this->y, -this->z };
	}
	
	static Quaternion FromAngleAxis(const real& angle, const Vec3& axis)
    {
		Quaternion Return;
		
        real fHalfAngle = (static_cast<real>(0.5) * angle);
        real fSin = sin(fHalfAngle);
		
        Return.w = cos(fHalfAngle);
        Return.x = fSin * axis.x;
        Return.y = fSin * axis.y;
        Return.z = fSin * axis.z;

		return Return;
    }
	
	real Dot(const Quaternion& other) const
	{
		return this->w * other.w
		+ this->x * other.x
		+ this->y * other.y
		+ this->z * other.z;
	}
	
	inline bool Normalize(void)
	{
		const real mag = sqrt(this->w * this->w
			+ this->x * this->x
			+ this->y * this->y
			+ this->z * this->z);

		if (mag >= FLT_MIN)
		{
			real invMag = static_cast<real>(1.0) / mag;
			
			this->w *= invMag;
			this->x *= invMag;
			this->y *= invMag;
			this->z *= invMag;

			return true;
		}

		return false;
	}

	inline Quaternion Inverse()
	{
		Quaternion conj = -(*this);
		return conj / (
			this->x * this->x +
			this->y * this->y +
			this->z * this->z +
			this->w * this->w
		);
	}

	static const Quaternion Zero;

};
