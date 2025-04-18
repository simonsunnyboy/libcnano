/**
 * libcnano
 * @file StrTrim.c
 * @brief implementation of StrTrim()
 * @copyright (c) 2025 Matthias Arndt <marndt@final-memory.org>
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


char * StrTrimLeft ( char * string )
{
	char * start = string;

	/* eat spaces and tabs in front of string */
	while ( ( start != NULL ) && ( ( *start == ' ' ) || ( *start == '\t' ) ) )
	{
		start++;
	}

	return start;
}

char * StrTrimRight ( char * string )
{
	char * start = string;

	if ( start != NULL )
	{
		/* Find the last non-whitespace character */
		char * end = start;  /* Start with the updated position */

		while ( *end != '\0' )
		{
			end++;
		}

		end--;  /* Move back to the last character of the string */

		while ( ( end >= start ) && ( ( *end == ' ' ) || ( *end == '\t' ) ) )
		{
			end--;  /* Adjust to skip trailing spaces and tabs */
		}

		/* Null-terminate the new trimmed string */
		* ( end + 1 ) = '\0';
	}

	return start;
}


char * StrTrim ( char * string )
{
	return StrTrimRight ( StrTrimLeft ( string ) );
}
