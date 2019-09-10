#pragma once

namespace BitOperations {
	union CharToInt
	{
		unsigned char	chars[4];
		unsigned int	number;
	};

	inline unsigned char CharLeftShift(unsigned char c, unsigned int shift)
	{
		shift = shift < 8 ? shift : shift - ((shift / 8) * 8);
		return (c << shift | c >> (8 - shift));
	}

	inline unsigned char CharRightShift(unsigned char c, unsigned int shift)
	{
		shift = shift < 8 ? shift : shift - ((shift / 8) * 8);
		return (c >> shift | c << (8 - shift));
	}

	inline unsigned int IntLeftShift(unsigned int c, unsigned int shift)
	{
		shift = shift < 32 ? shift : shift - ((shift / 32) * 32);
		return (c << shift | c >> (32 - shift));
	}

	inline unsigned int IntRightShift(unsigned int c, unsigned int shift)
	{
		shift = shift < 32 ? shift : shift - ((shift / 32) * 32);
		return (c >> shift | c << (32 - shift));
	}
}