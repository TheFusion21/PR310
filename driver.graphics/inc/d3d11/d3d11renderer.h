#pragma once
#include "../rendererinterface.h"


class D3D11Renderer : public RendererInterface
{
public:
	bool Init(u64 handle) override;
	void BeginRender() override;
	void Render() override;
	void EndRender() override;
	void Shutdown() override;

	void Resize(u64 handle) override;
private:
	
	IDXGISwapChain* swapchain = nullptr;

	ID3D11Device* device = nullptr;
	ID3D11DeviceContext* context = nullptr;

	ID3D11RenderTargetView* rtv = nullptr;

	ID3D11DepthStencilView* stencilView = nullptr;

	ID3D11BlendState* blendState = nullptr;

	bool SetViewPort(u64 handle) override;


	
};