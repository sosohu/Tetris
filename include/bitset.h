#ifndef __BITSET__H__
#define __BITSET__H__

#include <cstddef>

inline void setBit ( unsigned char *ptr, size_t pos ) {
	ptr [ pos / 8 ] |= ( 0x1 << ( pos % 8 ) );
}

inline void unSetBit ( unsigned char *ptr, size_t pos ) {
	ptr [ pos / 8 ] &= ( 0xff ^ ( 0x1 << ( pos % 8 ) ) );
}

inline bool isSetBit ( unsigned char *ptr, size_t pos ) {
	return ( ptr [ pos / 8 ] & ( 0x1 << ( pos % 8 ) ) );
}

#endif
