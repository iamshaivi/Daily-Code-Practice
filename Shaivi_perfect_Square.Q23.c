// Program to Check for Perfect Square in C

// Method 1: Using sqrt() Function (Brute Force)
#include <stdio.h>
#include <math.h>
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("%d is Not a Perfect Square\n", num);
    } else {
        int root = (int)sqrt(num);
        if (root * root == num)
            printf("%d is a Perfect Square\n", num);
        else
            printf("%d is Not a Perfect Square\n", num);
    }

    return 0;
}
// Method 1 - sqrt()  We take the square root of num and cast it to int to remove decimal. Then multiply root by itself and compare with original num. If equal it is a perfect square. Negative numbers are handled separately.

// Method 2: Using for Loop (Brute Force)
#include <stdio.h>
int main() {
    int num, isPerfectSq = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("%d is Not a Perfect Square\n", num);
    } else {
        for (int i = 0; i * i <= num; i++) {
            if (i * i == num) {
                isPerfectSq = 1;
                break;
            }
        }

        if (isPerfectSq)
            printf("%d is a Perfect Square\n", num);
        else
            printf("%d is Not a Perfect Square\n", num);
    }

    return 0;
}
// Method 2 - For Loop  We check every number i starting from 0. If i*i equals num we found the square root and it is a perfect square. We stop as soon as i*i exceeds num. No math library needed at all.

// Method 3: Using while Loop
#include <stdio.h>
int main() {
    int num, i = 0, isPerfectSq = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("%d is Not a Perfect Square\n", num);
    } else {
        while (i * i <= num) {
            if (i * i == num) {
                isPerfectSq = 1;
                break;
            }
            i++;
        }

        if (isPerfectSq)
            printf("%d is a Perfect Square\n", num);
        else
            printf("%d is Not a Perfect Square\n", num);
    }

    return 0;
}
// Method 3 - While Loop  Same logic as method 2 but using a while loop. We initialize i before the loop and increment it inside. Good practice to write the same perfect square logic using different loop types.

// Method 4: Using do-while Loop
#include <stdio.h>
int main() {
    int num, i = 0, isPerfectSq = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("%d is Not a Perfect Square\n", num);
    } else if (num == 0) {
        printf("0 is a Perfect Square\n");
    } else {
        do {
            if (i * i == num) {
                isPerfectSq = 1;
                break;
            }
            i++;
        } while (i * i <= num);

        if (isPerfectSq)
            printf("%d is a Perfect Square\n", num);
        else
            printf("%d is Not a Perfect Square\n", num);
    }

    return 0;
}
// Method 3 - do-while Loop  Body runs first then condition is checked. We handle 0 separately since do-while always runs once. Completes all 3 loop types for this problem. Good to practice do-while with math checks.

// Method 5: Using Function
#include <stdio.h>
#include <math.h>
int isPerfectSquare(int num) {
    if (num < 0) return 0;
    int root = (int)sqrt(num);
    return root * root == num;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPerfectSquare(num))
        printf("%d is a Perfect Square\n", num);
    else
        printf("%d is Not a Perfect Square\n", num);

    return 0;
}
// Method 5 - Function  The perfect square logic is placed in a separate function isPerfectSquare() that returns 1 if true and 0 if false. Main just takes input and prints. Clean reusable and well organized code structure.

// Method 6: Using Recursion
#include <stdio.h>
int checkSquare(int num, int i) {
    if (i * i > num) return 0;
    if (i * i == num) return 1;
    return checkSquare(num, i + 1);
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0)
        printf("%d is Not a Perfect Square\n", num);
    else if (checkSquare(num, 0))
        printf("%d is a Perfect Square\n", num);
    else
        printf("%d is Not a Perfect Square\n", num);

    return 0;
}
// Method 6 - Recursion  The function checks if i*i equals num. If i*i exceeds num it returns 0. If equal it returns 1. Otherwise it calls itself with i+1. Good practice for understanding how recursion replaces a loop.

// Method 7: Using Binary Search
#include <stdio.h>
int isPerfectSquare(int num) {
    if (num < 0) return 0;
    if (num == 0 || num == 1) return 1;

    int low = 1, high = num / 2, mid;

    while (low <= high) {
        mid = low + (high - low) / 2;
        long long sq = (long long)mid * mid;

        if (sq == num) return 1;
        else if (sq < num) low = mid + 1;
        else high = mid - 1;
    }
    return 0;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPerfectSquare(num))
        printf("%d is a Perfect Square\n", num);
    else
        printf("%d is Not a Perfect Square\n", num);

    return 0;
}
// Method 7 - Binary Search  Instead of checking every number we binary search between 1 and num/2. Each step we check mid*mid against num and halve the search space. Much faster than brute force for large numbers.

