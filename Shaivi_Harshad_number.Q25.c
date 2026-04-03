// C Program to Check Whether a Number is Harshad Number or Not

// Method 1: Using for Loop (Brute Force)
#include <stdio.h>
int main() {
    int num, sum = 0, temp;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    // calculate sum of digits using for loop
    for (; temp != 0; temp /= 10)
        sum += temp % 10;

    if (num % sum == 0)
        printf("%d is a Harshad Number\n", num);
    else
        printf("%d is Not a Harshad Number\n", num);

    return 0;
}
// Method 1 - For Loop  We extract each digit using %10 and add to sum using a for loop. If num is divisible by its digit sum it is a Harshad number. Example 18 has digit sum 1+8=9 and 18/9=2 so 18 is Harshad.

// Method 2: Using while Loop
#include <stdio.h>
int main() {
    int num, sum = 0, temp;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    while (temp != 0) {
        sum += temp % 10;
        temp /= 10;
    }

    if (num % sum == 0)
        printf("%d is a Harshad Number\n", num);
    else
        printf("%d is Not a Harshad Number\n", num);

    return 0;
}
// Method 2 - While Loop  Same logic as method 1 but using a while loop. We extract last digit using %10 add to sum then remove last digit using /10. We repeat until temp becomes 0. Most common and readable approach.

// Method 3: Using do-while Loop
#include <stdio.h>
int main() {
    int num, sum = 0, temp;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    do {
        sum += temp % 10;
        temp /= 10;
    } while (temp != 0);

    if (num % sum == 0)
        printf("%d is a Harshad Number\n", num);
    else
        printf("%d is Not a Harshad Number\n", num);

    return 0;
}
// Method 3 - do-while Loop  Body runs first then condition is checked. Works same as while loop here. Completes all 3 loop types for this problem. Good to practice do-while with digit sum extraction logic.

// Method 4: Using Function
#include <stdio.h>
int digitSum(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int isHarshad(int num) {
    return num % digitSum(num) == 0;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isHarshad(num))
        printf("%d is a Harshad Number\n", num);
    else
        printf("%d is Not a Harshad Number\n", num);

    return 0;
}
// Method 4 - Function  Logic is split into digitSum() and isHarshad() functions. digitSum() calculates the sum of digits. isHarshad() checks divisibility. Main just takes input and prints. Clean reusable and well organized code.

// Method 5: Using Recursion
#include <stdio.h>
int digitSum(int num) {
    if (num == 0) return 0;
    return (num % 10) + digitSum(num / 10);
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int sum = digitSum(num);

    if (num % sum == 0)
        printf("%d is a Harshad Number\n", num);
    else
        printf("%d is Not a Harshad Number\n", num);

    return 0;
}
// Method 5 - Recursion  digitSum() calls itself with num/10 each time and adds the last digit. When num becomes 0 it returns 0. Good practice for understanding how recursion replaces a digit extraction loop cleanly.

// Method 6: Using String
#include <stdio.h>
#include <string.h>
int main() {
    char numStr[20];
    int sum = 0;

    printf("Enter a number: ");
    scanf("%s", numStr);

    int len = strlen(numStr);

    for (int i = 0; i < len; i++)
        sum += numStr[i] - '0';

    int original = 0;
    for (int i = 0; i < len; i++)
        original = original * 10 + (numStr[i] - '0');

    if (original % sum == 0)
        printf("%s is a Harshad Number\n", numStr);
    else
        printf("%s is Not a Harshad Number\n", numStr);

    return 0;
}
// Method 6 - String  We take the number as a string. Each character is converted to digit by subtracting '0' then added to sum. We also rebuild the original number from the string to check divisibility at the end.

// Method 7: Using Array to Store Digits
#include <stdio.h>
int main() {
    int num, sum = 0, temp;
    int digits[20], count = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    // store each digit in array
    while (temp != 0) {
        digits[count++] = temp % 10;
        temp /= 10;
    }

    // sum all digits from array
    for (int i = 0; i < count; i++)
        sum += digits[i];

    if (num % sum == 0)
        printf("%d is a Harshad Number\n", num);
    else
        printf("%d is Not a Harshad Number\n", num);

    return 0;
}
// Method 7 - Array  We extract each digit using %10 and store in an array. Then loop through the array to calculate sum. Not the most efficient way but good practice combining arrays with digit extraction logic in C.

