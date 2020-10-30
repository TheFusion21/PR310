#pragma once

// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "basetypes.h"

#define AEIsBigEndian (*(u16*)"\0\xff" < 0x100)

#define	AEHasFlag(val, flag) ((flag) == ((val)&(flag)))
#define	AEAddFlag(val, flag) ((val) |= (flag))
#define	AERemFlag(val, flag) ((val) &= (~(flag)))
#define	AESetFlag(val, flag, enable) if ( enable ){(val)|=(flag);} else {(val)&=~(flag);}

/*!
 *	@brief	This aligns the address to the alignment that comes BEFORE the address
 *	@param	address is the address to be aligned
 *	@param	alignment is the demanded alignment in bytes
 *	@return	the resulting aligned address which is smaller that the given one
 *	@note	Allocate enough space to accomodate for alignment + offset
 *			where offset must include all bytes that are needed in addition to the requested amount of bytes.
 *			E.g. (offset = sizeof(intptr_t) + alignment - 1)
 */
inline intptr_t AEAlignAddress(intptr_t address, size_t alignment)
{
	return address & ~(alignment - 1);
}
