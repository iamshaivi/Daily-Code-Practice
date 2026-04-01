// C Program to Check Perfect Number or Not

// Method 1: Using for Loop (Brute Force)
#include <stdio.h>
int main() {
    int num, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    for (int i = 1; i < num; i++)
        if (num % i == 0)
            sum += i;

    if (sum == num)
        printf("%d is a Perfect Number\n", num);
    else
        printf("%d is Not a Perfect Number\n", num);

    return 0;
}
// Method 1 - For Loop  We add all divisors of num excluding num itself. If the sum equals num it is a perfect number. Example 6 = 1+2+3 = 6 so 6 is perfect. Most basic and easy to understand method.

// Method 2: Using while Loop
#include <stdio.h>
int main() {
    int num, sum = 0, i = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (i < num) {
        if (num % i == 0)
            sum += i;
        i++;
    }

    if (sum == num)
        printf("%d is a Perfect Number\n", num);
    else
        printf("%d is Not a Perfect Number\n", num);

    return 0;
}
// Method 2 - While Loop  Same logic as method 1 but using a while loop. We initialize i before the loop and increment it inside. Good practice to write the same perfect number logic using different loop types.

// Method 3: Using do-while Loop
#include <stdio.h>
int main() {
    int num, sum = 0, i = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    do {
        if (num % i == 0)
            sum += i;
        i++;
    } while (i < num);

    if (sum == num)
        printf("%d is a Perfect Number\n", num);
    else
        printf("%d is Not a Perfect Number\n", num);

    return 0;
}
// Method 3 - do-while Loop  Body runs first then condition is checked. Works same as while loop here. Completes all 3 loop types for this problem. Good to practice do-while with divisor sum logic.

// Method 4: Using Square Root Optimization
#include <stdio.h>
#include <math.h>
int main() {
    int num, sum = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    // factors always come in pairs so check only up to sqrt
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i)
                sum += num / i;
        }
    }

    if (num > 1 && sum == num)
        printf("%d is a Perfect Number\n", num);
    else
        printf("%d is Not a Perfect Number\n", num);

    return 0;
}
// Method 4 - Square Root  Divisors come in pairs. If i divides num then num/i is also a divisor. We check only up to sqrt(num) and add both factors at once. We start sum at 1 since 1 is always a divisor. Much faster method.

// Method 5: Using Function
#include <stdio.h>
int isPerfect(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++)
        if (num % i == 0)
            sum += i;
    return sum == num;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPerfect(num))
        printf("%d is a Perfect Number\n", num);
    else
        printf("%d is Not a Perfect Number\n", num);

    return 0;
}
// Method 5 - Function  The perfect number logic is placed in a separate function isPerfect() that returns 1 if true and 0 if false. Main just takes input and prints. Clean reusable and well organized code structure.

// Method 6: Using Recursion
#include <stdio.h>
int divisorSum(int num, int i) {
    if (i == num) return 0;
    if (num % i == 0) return i + divisorSum(num, i + 1);
    return divisorSum(num, i + 1);
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int sum = divisorSum(num, 1);

    if (sum == num)
        printf("%d is a Perfect Number\n", num);
    else
        printf("%d is Not a Perfect Number\n", num);

    return 0;
}
// Method 6 - Recursion  divisorSum() checks if i divides num and adds it then calls itself with i+1. When i equals num it stops and returns 0. Good practice for understanding how recursion replaces a simple divisor loop.

// Method 7: Using Array to Store Divisors
#include <stdio.h>
int main() {
    int num, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    int divisors[num], count = 0;

    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            divisors[count++] = i;
            sum += i;
        }
    }

    printf("Divisors of %d are: ", num);
    for (int i = 0; i < count; i++)
        printf("%d ", divisors[i]);
    printf("\nSum of divisors = %d\n", sum);

    if (sum == num)
        printf("%d is a Perfect Number\n", num);
    else
        printf("%d is Not a Perfect Number\n", num);

    return 0;
}
// Method 7 - Array  We store all divisors in an array and also calculate their sum. We print the divisors list and sum before the final result. More informative output showing exactly which divisors were found and their total.

