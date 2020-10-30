#pragma once
#include "mat4x4.h"
#include "color.h"
#include "material.h"

namespace Engine::Utils
{
    /*! @class modelConstant \file shadercb.h
	 *  @brief a buffer for a individual mesh
	 *  @author Kay Hennig
	 *  @date 10.08.2020
	 */
    struct modelConstant
    {
        /*! @brief the transformation matrix of the mesh*/
        Engine::Math::Mat4x4 world = Engine::Math::Mat4x4::Identity; // 64 bytes
        /*! @brief the material of the mesh*/
        Material m; //52 bytes
        /*! @brief a buffer because the constantbuffer needs to be 16 byte aligned*/
        Engine::Math::Vec3 buffer; //3 * 4 bytes
    };

    /*! @class worldConstant \file shadercb.h
	 *  @brief a buffer the whole scene
	 *  @author Kay Hennig
	 *  @date 10.08.2020
	 */
    struct worldConstant
    {
        /*! @brief the projection matrix to transform objects to camera*/
        Engine::Math::Mat4x4 projView = Engine::Math::Mat4x4::Identity;
        /*! @brief the eye position of the camera*/
        Engine::Math::Vec3 eye = Engine::Math::Vec3::Zero;
        /*! @brief the strength of the ambient light*/
        float ambientLight = 0.2f;
    };
}