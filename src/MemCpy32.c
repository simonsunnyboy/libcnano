/**
 * libcnano
 * @file MemCpy32.c
 * @brief implementation of MemCpy32() and MemCpy()
 * @copyright (c) 2014/25 Matthias Arndt <marndt@final-memory.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 */

#include <stdint.h>

#include "libcnano.h"

/** @brief helper structure to group 8 uint32_t values together for copying in chunks */
struct long8
{
	uint32_t d[8];
};


void MemCpy32(void * src, void * dest, uint32_t len)
{
    struct long8 * s = (struct long8 *)src; 
	struct long8 * d = (struct long8 *)dest; 

	while(len > sizeof(struct long8))
	{
		*d++=*s++;
		
		len -= sizeof(struct long8);
	}

	if(len > 0)
	{
		MemCpy(s,d, len);
	}
	
	return;
}

void MemCpy(void * src, void * dest, uint32_t len)
{
	if (len >= sizeof(struct long8))
	{
		MemCpy32(src, dest, len);
	}
	else
	{
		uint8_t * s = (uint8_t *) src;
		uint8_t * d = (uint8_t *) dest;

		while(len > 0)
		{
			*d++=*s++;
			len--;
		}
	}

	return;
}
