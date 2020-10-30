// EXTERNAL INCLUDES
#include <d3d11.h>

// INTERNAL INCLUDES
#include "d3d11/graphicsinterface.h"
#include "logging.h"

GraphicsBuffer::GraphicsBuffer()
{
}

GraphicsBuffer::~GraphicsBuffer()
{
}

GraphicsResource::GraphicsResource()
{
}

GraphicsResource::~GraphicsResource()
{
}

GraphicsBuffer GraphicsInterface::CreateBuffer(BufferType type, void* data, size_t size, UsageType usageType)
{
	D3D11_BUFFER_DESC bufferDesc = {};
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;
	
	switch (type)
	{
	case BufferType::Constant:
		bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;
		bufferDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_CONSTANT_BUFFER;
		break;
	case BufferType::Vertex:
		bufferDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_VERTEX_BUFFER;
		break;
	case BufferType::Index:
		bufferDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_INDEX_BUFFER;
		break;
	case BufferType::DepthStencil:
		bufferDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_DEPTH_STENCIL;
		break;
	case BufferType::ShaderResource:
		bufferDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_SHADER_RESOURCE;
		break;
	case BufferType::RenderTarget:
		bufferDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_RENDER_TARGET;
		break;
	default:
		DebugWarn("Invalid buffer type has been requested (%i).", static_cast<u32>(type));
		return GraphicsBuffer(-1);
	}
	switch (usageType)
	{
	case UsageType::Default:
		bufferDesc.Usage = D3D11_USAGE::D3D11_USAGE_DEFAULT;
		break;
	case UsageType::Dynamic:
		bufferDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		break;
	case UsageType::Immutable:
		bufferDesc.Usage = D3D11_USAGE::D3D11_USAGE_IMMUTABLE;
		break;
	case UsageType::Staging:
		bufferDesc.Usage = D3D11_USAGE::D3D11_USAGE_STAGING;
		break;
	default:
		DebugWarn("Invalid usage type has been requested (%i).", static_cast<u32>(usageType));
		return GraphicsBuffer(-1);
	}

	D3D11_SUBRESOURCE_DATA subResData = {};
	subResData.pSysMem = data;
	subResData.SysMemPitch = 0;
	subResData.SysMemSlicePitch = 0;
	ID3D11Buffer* buffer = nullptr;
	if (FAILED(device->CreateBuffer(&bufferDesc, &subResData, &buffer))
	{
		DebugErr("Not able to allocate requested buffer");
		return GraphicsBuffer(-1);
	}
	return GraphicsBuffer(reinterpret_cast<intptr_t>(buffer));
}

GraphicsResource GraphicsInterface::CreateResource(TextureType type, u64 width, u64 height, u64 depth, void* data, ResourceFormat format, BindType bindType = BindType::ShaderResource)
{
	DXGI_FORMAT dFormat;
	switch (format)
	{
	case RGBA32_TYPELESS:
		dFormat = DXGI_FORMAT_R32G32B32A32_TYPELESS;
		break;
	case RGBA32_FLOAT:
		dFormat = DXGI_FORMAT_R32G32B32A32_FLOAT;
		break;
	case RGBA32_UINT:
		dFormat = DXGI_FORMAT_R32G32B32A32_UINT;
		break;
	case RGBA32_SINT:
		dFormat = DXGI_FORMAT_R32G32B32A32_SINT;
		break;
	case RGBA16_TYPELESS:
		dFormat = DXGI_FORMAT_R16G16B16A16_TYPELESS;
		break;
	case RGBA16_FLOAT:
		dFormat = DXGI_FORMAT_R16G16B16A16_FLOAT;
		break;
	case RGBA16_UINT:
		dFormat = DXGI_FORMAT_R16G16B16A16_UINT;
		break;
	case RGBA16_SINT:
		dFormat = DXGI_FORMAT_R16G16B16A16_SINT;
		break;
	case RGBA8_TYPELESS:
		dFormat = DXGI_FORMAT_R8G8B8A8_TYPELESS;
		break;
	case RGBA8_UINT:
		dFormat = DXGI_FORMAT_R8G8B8A8_UINT;
		break;
	case RGBA8_SINT:
		dFormat = DXGI_FORMAT_R8G8B8A8_SINT;
		break;
	case RGB32_TYPELESS:
		dFormat = DXGI_FORMAT_R32G32B32_TYPELESS;
		break;
	case RGB32_FLOAT:
		dFormat = DXGI_FORMAT_R32G32B32_FLOAT;
		break;
	case RGB32_UINT:
		dFormat = DXGI_FORMAT_R32G32B32_UINT;
		break;
	case RGB32_SINT:
		dFormat = DXGI_FORMAT_R32G32B32_SINT;
		break;
	case RG32_TYPELESS:
		dFormat = DXGI_FORMAT_R32G32_TYPELESS;
		break;
	case RG32_FLOAT:
		dFormat = DXGI_FORMAT_R32G32_FLOAT;
		break;
	case RG32_UINT:
		dFormat = DXGI_FORMAT_R32G32_UINT;
		break;
	case RG32_SINT:
		dFormat = DXGI_FORMAT_R32G32_SINT;
		break;
	case RG16_TYPELESS:
		dFormat = DXGI_FORMAT_R16G16_TYPELESS;
		break;
	case RG16_FLOAT:
		dFormat = DXGI_FORMAT_R16G16_FLOAT;
		break;
	case RG16_UINT:
		dFormat = DXGI_FORMAT_R16G16_UINT;
		break;
	case RG16_SINT:
		dFormat = DXGI_FORMAT_R16G16_SINT;
		break;
	case RG8_TYPELESS:
		dFormat = DXGI_FORMAT_R8G8_TYPELESS;
		break;
	case RG8_UINT:
		dFormat = DXGI_FORMAT_R8G8_UINT;
		break;
	case RG8_SINT:
		dFormat = DXGI_FORMAT_R8G8_SINT;
		break;
	case R32_TYPELESS:
		dFormat = DXGI_FORMAT_R32_TYPELESS;
		break;
	case R32_FLOAT:
		dFormat = DXGI_FORMAT_R32_FLOAT;
		break;
	case R32_UINT:
		dFormat = DXGI_FORMAT_R32_UINT;
		break;
	case R32_SINT:
		dFormat = DXGI_FORMAT_R32_SINT;
		break;
	case R16_TYPELESS:
		dFormat = DXGI_FORMAT_R16_TYPELESS;
		break;
	case R16_UNORM:
		dFormat = DXGI_FORMAT_R16_UNORM;
		break;
	case R16_SNORM:
		dFormat = DXGI_FORMAT_R16_SNORM;
		break;
	case R16_FLOAT:
		dFormat = DXGI_FORMAT_R16_FLOAT;
		break;
	case R16_UINT:
		dFormat = DXGI_FORMAT_R16_UINT;
		break;
	case R16_SINT:
		dFormat = DXGI_FORMAT_R16_SINT;
		break;
	case R8_TYPELESS:
		dFormat = DXGI_FORMAT_R8_TYPELESS;
		break;
	case R8_UNORM:
		dFormat = DXGI_FORMAT_R8_UNORM;
		break;
	case R8_SNORM:
		dFormat = DXGI_FORMAT_R8_SNORM;
		break;
	case R8_UINT:
		dFormat = DXGI_FORMAT_R8_UINT;
		break;
	case R8_SINT:
		dFormat = DXGI_FORMAT_R8_SINT;
		break;
	case R1_UNORM:
		dFormat = DXGI_FORMAT_R1_UNORM;
		break;
	case D32_FLOAT:
		dFormat = DXGI_FORMAT_D32_FLOAT;
		break;
	case D16_UNORM:
		dFormat = DXGI_FORMAT_D16_UNORM;
		break;
	case A8_UNORM:
		dFormat = DXGI_FORMAT_A8_UNORM;
		break;
	case D32_FLOAT_S8X24_UINT:
		dFormat = DXGI_FORMAT_D32_FLOAT_S8X24_UINT;
		break;
	default:
		break;
	}

	u32 bindFlag;
	switch (bindType)
	{
	case DepthStencil:
		bindFlag = D3D11_BIND_FLAG::D3D11_BIND_DEPTH_STENCIL;
		break;
	case ShaderResource:
		bindFlag = D3D11_BIND_FLAG::D3D11_BIND_SHADER_RESOURCE;
		break;
	case RenderTarget:
		bindFlag = D3D11_BIND_FLAG::D3D11_BIND_RENDER_TARGET;
		break;
	case UnorderedAccess:
		bindFlag = D3D11_BIND_FLAG::D3D11_BIND_UNORDERED_ACCESS;
		break;
	default:
		DebugWarn("Invalid bind type has been requested (%i).", static_cast<u32>(bindType));
		return GraphicsResource(-1);
		break;
	}
	switch (type)
	{
	case ResourceType::Texture1D:
		D3D11_TEXTURE1D_DESC desc;
		desc.Width = width;
		desc.ArraySize = depth;
		desc.MipLevels = 1;
		desc.Format = dFormat;
		desc.SampleDesc.Count = 1;
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.BindFlags = bindFlag;


		break;
	case ResourceType::Texture2D:
		D3D11_TEXTURE2D_DESC desc = {};
		desc.Width = width;
		desc.Height = height;
		desc.MipLevels = 1;
		desc.ArraySize = 1;
		desc.Format = dFormat;
		desc.SampleDesc.Count = 1;
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.BindFlags = bindFlag;
		D3D11_SUBRESOURCE_DATA* bufferSubResource = nullptr;
		D3D11Texture2D* tex2D = nullptr;
		break;
	case ResourceType::Texture2DArray:
		D3D11_TEXTURE2D_DESC desc = {};
		desc.Width = width;
		desc.Height = height;
		desc.MipLevels = 1;
		desc.ArraySize = depth;
		desc.Format = dFormat;
		desc.SampleDesc.Count = 1;
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.BindFlags = bindFlag;
		break;
	case ResourceType::Texture2DMSArray:
		D3D11_TEXTURE2D_DESC desc = {};
		desc.Width = width;
		desc.Height = height;
		desc.MipLevels = 1;
		desc.ArraySize = depth;
		desc.Format = dFormat;
		desc.SampleDesc.Count = 1;
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.BindFlags = bindFlag;
		break;
	case ResourceType::Texture3D:
		break;
	case ResourceType::Texture3DArray:
		break;
	case ResourceType::Cubemap:
		break;
	case ResourceType::CubemapArray:
		break;
	default:
		DebugWarn("Invalid resource type has been requested (%i).", static_cast<u32>(type));
		return GraphicsResource(-1);
		break;
	}
}
