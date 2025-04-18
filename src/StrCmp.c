/**
 * libcnano
 * @file StrCmp.c
 * @brief implementation of StrCmp() and derivates
 * @details This sums up functions for string comparison.
 *
 * @copyright (c) 2017 Matthias Arndt <marndt@final-memory.org>
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

int32_t StrNcmp(char * str1, char * str2, int32_t limit)
{
    for(; ((--limit) && (*str1 == *str2)); ++str1, ++str2)
    {
        if(*str1 == '\0')
            return(0);
    }

    return(*str1 - *str2);
}

char * StrChr(char * string, char symbol)
{
    do
    {
        if(*string == symbol)
        {
            return(string);
        }
    }
    while(*string++);

    return(NULL);
}

int32_t StrCmp(char * str1, char * str2)
{
    for(; *str1 == *str2; ++str1, ++str2)
    {
        if(*str1 == '\0')
        {
            return(0);
        }
    }

    return(*str1 - *str2);
}
