// hex.h

#pragma once

#include <inttypes.h>

typedef uint8_t u8;

// Options for hexadecimal translation
#define HEX_OPT_UPPERCASE	1 // Use uppercase letters in hex string
#define HEX_OPT_APPEND_NULL	2 // Append a null character ('\0') to the hex string

// Translates the first binlen bytes of bin to hexadecimal using the given
// options and stores them in hex. Can translate in-place if bin and hex refer to different
// type-casts of the same array in memory.
void ToHex(u8* bin, int binlen, char* hex, int opts);

#define HEX_ERR_INVALID_CHAR	1
#define HEX_ERR_OVERFLOW		2 // The number of bytes generated would overflow the buffer
#define HEX_ERR_ODD_CHAR_CNT	3 // Odd number of characters in hex string

// Translates the given hex string to binary and stores the results in bin, up to binlen bytes.
// Can translate in-place if bin and hex refer to different type-casts of the same array in memory.
// Returns non-zero if the translation was successful. Otherwise, returns an error code.
// In the case of HEX_ERR_OVERFLOW, binlen bytes will still be translated and stored in bin.
int FromHex(u8* bin, int binlen, char* hex);
