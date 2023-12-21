/*
Runtime: 3 ms, 50.17%
Memory Usage: 6.6 MB, 49.70%
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ITERATE FROM START (might as well go from the back)
    int finalWordLength = 0;
    int currentWordLength = 0;
    for (int i = 0; i < strlen(s) + 1; i++){
        if (i == strlen(s)){
            finalWordLength = currentWordLength;
            break;
        }
        if (s[i] == ' '){
            if (i + 1 < strlen(s)){
                if (s[i + 1] != ' '){
                    finalWordLength = currentWordLength;
                    currentWordLength = 0;
                }
            }
        }else{
            currentWordLength++;
        }

    }
    return finalWordLength;
*/

int lengthOfLastWord(char* s) {
    int wordLength = 0;
    int sLen = strlen(s);
    for (int i = sLen-1; i >= 0; i--){
        if (s[i] == ' '){
            // either stop or move on
            if (wordLength == 0){
                continue;
            } else {
                return wordLength;
            }
        } else {
            wordLength++;
        }
    }
    return wordLength;
}

int main(){
    char test[] = "a";
    int result = lengthOfLastWord(test);
    printf("Answer: %d", result);
}

/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
*/