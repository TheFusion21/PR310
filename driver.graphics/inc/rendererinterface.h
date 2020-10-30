#pragma once
#include "basetypes.h"

class RendererInterface
{
public:
	virtual bool Init(u64 handle) = 0;
	virtual void BeginRender() = 0;
	virtual void Render() = 0;
	virtual void EndRender() = 0;
	virtual void Shutdown() = 0;
	
	virtual void Resize(u64 handle) = 0;
protected:
	//TODO: put in config.h?
	bool fullscreen = false;
	bool wireframe = false;
	bool vsyncEnable = true;

	float clearColor[4] = { 0.f, 0.f, 0.f, 1.f };

	virtual bool SetViewPort(u64 handle) = 0;
};

