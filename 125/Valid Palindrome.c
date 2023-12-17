/*
Runtime: 102ms 6.38%
Memory Usage: 7.22MB 23.01%
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char* s) {
    if (s == NULL) {
        return true;
    }

    int len = strlen(s);
    char *result = (char *)malloc(len + 1);

    int j = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (isalnum(s[i]) != 0) {
            result[j++] = tolower(s[i]);
        }
    }
    result[j] = '\0';
    strcpy(s, result);
    free(result);

    printf("\n String: ");
    printf("%s", s);

    // need to loop through the string and find out if it is a palidrome  
    int k =  strlen(s) - 1;
    printf("\n Values:");
    for (int i = 0; s[i] != '\0' && i <= strlen(s) / 2; i++)
    {
        printf(" %di:", i);
        printf("%c ", s[i]);
        printf("%dk:", k);
        printf("%c", s[k]);
        if (s[i] == s[k]) { 
            k--;
            continue; 
        }
        else { return false; }
        
    }
    return true;
}

/*
"Hello, @World123!"
"H e llol l eH"

*/

int main(){
    const char input[] = "";
    bool result = isPalindrome(input);
    if (result){
        printf("\nIs Palindrome");
    }else{
        printf("\nNot Palindrome");
    }
}