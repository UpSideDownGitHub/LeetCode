/*
Runtime: 6 ms, 14.27%
Memory Usage: 6.4 MB, 67.42%
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSubsequence(char* s, char* t) {
    int currentIndex = 0;
    for (int i = 0; i < strlen(t); i++){
        if (t[i] == s[currentIndex]){
            currentIndex++;
        }
    }
    
    if (currentIndex == strlen(s)) { return true; }
    return false;
}

void test(char* s, char* t, bool expected) {
    bool result = isSubsequence(s, t);

    if (result == expected) {
        printf("PASS");
        printf(": %d\n", result);
    } else {
        printf("FAIL");
        printf(": %d\n", result);
    }
}

int main() {
    test("abc", "ahbgdc", true);
    test("axc", "ahbgdc", false);
}

/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) 
of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while 
"aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:
0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
*/