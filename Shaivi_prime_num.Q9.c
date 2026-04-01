// C Program to Check Whether a Number is Prime Number or Not

// Method 1: Using if-else (Brute Force)
#include <stdio.h>
int main() {
    int num, isPrime = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num <= 1) {
        isPrime = 0;
    } else {
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }

    if (isPrime)
        printf("%d is a Prime Number\n", num);
    else
        printf("%d is Not a Prime Number\n", num);

    return 0;
}
// Method 1 - Brute Force  We check if num is divisible by any number from 2 to num-1. If any divisor is found we set isPrime to 0 and break. Numbers less than or equal to 1 are never prime.

// Method 2: Using Square Root Optimization
#include <stdio.h>
#include <math.h>
int main() {
    int num, isPrime = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num <= 1) {
        isPrime = 0;
    } else {
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }

    if (isPrime)
        printf("%d is a Prime Number\n", num);
    else
        printf("%d is Not a Prime Number\n", num);

    return 0;
}
// Method 2 - Square Root  Instead of checking up to num-1 we only check up to sqrt(num). If a number has a factor larger than its square root the other factor will always be smaller. Much faster method.

// Method 3: Using while Loop
#include <stdio.h>
int main() {
    int num, isPrime = 1, i = 2;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num <= 1) {
        isPrime = 0;
    } else {
        while (i < num) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
            i++;
        }
    }

    if (isPrime)
        printf("%d is a Prime Number\n", num);
    else
        printf("%d is Not a Prime Number\n", num);

    return 0;
}
// Method 3 - While Loop  Same logic as method 1 but using a while loop instead of for loop. We initialize i before the loop and increment it inside. Good practice to use while loop for such checks.

// Method 4: Using Function
#include <stdio.h>
int isPrime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPrime(num))
        printf("%d is a Prime Number\n", num);
    else
        printf("%d is Not a Prime Number\n", num);

    return 0;
}
// Method 4 - Function  The prime checking logic is placed in a separate function isPrime() that returns 1 for prime and 0 for not prime. We use i*i <= num instead of sqrt to avoid math.h header.

// Method 5: Using Recursion
#include <stdio.h>
int checkPrime(int num, int i) {
    if (num <= 1)
        return 0;
    if (i * i > num)
        return 1;
    if (num % i == 0)
        return 0;
    return checkPrime(num, i + 1);
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (checkPrime(num, 2))
        printf("%d is a Prime Number\n", num);
    else
        printf("%d is Not a Prime Number\n", num);

    return 0;
}
// Method 5 - Recursion  The function calls itself with i+1 each time. If i*i goes beyond num it means no divisor was found and number is prime. If num%i is 0 a divisor is found so not prime.

// Method 6: Using Ternary Operator
#include <stdio.h>
int checkPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0) return 0;
    return 1;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // condition ? "if true" : "if false"
    checkPrime(num)
        ? printf("%d is a Prime Number\n", num)
        : printf("%d is Not a Prime Number\n", num);

    return 0;
}
// Method 6 - Ternary Operator  We use the checkPrime() function with a ternary operator to print the result in one statement. Short and clean way to display output based on a function return value.

// Method 7: Using switch Statement
#include <stdio.h>
int checkPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0) return 0;
    return 1;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // checkPrime() returns 1 if prime and 0 if not prime
    switch (checkPrime(num)) {
        case 1:
            printf("%d is a Prime Number\n", num);
            break;
        case 0:
            printf("%d is Not a Prime Number\n", num);
            break;
    }

    return 0;
}
// Method 7 - Switch Case  checkPrime() returns 1 for prime and 0 for not prime. Switch works on these values. Case 1 means prime and case 0 means not prime. Good practice combining function with switch.