// Method 8: Using Ternary Operator
#include <stdio.h>
int digitSum(int n) {
    int s = 0;
    while (n != 0) { s += n % 10; n /= 10; }
    return s;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // condition ? true : false
    (num % digitSum(num) == 0)
        ? printf("%d is a Harshad Number\n", num)
        : printf("%d is Not a Harshad Number\n", num);

    return 0;
}
// Method 8 - Ternary Operator  We call digitSum() inside the ternary condition directly. If num is divisible by its digit sum print yes else print no. All output handled in one clean single statement. Compact and concise version.

// Method 9: Using switch Statement
#include <stdio.h>
int digitSum(int n) {
    int s = 0;
    while (n != 0) { s += n % 10; n /= 10; }
    return s;
}
int isHarshad(int num) {
    return num % digitSum(num) == 0;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // isHarshad() returns 1 if true and 0 if false
    switch (isHarshad(num)) {
        case 1:
            printf("%d is a Harshad Number\n", num);
            break;
        case 0:
            printf("%d is Not a Harshad Number\n", num);
            break;
    }

    return 0;
}
// Method 9 - Switch Case  isHarshad() returns 1 for Harshad and 0 for not Harshad. Switch works on these values. Case 1 means Harshad number and case 0 means not. Good practice combining function with switch statement.

// Method 10: Print Harshad Numbers in a Given Range
#include <stdio.h>
int digitSum(int n) {
    int s = 0;
    while (n != 0) { s += n % 10; n /= 10; }
    return s;
}
int isHarshad(int num) {
    return num % digitSum(num) == 0;
}
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Harshad numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++)
        if (i > 0 && isHarshad(i))
            printf("%d ", i);
    printf("\n");

    return 0;
}
// Method 10 - Range  We check every number in the given range and print if it is Harshad. We skip 0 since digit sum would be 0 causing division by zero. Common Harshad numbers include 1 2 3 4 5 6 7 8 9 10 12 18 20 21 24 27 30.

// Method 11: Using Array to Store Harshad Numbers in Range
#include <stdio.h>
int digitSum(int n) {
    int s = 0;
    while (n != 0) { s += n % 10; n /= 10; }
    return s;
}
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    int result[1000], count = 0;

    for (int i = start; i <= end; i++)
        if (i > 0 && i % digitSum(i) == 0)
            result[count++] = i;

    printf("Harshad numbers between %d and %d are: ", start, end);
    for (int i = 0; i < count; i++)
        printf("%d ", result[i]);
    printf("\nTotal Harshad numbers found: %d\n", count);

    return 0;
}
// Method 11 - Array with Count  We store all Harshad numbers found in the range in an array and also print the total count at the end. Useful when you need to use the Harshad numbers further in the program for processing.

// Method 12: Using Macro
#include <stdio.h>

int dsHelper(int n) {
    int s = 0;
    while (n != 0) { s += n % 10; n /= 10; }
    return s;
}

#define IS_HARSHAD(n) ((n) % dsHelper(n) == 0)

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (IS_HARSHAD(num))
        printf("%d is a Harshad Number\n", num);
    else
        printf("%d is Not a Harshad Number\n", num);

    return 0;
}
// Method 12 - Macro  We define IS_HARSHAD as a macro that computes digit sum and checks divisibility inline. Wherever IS_HARSHAD(n) is written it gets replaced by the full expression. Good to know how macros work in C.

// Method 13: Printing Digit Sum and Quotient
#include <stdio.h>
int main() {
    int num, sum = 0, temp;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;
    while (temp != 0) {
        sum += temp % 10;
        temp /= 10;
    }

    printf("Sum of digits of %d = %d\n", num, sum);

    if (num % sum == 0) {
        printf("%d / %d = %d\n", num, sum, num / sum);
        printf("%d is a Harshad Number\n", num);
    } else {
        printf("%d is not exactly divisible by %d\n", num, sum);
        printf("%d is Not a Harshad Number\n", num);
    }

    return 0;
}
// Method 13 - Detailed Output  We print the digit sum and the result of dividing num by sum before the final verdict. This makes the output more informative and educational. Good for understanding why a number is or is not Harshad.
