// C Program to Check a Number is Armstrong or Not

// Method 1: Using while Loop (Brute Force)
#include <stdio.h>
#include <math.h>
int main() {
    int num, original, sum = 0, remainder, digits = 0;
    int temp;

    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;
    temp = num;

    // count number of digits
    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    temp = num;

    // calculate sum of digits raised to power of digit count
    while (temp != 0) {
        remainder = temp % 10;
        sum += pow(remainder, digits);
        temp /= 10;
    }

    if (sum == original)
        printf("%d is an Armstrong Number\n", original);
    else
        printf("%d is Not an Armstrong Number\n", original);

    return 0;
}
// Method 1 - While Loop  We first count the number of digits. Then extract each digit using %10 raise it to the power of digit count and add to sum. If sum equals original number it is Armstrong.

// Method 2: Using for Loop
#include <stdio.h>
#include <math.h>
int main() {
    int num, original, sum = 0, digits = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;

    // count digits
    for (int temp = num; temp != 0; temp /= 10)
        digits++;

    // calculate armstrong sum
    for (int temp = num; temp != 0; temp /= 10)
        sum += pow(temp % 10, digits);

    if (sum == original)
        printf("%d is an Armstrong Number\n", original);
    else
        printf("%d is Not an Armstrong Number\n", original);

    return 0;
}
// Method 2 - For Loop  Same logic as method 1 but both loops are written as for loops. We use a temp variable to avoid modifying original num. Compact and clean way to write the same solution.

// Method 3: Using do-while Loop
#include <stdio.h>
#include <math.h>
int main() {
    int num, original, sum = 0, digits = 0;
    int temp;

    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;
    temp = num;

    // count digits using do-while
    do {
        digits++;
        temp /= 10;
    } while (temp != 0);

    temp = num;

    // calculate armstrong sum using do-while
    do {
        sum += pow(temp % 10, digits);
        temp /= 10;
    } while (temp != 0);

    if (sum == original)
        printf("%d is an Armstrong Number\n", original);
    else
        printf("%d is Not an Armstrong Number\n", original);

    return 0;
}
// Method 3 - do-while Loop  Body runs first then condition is checked. Works same as while loop here. Completes all 3 loop types for this problem. Good to practice do-while with digit extraction logic.

// Method 4: Using Function
#include <stdio.h>
#include <math.h>
int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num /= 10;
    }
    return count;
}
int isArmstrong(int num) {
    int digits = countDigits(num);
    int temp = num, sum = 0;
    while (temp != 0) {
        sum += pow(temp % 10, digits);
        temp /= 10;
    }
    return sum == num;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isArmstrong(num))
        printf("%d is an Armstrong Number\n", num);
    else
        printf("%d is Not an Armstrong Number\n", num);

    return 0;
}
// Method 4 - Function  Logic is split into two functions. countDigits() counts the digits and isArmstrong() checks the condition. Main just takes input and prints. Clean reusable and well organized code.

// Method 5: Using Recursion
#include <stdio.h>
#include <math.h>
int countDigits(int num) {
    if (num == 0) return 0;
    return 1 + countDigits(num / 10);
}
int armstrongSum(int num, int digits) {
    if (num == 0) return 0;
    return pow(num % 10, digits) + armstrongSum(num / 10, digits);
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int digits = countDigits(num);
    int sum = armstrongSum(num, digits);

    if (sum == num)
        printf("%d is an Armstrong Number\n", num);
    else
        printf("%d is Not an Armstrong Number\n", num);

    return 0;
}
// Method 5 - Recursion  Two recursive functions are used. countDigits() counts digits recursively and armstrongSum() calculates the sum recursively. Each calls itself with num/10 until num becomes 0.

// Method 6: Using String
#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    char numStr[20];
    int sum = 0;

    printf("Enter a number: ");
    scanf("%s", numStr);

    int digits = strlen(numStr);

    for (int i = 0; i < digits; i++)
        sum += pow(numStr[i] - '0', digits);

    int original = 0;
    for (int i = 0; i < digits; i++)
        original = original * 10 + (numStr[i] - '0');

    if (sum == original)
        printf("%s is an Armstrong Number\n", numStr);
    else
        printf("%s is Not an Armstrong Number\n", numStr);

    return 0;
}
// Method 6 - String  We take the number as a string. strlen() gives digit count directly. Each character is converted to digit by subtracting '0' then raised to power. No need to count digits separately.

