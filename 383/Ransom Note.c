/*
Runtime: 218 ms, 7%
Memory Usage: 7.4 MB, 38.26%
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canConstruct(char* ransomNote, char* magazine) {
    bool* set = malloc(sizeof(char) * strlen(ransomNote));
    for (int i = 0; i < strlen(ransomNote); i++)
    {
        set[i] = false;
    }
    
    int currentIndex = 0;
    for (int i = 0; i < strlen(magazine); i++){
        for (int j = 0; j < strlen(ransomNote); j++){
            if (magazine[i] == ransomNote[j] && set[j] == false){
                currentIndex++;
                set[j] = true;
                break;
            }
        }
        if (currentIndex == strlen(ransomNote)) { return true; }
    }
    if (currentIndex == strlen(ransomNote)) { return true; }
    return false;
}

void test(char* ransomNote, char* magazine, bool expected) {
    bool result = canConstruct(ransomNote, magazine);

    if (result == expected) {
        printf("PASS");
        printf(": %d\n", result);
    } else {
        printf("FAIL");
        printf(": %d\n", result);
    }
}

int main() {
    test("a", "b", false);
    test("aa", "ab", false);
    test("aa", "aab", true);
}

/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and 
false otherwise.

Each letter in magazine can only be used once in ransomNote.

Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:
Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true
 
Constraints:
1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.
*/