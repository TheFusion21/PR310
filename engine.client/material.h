#pragma once

// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "color.h"

/*! @class Material \file material.h
 *  @brief the material to descripe the looks of a mesh
 *  @author Kay Hennig
 *  @date 09.08.2020
 */
struct Material
{
	/*! @brief the ambient color of the object */
	Engine::Utils::FloatColor Ka = { 1.0f, 1.0f, 1.0f, 1.0f }; //4*4 bytes
	/*! @brief the diffuse color of the object */
	Engine::Utils::FloatColor Kd = { 0.8f, 0.8f, 0.8f, 1.0f }; //4*4 bytes
	/*! @brief the specular color of the object */
	Engine::Utils::FloatColor Ks = { 1.0f, 1.0f, 1.0f, 1.0f }; //4*4 bytes
	/*! @brief the roughness of the object */
	float roughness = 0.0f; //1 * 4 bytes
};