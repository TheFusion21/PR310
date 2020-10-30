#pragma once
// EXTERNAL INCLUDES
#include <dxgi.h>
#include <d3d11.h>
#include <vector>
// INTERNAL INCLUDES
#include "types.h"
#include "appwindow.h"
#include "singleton.h"
#include "camera.h"
#include "gameobject.h"

namespace Engine::Graphics
{
	/*! @class D3D11Renderer \file d3d11renderer.h
	 *  @brief a renderer for directX 11 
	 *  @author Kay Hennig
	 *  @date 09.08.2020
	 */
	class D3D11Renderer
	{
		GE_DECLARE_SINGLETON(D3D11Renderer)
	private:
		bool vsyncEnable = false;
		bool wireframe = false;
		BOOL inFullscreen = false;

		IDXGISwapChain* swapChain = nullptr;
		//the render device
		ID3D11Device* device = nullptr;
		ID3D11DeviceContext* context = nullptr;
		ID3D11DepthStencilView* depthView = nullptr;
		ID3D11RasterizerState* rasterState = nullptr;
		//The view to render to
		ID3D11RenderTargetView* rtv = nullptr;

		FLOAT clearColor[4] = { 0.529411f, 0.807843f, 0.921686f, 1.0f };
		//Mesh Buffers
		GraphicsBufferPtr modelBuffer = nullptr;
		//Shaders
		ID3D11VertexShader* vertexShader = nullptr;
		ID3D11InputLayout* vertexLayout = nullptr;
		ID3D11PixelShader* pixelShader = nullptr;
		ID3D11PixelShader* pixelSDFShader = nullptr;

		//Texture Sampler
		ID3D11SamplerState* sampler = nullptr;

		ID3D11BlendState* blendState = nullptr;
		//Camera
		GraphicsBufferPtr worldBuffer = nullptr;
		ui32 width = 0, height = 0;

	public:
		/*! @brief Types of buffer that the renderer can create*/
		enum class BufferType
		{
			Index,
			Vertex,
			Constant,
			DepthStencil,
			ShaderResource,
		};
		/*! @brief Types of usage that the renderer can create a buffer with*/
		enum class UsageType
		{
			Default,
			Dynamic
		};
		/*! @brief Initializes the renderer
		 *  @param window to init with
		 *  @return Initialization was successful
		 */
		bool Init(Engine::Core::AppWindow &window);
		/*! @brief resizes the viewport to the window */
		void SetViewPort();
		/*! @brief creates or recreates a render target view
		 *  @return Initialization was successful
		 */
		bool CreateRenderTarget();
		/*! @brief creates or recreates a depth stencil view
		 *  @return Initialization was successful
		 */
		bool CreateDepthStencil();
		/*! @brief resizes the buffers and viewport to the window
		 *  @return Resize was successful
		 */
		bool Resize(Engine::Core::AppWindow& window);
		/*! @brief Creates shaders and layout for vertex and pixel shader loaded from file */
		void CreateShader();
		/*! @brief To begin a render and clear the screen with clearColor */
		void BeginScene();
		/*! @brief To end a render and present rtv using vsync if enabled */
		void EndScene();
		/*! @brief Release and clear/delete previously created pointers and exit fullscreen if required */
		void Shutdown();
		/*! @brief Render a gameobject to the camera
		 *  @param object GameObject to render
		 */
		void Render(const GameObject* object);
		/*! @brief Set a active camera to render with
		 *  @param camera to use
		 */
		void SetActiveCamera(Engine::Components::Camera* camera);

		/*! @brief Create a buffer
		 * @param type what this buffer is
		 * @param data the contents of the buffer
		 * @param dataSize the byte size of the data
		 * @param usage describes the type of usage the buffer has
		 * @return generic buffer pointer
		 */
		GraphicsBufferPtr CreateBuffer(BufferType type, const void* data, int dataSize, UsageType usage = UsageType::Default);
		/*! @brief Create a Texture2D buffer
		 * @param type what this buffer is
		 * @param data the contents of the buffer
		 * @param width the horizontal size of the buffer
		 * @param height the vertical size of the buffer
		 * @param pitch of the data in memory
		 * @return generic buffer pointer
		 */
		GraphicsBufferPtr CreateTexture2D(BufferType type, DXGI_FORMAT format, const void* data, ui32 width, ui32 height, ui32 pitch, UsageType usage = UsageType::Default);
		/*! @brief Create a resource view
		 * @param resource to create a view from
		 * @param desc of the view
		 * @return DirectX view pointer
		 */
		ID3D11ShaderResourceView* CreateShaderResource(GraphicsBufferPtr resource, D3D11_SHADER_RESOURCE_VIEW_DESC* desc);

	};
}