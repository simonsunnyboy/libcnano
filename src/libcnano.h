/**
 * libcnano
 * @file libcnano.h
 * @brief common library header defining all available functions
 * @copyright (c) 2014/2016/2017/2025 Matthias Arndt <marndt@final-memory.org>
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

#ifndef LIBCNANO_H
	#define LIBCNANO_H

	#include <stdbool.h>
	#include <stdint.h>

    #ifndef NULL
        #define NULL ((char *)0)  /* NULL definition if missing */
    #endif

	/* memory copy functions */

    /**
     * @brief copy memory in 32 byte chunks (8 longs)
     * @details If the length to copy is not dividable by 32, additional bytes are also copied.
     * @attention Address alignment is is not checked and up to the caller!
     * @param[in] src pointer
     * @param[in] dest pointer
     * @param[in] len in bytes 
     */
	void MemCpy32(void * src, void * dest, uint32_t len);

    /**
     * @brief copy memory in as single bytes
     * @details If the length of the copy exceeds 8 uint32_t, MemCpy32 is used.
     * @attention Address alignment is is not checked and up to the caller!
     * @param[in] src pointer
     * @param[in] dest pointer
     * @param[in] len in bytes 
     */
    void MemCpy(void * src, void * dest, uint32_t len);

	/* String handling functions */

    /**
     * @brief compares the a string against the left part of the string 
     * @details The beginning of a string can be checked against a different string.
     * @param[in] src is main string
     * @param[in] left_part is the part to be matched on the left end of the main string
     * @returns true if the left part matches
     * @returns false if not
     */
	bool StrLeft(char * src, char * left_part);

    /**
     * @brief matches part of a string at an arbitrary position in the main string
     * @details A NULL string never matches.
     * @param[in] src is the main string to be searched
     * @param[in] start_pos is the index position inside the main string
     * @param[in] match_str is the substring searched in the main string
     * @returns true if the sub string is found
     * @returns false if the sub string is not found
     */
	bool StrMid(char * src, uint32_t start_pos, char * match);

    /**
     * @brief compares the a string against the right part of the string 
     * @details The end of a string can be checked against a different string.
     * @param[in] src is main string
     * @param[in] right_part is the part to be matched on the left end of the main string
     * @returns true if the left part matches
     * @returns false if not
     */
    bool StrRight(char * src, char * right_part);

    /**
     * @brief copies a source string to a destination string
     * @details The trailing 0x00 char is also copied.
     */
	void StrCpy(char * src,  char * dest);

    /**
     * @brief copy a smaller substring into a larger source string at an arbitrary position
     * @details A trailing 0x00 char is not copied from the substring. 
     *          If the substring is longer than the destination string, the copy stops at the 0x00 char.
     * @param[in] src is the substring to be copied into the main string
     * @param[in] start_pos is the index where data is to copied
     * @param[in] dest is the main string
     */
	void StrMidCpy(char * src, uint32_t start_pos, char * dest);

	/**
     * @brief compares at most the first n bytes from str1  str2.
     * @details
     * @param[in] str1 points to the first string
     * @param[in] str2 points to the second string
     * @param[in] limit denotes the number of characters to compare
     * @returns value < 0 then it indicates str1 is less than str2.
     * @returns value > 0 then it indicates str2 is less than str1.
     * @returns value = 0 then it indicates str1 is equal to str2 within the limit of characters
     */
    int32_t StrNcmp(char * str1, char * str2, int32_t limit);

    /**
     * @brief finds the given symbol inside the string
     * @details
     * @param[in] string to search
     * @param[in] symbol to find inside the string
     * @returns NULL if the symbol is not found
     * @returns the pointer to the symbol's location inside the string if the symbol is found
     */
    char * StrChr(char * string, char symbol);

    /**
     * @brief Compares two strings lexicographically.
     * @details
     * This function compares two null-terminated strings character by character.
     * The comparison is performed using ASCII values. If the strings are equal,
     * the function returns 0. Otherwise, it returns the difference between
     * the ASCII values of the first non-matching characters.
     *
     * @param[in] str1 Pointer to the first null-terminated string.
     * @param[in] str2 Pointer to the second null-terminated string.
     * @returns 0 if the strings are equal.
     * @returns A negative value if the first string is lexicographically less than the second.
     * @returns A positive value if the first string is lexicographically greater than the second.
    */
    int32_t StrCmp(char * str1, char * str2);

    /**
     * @brief determine length of the given string
     * @details
     * @param[in] string 
     * @return length of string in characters
     */
    int32_t StrLen(char * string);

    /**
     * @brief Locates the first occurrence of a substring within a string.
     * @details
     * This function searches for the first occurrence of the specified pattern
     * within the given string. If the pattern is found, a pointer to the start of 
     * the matching substring is returned. If the pattern is not found, the function 
     * returns NULL.
     * 
     * The search is case-sensitive.
     *
     * @param[in] string Pointer to the null-terminated target string to search in.
     * @param[in] pattern Pointer to the null-terminated substring (pattern) to locate.
     * @return char* Pointer to the beginning of the first occurrence of the pattern 
     *         within the target string, or NULL if the pattern is not found.
     */
    char * StrStr(char * string, char * pattern);

    /**
     * @brief Removes leading and trailing spaces and tabs from a string in RAM
     * @details
     * This function processes the given string to remove any leading and trailing whitespace
     * characters, specifically spaces (' ') and tabs ('\t'). It returns a pointer 
     * to the first non-whitespace character of the string.
     *
     * @param[in] string Pointer to the null-terminated string to be trimmed.
     * @return char* Pointer to the modified string, starting from the first non-whitespace 
     *         character.
     *
     * @note The original string is altered to relocate the trailing NUL.
     */
    char * StrTrim(char * string);

    /**
     * @brief Removes leading spaces and tabs from a string in RAM
     * @details
     * This function processes the given string to remove any leading whitespace
     * characters, specifically spaces (' ') and tabs ('\t'). It returns a pointer 
     * to the first non-whitespace character of the string.
     *
     * @param[in] string Pointer to the null-terminated string to be trimmed.
     * @return char* Pointer to the modified string, starting from the first non-whitespace 
     *         character.
     *
     * @note The original string is not altered; only the starting pointer is adjusted.
     */
    char * StrTrimLeft(char * string);

    /**
     * @brief Removes trailing spaces and tabs from a string in RAM
     *
     * This function processes the given string to remove any trailing whitespace
     * characters, specifically spaces (' ') and tabs ('\t'). It returns a pointer 
     * to the first non-whitespace character of the string.
     *
     * @param[in] string Pointer to the null-terminated string to be trimmed.
     * @return char* Pointer to the modified string, starting from the first non-whitespace 
     *         character.
     *
     * @note The original string is altered to relocate the trailing NUL.
     */
    char * StrTrimRight(char * string);

    /**
     * @brief Converts all lowercase letters in a string to uppercase.
     *
     * This function processes the input null-terminated string and converts
     * all lowercase alphabetic characters ('a' to 'z') to their corresponding
     * uppercase equivalents ('A' to 'Z'). Non-alphabetic characters remain
     * unchanged.
     *
     * @param[in] string Pointer to the null-terminated string to be converted.
     * @return char* Pointer to the modified input string.
     *
     * @note The function modifies the string in place.
     */
    char * StrToUpper(char * string);

    /**
     * @brief Converts all uppercase letters in a string to lowercase.
     *
     * This function processes the input null-terminated string and converts
     * all uppercase alphabetic characters ('A' to 'Z') to their corresponding
     * lowercase equivalents ('a' to 'z'). Non-alphabetic characters remain
     * unchanged.
     *
     * @param[in] string Pointer to the null-terminated string to be converted.
     * @return char* Pointer to the modified input string.
     *
     * @note The function modifies the string in place.
     */
    char * StrToLower(char * string);

#endif
