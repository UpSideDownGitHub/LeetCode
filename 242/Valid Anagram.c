/*
Runtime: 0 ms, 100%
Memory Usage: 6.9 MB, 9.74%
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    int sLen = strlen(s);
    int tLen = strlen(t);
    
    if (sLen != tLen) { return false; }

    int* used = malloc(sizeof(int) * 26);
    memset(used, false, 26 * sizeof(int)); 

    for (int i = 0; i < sLen; i++){ ++used[s[i] - 'a']; }
    for (int i = 0; i < tLen; i++){ 
        if (used[t[i] - 'a'] == 0)
            return false;
        --used[t[i] - 'a']; 
    }
    return true;
}

void test(char* s, char* t, bool expected) {
    bool result = isIsomorphic(s, test);

    if (result == expected) {
        printf("PASS");
        printf(": %d\n", result);
    } else {
        printf("FAIL");
        printf(": %d\n", result);
    }
}

int main() {
    test("anagram", "nagaram", true);
    test("rat", "car", false);
    test("paper", "title", true);
    test("ab", "aa", false);
}

/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
 
Constraints:
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
*/