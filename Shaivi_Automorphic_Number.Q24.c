// Automorphic Number or Not | C Program

// Method 1: Using for Loop (Brute Force)
#include <stdio.h>
int main() {
    int num, square, temp, digits = 0, lastDigits;

    printf("Enter a number: ");
    scanf("%d", &num);

    square = num * num;

    // count digits in num
    temp = num;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    // extract last 'digits' digits of square
    int divisor = 1;
    for (int i = 0; i < digits; i++)
        divisor *= 10;

    lastDigits = square % divisor;

    if (lastDigits == num)
        printf("%d is an Automorphic Number\n", num);
    else
        printf("%d is Not an Automorphic Number\n", num);

    return 0;
}
// Method 1 - For Loop  We square the number then count how many digits num has. We extract the same number of digits from the end of square using modulo. If those last digits equal num it is automorphic. Example 5^2=25 ends in 5.

// Method 2: Using while Loop
#include <stdio.h>
int main() {
    int num, square, temp, digits = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    square = num * num;
    temp = num;

    // count digits using while loop
    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    // build divisor using while loop
    int divisor = 1, i = 0;
    while (i < digits) {
        divisor *= 10;
        i++;
    }

    if (square % divisor == num)
        printf("%d is an Automorphic Number\n", num);
    else
        printf("%d is Not an Automorphic Number\n", num);

    return 0;
}
// Method 2 - While Loop  Same logic as method 1 but both digit counting and divisor building use while loops. We initialize counters before and increment inside. Good practice writing the same logic using different loop types.

// Method 3: Using do-while Loop
#include <stdio.h>
int main() {
    int num, square, temp, digits = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    square = num * num;
    temp = num;

    // count digits using do-while
    do {
        digits++;
        temp /= 10;
    } while (temp != 0);

    int divisor = 1, i = 0;
    do {
        divisor *= 10;
        i++;
    } while (i < digits);

    if (square % divisor == num)
        printf("%d is an Automorphic Number\n", num);
    else
        printf("%d is Not an Automorphic Number\n", num);

    return 0;
}
// Method 3 - do-while Loop  Body runs first then condition is checked. Works same as while loop here. Completes all 3 loop types for this problem. Good to practice do-while with digit counting and divisor building logic.

// Method 4: Using Function
#include <stdio.h>
int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num /= 10;
    }
    return count;
}
int isAutomorphic(int num) {
    int square = num * num;
    int digits = countDigits(num);
    int divisor = 1;
    for (int i = 0; i < digits; i++)
        divisor *= 10;
    return square % divisor == num;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isAutomorphic(num))
        printf("%d is an Automorphic Number\n", num);
    else
        printf("%d is Not an Automorphic Number\n", num);

    return 0;
}
// Method 4 - Function  Logic is split into countDigits() and isAutomorphic() functions. countDigits() counts how many digits num has. isAutomorphic() checks if square ends with num. Main just takes input and prints. Clean and reusable.

// Method 5: Using Recursion
#include <stdio.h>
int countDigits(int num) {
    if (num == 0) return 0;
    return 1 + countDigits(num / 10);
}
int buildDivisor(int digits) {
    if (digits == 0) return 1;
    return 10 * buildDivisor(digits - 1);
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int square = num * num;
    int digits = countDigits(num);
    int divisor = buildDivisor(digits);

    if (square % divisor == num)
        printf("%d is an Automorphic Number\n", num);
    else
        printf("%d is Not an Automorphic Number\n", num);

    return 0;
}
// Method 5 - Recursion  Two recursive functions are used. countDigits() counts digits by dividing num recursively. buildDivisor() builds 10^digits by multiplying 10 recursively. Good practice using recursion for math building blocks.

// Method 6: Using String
#include <stdio.h>
#include <string.h>
#include <stdio.h>
int main() {
    int num, square;
    char numStr[20], squareStr[20];

    printf("Enter a number: ");
    scanf("%d", &num);

    square = num * num;

    // convert both to strings
    sprintf(numStr, "%d", num);
    sprintf(squareStr, "%d", square);

    int numLen = strlen(numStr);
    int squareLen = strlen(squareStr);

    // check if squareStr ends with numStr
    int isAutomorphic = (strcmp(squareStr + squareLen - numLen, numStr) == 0);

    if (isAutomorphic)
        printf("%d is an Automorphic Number\n", num);
    else
        printf("%d is Not an Automorphic Number\n", num);

    return 0;
}
// Method 6 - String  We convert num and square to strings using sprintf(). Then check if the end of squareStr matches numStr using strcmp(). squareStr + squareLen - numLen points to the last numLen characters of squareStr.