// Method 8: Using Bitwise Operator
#include <stdio.h>
int isPerfectSquare(int num) {
    if (num < 0) return 0;
    if (num == 0) return 1;

    int x = num;
    int root = 0;

    // find square root using bitwise method
    for (int bit = 1 << 15; bit > 0; bit >>= 1) {
        root |= bit;
        if (root * root > x)
            root ^= bit;
    }
    return root * root == num;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPerfectSquare(num))
        printf("%d is a Perfect Square\n", num);
    else
        printf("%d is Not a Perfect Square\n", num);

    return 0;
}
// Method 8 - Bitwise  We build the square root bit by bit from the most significant bit down. We set each bit and check if root*root exceeds num. If it does we unset it. Advanced low level technique good to know exists.

// Method 9: Using Newton Raphson Method
#include <stdio.h>
int isPerfectSquare(int num) {
    if (num < 0) return 0;
    if (num == 0) return 1;

    double x = num;

    // iterate until result converges
    while (1) {
        double root = (x + num / x) / 2.0;
        if (root >= x) break;
        x = root;
    }

    int r = (int)x;
    return r * r == num;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPerfectSquare(num))
        printf("%d is a Perfect Square\n", num);
    else
        printf("%d is Not a Perfect Square\n", num);

    return 0;
}
// Method 9 - Newton Raphson  We use the Newton Raphson iterative formula to converge on the square root. Each iteration improves the estimate. When it stops improving we check if the integer root squared equals num.

// Method 10: Using Ternary Operator
#include <stdio.h>
#include <math.h>
int isPerfectSquare(int num) {
    if (num < 0) return 0;
    int r = (int)sqrt(num);
    return r * r == num;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // condition ? true : false
    isPerfectSquare(num)
        ? printf("%d is a Perfect Square\n", num)
        : printf("%d is Not a Perfect Square\n", num);

    return 0;
}
// Method 10 - Ternary Operator  We call isPerfectSquare() inside a ternary condition directly. If it returns 1 print yes else print no. All output handled in one clean single statement. Compact version combining function and ternary.

// Method 11: Using switch Statement
#include <stdio.h>
#include <math.h>
int isPerfectSquare(int num) {
    if (num < 0) return 0;
    int r = (int)sqrt(num);
    return r * r == num;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // isPerfectSquare() returns 1 if true and 0 if false
    switch (isPerfectSquare(num)) {
        case 1:
            printf("%d is a Perfect Square\n", num);
            break;
        case 0:
            printf("%d is Not a Perfect Square\n", num);
            break;
    }

    return 0;
}
// Method 11 - Switch Case  isPerfectSquare() returns 1 for perfect square and 0 for not. Switch works on these values. Case 1 means perfect square and case 0 means not. Good practice combining function with switch.

// Method 12: Print Perfect Squares in a Given Range
#include <stdio.h>
#include <math.h>
int isPerfectSquare(int num) {
    if (num < 0) return 0;
    int r = (int)sqrt(num);
    return r * r == num;
}
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Perfect squares between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++)
        if (isPerfectSquare(i))
            printf("%d ", i);
    printf("\n");

    return 0;
}
// Method 12 - Range  We check every number in the given range and print it if it is a perfect square. isPerfectSquare() is reused cleanly for each number. Good practice combining range loops with a reusable function.

// Method 13: Using Macro
#include <stdio.h>
#include <math.h>

int sqHelper(int n) {
    if (n < 0) return 0;
    int r = (int)sqrt(n);
    return r * r == n;
}

#define IS_PERFECT_SQUARE(n) sqHelper(n)

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (IS_PERFECT_SQUARE(num))
        printf("%d is a Perfect Square\n", num);
    else
        printf("%d is Not a Perfect Square\n", num);

    return 0;
}
// Method 13 - Macro  We define IS_PERFECT_SQUARE as a macro that calls sqHelper(). Wherever IS_PERFECT_SQUARE(n) is written it gets replaced by sqHelper(n). Good to know how macros wrap function calls cleanly in C.

// Method 14: Using Odd Number Subtraction Property
#include <stdio.h>
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("%d is Not a Perfect Square\n", num);
    } else {
        int temp = num, odd = 1;

        // every perfect square is sum of consecutive odd numbers
        // 1=1 4=1+3 9=1+3+5 16=1+3+5+7
        while (temp > 0) {
            temp -= odd;
            odd += 2;
        }

        if (temp == 0)
            printf("%d is a Perfect Square\n", num);
        else
            printf("%d is Not a Perfect Square\n", num);
    }

    return 0;
}
// Method 14 - Odd Subtraction  Every perfect square is the sum of consecutive odd numbers starting from 1. So we subtract 1 3 5 7 and so on from num. If we reach exactly 0 it is a perfect square. Unique math property approach.
