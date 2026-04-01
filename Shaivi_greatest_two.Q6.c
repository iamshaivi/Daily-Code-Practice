// Find the Greatest of the Two Numbers in C

// Method 1: Using if-else (Brute Force)
#include <stdio.h>
int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    if (a > b) {
        printf("%d is the Greatest\n", a);
    } else if (b > a) {
        printf("%d is the Greatest\n", b);
    } else {
        printf("Both numbers are Equal\n");
    }

    return 0;
}
// Method 1 - if-else  We compare a and b using simple conditions. If a is greater print a. If b is greater print b. If neither is greater then both are equal. Most basic and clear method.

// Method 2: Using Nested if
#include <stdio.h>
int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    if (a >= b) {
        if (a == b)
            printf("Both numbers are Equal\n");
        else
            printf("%d is the Greatest\n", a);
    } else {
        printf("%d is the Greatest\n", b);
    }

    return 0;
}
// Method 2 - Nested if  We first check if a is greater or equal to b. Inside that we check if they are equal. This is called nesting one if inside another. Good for understanding nested logic.

// Method 3: Using Ternary Operator
#include <stdio.h>
int main() {
    int a, b, greatest;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    // condition ? value if true : value if false
    greatest = (a > b) ? a : b;

    if (a == b)
        printf("Both numbers are Equal\n");
    else
        printf("%d is the Greatest\n", greatest);

    return 0;
}
// Method 3 - Ternary Operator  Short form of if-else. We write condition then ? then true value then : then false value. Result is stored in greatest. Good for short and simple comparisons.

// Method 4: Using Function
#include <stdio.h>
void findGreatest(int a, int b) {
    if (a > b)
        printf("%d is the Greatest\n", a);
    else if (b > a)
        printf("%d is the Greatest\n", b);
    else
        printf("Both numbers are Equal\n");
}
int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    findGreatest(a, b);

    return 0;
}
// Method 4 - Function  The comparison logic is written in a separate function findGreatest() and just called from main. This keeps code clean and reusable. A good habit for organized programs.

// Method 5: Using Subtraction
#include <stdio.h>
int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    // if a - b is positive then a is greater
    // if a - b is negative then b is greater
    int diff = a - b;

    if (diff > 0)
        printf("%d is the Greatest\n", a);
    else if (diff < 0)
        printf("%d is the Greatest\n", b);
    else
        printf("Both numbers are Equal\n");

    return 0;
}
// Method 5 - Subtraction  We subtract b from a. If the result is positive a is greater. If negative b is greater. If zero both are equal. A different way to compare without using > or < directly.

// Method 6: Using switch Statement
#include <stdio.h>
int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    // (a > b) gives 1 if true and 0 if false
    switch (a > b) {
        case 1:
            printf("%d is the Greatest\n", a);
            break;
        case 0:
            if (a == b)
                printf("Both numbers are Equal\n");
            else
                printf("%d is the Greatest\n", b);
            break;
    }

    return 0;
}
// Method 6 - Switch Case  A condition like a > b returns 1 if true and 0 if false. Switch works on these values. Case 1 means a is greater and case 0 handles b greater or equal case.

// Method 7: Using Bitwise Operator
#include <stdio.h>
int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    // right shift by 31 checks the sign bit of the difference
    int diff = a - b;

    if (diff == 0)
        printf("Both numbers are Equal\n");
    else if (diff >> 31)
        printf("%d is the Greatest\n", b);
    else
        printf("%d is the Greatest\n", a);

    return 0;
}
// Method 7 - Bitwise  We subtract b from a and check the sign bit using >> 31. If sign bit is 1 the difference is negative meaning b is greater. Slightly advanced. Learn it after basics are clear.
