#ifndef __BITSET__H__
#define __BITSET__H__

#include "log.h"
#include <cstddef>

inline void setBit ( unsigned char *ptr, size_t pos ) {
	ptr [ pos / 8 ] |= ( 0x1 << ( pos % 8 ) );
}

inline void unSetBit ( unsigned char *ptr, size_t pos ) {
	ptr [ pos / 8 ] &= ( 0xff ^ ( 0x1 << ( pos % 8 ) ) );
}

inline bool isSetBit (const unsigned char *ptr, size_t pos ) {
	return ( ptr [ pos / 8 ] & ( 0x1 << ( pos % 8 ) ) );
}

inline void rightShiftBit(unsigned char *ptr, size_t start, size_t end, size_t n){
	Log* pLog = Log::getLogInstance();
	pLog->Print(INFO, "ptr: %0x, start: %d, end: %d, n: %d", ptr, start, end, n);
	for(int i = int(end + n); i >= int(start + n); i--){
		pLog->Print(NOTSET, "%d, %d", i - n, i);
		if(isSetBit(ptr, i - n))	setBit(ptr, i);
		else	unSetBit(ptr, i);
	}
	for(int i = int(start + n - 1); i >= int(start); i--){
		pLog->Print(NOTSET, "%d", i);
		unSetBit(ptr, i);
	}
}

#endif
