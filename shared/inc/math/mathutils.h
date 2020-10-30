#pragma once

// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "basetypes.h"

/*!
* @brief    This expression caches the number (Pi) statically
*/
constexpr static real PI = static_cast<real>(3.14159265358979);
/*!
* @brief    This expression caches the number (Pi / 2) statically
*/
constexpr static real PI_Half = static_cast<real>(1.57079632679490);
/*!
* @brief    This expression caches the number (Pi / 4) statically
*/
constexpr static real PI_Quart = static_cast<real>(0.78539816339745);

/*!
* @brief    This expression caches the converse coefficient of the angle to radian conversion.\n
*           Multiply a deg angle by this expression to get the related radian
* @note     Please multiply your angle by this expression to get the correct result.
*/
constexpr static real Ang2Rad() { return (PI / static_cast<real>(180.0)); }
/*!
* @brief    This expression caches the converse coefficient of the angle to degree conversion.\n
*           Multiply a rad angle by this expression to get the related degree
* @note     Please multiply your angle by this expression to get the correct result.
*/
constexpr static real Ang2Deg() { return (static_cast<real>(180.0) / PI); }

/*!
 * @brief   This function returns the smaller of two given values.
 * @param   Value is the reference value
 * @param   Min is the minimum value
 * @return  Value if it is bigger than the minimum, else Min is returned
 */
template <typename T>
inline T Min(const T& Value, const T& Min)
{
    return (Value > Min) * Min + (Value <= Min) * Value;
}
/*!
 * @brief   This function returns the bigger of two given values.
 * @param   Value is the reference value
 * @param   Max is the maximum value
 * @return  Value if it is smaller than the maximum, else Max is returned
 */
template <typename T>
inline T Max(const T& Value, const T& Max)
{
    return (Value > Max) * Value + (Value <= Max) * Max;
}
/*!
 * @brief   This function clamps a value between a specified minimum and maximum.
 * @param   Value is the value that will be clamped
 * @param   Min is the minimum that value can have after clamp is called
 * @param   Max is the maximum that value can have after clamp is called
 * @return  the clamped version of the input value
 */
template <typename T>
inline T Clamp(const T& Value, const T& Min, const T& Max)
{
    return ::Max(::Min(Value, Max), Min);
}
/*!
 * @brief   This function checks if a value lies in a certain range
 * @param   Value is the value that is to be checked
 * @param   Min is the minimum that value will be checked against
 * @param   Max is the maximum that value will be checked against
 * @return  true if value is bigger than min and smaller than max
 */
template <typename T>
inline bool InRange(T Value, T Min, T Max)
{
    return ((Value >= Min) && (Value <= Max));
}

/*!
 * @brief   This function contains the linear fade-in function
 * @note    This function clamps input less than zero and bigger than 1.0
 * @param   Percent is the input value in percent
 * @return  the corresponding output value
 */
template <typename T>
inline T LinearFadeIn(T Percent)
{
    Clamp(Percent, static_cast<T>(0.0), static_cast<T>(1.0));
    return Percent;
}
/*!
 * @brief   This function contains the linear fade-out function
 * @note    This function clamps input less than zero and bigger than 1.0
 * @param   Percent is the input value in percent
 * @return  the corresponding output value
 */
template <typename T>
inline T LinearFadeOut(T Percent)
{
    Clamp(Percent, static_cast<T>(0.0), static_cast<T>(1.0));
    return static_cast<T>(1.0) - Percent;
}

/*!
 * @brief   This function contains the spherical fade-in function
 * @note    This function is computationally expensive, consider using CubicFade instead.\n
 *          This function clamps input less than zero and bigger than 1.0
 * @param   Percent is the input value in percent
 * @return  the corresponding output value
 */
template <typename T>
inline T SphericalEaseIn(T Percent)
{
    Clamp(Percent, static_cast<T>(0.0), static_cast<T>(1.0));
    return static_cast<T>(sqrt(-(Percent - static_cast<T>(2.0)) * Percent));
}
/*!
 * @brief   This function contains the spherical fade-in function
 * @note    This function is computationally expensive, consider using CubicFade instead.\n
 *          This function clamps input less than zero and bigger than 1.0
 * @param   Percent is the input value in percent
 * @return  the corresponding output value
 */
template <typename T>
inline T SphericalEaseOut(T Percent)
{
    Clamp(Percent, static_cast<T>(0.0), static_cast<T>(1.0));
    return (static_cast<T>(1.0) - static_cast<T>(sqrt(-(Percent - 2) * Percent)));
}
/*!
 * @brief   This function contains the spherical ease-in function
 * @note    This function is computationally expensive, consider using CubicFade instead.\n
 *          This function clamps input less than zero and bigger than 1.0
 * @param   Percent is the input value in percent
 * @return  the corresponding output value
 */
template <typename T>
inline T SphericalFadeIn(T Percent)
{
    Clamp(Percent, static_cast<T>(0.0), static_cast<T>(1.0));
    return (static_cast<T>(1.0) - static_cast<T>(sqrt(1 - (Percent * Percent))));
}
/*!
 * @brief   This function contains the spherical ease-out function
 * @note    This function is computationally expensive, consider using CubicFade instead.\n
 *          This function clamps input less than zero and bigger than 1.0
 * @param   Percent is the input value in percent
 * @return  the corresponding output value
 */
template <typename T>
inline T SphericalFadeOut(T Percent)
{
    Clamp(Percent, static_cast<T>(0.0), static_cast<T>(1.0));
    return static_cast<T>(sqrt(static_cast<T>(1.0))) - (Percent * Percent);
}

/*!
 * @brief   This function contains the cubic ease-in function
 * @note    This function clamps input less than zero and bigger than 1.0
 * @param   Percent is the input value in percent
 * @return  the corresponding output value
 */
template <typename T>
inline T CubicEaseIn(T Percent)
{
    Clamp(Percent, static_cast<T>(0.0), static_cast<T>(1.0));
    return (static_cast<T>(2.0) * Percent) - (Percent * Percent);
}
/*!
 * @brief   This function contains the cubic ease-out function
 * @note    This function clamps input less than zero and bigger than 1.0
 * @param   Percent is the input value in percent
 * @return  the corresponding output value
 */
template <typename T>
inline T CubicEaseOut(T Percent)
{
    Clamp(Percent, static_cast<T>(0.0), static_cast<T>(1.0));
    return (static_cast<T>(-2.0) * Percent) + (Percent * Percent) + static_cast<T>(1.0);
}
/*!
 * @brief   This function contains the cubic fade-in function
 * @note    This function clamps input less than zero and bigger than 1.0
 * @param   Percent is the input value in percent
 * @return  the corresponding output value
 */
template <typename T>
inline T CubicFadeIn(T Percent)
{
    Clamp(Percent, static_cast<T>(0.0), static_cast<T>(1.0));
    return Percent * Percent;
}
/*!
 * @brief   This function contains the cubic fade-out function
 * @note    This function clamps input less than zero and bigger than 1.0
 * @param   Percent is the input value in percent
 * @return  the corresponding output value
 */
template <typename T>
inline T CubicFadeOut(T Percent)
{
    Clamp(Percent, static_cast<T>(0.0), static_cast<T>(1.0));
    return static_cast<T>(1.0) - Percent * Percent;
}
