/*
Runtime: 0 ms, 100%
Memory Usage: 6.7 MB, 14.64%
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int strStr(char* haystack, char* needle) {
    for (int i = 0; i < strlen(haystack); i++){
        int foundCount = 0;
        //printf(" Comparing %c - %c ", haystack[i], needle[0]);
        if (haystack[i] == needle[0]){
            //printf("\nStarting Value Same: I -> %d", i);
            foundCount++;
            // loop through needle and check for next letters
            for (int j = 1; j < strlen(needle); j++){
                if (haystack[i + j] != needle[j]){
                    break;
                }
                foundCount++;
            }
        }
        printf("\nFinal step: found => %d length => %d", foundCount, strlen(needle));
        if (foundCount == strlen(needle)){
            return i;
        }
    }
    return -1;
}

void test(char* haystack, char* needle, int expected) {
    int result = strStr(haystack, needle);

    if (result == expected) {
        printf("PASS");
        printf(": %d\n", result);
    } else {
        printf("FAIL");
        printf(": %d\n", result);
    }
}

int main() {
    //test("sadbutsad", "sad", 0);
    //test("leetcode", "leeto", -1);
    //test("thereisamannamedman", "man", 8);
    test("mississippi", "issip", 4);
}

/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints:
1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/