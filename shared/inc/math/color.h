#pragma once

// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "basetypes.h"

// Opacity
static constexpr u32 const& HCC_Transparent = 0x00000000;
static constexpr u32 const& HCC_Opaque = 0x000000FF;

// Pink colors
static constexpr u32 const& HCC_Pink = 0xFFC0CBFF;
static constexpr u32 const& HCC_LightPink = 0xFFB6C1FF;
static constexpr u32 const& HCC_HotPink = 0xFF69B4FF;
static constexpr u32 const& HCC_DeepPink = 0xFF1493FF;
static constexpr u32 const& HCC_PaleVioletRed = 0xDB7093FF;
static constexpr u32 const& HCC_MediumVioletRed = 0xC71585FF;

// Red colors
static constexpr u32 const& HCC_LightSalmon = 0xFFA07AFF;
static constexpr u32 const& HCC_Salmon = 0xFA8072FF;
static constexpr u32 const& HCC_DarkSalmon = 0xE9967AFF;
static constexpr u32 const& HCC_LightCoral = 0xF08080FF;
static constexpr u32 const& HCC_IndianRed = 0xCD5C5CFF;
static constexpr u32 const& HCC_Crimson = 0xDC143CFF;
static constexpr u32 const& HCC_FireBrick = 0xB22222FF;
static constexpr u32 const& HCC_DarkRed = 0x8B0000FF;
static constexpr u32 const& HCC_Red = 0xFF0000FF;

// Orange colors
static constexpr u32 const& HCC_OrangeRed = 0xFF4500FF;
static constexpr u32 const& HCC_Tomato = 0xFF6347FF;
static constexpr u32 const& HCC_Coral = 0xFF7F50FF;
static constexpr u32 const& HCC_DarkOrange = 0xFF8C00FF;
static constexpr u32 const& HCC_Orange = 0xFFA500FF;

// Yellow colors
static constexpr u32 const& HCC_Yellow = 0xFFFF00FF;
static constexpr u32 const& HCC_LightYellow = 0xFFFFE0FF;
static constexpr u32 const& HCC_LemonChiffon = 0xFFFACDFF;
static constexpr u32 const& HCC_LightGoldenrodYellow = 0xFAFAD2FF;
static constexpr u32 const& HCC_PapayaWhip = 0xFFEFD5FF;
static constexpr u32 const& HCC_Moccasin = 0xFFE4B5FF;
static constexpr u32 const& HCC_PeachPuff = 0xFFDAB9FF;
static constexpr u32 const& HCC_PaleGoldenrod = 0xEEE8AAFF;
static constexpr u32 const& HCC_Khaki = 0xF0E68CFF;
static constexpr u32 const& HCC_DarkKhaki = 0xBDB76BFF;
static constexpr u32 const& HCC_Gold = 0xFFD700FF;

// Brown colors
static constexpr u32 const& HCC_Cornsilk = 0xFFF8DCFF;
static constexpr u32 const& HCC_BlanchedAlmond = 0xFFEBCDFF;
static constexpr u32 const& HCC_Bisque = 0xFFE4C4FF;
static constexpr u32 const& HCC_NavajoWhite = 0xFFDEADFF;
static constexpr u32 const& HCC_Wheat = 0xF5DEB3FF;
static constexpr u32 const& HCC_BurlyWood = 0xDEB887FF;
static constexpr u32 const& HCC_Tan = 0xD2B48CFF;
static constexpr u32 const& HCC_RosyBrown = 0xBC8F8FFF;
static constexpr u32 const& HCC_SandyBrown = 0xF4A460FF;
static constexpr u32 const& HCC_Goldenrod = 0xDAA520FF;
static constexpr u32 const& HCC_DarkGoldenrod = 0xB8860BFF;
static constexpr u32 const& HCC_Peru = 0xCD853FFF;
static constexpr u32 const& HCC_Chocolate = 0xD2691EFF;
static constexpr u32 const& HCC_SaddleBrown = 0x8B4513FF;
static constexpr u32 const& HCC_Sienna = 0xA0522DFF;
static constexpr u32 const& HCC_Brown = 0xA52A2AFF;
static constexpr u32 const& HCC_Maroon = 0x800000FF;

