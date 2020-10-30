#pragma once

// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "basetypes.h"
#include "mathutils.h"
#include "quaternion.h"
#include "vec3.h"

class Mat4x4
{
public:

	real m11 = static_cast<real>(0.0), m12 = static_cast<real>(0.0), m13 = static_cast<real>(0.0), m14 = static_cast<real>(0.0);
	real m21 = static_cast<real>(0.0), m22 = static_cast<real>(0.0), m23 = static_cast<real>(0.0), m24 = static_cast<real>(0.0);
	real m31 = static_cast<real>(0.0), m32 = static_cast<real>(0.0), m33 = static_cast<real>(0.0), m34 = static_cast<real>(0.0);
	real m41 = static_cast<real>(0.0), m42 = static_cast<real>(0.0), m43 = static_cast<real>(0.0), m44 = static_cast<real>(0.0);

	Mat4x4(real m11, real m12, real m13, real m14
		, real m21, real m22, real m23, real m24
		, real m31, real m32, real m33, real m34
		, real m41, real m42, real m43, real m44) :
		m11(m11), m12(m12), m13(m13), m14(m14),
		m21(m21), m22(m22), m23(m23), m24(m24),
		m31(m31), m32(m32), m33(m33), m34(m34),
		m41(m41), m42(m42), m43(m43), m44(m44)
	{ }

	inline Mat4x4 operator+(const Mat4x4& rhs) const
	{
		return Mat4x4{
			this->m11 + rhs.m11, this->m12 + rhs.m12,  this->m13 + rhs.m13,  this->m14 + rhs.m14,
			this->m21 + rhs.m21, this->m22 + rhs.m22,  this->m23 + rhs.m23,  this->m24 + rhs.m24,
			this->m31 + rhs.m31, this->m32 + rhs.m32,  this->m33 + rhs.m33,  this->m34 + rhs.m34,
			this->m41 + rhs.m41, this->m42 + rhs.m42,  this->m43 + rhs.m43,  this->m44 + rhs.m44
		};
	}
	inline Mat4x4 operator-(const Mat4x4& rhs) const
	{
		return Mat4x4 {
			this->m11 - rhs.m11, this->m12 - rhs.m12,  this->m13 - rhs.m13,  this->m14 - rhs.m14,
			this->m21 - rhs.m21, this->m22 - rhs.m22,  this->m23 - rhs.m23,  this->m24 - rhs.m24,
			this->m31 - rhs.m31, this->m32 - rhs.m32,  this->m33 - rhs.m33,  this->m34 - rhs.m34,
			this->m41 - rhs.m41, this->m42 - rhs.m42,  this->m43 - rhs.m43,  this->m44 - rhs.m44
		};
	}
	inline Mat4x4 operator*(const Mat4x4& rhs) const
	{
		return Mat4x4 {
			this->m11 * rhs.m11 + this->m12 * rhs.m21 + this->m13 * rhs.m31 + this->m14 * rhs.m41,
			this->m11 * rhs.m12 + this->m12 * rhs.m22 + this->m13 * rhs.m32 + this->m14 * rhs.m42,
			this->m11 * rhs.m13 + this->m12 * rhs.m23 + this->m13 * rhs.m33 + this->m14 * rhs.m43,
			this->m11 * rhs.m14 + this->m12 * rhs.m24 + this->m13 * rhs.m34 + this->m14 * rhs.m44,

			this->m21 * rhs.m11 + this->m22 * rhs.m21 + this->m23 * rhs.m31 + this->m24 * rhs.m41,
			this->m21 * rhs.m12 + this->m22 * rhs.m22 + this->m23 * rhs.m32 + this->m24 * rhs.m42,
			this->m21 * rhs.m13 + this->m22 * rhs.m23 + this->m23 * rhs.m33 + this->m24 * rhs.m43,
			this->m21 * rhs.m14 + this->m22 * rhs.m24 + this->m23 * rhs.m34 + this->m24 * rhs.m44,

			this->m31 * rhs.m11 + this->m32 * rhs.m21 + this->m33 * rhs.m31 + this->m34 * rhs.m41,
			this->m31 * rhs.m12 + this->m32 * rhs.m22 + this->m33 * rhs.m32 + this->m34 * rhs.m42,
			this->m31 * rhs.m13 + this->m32 * rhs.m23 + this->m33 * rhs.m33 + this->m34 * rhs.m43,
			this->m31 * rhs.m14 + this->m32 * rhs.m24 + this->m33 * rhs.m34 + this->m34 * rhs.m44,

			this->m41 * rhs.m11 + this->m42 * rhs.m21 + this->m43 * rhs.m31 + this->m44 * rhs.m41,
			this->m41 * rhs.m12 + this->m42 * rhs.m22 + this->m43 * rhs.m32 + this->m44 * rhs.m42,
			this->m41 * rhs.m13 + this->m42 * rhs.m23 + this->m43 * rhs.m33 + this->m44 * rhs.m43,
			this->m41 * rhs.m14 + this->m42 * rhs.m24 + this->m43 * rhs.m34 + this->m44 * rhs.m44
		};
	}
	inline Mat4x4 operator*(const real scalar) const
	{
		return Mat4x4 {
			this->m11 * scalar, this->m12 * scalar,  this->m13 * scalar,  this->m14 * scalar,
			this->m21 * scalar, this->m22 * scalar,  this->m23 * scalar,  this->m24 * scalar,
			this->m31 * scalar, this->m32 * scalar,  this->m33 * scalar,  this->m34 * scalar,
			this->m41 * scalar, this->m42 * scalar,  this->m43 * scalar,  this->m44 * scalar
		};
	}
	inline Vec3 operator*(const Vec3& rhs) const
	{
		return Vec3{
			this->m11 * rhs.x + this->m12 * rhs.y + this->m13 * rhs.z,
			this->m21 * rhs.x + this->m22 * rhs.y + this->m23 * rhs.z,
			this->m31 * rhs.x + this->m32 * rhs.y + this->m33 * rhs.z
		};
	}

