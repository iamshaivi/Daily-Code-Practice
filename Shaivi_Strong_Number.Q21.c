// Strong Number Program in C

// Method 1: Using for Loop (Brute Force)
#include <stdio.h>
int main() {
    int num, sum = 0, temp;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    while (temp != 0) {
        int digit = temp % 10;

        // calculate factorial of digit
        int fact = 1;
        for (int i = 1; i <= digit; i++)
            fact *= i;

        sum += fact;
        temp /= 10;
    }

    if (sum == num)
        printf("%d is a Strong Number\n", num);
    else
        printf("%d is Not a Strong Number\n", num);

    return 0;
}
// Method 1 - For Loop  We extract each digit using %10 then calculate its factorial using a for loop. Add all factorials to sum. If sum equals original number it is a Strong number. Example 145 = 1! + 4! + 5! = 145.

// Method 2: Using while Loop
#include <stdio.h>
int main() {
    int num, sum = 0, temp;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    while (temp != 0) {
        int digit = temp % 10;

        // calculate factorial using while loop
        int fact = 1, i = 1;
        while (i <= digit) {
            fact *= i;
            i++;
        }

        sum += fact;
        temp /= 10;
    }

    if (sum == num)
        printf("%d is a Strong Number\n", num);
    else
        printf("%d is Not a Strong Number\n", num);

    return 0;
}
// Method 2 - While Loop  Same logic as method 1 but the factorial calculation uses a while loop instead of for loop. We initialize i before and increment inside. Good practice using while loop for factorial inside a while loop.

// Method 3: Using do-while Loop
#include <stdio.h>
int main() {
    int num, sum = 0, temp;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    do {
        int digit = temp % 10;

        int fact = 1;
        for (int i = 1; i <= digit; i++)
            fact *= i;

        sum += fact;
        temp /= 10;
    } while (temp != 0);

    if (sum == num)
        printf("%d is a Strong Number\n", num);
    else
        printf("%d is Not a Strong Number\n", num);

    return 0;
}
// Method 3 - do-while Loop  Body runs first then condition is checked. Works same as while loop here. Completes all 3 loop types for this problem. Good to practice do-while with digit extraction and factorial logic.

// Method 4: Using Function
#include <stdio.h>
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}
int isStrong(int num) {
    int temp = num, sum = 0;
    while (temp != 0) {
        sum += factorial(temp % 10);
        temp /= 10;
    }
    return sum == num;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isStrong(num))
        printf("%d is a Strong Number\n", num);
    else
        printf("%d is Not a Strong Number\n", num);

    return 0;
}
// Method 4 - Function  Logic is split into two functions. factorial() calculates factorial of a digit and isStrong() checks the condition. Main just takes input and prints. Clean reusable and well organized code structure.

// Method 5: Using Recursion
#include <stdio.h>
int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}
int strongSum(int num) {
    if (num == 0) return 0;
    return factorial(num % 10) + strongSum(num / 10);
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int sum = strongSum(num);

    if (sum == num)
        printf("%d is a Strong Number\n", num);
    else
        printf("%d is Not a Strong Number\n", num);

    return 0;
}
// Method 5 - Recursion  Two recursive functions are used. factorial() calculates digit factorial recursively. strongSum() extracts each digit recursively and adds its factorial. When num becomes 0 it returns 0 and stops.

// Method 6: Using Precomputed Factorial Array
#include <stdio.h>
int main() {
    int num, sum = 0, temp;

    printf("Enter a number: ");
    scanf("%d", &num);

    // precompute factorials of 0 to 9
    int fact[10];
    fact[0] = 1;
    for (int i = 1; i <= 9; i++)
        fact[i] = fact[i - 1] * i;

    temp = num;
    while (temp != 0) {
        sum += fact[temp % 10];
        temp /= 10;
    }

    if (sum == num)
        printf("%d is a Strong Number\n", num);
    else
        printf("%d is Not a Strong Number\n", num);

    return 0;
}
// Method 6 - Precomputed Array  Since digits are only 0 to 9 we precompute all factorials once and store in an array. Then just look up fact[digit] directly instead of recalculating each time. Faster and more efficient method.