// Green colors
static constexpr u32 const& HCC_DarkOliveGreen = 0x556B2FFF;
static constexpr u32 const& HCC_Olive = 0x808000FF;
static constexpr u32 const& HCC_OliveDrab = 0x6B8E23FF;
static constexpr u32 const& HCC_YellowGreen = 0x9ACD32FF;
static constexpr u32 const& HCC_LimeGreen = 0x32CD32FF;
static constexpr u32 const& HCC_Lime = 0x00FF00FF;
static constexpr u32 const& HCC_LawnGreen = 0x7CFC00FF;
static constexpr u32 const& HCC_Chartreuse = 0x7FFF00FF;
static constexpr u32 const& HCC_GreenYellow = 0xADFF2FFF;
static constexpr u32 const& HCC_SpringGreen = 0x00FF7FFF;
static constexpr u32 const& HCC_MediumSpringGreen = 0x00FA9AFF;
static constexpr u32 const& HCC_LightGreen = 0x90EE90FF;
static constexpr u32 const& HCC_PaleGreen = 0x98FB98FF;
static constexpr u32 const& HCC_DarkSeaGreen = 0x8FBC8FFF;
static constexpr u32 const& HCC_MediumAquamarine = 0x66CDAAFF;
static constexpr u32 const& HCC_MediumSeaGreen = 0x3CB371FF;
static constexpr u32 const& HCC_SeaGreen = 0x2E8B57FF;
static constexpr u32 const& HCC_ForestGreen = 0x228B22FF;
static constexpr u32 const& HCC_Green = 0x008000FF;
static constexpr u32 const& HCC_DarkGreen = 0x006400FF;

// Cyan colors
static constexpr u32 const& HCC_Aqua = 0x00FFFFFF;
static constexpr u32 const& HCC_Cyan = HCC_Aqua;
static constexpr u32 const& HCC_LightCyan = 0xE0FFFFFF;
static constexpr u32 const& HCC_PaleTurquoise = 0xAFEEEEFF;
static constexpr u32 const& HCC_Aquamarine = 0x7FFFD4FF;
static constexpr u32 const& HCC_Turquoise = 0x40E0D0FF;
static constexpr u32 const& HCC_MediumTurquoise = 0x48D1CCFF;
static constexpr u32 const& HCC_DarkTurquoise = 0x00CED1FF;
static constexpr u32 const& HCC_LightSeaGreen = 0x20B2AAFF;
static constexpr u32 const& HCC_CadetBlue = 0x5F9EA0FF;
static constexpr u32 const& HCC_DarkCyan = 0x008B8BFF;
static constexpr u32 const& HCC_Teal = 0x008080FF;

// Blue colors
static constexpr u32 const& HCC_LightSteelBlue = 0xB0C4DEFF;
static constexpr u32 const& HCC_PowderBlue = 0xB0E0E6FF;
static constexpr u32 const& HCC_LightBlue = 0xADD8E6FF;
static constexpr u32 const& HCC_SkyBlue = 0x87CEEBFF;
static constexpr u32 const& HCC_LightSkyBlue = 0x87CEFAFF;
static constexpr u32 const& HCC_DeepSkyBlue = 0x00BFFFFF;
static constexpr u32 const& HCC_DodgerBlue = 0x1E90FFFF;
static constexpr u32 const& HCC_CornflowerBlue = 0x6495EDFF;
static constexpr u32 const& HCC_SteelBlue = 0x4682B4FF;
static constexpr u32 const& HCC_RoyalBlue = 0x4169E1FF;
static constexpr u32 const& HCC_Blue = 0x0000FFFF;
static constexpr u32 const& HCC_MediumBlue = 0x0000CDFF;
static constexpr u32 const& HCC_DarkBlue = 0x00008BFF;
static constexpr u32 const& HCC_Navy = 0x000080FF;
static constexpr u32 const& HCC_MidnightBlue = 0x191970FF;

