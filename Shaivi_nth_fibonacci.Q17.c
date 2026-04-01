// Finding Nth Term of a Fibonacci Series in C

// Method 1: Using for Loop (Brute Force)
#include <stdio.h>
int main() {
    int n;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    int a = 0, b = 1;

    if (n == 1) {
        printf("Nth term of Fibonacci = 0\n");
    } else if (n == 2) {
        printf("Nth term of Fibonacci = 1\n");
    } else {
        for (int i = 3; i <= n; i++) {
            int next = a + b;
            a = b;
            b = next;
        }
        printf("Nth term of Fibonacci = %d\n", b);
    }

    return 0;
}
// Method 1 - For Loop  We handle first two terms as special cases. For n greater than 2 we run the loop from 3 to n shifting a and b forward each time. When loop ends b holds the nth fibonacci term.

// Method 2: Using while Loop
#include <stdio.h>
int main() {
    int n;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    int a = 0, b = 1, i = 3;

    if (n == 1) {
        printf("Nth term of Fibonacci = 0\n");
    } else if (n == 2) {
        printf("Nth term of Fibonacci = 1\n");
    } else {
        while (i <= n) {
            int next = a + b;
            a = b;
            b = next;
            i++;
        }
        printf("Nth term of Fibonacci = %d\n", b);
    }

    return 0;
}
// Method 2 - While Loop  Same logic as method 1 but using a while loop. We initialize i as 3 before the loop and increment inside. Good practice to write the same solution using different loop types.

// Method 3: Using do-while Loop
#include <stdio.h>
int main() {
    int n;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    int a = 0, b = 1, i = 3;

    if (n == 1) {
        printf("Nth term of Fibonacci = 0\n");
    } else if (n == 2) {
        printf("Nth term of Fibonacci = 1\n");
    } else {
        do {
            int next = a + b;
            a = b;
            b = next;
            i++;
        } while (i <= n);
        printf("Nth term of Fibonacci = %d\n", b);
    }

    return 0;
}
// Method 3 - do-while Loop  Body runs first then condition is checked. Works same as while loop here. Completes all 3 loop types for this problem. Special cases for n=1 and n=2 are still handled separately.

// Method 4: Using Function
#include <stdio.h>
int getNthFibonacci(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    int a = 0, b = 1;
    for (int i = 3; i <= n; i++) {
        int next = a + b;
        a = b;
        b = next;
    }
    return b;
}
int main() {
    int n;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    printf("Nth term of Fibonacci = %d\n", getNthFibonacci(n));

    return 0;
}
// Method 4 - Function  The logic is placed in a separate function getNthFibonacci() that returns the result directly. Main just takes input and prints. Clean reusable and well organized code structure.

// Method 5: Using Recursion
#include <stdio.h>
int fibonacci(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
    int n;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    printf("Nth term of Fibonacci = %d\n", fibonacci(n));

    return 0;
}
// Method 5 - Recursion  fibonacci(n) calls itself with n-1 and n-2 and adds results. Base cases are n=1 returns 0 and n=2 returns 1. Easy to understand but slow for large n due to repeated calculations.

// Method 6: Using Memoization (Top Down DP)
#include <stdio.h>
#define MAX 1000

int memo[MAX];

int fibonacci(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}
int main() {
    int n;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    for (int i = 0; i < MAX; i++)
        memo[i] = -1;

    printf("Nth term of Fibonacci = %d\n", fibonacci(n));

    return 0;
}
// Method 6 - Memoization  Same as recursion but already computed values are stored in memo array. If value is already calculated we return it directly instead of recalculating. Much faster than plain recursion.

// Method 7: Using Array (Bottom Up DP)
#include <stdio.h>
int main() {
    int n;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    int fib[n + 1];
    fib[1] = 0;
    fib[2] = 1;

    for (int i = 3; i <= n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    printf("Nth term of Fibonacci = %d\n", fib[n]);

    return 0;
}
// Method 7 - Bottom Up DP  We fill the array from index 1 to n. Each value is sum of two before it. No recursion needed at all. We directly access fib[n] at the end. Efficient and easy to understand approach.

// Method 8: Using Tail Recursion
#include <stdio.h>
int fibTail(int n, int a, int b) {
    if (n == 1) return a;
    if (n == 2) return b;
    return fibTail(n - 1, b, a + b);
}
int main() {
    int n;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    printf("Nth term of Fibonacci = %d\n", fibTail(n, 0, 1));

    return 0;
}
// Method 8 - Tail Recursion  We pass current and next fibonacci values as arguments. Each call reduces n by 1 and shifts values forward. When n reaches 1 we return a directly. More efficient than normal recursion.

// Method 9: Using Ternary Operator
#include <stdio.h>
int fibonacci(int n) {
    return (n == 1) ? 0 : (n == 2) ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
    int n;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    printf("Nth term of Fibonacci = %d\n", fibonacci(n));

    return 0;
}
// Method 9 - Ternary Operator  The entire recursive function is written in a single line using nested ternary operators. If n=1 return 0 if n=2 return 1 else recurse. Compact and clean version of method 5.

// Method 10: Using Golden Ratio Formula
#include <stdio.h>
#include <math.h>
int main() {
    int n;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    // phi = (1 + sqrt(5)) / 2
    double phi = (1 + sqrt(5)) / 2;

    // nth fibonacci = round(phi^(n-1) / sqrt(5))
    int result = (int)round(pow(phi, n - 1) / sqrt(5));

    printf("Nth term of Fibonacci = %d\n", result);

    return 0;
}
// Method 10 - Golden Ratio  The nth fibonacci term is calculated directly using the golden ratio formula without any loop or recursion. Works well for small values but loses precision for large n due to floating point limits.

// Method 11: Using Matrix Exponentiation
#include <stdio.h>
void multiply(int F[2][2], int M[2][2]) {
    int a = F[0][0]*M[0][0] + F[0][1]*M[1][0];
    int b = F[0][0]*M[0][1] + F[0][1]*M[1][1];
    int c = F[1][0]*M[0][0] + F[1][1]*M[1][0];
    int d = F[1][0]*M[0][1] + F[1][1]*M[1][1];
    F[0][0]=a; F[0][1]=b;
    F[1][0]=c; F[1][1]=d;
}
int fibonacci(int n) {
    if (n == 1) return 0;
    int F[2][2] = {{1,1},{1,0}};
    int M[2][2] = {{1,1},{1,0}};
    for (int i = 2; i < n; i++)
        multiply(F, M);
    return F[0][0];
}
int main() {
    int n;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    printf("Nth term of Fibonacci = %d\n", fibonacci(n));

    return 0;
}
// Method 11 - Matrix Exponentiation  Fibonacci numbers can be derived using matrix multiplication of a 2x2 matrix. Advanced method used in competitive programming for very large n values. Good to know it exists and learn later.

// Method 12: Using switch Statement
#include <stdio.h>
int getNthFib(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    int a = 0, b = 1;
    for (int i = 3; i <= n; i++) {
        int next = a + b;
        a = b;
        b = next;
    }
    return b;
}
int main() {
    int n;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    // use switch for special cases
    switch (n) {
        case 1:
            printf("Nth term of Fibonacci = 0\n");
            break;
        case 2:
            printf("Nth term of Fibonacci = 1\n");
            break;
        default:
            printf("Nth term of Fibonacci = %d\n", getNthFib(n));
            break;
    }

    return 0;
}
// Method 12 - Switch Statement  Switch handles the first two special cases directly. The default case calls getNthFib() for all other values of n. Good practice combining switch with a function for cleaner output handling.