// Method 8: Using Ternary Operator
#include <stdio.h>
int isPerfect(int num) {
    int s = 0;
    for (int i = 1; i < num; i++)
        if (num % i == 0) s += i;
    return s == num;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // condition ? true : false
    isPerfect(num)
        ? printf("%d is a Perfect Number\n", num)
        : printf("%d is Not a Perfect Number\n", num);

    return 0;
}
// Method 8 - Ternary Operator  We call isPerfect() inside a ternary condition directly. If it returns 1 print yes else print no. All output handled in one clean single statement. Compact version combining function and ternary.

// Method 9: Using switch Statement
#include <stdio.h>
int isPerfect(int num) {
    int s = 0;
    for (int i = 1; i < num; i++)
        if (num % i == 0) s += i;
    return s == num;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // isPerfect() returns 1 if true and 0 if false
    switch (isPerfect(num)) {
        case 1:
            printf("%d is a Perfect Number\n", num);
            break;
        case 0:
            printf("%d is Not a Perfect Number\n", num);
            break;
    }

    return 0;
}
// Method 9 - Switch Case  isPerfect() returns 1 for perfect and 0 for not perfect. Switch works on these values. Case 1 means perfect number and case 0 means not perfect number. Good practice combining function with switch.

// Method 10: Print Perfect Numbers in a Given Range
#include <stdio.h>
int isPerfect(int num) {
    int s = 0;
    for (int i = 1; i < num; i++)
        if (num % i == 0) s += i;
    return s == num;
}
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Perfect numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++)
        if (isPerfect(i))
            printf("%d ", i);
    printf("\n");

    return 0;
}
// Method 10 - Range  We check every number in the given range and print it if it is a perfect number. isPerfect() is reused cleanly for each number. Known perfect numbers are 6 28 496 and 8128 so test with a wide range.

// Method 11: Using Euclid Euler Formula
#include <stdio.h>
#include <math.h>
int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}
int main() {
    int limit;

    printf("Enter limit to find even perfect numbers: ");
    scanf("%d", &limit);

    // Euclid Euler formula: 2^(p-1) * (2^p - 1) is perfect if (2^p - 1) is prime
    printf("Even perfect numbers up to %d: ", limit);
    for (int p = 2; p <= 30; p++) {
        long long mersenne = (1LL << p) - 1;
        if (isPrime(mersenne)) {
            long long perfect = (1LL << (p - 1)) * mersenne;
            if (perfect <= limit)
                printf("%lld ", perfect);
        }
    }
    printf("\n");

    return 0;
}
// Method 11 - Euclid Euler Formula  Every even perfect number has the form 2^(p-1) * (2^p - 1) where (2^p - 1) is a Mersenne prime. This is a mathematical formula to generate perfect numbers directly. Advanced but good to know.

// Method 12: Using Macro
#include <stdio.h>

int perfectHelper(int n) {
    int s = 0;
    for (int i = 1; i < n; i++)
        if (n % i == 0) s += i;
    return s == n;
}

#define IS_PERFECT(n) perfectHelper(n)

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (IS_PERFECT(num))
        printf("%d is a Perfect Number\n", num);
    else
        printf("%d is Not a Perfect Number\n", num);

    return 0;
}
// Method 12 - Macro  We define IS_PERFECT as a macro that calls perfectHelper(). Wherever IS_PERFECT(n) is written it gets replaced by perfectHelper(n). Good to know how macros wrap function calls cleanly in C.

// Method 13: Without using Division Operator
#include <stdio.h>
int main() {
    int num, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    // use multiplication instead of division to check divisibility
    for (int i = 1; i < num; i++)
        for (int j = 1; j <= num; j++)
            if (i * j == num) {
                sum += i;
                break;
            }

    if (sum == num)
        printf("%d is a Perfect Number\n", num);
    else
        printf("%d is Not a Perfect Number\n", num);

    return 0;
}
// Method 13 - Without Division  Instead of using % operator we use multiplication to check if i is a divisor. We look for j such that i*j equals num. Not efficient but a good exercise to think about divisibility differently.