// Purple, violet, magenta colors
static constexpr u32 const& HCC_Lavender = 0xE6E6FAFF;
static constexpr u32 const& HCC_Thistle = 0xD8BFD8FF;
static constexpr u32 const& HCC_Plum = 0xDDA0DDFF;
static constexpr u32 const& HCC_Violet = 0xEE82EEFF;
static constexpr u32 const& HCC_Orchid = 0xDA70D6FF;
static constexpr u32 const& HCC_Fuchsia = 0xFF00FFFF;
static constexpr u32 const& HCC_Magenta = HCC_Fuchsia;
static constexpr u32 const& HCC_MediumOrchid = 0xBA55D3FF;
static constexpr u32 const& HCC_MediumPurple = 0x9370DBFF;
static constexpr u32 const& HCC_BlueViolet = 0x8A2BE2FF;
static constexpr u32 const& HCC_DarkViolet = 0x9400D3FF;
static constexpr u32 const& HCC_DarkOrchid = 0x9932CCFF;
static constexpr u32 const& HCC_DarkMagenta = 0x8B008BFF;
static constexpr u32 const& HCC_Purple = 0x800080FF;
static constexpr u32 const& HCC_Indigo = 0x4B0082FF;
static constexpr u32 const& HCC_DarkSlateBlue = 0x483D8BFF;
static constexpr u32 const& HCC_RebeccaPurple = 0x663399FF;
static constexpr u32 const& HCC_SlateBlue = 0x6A5ACDFF;
static constexpr u32 const& HCC_MediumSlateBlue = 0x7B68EEFF;

// White colors
static constexpr u32 const& HCC_White = 0xFFFFFFFF;
static constexpr u32 const& HCC_Snow = 0xFFFAFAFF;
static constexpr u32 const& HCC_Honeydew = 0xF0FFF0FF;
static constexpr u32 const& HCC_MintCream = 0xF5FFFAFF;
static constexpr u32 const& HCC_Azure = 0xF0FFFFFF;
static constexpr u32 const& HCC_AliceBlue = 0xF0F8FFFF;
static constexpr u32 const& HCC_GhostWhite = 0xF8F8FFFF;
static constexpr u32 const& HCC_WhiteSmoke = 0xF5F5F5FF;
static constexpr u32 const& HCC_Seashell = 0xFFF5EEFF;
static constexpr u32 const& HCC_Beige = 0xF5F5DCFF;
static constexpr u32 const& HCC_OldLace = 0xFDF5E6FF;
static constexpr u32 const& HCC_FloralWhite = 0xFFFAF0FF;
static constexpr u32 const& HCC_Ivory = 0xFFFFF0FF;
static constexpr u32 const& HCC_AntiqueWhite = 0xFAEBD7FF;
static constexpr u32 const& HCC_Linen = 0xFAF0E6FF;
static constexpr u32 const& HCC_LavenderBlush = 0xFFF0F5FF;
static constexpr u32 const& HCC_MistyRose = 0xFFE4E1FF;

// Gray, black colors
static constexpr u32 const& HCC_Gainsboro = 0xDCDCDCFF;
static constexpr u32 const& HCC_LightGrey = 0xD3D3D3FF;
static constexpr u32 const& HCC_Silver = 0xC0C0C0FF;
static constexpr u32 const& HCC_DarkGray = 0xA9A9A9FF;
static constexpr u32 const& HCC_Gray = 0x808080FF;
static constexpr u32 const& HCC_DimGray = 0x696969FF;
static constexpr u32 const& HCC_LightSlateGray = 0x778899FF;
static constexpr u32 const& HCC_SlateGray = 0x708090FF;
static constexpr u32 const& HCC_DarkSlateGray = 0x2F4F4FFF;
static constexpr u32 const& HCC_Black = 0x000000FF;