// Method 7: Using Array
#include <stdio.h>
#include <math.h>
int main() {
    int num, digits[20], count = 0, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    int original = num, temp = num;

    // store each digit in array
    while (temp != 0) {
        digits[count++] = temp % 10;
        temp /= 10;
    }

    // raise each digit to power of count and sum
    for (int i = 0; i < count; i++)
        sum += pow(digits[i], count);

    if (sum == original)
        printf("%d is an Armstrong Number\n", original);
    else
        printf("%d is Not an Armstrong Number\n", original);

    return 0;
}
// Method 7 - Array  We store all digits in an array first then loop through it raising each digit to the power of count. Good for practicing arrays with math logic. Makes the two steps very clear and separate.

// Method 8: Using Ternary Operator
#include <stdio.h>
#include <math.h>
int countDigits(int n) {
    int c = 0;
    while (n != 0) { c++; n /= 10; }
    return c;
}
int armSum(int n, int d) {
    int s = 0, t = n;
    while (t != 0) { s += pow(t % 10, d); t /= 10; }
    return s;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // condition ? true : false
    (armSum(num, countDigits(num)) == num)
        ? printf("%d is an Armstrong Number\n", num)
        : printf("%d is Not an Armstrong Number\n", num);

    return 0;
}
// Method 8 - Ternary Operator  We call both helper functions inside the ternary condition directly. If the armstrong sum equals num print yes else print no. All output handled in one clean single statement.

// Method 9: Using switch Statement
#include <stdio.h>
#include <math.h>
int isArmstrong(int num) {
    int digits = 0, sum = 0, temp = num;
    while (temp != 0) { digits++; temp /= 10; }
    temp = num;
    while (temp != 0) { sum += pow(temp % 10, digits); temp /= 10; }
    return sum == num;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // isArmstrong() returns 1 if true and 0 if false
    switch (isArmstrong(num)) {
        case 1:
            printf("%d is an Armstrong Number\n", num);
            break;
        case 0:
            printf("%d is Not an Armstrong Number\n", num);
            break;
    }

    return 0;
}
// Method 9 - Switch Case  isArmstrong() returns 1 for armstrong and 0 for not armstrong. Switch works on these values. Case 1 means armstrong and case 0 means not armstrong. Good practice combining function with switch.

// Method 10: Using Macro
#include <stdio.h>
#include <math.h>

int digitCount(int n) {
    int c = 0;
    while (n != 0) { c++; n /= 10; }
    return c;
}
int armstrongCheck(int n) {
    int d = digitCount(n), s = 0, t = n;
    while (t != 0) { s += pow(t % 10, d); t /= 10; }
    return s == n;
}

#define IS_ARMSTRONG(n) armstrongCheck(n)

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (IS_ARMSTRONG(num))
        printf("%d is an Armstrong Number\n", num);
    else
        printf("%d is Not an Armstrong Number\n", num);

    return 0;
}
// Method 10 - Macro  We define IS_ARMSTRONG as a macro that calls armstrongCheck(). Wherever IS_ARMSTRONG(n) is written it gets replaced by the full function call. Good to know how macros wrap functions in C.

// Method 11: Without using pow() Function
#include <stdio.h>
int main() {
    int num, sum = 0, digits = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    int original = num, temp = num;

    // count digits
    while (temp != 0) { digits++; temp /= 10; }

    temp = num;

    // manually raise to power without pow()
    while (temp != 0) {
        int digit = temp % 10;
        int power = 1;
        for (int i = 0; i < digits; i++)
            power *= digit;
        sum += power;
        temp /= 10;
    }

    if (sum == original)
        printf("%d is an Armstrong Number\n", original);
    else
        printf("%d is Not an Armstrong Number\n", original);

    return 0;
}
// Method 11 - Without pow()  Instead of using pow() from math.h we manually multiply the digit by itself digits times using a small for loop. This avoids including math.h and avoids floating point issues with pow().