	inline const Mat4x4& operator+=(const Mat4x4& rhs)
	{
		this->m11 += rhs.m11;
		this->m12 += rhs.m12;
		this->m13 += rhs.m13;
		this->m14 += rhs.m14;

		this->m21 += rhs.m21;
		this->m22 += rhs.m22;
		this->m23 += rhs.m23;
		this->m24 += rhs.m24;

		this->m31 += rhs.m31;
		this->m32 += rhs.m32;
		this->m33 += rhs.m33;
		this->m34 += rhs.m34;

		this->m41 += rhs.m41;
		this->m42 += rhs.m42;
		this->m43 += rhs.m43;
		this->m44 += rhs.m44;

		return *this;
	}
	inline const Mat4x4& operator-=(const Mat4x4& rhs)
	{
		this->m11 -= rhs.m11;
		this->m12 -= rhs.m12;
		this->m13 -= rhs.m13;
		this->m14 -= rhs.m14;

		this->m21 -= rhs.m21;
		this->m22 -= rhs.m22;
		this->m23 -= rhs.m23;
		this->m24 -= rhs.m24;

		this->m31 -= rhs.m31;
		this->m32 -= rhs.m32;
		this->m33 -= rhs.m33;
		this->m34 -= rhs.m34;

		this->m41 -= rhs.m41;
		this->m42 -= rhs.m42;
		this->m43 -= rhs.m43;
		this->m44 -= rhs.m44;

		return *this;
	}
	inline const Mat4x4& operator*=(const real scalar)
	{
		this->m11 *= scalar;
		this->m12 *= scalar;
		this->m13 *= scalar;
		this->m14 *= scalar;

		this->m21 *= scalar;
		this->m22 *= scalar;
		this->m23 *= scalar;
		this->m24 *= scalar;

		this->m31 *= scalar;
		this->m32 *= scalar;
		this->m33 *= scalar;
		this->m34 *= scalar;

		this->m41 *= scalar;
		this->m42 *= scalar;
		this->m43 *= scalar;
		this->m44 *= scalar;

		return *this;
	}

	inline Mat4x4 Transpose(void) const
	{
		return Mat4x4 {
			this->m11, this->m21, this->m31, this->m41,
			this->m12, this->m22, this->m32, this->m42,
			this->m13, this->m23, this->m33, this->m43,
			this->m14, this->m24, this->m34, this->m44
		};
	}
	inline Mat4x4 Inverse(void) const
	{
		real t11 = m33 * m22 - m32 * m23;
		real t21 = m31 * m23 - m33 * m21;
		real t31 = m32 * m21 - m31 * m22;

		real invDet = static_cast<real>(1.0) / (m11 * t11 + m12 * t21 + m13 * t31);

		t11 *= invDet;
		t21 *= invDet;
		t31 *= invDet;

		real tm11 = m11 * invDet;
		real tm12 = m12 * invDet;
		real tm13 = m13 * invDet;

		real r00 = t11;
		real r01 = tm13 * m32 - tm12 * m33;
		real r02 = tm12 * m23 - tm13 * m22;

		real r10 = t21;
		real r11 = tm11 * m33 - tm13 * m31;
		real r12 = tm13 * m21 - tm11 * m23;

		real r20 = t31;
		real r21 = tm12 * m31 - tm11 * m32;
		real r22 = tm11 * m22 - tm12 * m21;

		real p03 = -(r00 * m14 + r01 * m24 + r02 * m34);
		real p13 = -(r10 * m14 + r11 * m24 + r12 * m34);
		real p23 = -(r20 * m14 + r21 * m24 + r22 * m34);

		return Mat4x4
		{
			r00, r01, r02, p03,
			r10, r11, r12, p13,
			r20, r21, r22, p23,
			0.0, 0.0, 0.0, 1.0
		};
	}

