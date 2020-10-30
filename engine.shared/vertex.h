#pragma once

// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "vec3.h"
#include "vec2.h"
#include "color.h"

/*! @class Vertex \file vertex.h
 *  @brief struct to describe the points of a mesh
 *  @author Kay Hennig
 *  @date 09.08.2020
 */
struct Vertex
{
	/*! @brief position of the vertex */
	Engine::Math::Vec3 position;
	/*! @brief color of the vertex */
	Engine::Utils::FloatColor color;
	/*! @brief normal of the vertex */
	Engine::Math::Vec3 normal;
	/*! @brief UV0 of the vertex */
	Engine::Math::Vec2 texCoords;
};