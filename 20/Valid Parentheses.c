/*
Runtime: 0ms, 100%
Memory Usage: 2.44, 82.01%
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int push(char *, char, int);
char pop(char *, int);
bool isValid(char * s)
{
    int i=0,top=-1;
    char pstack[5000],op;
    while(*(s+i)!='\0')
    {
        if(*(s+i)=='{')
        {
            top=push(pstack,*(s+i),top);
            if(top>4999)
                return 0;
        }
        else if(*(s+i)=='[')
        {
            top=push(pstack,*(s+i),top);
            if(top>4999)
                return 0;
        }
        else if(*(s+i)=='(')
        {
            top=push(pstack,*(s+i),top);
            if(top>4999)
                return 0;
        }
        
        else
        {
            if(top>-1)
            {
                op=pop(pstack,top);
                top--;
                switch(op)
                {
                    case '{':
                        if(*(s+i)!='}')
                            return 0;
                        break;
                    case '[':
                        if(*(s+i)!=']')
                            return 0;
                        break;
                    case '(':
                        if(*(s+i)!=')')
                            return 0;
                        break;
                }
            }
            else
                return 0;
        }
        i++;
    }
    if(top!=-1)
        return 0;
    return 1;
}

int push(char *pstack, char para, int top)
{
    *(pstack+top+1)=para;
    top++;
    return top;
}

char pop(char *pstack, int top)
{
    return *(pstack+top);
}

void test(char* nums, bool expected) {
    bool result = isValid(nums);

    if (result == expected) {
        printf("PASS");
        printf(": %d\n", result);
    } else {
        printf("FAIL");
        printf(": %d\n", result);
    }
}

int main() {
    test("()", true);
    test("()[]{}", true);
    test("(]", false);
    test("([]){", false);
    test("(){}}{", false);
}

/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 
Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/