// Prime Factors of a Number in C

// Method 1: Using for Loop (Brute Force)
#include <stdio.h>
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Prime factors of %d are: ", num);
    for (int i = 2; i <= num; i++) {
        while (num % i == 0) {
            printf("%d ", i);
            num /= i;
        }
    }
    printf("\n");

    return 0;
}
// Method 1 - For Loop  We start from 2 and keep dividing num by i as long as it is divisible. This ensures only prime factors are printed because all smaller factors are already divided out before reaching larger ones.

// Method 2: Using while Loop
#include <stdio.h>
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Prime factors of %d are: ", num);
    int i = 2;
    while (i <= num) {
        while (num % i == 0) {
            printf("%d ", i);
            num /= i;
        }
        i++;
    }
    printf("\n");

    return 0;
}
// Method 2 - While Loop  Same logic as method 1 but outer loop is a while loop. We initialize i before the loop and increment it at the end. Good practice to write the same logic using different loop types.

// Method 3: Using Square Root Optimization
#include <stdio.h>
#include <math.h>
int main() {
    int num, original;

    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;
    printf("Prime factors of %d are: ", original);

    // divide out all small prime factors up to sqrt
    for (int i = 2; i <= sqrt(num); i++) {
        while (num % i == 0) {
            printf("%d ", i);
            num /= i;
        }
    }

    // if remaining num is greater than 1 it is a prime factor
    if (num > 1)
        printf("%d ", num);
    printf("\n");

    return 0;
}
// Method 3 - Square Root  We only check divisors up to sqrt(num). After dividing out all small factors if num is still greater than 1 that remaining value is itself a large prime factor. Much faster than method 1.

// Method 4: Using Function
#include <stdio.h>
#include <math.h>
void primeFactors(int num) {
    printf("Prime factors of %d are: ", num);
    for (int i = 2; i <= sqrt(num); i++) {
        while (num % i == 0) {
            printf("%d ", i);
            num /= i;
        }
    }
    if (num > 1)
        printf("%d ", num);
    printf("\n");
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    primeFactors(num);

    return 0;
}
// Method 4 - Function  The prime factorization logic is placed in a separate function primeFactors(). Main just takes input and calls it. Code is clean reusable and well organized. Good habit for structured programs.

// Method 5: Using Recursion
#include <stdio.h>
void primeFactors(int num, int i) {
    if (num <= 1) return;
    if (num % i == 0) {
        printf("%d ", i);
        primeFactors(num / i, i);
    } else {
        primeFactors(num, i + 1);
    }
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Prime factors of %d are: ", num);
    primeFactors(num, 2);
    printf("\n");

    return 0;
}
// Method 5 - Recursion  If num is divisible by i we print i and recurse with num/i. If not we recurse with i+1. When num becomes 1 we stop. Good practice for understanding how recursion replaces nested loops.

// Method 6: Using Array to Store Prime Factors
#include <stdio.h>
#include <math.h>
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int factors[100], count = 0;
    int temp = num;

    for (int i = 2; i <= sqrt(temp); i++) {
        while (temp % i == 0) {
            factors[count++] = i;
            temp /= i;
        }
    }
    if (temp > 1)
        factors[count++] = temp;

    printf("Prime factors of %d are: ", num);
    for (int i = 0; i < count; i++)
        printf("%d ", factors[i]);
    printf("\nTotal prime factors: %d\n", count);

    return 0;
}
// Method 6 - Array  We store all prime factors in an array first then print them along with the total count. Useful when you need to use the prime factors later in the program for further processing or calculations.

// Method 7: Using Sieve of Eratosthenes
#include <stdio.h>
#define MAX 100000
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // build smallest prime factor sieve
    int spf[MAX];
    for (int i = 0; i < MAX; i++)
        spf[i] = i;

    for (int i = 2; i * i < MAX; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAX; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }

    printf("Prime factors of %d are: ", num);
    int temp = num;
    while (temp != 1) {
        printf("%d ", spf[temp]);
        temp /= spf[temp];
    }
    printf("\n");

    return 0;
}
// Method 7 - Sieve  We precompute the smallest prime factor for every number using a sieve. Then repeatedly divide num by its smallest prime factor. Very fast for multiple queries as sieve is built only once.

