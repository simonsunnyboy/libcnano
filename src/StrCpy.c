/**
 * libcnano
 * @file StrCpy.c
 * @brief implementation of StrCpy() and derivates
 * @copyright (c) 2014/2025 Matthias Arndt <marndt@final-memory.org>
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

#include "libcnano.h"

void StrCpy ( char * src,  char * dest )
{
	while ( *src != '\0' )
	{
		*dest++=*src++;
	}

	*dest='\0';
	return;
}

void StrMidCpy ( char * src, uint32_t start_pos, char * dest )
{
	/* find start of string */
	while ( ( start_pos > 0 ) && ( *dest != '\0' ) )
	{
		dest++;
		start_pos--;
	}

	/* is the string longer than the desired starting position? */
	if ( *dest != '\0' )
	{
		while ( ( *dest != '\0' ) && ( *src != '\0' ) )
		{
			*dest++=*src ++;
		}
	}

	return;
}

