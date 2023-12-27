/*
Runtime: 0 ms, 100%
Memory Usage: 6.5 MB, 37.42%
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *append(const char *orig, char c)
{
    size_t sz = strlen(orig);
    char *str = malloc(sz + 2);
    strcpy(str, orig);
    str[sz] = c;
    str[sz + 1] = '\0';
    return str;
}

bool wordPattern(char* pattern, char* s) {
    int sLen = strlen(s);
    int patternLen = strlen(pattern);
    char* previous[256] = {""};
    for (int i = 0; i < 256; i++){ previous[i] = "";}
    
    int currentSPos = 0;

    for (int i = 0; i < patternLen; i++){
        char* currentWord = "";
        for (int j = currentSPos; j < sLen; j++){
            if (s[j] != ' '){
                currentWord = append(currentWord, s[j]);
                currentSPos++;
            }else{
                currentSPos++;
                break;
            }
        }
        if (i == patternLen - 1){
            if (sLen > currentSPos){ return false; }
        }
        // need to check if there is more words that there is pattern
        //printf("\nPattern: %c, current Word: %s, previous: %s", pattern[i], currentWord, previous[pattern[i]]);
        if (strcmp(previous[pattern[i]], "") != 0 && strcmp(previous[pattern[i]], currentWord) != 0) { return false; }
        for (int j = 0; j < 256; j++){
            //printf("\n=========================\nPrevious[j] => %s \nCurrent => %s\nPattern[i] => %d\nJ => %d", previous[j], currentWord, pattern[i], i);
            if (strcmp(previous[j], currentWord) == 0 && pattern[i] != j){ return false; }
        }
        previous[pattern[i]] = currentWord;
    }
    return true;
}

void test(char* pattern, char* s, bool expected) {
    bool result = wordPattern(pattern, s);

    if (result == expected) {
        printf("PASS");
        printf(": %d\n", result);
    } else {
        printf("FAIL");
        printf(": %d\n", result);
    }
}

int main() {
    test("abba", "dog cat cat dog", true);
    test("abba", "dog cat cat fish", false);
    test("aaaa", "dog cat cat dog", false);
    test("abba", "dog dog dog dog", false);
}

/*
Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

Example 1:
Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Example 2:
Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 

Constraints:
1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
*/