// Method 7: Using String
#include <stdio.h>
#include <string.h>
int main() {
    char numStr[20];
    int sum = 0;

    printf("Enter a number: ");
    scanf("%s", numStr);

    int len = strlen(numStr);

    // precompute factorials 0 to 9
    int fact[10];
    fact[0] = 1;
    for (int i = 1; i <= 9; i++)
        fact[i] = fact[i - 1] * i;

    for (int i = 0; i < len; i++)
        sum += fact[numStr[i] - '0'];

    int original = 0;
    for (int i = 0; i < len; i++)
        original = original * 10 + (numStr[i] - '0');

    if (sum == original)
        printf("%s is a Strong Number\n", numStr);
    else
        printf("%s is Not a Strong Number\n", numStr);

    return 0;
}
// Method 7 - String  We take the number as a string. Each character is converted to digit by subtracting '0'. Factorial is looked up from precomputed array. No need to extract digits manually using %10 and /10.

// Method 8: Using Ternary Operator
#include <stdio.h>
int factorial(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) f *= i;
    return f;
}
int strongSum(int n) {
    int s = 0, t = n;
    while (t != 0) { s += factorial(t % 10); t /= 10; }
    return s;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // condition ? true : false
    (strongSum(num) == num)
        ? printf("%d is a Strong Number\n", num)
        : printf("%d is Not a Strong Number\n", num);

    return 0;
}
// Method 8 - Ternary Operator  We call strongSum() inside a ternary condition directly. If sum equals num print yes else print no. All output handled in one clean single statement. Compact version combining functions and ternary.

// Method 9: Using switch Statement
#include <stdio.h>
int factorial(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) f *= i;
    return f;
}
int isStrong(int num) {
    int s = 0, t = num;
    while (t != 0) { s += factorial(t % 10); t /= 10; }
    return s == num;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // isStrong() returns 1 if true and 0 if false
    switch (isStrong(num)) {
        case 1:
            printf("%d is a Strong Number\n", num);
            break;
        case 0:
            printf("%d is Not a Strong Number\n", num);
            break;
    }

    return 0;
}
// Method 9 - Switch Case  isStrong() returns 1 for strong and 0 for not strong. Switch works on these values. Case 1 means strong number and case 0 means not strong number. Good practice combining function with switch.

// Method 10: Print Strong Numbers in a Given Range
#include <stdio.h>
int factorial(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) f *= i;
    return f;
}
int isStrong(int num) {
    int s = 0, t = num;
    while (t != 0) { s += factorial(t % 10); t /= 10; }
    return s == num;
}
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Strong numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++)
        if (isStrong(i))
            printf("%d ", i);
    printf("\n");

    return 0;
}
// Method 10 - Range  We check every number in the given range and print it if it is a strong number. isStrong() is reused cleanly for each number. Known strong numbers are 1 2 145 and 40585 so test with a wide range.

// Method 11: Using Macro
#include <stdio.h>

int factHelper(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) f *= i;
    return f;
}
int strongHelper(int n) {
    int s = 0, t = n;
    while (t != 0) { s += factHelper(t % 10); t /= 10; }
    return s == n;
}

#define IS_STRONG(n) strongHelper(n)

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (IS_STRONG(num))
        printf("%d is a Strong Number\n", num);
    else
        printf("%d is Not a Strong Number\n", num);

    return 0;
}
// Method 11 - Macro  We define IS_STRONG as a macro that calls strongHelper(). Wherever IS_STRONG(n) is written it gets replaced by strongHelper(n). Good to know how macros wrap function calls cleanly in C.

// Method 12: Without using pow() or Extra Library
#include <stdio.h>
int main() {
    int num, sum = 0, temp;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    while (temp != 0) {
        int digit = temp % 10;

        // manually calculate factorial without any library
        int fact = 1;
        int i = 2;
        while (i <= digit) {
            fact *= i;
            i++;
        }

        sum += fact;
        temp /= 10;
    }

    if (sum == num)
        printf("%d is a Strong Number\n", num);
    else
        printf("%d is Not a Strong Number\n", num);

    return 0;
}
// Method 12 - No Library  We calculate factorial manually starting from i=2 since multiplying by 1 changes nothing. No math.h or any other library is needed at all. Clean standalone solution using only stdio.h for input and output.
