// Find the Greatest of the Three Numbers in C

// Method 1: Using if-else (Brute Force)
#include <stdio.h>
int main() {
    int a, b, c;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("Enter third number: ");
    scanf("%d", &c);

    if (a >= b && a >= c) {
        printf("%d is the Greatest\n", a);
    } else if (b >= a && b >= c) {
        printf("%d is the Greatest\n", b);
    } else {
        printf("%d is the Greatest\n", c);
    }

    return 0;
}
// Method 1 - if-else  We check each number against the other two using && operator. If a is greater than both print a. If b is greater than both print b. Otherwise c is the greatest.

// Method 2: Using Nested if
#include <stdio.h>
int main() {
    int a, b, c;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("Enter third number: ");
    scanf("%d", &c);

    if (a > b) {
        if (a > c)
            printf("%d is the Greatest\n", a);
        else
            printf("%d is the Greatest\n", c);
    } else {
        if (b > c)
            printf("%d is the Greatest\n", b);
        else
            printf("%d is the Greatest\n", c);
    }

    return 0;
}
// Method 2 - Nested if  We first compare a and b. Then inside each branch we compare the winner with c. This is nesting one if inside another. Good for understanding step by step comparison logic.

// Method 3: Using Ternary Operator
#include <stdio.h>
int main() {
    int a, b, c, greatest;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("Enter third number: ");
    scanf("%d", &c);

    // first find greater of a and b then compare with c
    greatest = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);

    printf("%d is the Greatest\n", greatest);

    return 0;
}
// Method 3 - Ternary Operator  We nest two ternary operators. First compare a and b then compare the bigger one with c. All done in a single line. Good for short comparisons once basics are clear.

// Method 4: Using Function
#include <stdio.h>
void findGreatest(int a, int b, int c) {
    if (a >= b && a >= c)
        printf("%d is the Greatest\n", a);
    else if (b >= a && b >= c)
        printf("%d is the Greatest\n", b);
    else
        printf("%d is the Greatest\n", c);
}
int main() {
    int a, b, c;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("Enter third number: ");
    scanf("%d", &c);

    findGreatest(a, b, c);

    return 0;
}
// Method 4 - Function  The comparison logic is placed in a separate function findGreatest() that takes all three numbers. Main just handles input and output. Clean reusable and well organized code.

// Method 5: Using Temp Variable
#include <stdio.h>
int main() {
    int a, b, c, greatest;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("Enter third number: ");
    scanf("%d", &c);

    // first assume a is greatest
    greatest = a;

    if (b > greatest)
        greatest = b;
    if (c > greatest)
        greatest = c;

    printf("%d is the Greatest\n", greatest);

    return 0;
}
// Method 5 - Temp Variable  We assume a is the greatest first. Then compare b and c one by one with greatest and update if bigger. Simple and clean approach. Very easy to extend for more numbers.

// Method 6: Using switch Statement
#include <stdio.h>
int main() {
    int a, b, c;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("Enter third number: ");
    scanf("%d", &c);

    // (a >= b && a >= c) gives 1 if true and 0 if false
    switch (a >= b && a >= c) {
        case 1:
            printf("%d is the Greatest\n", a);
            break;
        case 0:
            if (b >= c)
                printf("%d is the Greatest\n", b);
            else
                printf("%d is the Greatest\n", c);
            break;
    }

    return 0;
}
// Method 6 - Switch Case  The condition a >= b && a >= c returns 1 if true and 0 if false. Case 1 means a is greatest. In case 0 we compare b and c to find the greater one between them.

// Method 7: Using Bitwise Operator
#include <stdio.h>
int main() {
    int a, b, c;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("Enter third number: ");
    scanf("%d", &c);

    // right shift by 31 checks the sign bit
    // if sign bit is 1 the number is negative
    int greatest = a;

    if ((b - greatest) >> 31 == 0 && b != greatest)
        greatest = b;
    if ((c - greatest) >> 31 == 0 && c != greatest)
        greatest = c;

    printf("%d is the Greatest\n", greatest);

    return 0;
}
// Method 7 - Bitwise  We check the sign bit of the difference using >> 31. If the result is 0 the difference is positive meaning the new number is greater. Slightly advanced topic learn after basics are done.
