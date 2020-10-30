#pragma once

// EXTERNAL INCLUDES
#include <d3dcompiler.h>
#include <d3d11.h>
// INTERNAL INCLUDES
#include "component.h"
#include "types.h"
#include "mesh.h"
#include "material.h"

namespace Engine::Graphics
{
	class D3D11Renderer;
}
namespace Engine::Components
{
	/*! @class MeshRenderer \file meshrenderer.h
	 *  @brief a component to add a renderable mesh to a game object
	 *  @author Kay Hennig
	 *  @date 09.08.2020
	 */
	class MeshRenderer : public Component
	{
	public:
		/*! @brief the type of component */
		static ComponentType baseType;
		/*! @brief the type of shader that the mesh can be rendered with */
		enum class ShaderType
		{
			BlinnPhong,
			SignedDistanceField
		};
		/*! @brief Sets a new material to render with
		 *  @param mat the material to use
		 */
		void SetMaterial(Material mat);
		/*! @brief Sets a Mesh that should be rendered
		 *  @param mesh to set to
		 */
		void SetMesh(Engine::Resources::Mesh mesh);
		/*! @brief Sets a Type of shader to use
		 *  @param type of shader
		 */
		void SetShaderType(ShaderType type);
		/*! @brief Sets a Texture to use for SignedDistanceField Type
		 *  @param filename path of the texture to load
		 */
		void UseTexture(const char* filename);
	private:
		ShaderType shaderType = ShaderType::BlinnPhong;
		GraphicsBufferPtr vertexBuffer = nullptr;
		GraphicsBufferPtr indexBuffer = nullptr;
		ID3D11ShaderResourceView* texture = nullptr;
		int indexCount = 0;
		Material mat;
		friend class Engine::Graphics::D3D11Renderer;
	protected:
		/*! @brief construct a new meshrenderer component attached to a game object */
		MeshRenderer(GameObject* attach);
		friend class GameObject;
	};
}