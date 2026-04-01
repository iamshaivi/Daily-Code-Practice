// Fibonacci Series Program in C

// Method 1: Using for Loop (Brute Force)
#include <stdio.h>
int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    int a = 0, b = 1;

    printf("Fibonacci Series: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        int next = a + b;
        a = b;
        b = next;
    }
    printf("\n");

    return 0;
}
// Method 1 - For Loop  We start with a=0 and b=1. Each iteration we print a then calculate next as a+b. Then shift a=b and b=next. This moves the window forward by one step each time.

// Method 2: Using while Loop
#include <stdio.h>
int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    int a = 0, b = 1, i = 1;

    printf("Fibonacci Series: ");
    while (i <= n) {
        printf("%d ", a);
        int next = a + b;
        a = b;
        b = next;
        i++;
    }
    printf("\n");

    return 0;
}
// Method 2 - While Loop  Same logic as method 1 but written as a while loop. We initialize i before the loop and increment it inside. Good practice to know both for and while for series problems.

// Method 3: Using do-while Loop
#include <stdio.h>
int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    int a = 0, b = 1, i = 1;

    printf("Fibonacci Series: ");
    do {
        printf("%d ", a);
        int next = a + b;
        a = b;
        b = next;
        i++;
    } while (i <= n);
    printf("\n");

    return 0;
}
// Method 3 - do-while Loop  Body runs first then condition is checked. Works same as while loop here. Completes all 3 loop types for this problem. Note: gives wrong output if n is 0 or negative.

// Method 4: Using Function
#include <stdio.h>
void printFibonacci(int n) {
    int a = 0, b = 1;
    printf("Fibonacci Series: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        int next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}
int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printFibonacci(n);

    return 0;
}
// Method 4 - Function  The series logic is placed in a separate function printFibonacci(). Main just takes input and calls it. Code is clean reusable and well organized. Good habit for writing structured programs.

// Method 5: Using Recursion
#include <stdio.h>
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++)
        printf("%d ", fibonacci(i));
    printf("\n");

    return 0;
}
// Method 5 - Recursion  fibonacci(n) calls itself with n-1 and n-2 and adds the results. Base cases are 0 and 1. Simple to understand but slow for large n because it recalculates the same values many times.

// Method 6: Using Array
#include <stdio.h>
int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++)
        printf("%d ", fib[i]);
    printf("\n");

    return 0;
}
// Method 6 - Array  We store all fibonacci values in an array. Each element is the sum of the two before it. Good for when you need to access any fibonacci number later in the program by its index.

// Method 7: Using Dynamic Programming (Memoization)
#include <stdio.h>
#define MAX 1000

int memo[MAX];

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}
int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < MAX; i++)
        memo[i] = -1;

    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++)
        printf("%d ", fibonacci(i));
    printf("\n");

    return 0;
}
// Method 7 - Memoization  Same as recursion but we store already calculated values in memo array. If a value is already computed we return it directly instead of recalculating. Much faster than plain recursion.

// Method 8: Using Recursion with Two Variables
#include <stdio.h>
void fibRecursive(int a, int b, int n) {
    if (n == 0) return;
    printf("%d ", a);
    fibRecursive(b, a + b, n - 1);
}
int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    fibRecursive(0, 1, n);
    printf("\n");

    return 0;
}
// Method 8 - Tail Recursion  Instead of calculating fib(n-1)+fib(n-2) separately we pass both current and next values as arguments. Each call prints current and passes next two values. Much more efficient than method 5.

// Method 9: Using Swap Method
#include <stdio.h>
int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    int a = 0, b = 1;

    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        // swap and add without temp variable
        b = a + b;
        a = b - a;
    }
    printf("\n");

    return 0;
}
// Method 9 - Swap Method  We update b as a+b first then recover new a as b-a. This avoids using a third temp variable for the swap. Clever trick that works correctly and saves one variable in memory.

// Method 10: Using Matrix Exponentiation
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
    int F[2][2] = {{1,1},{1,0}};
    int M[2][2] = {{1,1},{1,0}};
    if (n == 0) return 0;
    for (int i = 2; i < n; i++)
        multiply(F, M);
    return F[0][0];
}
int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++)
        printf("%d ", fibonacci(i));
    printf("\n");

    return 0;
}
// Method 10 - Matrix Exponentiation  We use the property that fibonacci numbers can be derived from matrix multiplication. Advanced method used in competitive programming. Good to know it exists and learn later.

// Method 11: Using Golden Ratio Formula
#include <stdio.h>
#include <math.h>
int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // phi = (1 + sqrt(5)) / 2
    double phi = (1 + sqrt(5)) / 2;

    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++)
        printf("%d ", (int)round(pow(phi, i) / sqrt(5)));
    printf("\n");

    return 0;
}
// Method 11 - Golden Ratio  The nth fibonacci number can be calculated directly using the golden ratio formula phi^n/sqrt(5). Purely math based with no loop or recursion needed. Works for small values but loses precision for large n due to floating point.