// Method 7: Using pow() Function
#include <stdio.h>
#include <math.h>
int main() {
    int num, square, digits = 0;
    int temp;

    printf("Enter a number: ");
    scanf("%d", &num);

    square = num * num;
    temp = num;

    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    // use pow() to build divisor
    int divisor = (int)pow(10, digits);

    if (square % divisor == num)
        printf("%d is an Automorphic Number\n", num);
    else
        printf("%d is Not an Automorphic Number\n", num);

    return 0;
}
// Method 7 - pow()  Instead of building divisor using a loop we use pow(10, digits) from math.h directly. We cast the result to int since pow() returns double. Cleaner and shorter way to get 10 raised to digit count.

// Method 8: Using Ternary Operator
#include <stdio.h>
int isAutomorphic(int num) {
    int sq = num * num, d = 0, div = 1, t = num;
    while (t != 0) { d++; t /= 10; }
    for (int i = 0; i < d; i++) div *= 10;
    return sq % div == num;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // condition ? true : false
    isAutomorphic(num)
        ? printf("%d is an Automorphic Number\n", num)
        : printf("%d is Not an Automorphic Number\n", num);

    return 0;
}
// Method 8 - Ternary Operator  We call isAutomorphic() inside a ternary condition directly. If it returns 1 print yes else print no. All output handled in one clean single statement. Compact version combining function and ternary.

// Method 9: Using switch Statement
#include <stdio.h>
int isAutomorphic(int num) {
    int sq = num * num, d = 0, div = 1, t = num;
    while (t != 0) { d++; t /= 10; }
    for (int i = 0; i < d; i++) div *= 10;
    return sq % div == num;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // isAutomorphic() returns 1 if true and 0 if false
    switch (isAutomorphic(num)) {
        case 1:
            printf("%d is an Automorphic Number\n", num);
            break;
        case 0:
            printf("%d is Not an Automorphic Number\n", num);
            break;
    }

    return 0;
}
// Method 9 - Switch Case  isAutomorphic() returns 1 for automorphic and 0 for not automorphic. Switch works on these values. Case 1 means automorphic and case 0 means not. Good practice combining function with switch.

// Method 10: Print Automorphic Numbers in a Given Range
#include <stdio.h>
int isAutomorphic(int num) {
    int sq = num * num, d = 0, div = 1, t = num;
    while (t != 0) { d++; t /= 10; }
    for (int i = 0; i < d; i++) div *= 10;
    return sq % div == num;
}
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Automorphic numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++)
        if (isAutomorphic(i))
            printf("%d ", i);
    printf("\n");

    return 0;
}
// Method 10 - Range  We check every number in the given range and print it if it is automorphic. isAutomorphic() is reused cleanly for each number. Known automorphic numbers are 0 1 5 6 25 76 376 625 so test with a wide range.

// Method 11: Using Array to Store Automorphic Numbers
#include <stdio.h>
int isAutomorphic(int num) {
    int sq = num * num, d = 0, div = 1, t = num;
    while (t != 0) { d++; t /= 10; }
    for (int i = 0; i < d; i++) div *= 10;
    return sq % div == num;
}
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    int result[1000], count = 0;

    for (int i = start; i <= end; i++)
        if (isAutomorphic(i))
            result[count++] = i;

    printf("Automorphic numbers between %d and %d are: ", start, end);
    for (int i = 0; i < count; i++)
        printf("%d ", result[i]);
    printf("\nTotal automorphic numbers found: %d\n", count);

    return 0;
}
// Method 11 - Array  We store all automorphic numbers found in the range into an array and print them with a total count at the end. Useful when you need to process or use the automorphic numbers further in the program.

// Method 12: Using Macro
#include <stdio.h>

int autoHelper(int n) {
    int sq = n * n, d = 0, div = 1, t = n;
    while (t != 0) { d++; t /= 10; }
    for (int i = 0; i < d; i++) div *= 10;
    return sq % div == n;
}

#define IS_AUTOMORPHIC(n) autoHelper(n)

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (IS_AUTOMORPHIC(num))
        printf("%d is an Automorphic Number\n", num);
    else
        printf("%d is Not an Automorphic Number\n", num);

    return 0;
}
// Method 12 - Macro  We define IS_AUTOMORPHIC as a macro that calls autoHelper(). Wherever IS_AUTOMORPHIC(n) is written it gets replaced by autoHelper(n). Good to know how macros wrap function calls cleanly in C.

// Method 13: Using long long for Large Numbers
#include <stdio.h>
int main() {
    long long num, square, temp, digits = 0, divisor = 1;

    printf("Enter a number: ");
    scanf("%lld", &num);

    square = num * num;
    temp = num;

    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    for (int i = 0; i < digits; i++)
        divisor *= 10;

    if (square % divisor == num)
        printf("%lld is an Automorphic Number\n", num);
    else
        printf("%lld is Not an Automorphic Number\n", num);

    return 0;
}
// Method 13 - Long Long  Normal int overflows for large numbers when squaring. We use long long which holds much larger values. This handles bigger automorphic numbers like 376 whose square is 141376 and 5765625 whose square ends in 5765625.
