// C Program to Find the Factors of a Number

// Method 1: Using for Loop (Brute Force)
#include <stdio.h>
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factors of %d are: ", num);
    for (int i = 1; i <= num; i++) {
        if (num % i == 0)
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}
// Method 1 - For Loop  We check every number from 1 to num. If num is divisible by i with no remainder then i is a factor. Simple and easy to understand but checks all numbers up to num so it is slow for large numbers.

// Method 2: Using while Loop
#include <stdio.h>
int main() {
    int num, i = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factors of %d are: ", num);
    while (i <= num) {
        if (num % i == 0)
            printf("%d ", i);
        i++;
    }
    printf("\n");

    return 0;
}
// Method 2 - While Loop  Same logic as method 1 but using a while loop. We initialize i before the loop and increment it inside. Good practice to write the same factor logic using different loop types.

// Method 3: Using do-while Loop
#include <stdio.h>
int main() {
    int num, i = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factors of %d are: ", num);
    do {
        if (num % i == 0)
            printf("%d ", i);
        i++;
    } while (i <= num);
    printf("\n");

    return 0;
}
// Method 3 - do-while Loop  Body runs first then condition is checked. Works same as while loop here. Completes all 3 loop types for this problem. Good to practice do-while with divisibility check logic.

// Method 4: Using Square Root Optimization
#include <stdio.h>
#include <math.h>
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factors of %d are: ", num);
    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            printf("%d ", i);
            // print the paired factor if it is different
            if (i != num / i)
                printf("%d ", num / i);
        }
    }
    printf("\n");

    return 0;
}
// Method 4 - Square Root Optimization  Factors always come in pairs. If i is a factor then num/i is also a factor. So we only check up to sqrt(num) and print both factors at once. Much faster than checking up to num.

// Method 5: Using Function
#include <stdio.h>
void findFactors(int num) {
    printf("Factors of %d are: ", num);
    for (int i = 1; i <= num; i++)
        if (num % i == 0)
            printf("%d ", i);
    printf("\n");
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    findFactors(num);

    return 0;
}
// Method 5 - Function  The factor finding logic is placed in a separate function findFactors(). Main just takes input and calls it. Code is clean reusable and well organized. Good habit for writing structured programs.

// Method 6: Using Recursion
#include <stdio.h>
void findFactors(int num, int i) {
    if (i > num) return;
    if (num % i == 0)
        printf("%d ", i);
    findFactors(num, i + 1);
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factors of %d are: ", num);
    findFactors(num, 1);
    printf("\n");

    return 0;
}
// Method 6 - Recursion  The function checks if i is a factor and prints it then calls itself with i+1. When i exceeds num the function stops. Good practice for understanding how recursion replaces a simple loop.

// Method 7: Using Array to Store Factors
#include <stdio.h>
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int factors[num], count = 0;

    for (int i = 1; i <= num; i++)
        if (num % i == 0)
            factors[count++] = i;

    printf("Factors of %d are: ", num);
    for (int i = 0; i < count; i++)
        printf("%d ", factors[i]);
    printf("\nTotal number of factors: %d\n", count);

    return 0;
}
// Method 7 - Array  We store all factors in an array first then print them. We also print the total count at the end. Useful when you need to use the factors later in the program for further processing or calculations.

// Method 8: Using Ternary Operator
#include <stdio.h>
void findFactors(int num, int i) {
    if (i > num) return;
    (num % i == 0) ? printf("%d ", i) : 0;
    findFactors(num, i + 1);
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factors of %d are: ", num);
    findFactors(num, 1);
    printf("\n");

    return 0;
}
// Method 8 - Ternary Operator  We use ternary inside the recursive function. If num%i is 0 we print i else we do nothing using 0. Short and compact way to print factors without writing a full if block inside recursion.

// Method 9: Printing Factors in Pairs
#include <stdio.h>
#include <math.h>
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factor pairs of %d are:\n", num);
    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            if (i == num / i)
                printf("%d x %d\n", i, i);
            else
                printf("%d x %d\n", i, num / i);
        }
    }

    return 0;
}
// Method 9 - Factor Pairs  Instead of printing factors individually we print them as pairs. For every factor i we print i x num/i. If both are equal like in a perfect square we print it only once. More informative output format.

// Method 10: Count and Print Factors
#include <stdio.h>
int main() {
    int num, count = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factors of %d are: ", num);
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTotal number of factors: %d\n", count);

    return 0;
}
// Method 10 - Count Factors  Same as method 1 but we also keep a count of how many factors are found. At the end we print the total number of factors. More complete and user friendly output for the program.

// Method 11: Check if Number is Perfect Number
#include <stdio.h>
int main() {
    int num, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factors of %d (excluding itself) are: ", num);
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            printf("%d ", i);
            sum += i;
        }
    }

    printf("\nSum of factors = %d\n", sum);

    if (sum == num)
        printf("%d is a Perfect Number\n", num);
    else
        printf("%d is Not a Perfect Number\n", num);

    return 0;
}
// Method 11 - Perfect Number Check  A perfect number is one whose factors excluding itself add up to the number itself. We print all factors except num and check if their sum equals num. Example 6 = 1+2+3 so 6 is perfect.

// Method 12: Using Macro
#include <stdio.h>

void factorHelper(int num) {
    for (int i = 1; i <= num; i++)
        if (num % i == 0)
            printf("%d ", i);
}

#define FIND_FACTORS(n) factorHelper(n)

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factors of %d are: ", num);
    FIND_FACTORS(num);
    printf("\n");

    return 0;
}
// Method 12 - Macro  We define FIND_FACTORS as a macro that calls factorHelper(). Wherever FIND_FACTORS(n) is written it gets replaced by factorHelper(n). Good to know how macros wrap function calls cleanly in C.

// Method 13: Sorted Factors Using Square Root
#include <stdio.h>
#include <math.h>
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // store small and large factors separately
    int small[1000], large[1000];
    int sc = 0, lc = 0;

    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            small[sc++] = i;
            if (i != num / i)
                large[lc++] = num / i;
        }
    }

    // print small factors then large factors in reverse
    printf("Factors of %d in sorted order: ", num);
    for (int i = 0; i < sc; i++)
        printf("%d ", small[i]);
    for (int i = lc - 1; i >= 0; i--)
        printf("%d ", large[i]);
    printf("\n");

    return 0;
}
// Method 13 - Sorted with Square Root  We collect small factors up to sqrt(num) and their pairs separately. Then print small factors forward and large factors in reverse to get a fully sorted output. Efficient and clean approach.
