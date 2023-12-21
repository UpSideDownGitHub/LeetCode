/*
Runtime: 4 ms, 46.67%
Memory Usage: 6.6 MB, 48.96%
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int count = 0;
    char buffer[255];

    if (strsSize == 0)
        return "";

    for (int i = 0; i < 255; i++){
        for (int j = 0; j < strsSize; j++){
            if (strs[j][i] == NULL || (j > 0 && strs[j-1][i] != strs[j][i])){
                buffer[count] = '\0';
                char *result = (char *) malloc(sizeof(char) * (count + 1));
                strcpy(result, buffer);
                return result;
            }
        }
        buffer[count++] = strs[0][i];
    }
    buffer[count] = '\0';
    char *result = (char *) malloc(sizeof(char) * (count + 1));
    strcpy(result, buffer);
    return result;
}

void test(char** strs, int strsSize, char* expected) {
    char* result = longestCommonPrefix(strs, strsSize);

    if (strcmp(result, expected) == 0) {
        printf("PASS");
        printf(": %s\n", result);
    } else {
        printf("FAIL");
        printf(": %s\n", result);
    }

    free(result);  // Don't forget to free the memory allocated by longestCommonPrefix
}

int main() {
    // Test Cases
    test((char*[]){"apple", "apricot", "appetizer"}, 3, "ap");
    test((char*[]){NULL}, 0, "");
    test((char*[]){"apple", "", "appetizer"}, 3, "");
    return 0;
}

/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/