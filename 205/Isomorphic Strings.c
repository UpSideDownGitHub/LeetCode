/*
Runtime: 30 ms, 10%
Memory Usage: 6.9 MB, 8.64%
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isIsomorphic(char* s, char* t) {
    int sLen = strlen(s);
    int tLen = strlen(t);
    if (sLen != tLen)
        return false;
    int sArr[256] = {-1};
    int tArr[256] = {-1};
    for(int i = 0; i < 256; i++){
        sArr[i] = -1;
        tArr[i] = -1;
    }
    printf("\n\n");
    for(int i = 0; i < sLen; i++){
        printf("\nS: %d, T: %d\n Values: %d, %d", sArr[s[i]], tArr[t[i]], s[i], t[i]);
        if(sArr[s[i]] != tArr[t[i]]) { return false; }
        sArr[s[i]] = tArr[t[i]] = i;
        
    }
    return true;
}

void test(char* ransomNote, char* magazine, bool expected) {
    bool result = isIsomorphic(ransomNote, magazine);

    if (result == expected) {
        printf("PASS");
        printf(": %d\n", result);
    } else {
        printf("FAIL");
        printf(": %d\n", result);
    }
}

int main() {
    test("egg", "add", true);
    test("foo", "bar", false);
    test("paper", "title", true);
    test("ab", "aa", false);
}

/*
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true

Constraints:
1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/