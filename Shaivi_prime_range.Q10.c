// C Program to Print Prime Numbers in a Given Range

// Method 1: Using Nested for Loop (Brute Force)
#include <stdio.h>
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++) {
        if (i <= 1) continue;
        int isPrime = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime)
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}
// Method 1 - Nested for Loop  For every number in the range we check if it is divisible by any number from 2 to i-1. If no divisor found it is prime. Numbers less than or equal to 1 are skipped.

// Method 2: Using Square Root Optimization
#include <stdio.h>
#include <math.h>
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++) {
        if (i <= 1) continue;
        int isPrime = 1;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime)
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}
// Method 2 - Square Root  Instead of checking up to i-1 we only check up to sqrt(i). If a number has a factor bigger than its square root the other factor is always smaller. Much faster than method 1.

// Method 3: Using i*i Instead of sqrt()
#include <stdio.h>
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++) {
        if (i <= 1) continue;
        int isPrime = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime)
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}
// Method 3 - i*i Optimization  Same as method 2 but we use j*j <= i instead of sqrt(). This avoids including math.h header and is slightly cleaner. Most recommended way to write prime check in C.

// Method 4: Using while Loop
#include <stdio.h>
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are: ", start, end);
    int i = start;
    while (i <= end) {
        if (i > 1) {
            int isPrime = 1, j = 2;
            while (j * j <= i) {
                if (i % j == 0) {
                    isPrime = 0;
                    break;
                }
                j++;
            }
            if (isPrime)
                printf("%d ", i);
        }
        i++;
    }
    printf("\n");

    return 0;
}
// Method 4 - While Loop  Same logic as method 3 but both outer and inner loops are written as while loops. We manually initialize and increment the counters. Good practice to use while loop for such problems.

// Method 5: Using a Function
#include <stdio.h>
int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0) return 0;
    return 1;
}
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++)
        if (isPrime(i))
            printf("%d ", i);
    printf("\n");

    return 0;
}
// Method 5 - Function  The prime checking logic is moved into a separate function isPrime(). Main loop just calls it for each number in range. Code is clean reusable and easy to read and maintain.

// Method 6: Using Recursion
#include <stdio.h>
int checkPrime(int num, int i) {
    if (num <= 1) return 0;
    if (i * i > num) return 1;
    if (num % i == 0) return 0;
    return checkPrime(num, i + 1);
}
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++)
        if (checkPrime(i, 2))
            printf("%d ", i);
    printf("\n");

    return 0;
}
// Method 6 - Recursion  checkPrime() calls itself with i+1 each time. If i*i goes beyond num no divisor was found so it is prime. If num%i is 0 a divisor is found so not prime. Good recursion practice.

// Method 7: Using Sieve of Eratosthenes
#include <stdio.h>
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    int sieve[end + 1];
    for (int i = 0; i <= end; i++)
        sieve[i] = 1;

    sieve[0] = sieve[1] = 0;

    for (int i = 2; i * i <= end; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= end; j += i)
                sieve[j] = 0;
        }
    }

    printf("Prime numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++)
        if (sieve[i])
            printf("%d ", i);
    printf("\n");

    return 0;
}
// Method 7 - Sieve of Eratosthenes  We create an array and mark all multiples of each prime as 0. What remains marked as 1 are primes. This is the fastest known method for printing all primes in a range.

// Method 8: Using 6k+1 Optimization
#include <stdio.h>
int isPrime6k(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    for (int i = 5; i * i <= num; i += 6)
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    return 1;
}
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);
