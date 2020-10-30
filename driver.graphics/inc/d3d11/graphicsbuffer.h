#pragma once

// EXTERNAL INCLUDES
#include <d3d11.h>
// INTERNAL INCLUDES

enum class GfxBufferType
{
	Unknown,
	ConstantBuffer,
	IndexBuffer,
	VertexBuffer
};

struct GraphicsResource
{
	GfxBufferType Type;
	u32 Size;
	void* Buffer;
};

template <GfxBufferType BufferType>
void CreateBuffer(ID3D11Device* Device, GraphicsResource& Resource)
{
	if (!Device)
		AEErr("Invalid D3D11Device. Graphics Buffer could not be created.");

	AnsiString BufferTypeName = "";

	D3D11_BUFFER_DESC BufferDesc = { };

	BufferDesc.ByteWidth = Resource.Size;
	switch (BufferType)
	{
	case GfxBufferType::ConstantBuffer:
		BufferTypeName = "Constant Buffer";
		BufferDesc.Usage = D3D11_USAGE_DYNAMIC;
		BufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		BufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		BufferDesc.MiscFlags = 0;
		break;
	case GfxBufferType::IndexBuffer:
		BufferTypeName = "Index Buffer";
		BufferDesc.Usage = D3D11_USAGE_DEFAULT;
		BufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		BufferDesc.CPUAccessFlags = 0;
		BufferDesc.MiscFlags = 0;
		break;
	case GfxBufferType::VertexBuffer:
		BufferTypeName = "Vertex Buffer";
		BufferDesc.Usage = D3D11_USAGE_DEFAULT;
		BufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		BufferDesc.CPUAccessFlags = 0;
		BufferDesc.MiscFlags = 0;
		break;
	default:
		BufferTypeName = "Unknown Buffer";
		AEWarn("Invalid buffer type has been requested (%i).", static_cast<u32>(Resource.Type));
		return;
	}

	D3D11_SUBRESOURCE_DATA SubData = { };
	SubData.pSysMem = Resource.Buffer;
	SubData.SysMemPitch = 0;
	SubData.SysMemSlicePitch = 0;

	ID3D11Buffer* Buffer = nullptr;
	if (FAILED(Device->CreateBuffer(&BufferDesc, &SubData, &Buffer)))
		AEErr("Unable to create %s.", BufferTypeName);

	Resource.Buffer	= Buffer;
	Resource.Type	= BufferType;
}
