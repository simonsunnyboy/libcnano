/**
 * libcnano
 * @file StrLeft.c
 * @brief implementation of StrLeft(), StrRight() and derivatives
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

#include <stddef.h>
#include "libcnano.h"

bool StrLeft(char * src, char * left_part)
{
    bool match = true;
    
    do
    {
        if(*src++ != *left_part++)
        {
            match = false;
        }
    }
    while((match == true)&&(*left_part != '\0'));
    
    return match;
}

bool StrRight(char * src, char * right_part)
{
    bool match = true;

    // Traverse to the end of both strings
    char * src_end = src;
    char * right_end = right_part;

    while (*src_end != '\0') src_end++;
    while (*right_end != '\0') right_end++;

    // Calculate the lengths by subtracting pointers
    size_t src_len = src_end - src;
    size_t right_len = right_end - right_part;

    // Ensure `right_part` can fit within `src`
    if (right_len > src_len)
    {
        return false;
    }

    // Start comparison from the end of `src`
    src_end = src + (src_len - right_len);

    while ((*right_part != '\0') && match)
    {
        if (*src_end++ != *right_part++)
        {
            match = false;
        }
    }

    return match;
}

bool StrMid(char * src, uint32_t start_pos, char * match_str)
{
    bool match = false;
    
    while((start_pos > 0)&&(*src != '\0'))
    {
        src++;
        start_pos--;
    }
    
    /* is the string longer than the desired starting position? */
    if(*src != '\0')
    {
        match = StrLeft(src, match_str);
    }
    
    return match;
}