struct FloatColor
{
    real r = static_cast<real>(0.0); /**< r is the red channel value of the color */
    real g = static_cast<real>(0.0); /**< g is the green channel value of the color */
    real b = static_cast<real>(0.0); /**< b is the blue channel value of the color */
    real a = static_cast<real>(0.0); /**< a is the alpha channel value of the color */

    FloatColor(void) = default;
    FloatColor(u32 Color);

    static AEFloatColor White(void) { return AEFloatColor(HCC_White); }
    static AEFloatColor Black(void) { return AEFloatColor(HCC_Black); }

    static AEFloatColor Red(void) { return AEFloatColor(HCC_Red); }
    static AEFloatColor Lime(void) { return AEFloatColor(HCC_Lime); }
    static AEFloatColor Blue(void) { return AEFloatColor(HCC_Blue); }
    static AEFloatColor Yellow(void) { return AEFloatColor(HCC_Yellow); }
    static AEFloatColor Cyan(void) { return AEFloatColor(HCC_Cyan); }
    static AEFloatColor Magenta(void) { return AEFloatColor(HCC_Magenta); }
    static AEFloatColor Silver(void) { return AEFloatColor(HCC_Silver); }
    static AEFloatColor Gray(void) { return AEFloatColor(HCC_Gray); }
    static AEFloatColor Maroon(void) { return AEFloatColor(HCC_Maroon); }
    static AEFloatColor Olive(void) { return AEFloatColor(HCC_Olive); }
    static AEFloatColor Green(void) { return AEFloatColor(HCC_Green); }
    static AEFloatColor Purple(void) { return AEFloatColor(HCC_Purple); }
    static AEFloatColor Teal(void) { return AEFloatColor(HCC_Teal); }
    static AEFloatColor Navy(void) { return AEFloatColor(HCC_Navy); }
};

/*!
 *  @brief  This class represents a 4 byte color.\n
 *          Several methods to automatically generate color values are available
 */
class Color32
{
public:

    byte r = static_cast<byte>(0); /**< r is the red channel value of the color */
    byte g = static_cast<byte>(0); /**< g is the green channel value of the color */
    byte b = static_cast<byte>(0); /**< b is the blue channel value of the color */
    byte a = static_cast<byte>(0); /**< a is the alpha channel value of the color */

    Color32(void) = default;
    Color32(byte r, byte g, byte b, byte a);
    Color32(real r, real g, real b, real a = static_cast<real>(1.0));
    Color32(const AEFloatColor&);
    Color32(u32 Color);

    static Color32 White(void) { return Color32(HCC_White); }
    static Color32 Black(void) { return Color32(HCC_Black); }

    static Color32 Red(void) { return Color32(HCC_Red); }
    static Color32 Lime(void) { return Color32(HCC_Lime); }
    static Color32 Blue(void) { return Color32(HCC_Blue); }
    static Color32 Yellow(void) { return Color32(HCC_Yellow); }
    static Color32 Cyan(void) { return Color32(HCC_Cyan); }
    static Color32 Magenta(void) { return Color32(HCC_Magenta); }
    static Color32 Silver(void) { return Color32(HCC_Silver); }
    static Color32 Gray(void) { return Color32(HCC_Gray); }
    static Color32 Maroon(void) { return Color32(HCC_Maroon); }
    static Color32 Olive(void) { return Color32(HCC_Olive); }
    static Color32 Green(void) { return Color32(HCC_Green); }
    static Color32 Purple(void) { return Color32(HCC_Purple); }
    static Color32 Teal(void) { return Color32(HCC_Teal); }
    static Color32 Navy(void) { return Color32(HCC_Navy); }

};