	static Mat4x4 FromTranslation(const Vec3& Position)
	{
		Mat4x4 Result = Mat4x4::Identity;
		
		Result.m14 = Position.x;
		Result.m24 = Position.y;
		Result.m34 = Position.z;
		
		return Result;
	}
	static Mat4x4 FromScale(const Vec3& Scale)
	{
		Mat4x4 Result = Mat4x4::Identity;
		
		Result.m11 = Scale.x;
		Result.m22 = Scale.y;
		Result.m33 = Scale.z;
		
		return Result;
	}
	static Mat4x4 FromScale(real UnitScale)
	{
		Mat4x4 ScalingMatrix = Mat4x4::Identity;
		ScalingMatrix.m44 = static_cast<real>(1.0) / UnitScale;
		return ScalingMatrix;
	}
	static Mat4x4 FromOrientation(const Quaternion& orientation)
	{
		Mat4x4 Result = Mat4x4::Identity;
		
		real fTx  = orientation.x + orientation.x;
        real fTy  = orientation.y + orientation.y;
        real fTz  = orientation.z + orientation.z;
        real fTwx = fTx * orientation.w;
        real fTwy = fTy * orientation.w;
        real fTwz = fTz * orientation.w;
		
        real fTxx = fTx * orientation.x;
        real fTxy = fTy * orientation.x;
        real fTxz = fTz * orientation.x;
		
        real fTyy = fTy * orientation.y;
        real fTyz = fTz * orientation.y;
		
        real fTzz = fTz * orientation.z;

        Result.m11 = 1.0f - (fTyy + fTzz);
        Result.m12 = fTxy - fTwz;
        Result.m13 = fTxz + fTwy;
		
        Result.m21 = fTxy + fTwz;
        Result.m22 = 1.0f - (fTxx + fTzz);
        Result.m23 = fTyz - fTwx;
		
        Result.m31 = fTxz - fTwy;
        Result.m32 = fTyz + fTwx;
        Result.m33 = 1.0f - (fTxx + fTyy);
		
		return Result;
	}
	/**
	 *	@brief	This method generates a lookat view matrix
	 *  @param	Eye is the position of the camera
	 *  @param	Target is the lookat target of the camera
	 *  @param	Up is the upwards directed vector of the camera
	 *  @return	the generated lookat view matrix
	 *  @note	Pitch and Yaw are expected to be in degree format.
	 *			Bounds of rotation are clamped by the function.
	 */
	static Mat4x4 FromView(Vec3 Eye, Vec3 Target, Vec3 Up = Vec3::UnitY)
	{
		// Forward axis = from target to eye (will be inversed later)
		Vec3 ForwardAxis = Eye - Target;
		ForwardAxis.Normalize();

		// Upward axis
		Vec3 UpwardAxis = Up;
		UpwardAxis.Normalize();

		// Construct third axis
		Vec3 RightAxis = UpwardAxis.Cross(ForwardAxis);

		// Generate inverted view from the axes
		// This is equal to Orientation * Translation
		// where Translation is inverted by negating Eye
		Mat4x4 View =
		{
			ForwardAxis.x, UpwardAxis.x, RightAxis.x, -ForwardAxis.Dot(Eye),
			ForwardAxis.y, UpwardAxis.y, RightAxis.y, -UpwardAxis.Dot(Eye),
			ForwardAxis.z, UpwardAxis.z, RightAxis.z, -RightAxis.Dot(Eye),
			static_cast<real>(0.0), static_cast<real>(0.0), static_cast<real>(0.0), static_cast<real>(1.0)
		};

		return View;
	}
	/**
	 *	@brief	This method generates an first person view matrix
	 *  @param	Eye is the position of the camera
	 *  @param	Pitch is the Pitch of the camera
	 *  @param	Yaw is the Yaw of the camera
	 *  @return	the generated first person view matrix
	 *  @note	Pitch and Yaw are expected to be in degree format.
	 *			Bounds of rotation are clamped by the function.
	 */
	static Mat4x4 FromView(Vec3 Eye, real Pitch, real Yaw)
	{
		// Convert pitch and yaw to radians
		Pitch = Clamp(Pitch, Ang2Rad() * static_cast<real>(-90) + FLT_MIN, Ang2Rad() * static_cast<real>(90) - FLT_MIN);
		Yaw = fmod(Yaw, Ang2Rad() * static_cast<real>(360.0));

		// Calculate the rotation
		real CosPitch = cos(Pitch);
		real SinPitch = sin(Pitch);
		real CosYaw = cos(Yaw);
		real SinYaw = sin(Yaw);

		// Set the rotation for each axis
		Vec3 ForwardAxis = { SinYaw * CosPitch, -SinPitch, CosPitch * CosYaw };
		Vec3 UpAxis = { SinYaw * SinPitch, CosPitch, CosYaw * SinPitch };
		Vec3 RightAxis = { CosPitch, static_cast<real>(0.0), -SinYaw };

		// Generate the view matrix
		Mat4x4 View =
		{
			RightAxis.x, UpAxis.x, ForwardAxis.x, -RightAxis.Dot(Eye),
			RightAxis.y, UpAxis.y, ForwardAxis.y, -UpAxis.Dot(Eye),
			RightAxis.z, UpAxis.z, ForwardAxis.z, -ForwardAxis.Dot(Eye),
			static_cast<real>(0.0), static_cast<real>(0.0), static_cast<real>(0.0), static_cast<real>(1.0)
		};

		return View;
	}
	/**
	 *	@brief	This method generates an arcball view matrix
	 *  @param	Offset is the offset vector from the Target
	 *  @param	Orientation is the Rotation of the camera
	 *  @param	Target is the camera view target
	 *  @return	the generated arcball view matrix
	 */
	static Mat4x4 FromView(Vec3 Offset, Quaternion Orientation, Vec3 Target = Vec3::Zero)
	{
		// Calculate the camera position
		Mat4x4 CameraTranslation = FromTranslation(-Offset);
		// Calculate the camera orientation
		Mat4x4 Rotation = FromOrientation(Orientation.Inverse());
		// Calculate the target translation
		Mat4x4 TargetTranslation = FromTranslation(-Target);

		// Generate the view matrix
		Mat4x4 View = CameraTranslation * Rotation * TargetTranslation;

		return View;
	}
	static Mat4x4 FromOrthographic(real width, real height, real nearPlane = static_cast<real>(1.0), real farPlane = static_cast<real>(10000.0))
	{
		return Mat4x4
		{
			static_cast<real>(2.0 / width), static_cast<real>(0.0), static_cast<real>(0.0), static_cast<real>(0.0),
			static_cast<real>(0.0), static_cast<real>(2.0 / height), static_cast<real>(0.0), static_cast<real>(0.0),
			static_cast<real>(0.0), static_cast<real>(0.0), static_cast<real>(1.0) / (nearPlane - farPlane), nearPlane / (nearPlane - farPlane),
			static_cast<real>(0.0), static_cast<real>(0.0), static_cast<real>(0.0), static_cast<real>(1.0)
		};
	}
	static Mat4x4 FromPerspectiveFOV(real fov = static_cast<real>(75.0), real aspect = static_cast<real>(1.77778), real nearPlane = static_cast<real>(1.0), real farPlane = static_cast<real>(10000.0))
	{
		real ScaleY = static_cast<real>(1.0) / static_cast<real>(tan(Ang2Rad() * fov * static_cast<real>(0.5)));
		real ScaleX = ScaleY / aspect;

		// right handed system
		return Mat4x4
		{
			ScaleX, static_cast<real>(0.0), static_cast<real>(0.0), static_cast<real>(0.0),
			static_cast<real>(0.0), ScaleY, static_cast<real>(0.0), static_cast<real>(0.0),
			static_cast<real>(0.0), static_cast<real>(0.0), farPlane / (nearPlane - farPlane), nearPlane * farPlane / (nearPlane - farPlane),
			static_cast<real>(0.0), static_cast<real>(0.0), static_cast<real>(-1.0), static_cast<real>(0.0)
		};
	}
	
	static const Mat4x4 Identity;
	static const Mat4x4 Zero;
};
