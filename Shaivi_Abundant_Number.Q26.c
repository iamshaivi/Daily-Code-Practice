// Abundant Number or Not in C Program

// Method 1: Using for Loop (Brute Force)
#include <stdio.h>
int main() {
    int num, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    for (int i = 1; i < num; i++)
        if (num % i == 0)
            sum += i;

    if (sum > num)
        printf("%d is an Abundant Number\n", num);
    else
        printf("%d is Not an Abundant Number\n", num);

    return 0;
}
// Method 1 - For Loop  We add all proper divisors of num excluding num itself. If their sum is greater than num it is an abundant number. Example 12 has divisors 1+2+3+4+6=16 and 16>12 so 12 is abundant.

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

    if (sum > num)
        printf("%d is an Abundant Number\n", num);
    else
        printf("%d is Not an Abundant Number\n", num);

    return 0;
}
// Method 2 - While Loop  Same logic as method 1 but using a while loop. We initialize i before the loop and increment it inside. Good practice to write the same abundant number logic using different loop types.

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

    if (sum > num)
        printf("%d is an Abundant Number\n", num);
    else
        printf("%d is Not an Abundant Number\n", num);

    return 0;
}
// Method 3 - do-while Loop  Body runs first then condition is checked. Works same as while loop here. Completes all 3 loop types for this problem. Good to practice do-while with divisor sum logic for abundant number check.

// Method 4: Using Square Root Optimization
#include <stdio.h>
#include <math.h>
int main() {
    int num, sum = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    // divisors come in pairs so check only up to sqrt
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i)
                sum += num / i;
        }
    }

    if (num > 1 && sum > num)
        printf("%d is an Abundant Number\n", num);
    else
        printf("%d is Not an Abundant Number\n", num);

    return 0;
}
// Method 4 - Square Root  Divisors always come in pairs. If i divides num then num/i is also a divisor. We check only up to sqrt(num) and add both at once. Start sum at 1 since 1 is always a divisor. Much faster method.

// Method 5: Using Function
#include <stdio.h>
int divisorSum(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++)
        if (num % i == 0)
            sum += i;
    return sum;
}
int isAbundant(int num) {
    return divisorSum(num) > num;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isAbundant(num))
        printf("%d is an Abundant Number\n", num);
    else
        printf("%d is Not an Abundant Number\n", num);

    return 0;
}
// Method 5 - Function  Logic is split into divisorSum() and isAbundant() functions. divisorSum() calculates the sum of all proper divisors. isAbundant() checks if sum exceeds num. Main just takes input and prints. Clean and reusable.

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

    if (sum > num)
        printf("%d is an Abundant Number\n", num);
    else
        printf("%d is Not an Abundant Number\n", num);

    return 0;
}
// Method 6 - Recursion  divisorSum() checks if i divides num and adds it then calls itself with i+1. When i equals num it stops and returns 0. Good practice for understanding how recursion replaces a simple divisor sum loop.

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

    printf("Proper divisors of %d are: ", num);
    for (int i = 0; i < count; i++)
        printf("%d ", divisors[i]);
    printf("\nSum of divisors = %d\n", sum);

    if (sum > num)
        printf("%d is an Abundant Number\n", num);
    else
        printf("%d is Not an Abundant Number\n", num);

    return 0;
}
// Method 7 - Array  We store all proper divisors in an array and also calculate their sum. We print the divisors list and sum before the final verdict. More informative output showing exactly which divisors were found and their total.

// Method 8: Using Ternary Operator
#include <stdio.h>
int divisorSum(int n) {
    int s = 0;
    for (int i = 1; i < n; i++)
        if (n % i == 0) s += i;
    return s;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // condition ? true : false
    (divisorSum(num) > num)
        ? printf("%d is an Abundant Number\n", num)
        : printf("%d is Not an Abundant Number\n", num);

    return 0;
}
// Method 8 - Ternary Operator  We call divisorSum() inside the ternary condition directly. If sum exceeds num print yes else print no. All output handled in one clean single statement. Compact and concise version of the solution.

// Method 9: Using switch Statement
#include <stdio.h>
int isAbundant(int num) {
    int s = 0;
    for (int i = 1; i < num; i++)
        if (num % i == 0) s += i;
    return s > num;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // isAbundant() returns 1 if true and 0 if false
    switch (isAbundant(num)) {
        case 1:
            printf("%d is an Abundant Number\n", num);
            break;
        case 0:
            printf("%d is Not an Abundant Number\n", num);
            break;
    }

    return 0;
}
// Method 9 - Switch Case  isAbundant() returns 1 for abundant and 0 for not abundant. Switch works on these values. Case 1 means abundant number and case 0 means not. Good practice combining function with switch statement.

// Method 10: Print Abundant Numbers in a Given Range
#include <stdio.h>
int isAbundant(int num) {
    int s = 0;
    for (int i = 1; i < num; i++)
        if (num % i == 0) s += i;
    return s > num;
}
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Abundant numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++)
        if (isAbundant(i))
            printf("%d ", i);
    printf("\n");

    return 0;
}
// Method 10 - Range  We check every number in the given range and print it if it is abundant. isAbundant() is reused cleanly for each number. Smallest abundant numbers are 12 18 20 24 30 36 40 42 48 54 56 60 66 70 72 78 80.

// Method 11: Classify Number as Deficient Perfect or Abundant
#include <stdio.h>
int main() {
    int num, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    for (int i = 1; i < num; i++)
        if (num % i == 0)
            sum += i;

    printf("Sum of proper divisors of %d = %d\n", num, sum);

    if (sum > num)
        printf("%d is an Abundant Number (sum > number)\n", num);
    else if (sum == num)
        printf("%d is a Perfect Number (sum == number)\n", num);
    else
        printf("%d is a Deficient Number (sum < number)\n", num);

    return 0;
}
// Method 11 - Classify  Every number falls into one of three categories. If divisor sum is greater than num it is abundant. If equal it is perfect. If less it is deficient. This classifies the number into all three categories at once.

// Method 12: Using Array to Store Abundant Numbers in Range
#include <stdio.h>
int isAbundant(int num) {
    int s = 0;
    for (int i = 1; i < num; i++)
        if (num % i == 0) s += i;
    return s > num;
}
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    int result[1000], count = 0;

    for (int i = start; i <= end; i++)
        if (isAbundant(i))
            result[count++] = i;

    printf("Abundant numbers between %d and %d are: ", start, end);
    for (int i = 0; i < count; i++)
        printf("%d ", result[i]);
    printf("\nTotal abundant numbers found: %d\n", count);

    return 0;
}
// Method 12 - Array with Count  We store all abundant numbers found in the range in an array and print them with a total count at the end. Useful when you need to process or use the abundant numbers further in the program.

// Method 13: Using Macro
#include <stdio.h>

int abundHelper(int n) {
    int s = 0;
    for (int i = 1; i < n; i++)
        if (n % i == 0) s += i;
    return s > n;
}

#define IS_ABUNDANT(n) abundHelper(n)

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (IS_ABUNDANT(num))
        printf("%d is an Abundant Number\n", num);
    else
        printf("%d is Not an Abundant Number\n", num);

    return 0;
}
// Method 13 - Macro  We define IS_ABUNDANT as a macro that calls abundHelper(). Wherever IS_ABUNDANT(n) is written it gets replaced by abundHelper(n). Good to know how macros wrap function calls cleanly in C.
