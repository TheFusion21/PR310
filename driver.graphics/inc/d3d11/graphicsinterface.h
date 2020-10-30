#pragma once
#include "basetypes.h"
#include "math/color.h"

enum class BufferType
{
	Constant,
	Vertex,
	Index,
	DepthStencil,
	ShaderResource,
	RenderTarget
};
enum class UsageType
{
	Default,
	Dynamic,
	Immutable,
	Staging
};

//TEXTURE

enum class TextureType
{
	Texture1D,
	Texture2D,
	Texture2DArray,
	Texture2DMSArray,
	Texture3D,
	Texture3DArray,
	Cubemap,
	CubemapArray
};
enum class TextureFormat
{
	RGBA,
	BGRA,
	RGB,

	RG,
	R,
	A,

	RGB_COMPRESSED,
	RGBA_COMPRESSED
};
enum class TextureDataFormat
{
	FLOAT_32,
	FLOAT_16,

	UINT_16,
	UINT_8,
	UINT_1,

	INT_16,
	INT_8,
	INT_1
};


enum class ResourceFormat
{
	//RGBA
	UNKNOWN,
	RGBA32_TYPELESS,
	RGBA32_FLOAT,
	RGBA32_UINT,
	RGBA32_SINT,

	RGBA16_TYPELESS,
	RGBA16_FLOAT,
	RGBA16_UINT,
	RGBA16_SINT,

	RGBA8_TYPELESS,
	RGBA8_UINT,
	RGBA8_SINT,

	//RGB

	RGB32_TYPELESS,
	RGB32_FLOAT,
	RGB32_UINT,
	RGB32_SINT,

	//RG

	RG32_TYPELESS,
	RG32_FLOAT,
	RG32_UINT,
	RG32_SINT,

	RG16_TYPELESS,
	RG16_FLOAT,
	RG16_UINT,
	RG16_SINT,

	//R

	RG8_TYPELESS,
	RG8_UINT,
	RG8_SINT,

	R32_TYPELESS,
	R32_FLOAT,
	R32_UINT,
	R32_SINT,

	R16_TYPELESS,
	R16_UNORM,
	R16_SNORM,
	R16_FLOAT,
	R16_UINT,
	R16_SINT,

	R8_TYPELESS,
	R8_UNORM,
	R8_SNORM,
	R8_UINT,
	R8_SINT,

	R1_UNORM,

	//D

	D32_FLOAT,

	D16_UNORM,

	//A

	A8_UNORM,

	//OTHERS

	D32_FLOAT_S8X24_UINT
};

enum class BindType
{
	DepthStencil,
	ShaderResource,
	RenderTarget,
	UnorderedAccess
};

class GraphicsBuffer
{
public:
	GraphicsBuffer();
	~GraphicsBuffer();
	const intptr_t handle;
};

class GraphicsResource
{
public:
	GraphicsResource();
	~GraphicsResource();
	const intptr_t handle;
};

struct TextureDescriptor
{
	TextureType type;
	TextureFormat format;
	TextureDataFormat dataFormat;
};

struct Texture
{
	TextureDescriptor description;
};

enum class AttachementType : byte
{
	Color,
	Depth,
	Stencil
};

struct RTAttachementDescriptor
{
	TextureDescriptor description;
	AttachementType type;
	FloatColor clearColor = FloatColor::Purple;
};

class RTAttachement
{
public:
	RTAttachementDescriptor description;
	GraphicsResource* textureResources;
	u8 mipLevels = 1;
};

class GraphicsInterface
{
public:
	GraphicsBuffer CreateBuffer(BufferType type, void* data, size_t size, UsageType usageType);
	GraphicsResource CreateResource(TextureType type, u64 width, u64 height, u64 depth, void* data, ResourceFormat format, BindType bindType);
private:
	ID3D11Device* device = nullptr;
	ID3D11DeviceContext* context = nullptr;
};