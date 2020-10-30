// EXTERNAL INCLUDES
#include <memory>
// INTERNAL INCLUDES
#include "bitlogic.h"
#include "math/color.h"

//********************************************************************************************
FloatColor::FloatColor(const u32 Color)
{
    if (!IsBigEndian)
    {
        this->r = static_cast<real>((Color & 0xFF000000) >> 24) / static_cast<real>(255.0);
        this->g = static_cast<real>((Color & 0x00FF0000) >> 16) / static_cast<real>(255.0);
        this->b = static_cast<real>((Color & 0x0000FF00) >> 8) / static_cast<real>(255.0);
        this->a = static_cast<real>((Color & 0x000000FF) >> 0) / static_cast<real>(255.0);
        return;
    }

    this->r = static_cast<real>((Color & 0x000000FF) >> 0) / static_cast<real>(255.0);
    this->g = static_cast<real>((Color & 0x0000FF00) >> 8) / static_cast<real>(255.0);
    this->b = static_cast<real>((Color & 0x00FF0000) >> 16) / static_cast<real>(255.0);
    this->a = static_cast<real>((Color & 0xFF000000) >> 24) / static_cast<real>(255.0);
}
//********************************************************************************************
Color32::Color32(byte r, byte g, byte b, byte a) :
    r(r),
    g(g),
    b(b),
    a(a)
{ }
//********************************************************************************************
Color32::Color32(real r, real g, real b, real a) :
    r(static_cast<byte>(r* static_cast<real>(255.0))),
    g(static_cast<byte>(g* static_cast<real>(255.0))),
    b(static_cast<byte>(b* static_cast<real>(255.0))),
    a(static_cast<byte>(a* static_cast<real>(255.0)))
{ }
//********************************************************************************************
Color32::Color32(const FloatColor& Color)
{
    this->r = static_cast<byte>(Color.r * static_cast<real>(255.0));
    this->g = static_cast<byte>(Color.g * static_cast<real>(255.0));
    this->b = static_cast<byte>(Color.b * static_cast<real>(255.0));
    this->a = static_cast<byte>(Color.a * static_cast<real>(255.0));
}
//********************************************************************************************
Color32::Color32(const u32 Color)
{
    if (!IsBigEndian)
    {
        this->r = static_cast<byte>((Color & 0xFF000000) >> 24);
        this->g = static_cast<byte>((Color & 0x00FF0000) >> 16);
        this->b = static_cast<byte>((Color & 0x0000FF00) >> 8);
        this->a = static_cast<byte>((Color & 0x000000FF) >> 0);
        return;
    }

    this->r = static_cast<byte>((Color & 0x000000FF) >> 0);
    this->g = static_cast<byte>((Color & 0x0000FF00) >> 8);
    this->b = static_cast<byte>((Color & 0x00FF0000) >> 16);
    this->a = static_cast<byte>((Color & 0xFF000000) >> 24);
}
//********************************************************************************************
