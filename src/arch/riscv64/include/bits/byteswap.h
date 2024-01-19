#ifndef _BITS_BYTESWAP_H
#define _BITS_BYTESWAP_H

/** @file
 *
 * Byte-order swapping functions
 *
 */

#include <stdint.h>

FILE_LICENCE ( GPL2_OR_LATER_OR_UBDL );

uint16_t
__bswap_variable_16 ( uint16_t x );

static inline __attribute__ (( always_inline )) void
__bswap_16s ( uint16_t *x ) {
	*x = __bswap_variable_16 ( *x );
}

uint32_t
__bswap_variable_32 ( uint32_t x );

static inline __attribute__ (( always_inline )) void
__bswap_32s ( uint32_t *x ) {
	*x = __bswap_variable_32 ( *x );
}

uint64_t
__bswap_variable_64 ( uint64_t x );

static inline __attribute__ (( always_inline )) void
__bswap_64s ( uint64_t *x ) {
	*x = __bswap_variable_64 ( *x );
}

#endif
