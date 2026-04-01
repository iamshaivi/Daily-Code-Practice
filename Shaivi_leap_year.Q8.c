// Check if the Year is a Leap Year or Not in C

// Method 1: Using if-else (Brute Force)
#include <stdio.h>
int main() {
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    if (year % 400 == 0) {
        printf("%d is a Leap Year\n", year);
    } else if (year % 100 == 0) {
        printf("%d is Not a Leap Year\n", year);
    } else if (year % 4 == 0) {
        printf("%d is a Leap Year\n", year);
    } else {
        printf("%d is Not a Leap Year\n", year);
    }

    return 0;
}
// Method 1 - if-else  A year is leap if divisible by 400. If divisible by 100 but not 400 it is not a leap year. If divisible by 4 but not 100 it is a leap year. Otherwise not a leap year.

// Method 2: Using Nested if
#include <stdio.h>
int main() {
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                printf("%d is a Leap Year\n", year);
            else
                printf("%d is Not a Leap Year\n", year);
        } else {
            printf("%d is a Leap Year\n", year);
        }
    } else {
        printf("%d is Not a Leap Year\n", year);
    }

    return 0;
}
// Method 2 - Nested if  We go step by step. First check divisible by 4. Inside that check divisible by 100. Inside that check divisible by 400. Each condition narrows down the result further.

// Method 3: Using Logical Operators
#include <stdio.h>
int main() {
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    // leap year condition in one line using && and ||
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("%d is a Leap Year\n", year);
    } else {
        printf("%d is Not a Leap Year\n", year);
    }

    return 0;
}
// Method 3 - Logical Operators  We combine all conditions in one line using && and ||. Divisible by 4 but not 100 OR divisible by 400 means leap year. Clean and most commonly used method.

// Method 4: Using Ternary Operator
#include <stdio.h>
int main() {
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    // condition ? "if true" : "if false"
    ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        ? printf("%d is a Leap Year\n", year)
        : printf("%d is Not a Leap Year\n", year);

    return 0;
}
// Method 4 - Ternary Operator  Short form of if-else. We put the full leap year condition before ? then true part then : then false part. All done in one statement. Good for short and clean checks.

// Method 5: Using Function
#include <stdio.h>
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    return 0;
}
int main() {
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    if (isLeapYear(year))
        printf("%d is a Leap Year\n", year);
    else
        printf("%d is Not a Leap Year\n", year);

    return 0;
}
// Method 5 - Function  The leap year logic is placed in a separate function isLeapYear() that returns 1 for leap and 0 for not leap. Main just checks the return value. Clean and reusable code.

// Method 6: Using switch Statement
#include <stdio.h>
int main() {
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    // condition gives 1 if true and 0 if false
    switch ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        case 1:
            printf("%d is a Leap Year\n", year);
            break;
        case 0:
            printf("%d is Not a Leap Year\n", year);
            break;
    }

    return 0;
}
// Method 6 - Switch Case  The leap year condition returns 1 if true and 0 if false. Switch works on these values. Case 1 means leap year and case 0 means not a leap year. Simple and clean.

// Method 7: Using Macro
#include <stdio.h>

// defining leap year condition as a macro
#define IS_LEAP(y) ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))

int main() {
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    if (IS_LEAP(year))
        printf("%d is a Leap Year\n", year);
    else
        printf("%d is Not a Leap Year\n", year);

    return 0;
}
// Method 7 - Macro  We define the leap year condition as a macro IS_LEAP using #define. Wherever we write IS_LEAP(y) it gets replaced by the full condition. Slightly advanced but good to know.
