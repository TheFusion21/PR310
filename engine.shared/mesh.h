#pragma once
// EXTERNAL INCLUDES
#include <vector>
// INTERNAL INCLUDES
#include "vertex.h"

namespace Engine::Resources
{
	/*! @class Mesh \file mesh.h
	 *  @brief the mesh containing the vertex and index data
	 *  @author Kay Hennig
	 *  @date 10.08.2020
	 */
	class Mesh
	{
	public:
		/*! @brief the vertices making up the mesh */
		std::vector<Vertex> vertices = std::vector<Vertex>();
		/*! @brief the indices indexing the vertices */
		std::vector<int> indices = std::vector<int>();

		/*! @brief generate a mesh in form of a quad */
		static Mesh GenerateQuad();
		/*! @brief generate a mesh in form of a flat shaded cube */
		static Mesh GenerateFlatCube();
		/*! @brief generate a mesh in form of a smooth shaded cube */
		static Mesh GenerateSmoothCube();
		/*! @brief generate a mesh in form of a sphere 
		 *  @param rings the horizontal amount of slices
		 *  @param segments the vertical amount of slices
		 */
		static Mesh GenerateSphere(int rings, int segments);
	};
}