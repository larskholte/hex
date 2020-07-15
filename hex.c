// hex.c

#include "hex.h"

char HexCharForNibble(u8 n, int opts) {
	if (n < 10) return '0' + n;
	if (opts & HEX_OPT_UPPERCASE) {
		return 'A' + n - 10;
	}
	return 'a' + n - 10;
}

int NibbleForHexChar(char c) {
	if (c >  'f') return -1;
	if (c >= 'a') return c - 'a' + 10;
	if (c >  'F') return -1;
	if (c >= 'A') return c - 'A' + 10;
	if (c >  '9') return -1;
	if (c >= '0') return c - '0';
	return -1;
}

void ToHex(u8* bin, int binlen, char* hex, int opts) {
	u8* in = bin + binlen;
	char* out = hex + 2 * binlen;
	if (opts & HEX_OPT_APPEND_NULL) {
		*out = '\0';
	}
	for (; in > bin; ) {
		in--;
		out--;
		u8 b = *in;
		// Low nibble
		*out = HexCharForNibble(b & 0x0f, opts);
		out--;
		// High nibble
		*out = HexCharForNibble(b >> 4, opts);
	}
}

int FromHex(u8* bin, int binlen, char* hex) {
	// Translate all bytes
	u8* out = bin;
	while (out - bin < binlen && *hex) {
		// Higher nibble
		int n = NibbleForHexChar(*hex);
		if (n < 0) {
			return HEX_ERR_INVALID_CHAR;
		}
		hex++;
		if (!*hex) {
			return HEX_ERR_ODD_CHAR_CNT;
		}
		int b = n << 4;
		// Lower nibble
		n = NibbleForHexChar(*hex);
		if (n < 0) {
			return HEX_ERR_INVALID_CHAR;
		}
		b |= n;
		*out = b;
		hex++;
		out++;
	}
	if (*hex) {
		return HEX_ERR_OVERFLOW;
	}
	return 0;
}
