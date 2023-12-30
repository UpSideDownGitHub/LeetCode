/*
Runtime: 9 ms, 14.12%
Memory Usage: 6.3 MB, 32.95%
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int SumSqaureDidgets(int n)
{
    int squareSum = 0;
    while (n) {
        squareSum += (n % 10) * (n % 10);
        n /= 10;
    }
    return squareSum;
}
 
bool isHappy(int n)
{
    int slow, fast;
    slow = fast = n;
    do {
        slow = SumSqaureDidgets(slow);
        fast = SumSqaureDidgets(SumSqaureDidgets(fast));
    } while (slow != fast);
    return (slow == 1);
}

void test(int num, bool expected) {
    bool result = isHappy(num);

    if (result == expected) {
        printf("PASS");
        printf(": %d\n", result);
    } else {
        printf("FAIL");
        printf(": %d\n", result);
    }
}

int main() {
    test(19, true);
    test(13, true);
    test(2, false);
}

/*
Write an algorithm to determine if a number n is happy.
A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Example 1:
Input: n = 19
Output: true
Explanation:
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

Example 2:
Input: n = 2
Output: false

Constraints:
1 <= n <= 231 - 1
*/