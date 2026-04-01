// C Program to Print Power of a Number

// Method 1: Using for Loop (Brute Force)
#include <stdio.h>
int main() {
    int base, exp;
    long long result = 1;

    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exp);

    for (int i = 1; i <= exp; i++)
        result *= base;

    printf("%d ^ %d = %lld\n", base, exp, result);

    return 0;
}
// Method 1 - For Loop  We multiply result by base exp times. We start result at 1 and keep multiplying. long long is used to handle large values. Most basic and easy to understand way to calculate power.

// Method 2: Using while Loop
#include <stdio.h>
int main() {
    int base, exp;
    long long result = 1;
    int i = 1;

    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exp);

    while (i <= exp) {
        result *= base;
        i++;
    }

    printf("%d ^ %d = %lld\n", base, exp, result);

    return 0;
}
// Method 2 - While Loop  Same logic as method 1 but using a while loop. We initialize i before the loop and increment it inside. Good practice to write the same power logic using different loop types.

// Method 3: Using do-while Loop
#include <stdio.h>
int main() {
    int base, exp;
    long long result = 1;
    int i = 1;

    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exp);

    if (exp == 0) {
        printf("%d ^ %d = 1\n", base, exp);
    } else {
        do {
            result *= base;
            i++;
        } while (i <= exp);
        printf("%d ^ %d = %lld\n", base, exp, result);
    }

    return 0;
}
// Method 3 - do-while Loop  Body runs first then condition is checked. We handle exp=0 separately since any number to power 0 is 1. Completes all 3 loop types for this problem. Good to know edge cases.

// Method 4: Using pow() Function
#include <stdio.h>
#include <math.h>
int main() {
    int base, exp;

    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exp);

    long long result = (long long)pow(base, exp);

    printf("%d ^ %d = %lld\n", base, exp, result);

    return 0;
}
// Method 4 - pow() Function  The math.h library provides a built in pow() function that takes base and exponent and returns the result. We cast it to long long to avoid floating point display. Simplest one liner method.

// Method 5: Using Function
#include <stdio.h>
long long power(int base, int exp) {
    long long result = 1;
    for (int i = 1; i <= exp; i++)
        result *= base;
    return result;
}
int main() {
    int base, exp;

    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exp);

    printf("%d ^ %d = %lld\n", base, exp, power(base, exp));

    return 0;
}
// Method 5 - Function  The power logic is placed in a separate function power() that takes base and exp and returns the result. Main just handles input and output. Clean reusable and well organized code.

// Method 6: Using Recursion
#include <stdio.h>
long long power(int base, int exp) {
    if (exp == 0) return 1;
    return base * power(base, exp - 1);
}
int main() {
    int base, exp;

    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exp);

    printf("%d ^ %d = %lld\n", base, exp, power(base, exp));

    return 0;
}
// Method 6 - Recursion  The function multiplies base with the result of calling itself with exp-1. When exp reaches 0 it returns 1 which is the base case. Good practice for understanding recursive multiplication.

// Method 7: Using Fast Power (Binary Exponentiation)
#include <stdio.h>
long long fastPower(int base, int exp) {
    long long result = 1;
    long long b = base;

    while (exp > 0) {
        // if exp is odd multiply result by base
        if (exp % 2 == 1)
            result *= b;
        b *= b;
        exp /= 2;
    }
    return result;
}
int main() {
    int base, exp;

    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exp);

    printf("%d ^ %d = %lld\n", base, exp, fastPower(base, exp));

    return 0;
}
// Method 7 - Binary Exponentiation  Instead of multiplying exp times we halve the exponent each step. If exp is odd we multiply result by base. This reduces the number of multiplications from n to log(n). Very fast method.

// Method 8: Using Recursive Fast Power
#include <stdio.h>
long long fastPower(int base, int exp) {
    if (exp == 0) return 1;
    if (exp % 2 == 0) {
        long long half = fastPower(base, exp / 2);
        return half * half;
    }
    return base * fastPower(base, exp - 1);
}
int main() {
    int base, exp;

    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exp);

    printf("%d ^ %d = %lld\n", base, exp, fastPower(base, exp));

    return 0;
}
// Method 8 - Recursive Fast Power  If exp is even we calculate half power and square it. If odd we multiply base once and reduce exp by 1. This is the recursive version of binary exponentiation. Very efficient method.

// Method 9: Using Ternary Operator
#include <stdio.h>
long long power(int base, int exp) {
    return (exp == 0) ? 1 : base * power(base, exp - 1);
}
int main() {
    int base, exp;

    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exp);

    printf("%d ^ %d = %lld\n", base, exp, power(base, exp));

    return 0;
}
// Method 9 - Ternary Operator  The entire recursive function is written in a single line using ternary. If exp is 0 return 1 else multiply base with recursive call. Compact and clean version of method 6.

// Method 10: Handling Negative Exponents
#include <stdio.h>
#include <math.h>
int main() {
    int base, exp;

    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exp);

    if (exp < 0) {
        // negative exponent means 1 / base^|exp|
        double result = 1.0 / pow(base, -exp);
        printf("%d ^ %d = %lf\n", base, exp, result);
    } else {
        long long result = (long long)pow(base, exp);
        printf("%d ^ %d = %lld\n", base, exp, result);
    }

    return 0;
}
// Method 10 - Negative Exponents  Normal methods only work for positive exponents. For negative exponents the result is 1 divided by base raised to the absolute value of exp. We use double to show the decimal result.

// Method 11: Print All Powers from 1 to N
#include <stdio.h>
int main() {
    int base, n;

    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter value of N: ");
    scanf("%d", &n);

    long long result = 1;

    printf("Powers of %d from 1 to %d:\n", base, n);
    for (int i = 1; i <= n; i++) {
        result *= base;
        printf("%d ^ %d = %lld\n", base, i, result);
    }

    return 0;
}
// Method 11 - All Powers 1 to N  Instead of finding just one power we print all powers from 1 to n. We keep multiplying result by base and print each step. Useful for seeing the full growth of a power series.

// Method 12: Using Macro
#include <stdio.h>
#include <math.h>

#define POWER(b, e) ((long long)pow(b, e))

int main() {
    int base, exp;

    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exp);

    printf("%d ^ %d = %lld\n", base, exp, POWER(base, exp));

    return 0;
}
// Method 12 - Macro  We define POWER as a macro that wraps the pow() function with a cast to long long. Wherever POWER(b,e) is written it gets replaced by the full expression. Good to know how macros simplify repeated expressions.

// Method 13: Using Bitwise Operator
#include <stdio.h>
long long power(int base, int exp) {
    long long result = 1;
    long long b = base;

    while (exp > 0) {
        // check if last bit is 1 using & operator
        if (exp & 1)
            result *= b;
        b *= b;
        // right shift to remove last bit
        exp >>= 1;
    }
    return result;
}
int main() {
    int base, exp;

    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exp);

    printf("%d ^ %d = %lld\n", base, exp, power(base, exp));

    return 0;
}
// Method 13 - Bitwise  Same as binary exponentiation but we use bitwise & to check if exp is odd and >>= to halve it. exp & 1 checks the last bit. exp >>= 1 removes the last bit. Faster and more low level version.