// Method 8: Print Unique Prime Factors Only
#include <stdio.h>
#include <math.h>
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Unique prime factors of %d are: ", num);
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            printf("%d ", i);
            while (num % i == 0)
                num /= i;
        }
    }
    if (num > 1)
        printf("%d ", num);
    printf("\n");

    return 0;
}
// Method 8 - Unique Factors  Instead of printing repeated prime factors we print each unique prime factor only once. We divide out all occurrences before moving to next. Example for 12 we print 2 3 instead of 2 2 3.

// Method 9: Print Prime Factors with Their Powers
#include <stdio.h>
#include <math.h>
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Prime factorization of %d: ", num);
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            int power = 0;
            while (num % i == 0) {
                power++;
                num /= i;
            }
            if (power == 1)
                printf("%d ", i);
            else
                printf("%d^%d ", i, power);
        }
    }
    if (num > 1)
        printf("%d ", num);
    printf("\n");

    return 0;
}
// Method 9 - With Powers  We count how many times each prime factor divides num and store it as power. If power is 1 we just print the factor. If greater than 1 we print factor^power. Example 12 prints as 2^2 3.

// Method 10: Using do-while Loop
#include <stdio.h>
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Prime factors of %d are: ", num);
    int i = 2;
    do {
        if (num % i == 0) {
            do {
                printf("%d ", i);
                num /= i;
            } while (num % i == 0);
        }
        i++;
    } while (i <= num);
    printf("\n");

    return 0;
}
// Method 10 - do-while Loop  Both outer and inner loops use do-while. Body always runs at least once before condition check. Completes all 3 loop types for this problem. Good practice nesting do-while loops together.

// Method 11: Using Ternary and Recursion
#include <stdio.h>
void primeFactors(int num, int i) {
    if (num <= 1) return;
    (num % i == 0) ? (printf("%d ", i), primeFactors(num / i, i))
                   : primeFactors(num, i + 1);
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Prime factors of %d are: ", num);
    primeFactors(num, 2);
    printf("\n");

    return 0;
}
// Method 11 - Ternary with Recursion  The recursive logic is compressed into a single ternary line. If divisible print and recurse with num/i else recurse with i+1. Compact and clean version that combines ternary and recursion together.

// Method 12: Using Macro
#include <stdio.h>
#include <math.h>

void pfHelper(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        while (num % i == 0) {
            printf("%d ", i);
            num /= i;
        }
    }
    if (num > 1) printf("%d ", num);
}

#define PRIME_FACTORS(n) pfHelper(n)

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Prime factors of %d are: ", num);
    PRIME_FACTORS(num);
    printf("\n");

    return 0;
}
// Method 12 - Macro  We define PRIME_FACTORS as a macro that calls pfHelper(). Wherever PRIME_FACTORS(n) is written it gets replaced by pfHelper(n). Good to know how macros wrap function calls cleanly in C.

// Method 13: Check if Number is Prime then Factor
#include <stdio.h>
#include <math.h>
int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPrime(num)) {
        printf("%d is itself a Prime Number\n", num);
        printf("Prime factors of %d are: %d\n", num, num);
    } else {
        int temp = num;
        printf("Prime factors of %d are: ", num);
        for (int i = 2; i <= sqrt(temp); i++) {
            while (temp % i == 0) {
                printf("%d ", i);
                temp /= i;
            }
        }
        if (temp > 1) printf("%d ", temp);
        printf("\n");
    }

    return 0;
}
// Method 13 - Prime Check First  We first check if the number itself is prime. If it is we print it directly as its own prime factor. If not we proceed with normal factorization. Adds an extra check for a cleaner and smarter output.
