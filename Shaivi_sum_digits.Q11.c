// Sum of Digits of a Number in C

// Method 1: Using while Loop (Brute Force)
#include <stdio.h>
int main() {
    int num, sum = 0, remainder;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num != 0) {
        remainder = num % 10;
        sum = sum + remainder;
        num = num / 10;
    }

    printf("Sum of digits = %d\n", sum);

    return 0;
}
// Method 1 - While Loop  We extract the last digit using %10 and add it to sum. Then remove the last digit using /10. We keep doing this until num becomes 0. Most basic and easy to understand method.

// Method 2: Using for Loop
#include <stdio.h>
int main() {
    int num, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    for (; num != 0; num /= 10)
        sum += num % 10;

    printf("Sum of digits = %d\n", sum);

    return 0;
}
// Method 2 - For Loop  Same logic as method 1 but written as a for loop. No initialization needed so we leave it empty. num /= 10 removes last digit each iteration. Compact and clean way to write it.

// Method 3: Using do-while Loop
#include <stdio.h>
int main() {
    int num, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    do {
        sum += num % 10;
        num /= 10;
    } while (num != 0);

    printf("Sum of digits = %d\n", sum);

    return 0;
}
// Method 3 - do-while Loop  Body executes first then condition is checked. Works the same as while loop here. Completes all 3 loop types for this problem. Good to know do-while for at least one digit numbers.

// Method 4: Using Function
#include <stdio.h>
int digitSum(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Sum of digits = %d\n", digitSum(num));

    return 0;
}
// Method 4 - Function  The digit sum logic is placed in a separate function digitSum() that returns the result. Main just takes input and prints. Clean reusable and well organized code structure.

// Method 5: Using Recursion
#include <stdio.h>
int digitSum(int num) {
    if (num == 0)
        return 0;
    return (num % 10) + digitSum(num / 10);
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Sum of digits = %d\n", digitSum(num));

    return 0;
}
// Method 5 - Recursion  The function extracts the last digit using %10 and adds it to the result of calling itself with num/10. When num becomes 0 it returns 0 and adding stops. Good recursion practice.

// Method 6: Using String
#include <stdio.h>
#include <string.h>
int main() {
    char numStr[20];
    int sum = 0;

    printf("Enter a number: ");
    scanf("%s", numStr);

    for (int i = 0; i < strlen(numStr); i++)
        sum += numStr[i] - '0';

    printf("Sum of digits = %d\n", sum);

    return 0;
}
// Method 6 - String  We take the number as a string. Each character digit can be converted to integer by subtracting '0' from it. We loop through all characters and keep adding. Good for practicing strings in C.

// Method 7: Using Array
#include <stdio.h>
int main() {
    int num, digits[20], count = 0, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num != 0) {
        digits[count++] = num % 10;
        num /= 10;
    }

    for (int i = 0; i < count; i++)
        sum += digits[i];

    printf("Sum of digits = %d\n", sum);

    return 0;
}
// Method 7 - Array  We extract each digit and store it in an array first then add them all in a second loop. Not the most efficient way but good for practicing arrays and digit extraction together.

// Method 8: Using Ternary Operator
#include <stdio.h>
int digitSum(int num) {
    return (num == 0) ? 0 : (num % 10) + digitSum(num / 10);
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Sum of digits = %d\n", digitSum(num));

    return 0;
}
// Method 8 - Ternary Operator  The recursive function is rewritten using ternary operator in a single line. If num is 0 return 0 else extract last digit and recurse. Compact and clean version of method 5.

// Method 9: Using Macro
#include <stdio.h>

int sumHelper(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

#define DIGIT_SUM(n) sumHelper(n)

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Sum of digits = %d\n", DIGIT_SUM(num));

    return 0;
}
// Method 9 - Macro  We define DIGIT_SUM as a macro that calls the helper function. Wherever DIGIT_SUM(n) is written it gets
