// Find the Armstrong Numbers in a Given Range in C

// Method 1: Using Nested while Loop (Brute Force)
#include <stdio.h>
#include <math.h>
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Armstrong numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++) {
        int temp = i, sum = 0, digits = 0;

        // count digits
        while (temp != 0) {
            digits++;
            temp /= 10;
        }

        temp = i;

        // calculate armstrong sum
        while (temp != 0) {
            sum += pow(temp % 10, digits);
            temp /= 10;
        }

        if (sum == i)
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}
// Method 1 - Brute Force  For every number in range we count its digits then raise each digit to the power of digit count and add to sum. If sum equals the number itself it is an Armstrong number.

// Method 2: Using for Loop
#include <stdio.h>
#include <math.h>
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Armstrong numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++) {
        int sum = 0, digits = 0;

        for (int temp = i; temp != 0; temp /= 10)
            digits++;

        for (int temp = i; temp != 0; temp /= 10)
            sum += pow(temp % 10, digits);

        if (sum == i)
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}
// Method 2 - For Loop  Same logic as method 1 but all loops are written as for loops. Two inner for loops handle digit counting and sum calculation separately. Compact and clean way to write it.

// Method 3: Using while Loop with do-while
#include <stdio.h>
#include <math.h>
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Armstrong numbers between %d and %d are: ", start, end);
    int i = start;
    while (i <= end) {
        int temp = i, sum = 0, digits = 0;

        do {
            digits++;
            temp /= 10;
        } while (temp != 0);

        temp = i;

        do {
            sum += pow(temp % 10, digits);
            temp /= 10;
        } while (temp != 0);

        if (sum == i)
            printf("%d ", i);
        i++;
    }
    printf("\n");

    return 0;
}
// Method 3 - do-while  Outer loop is while and inner loops are do-while. Body of do-while runs first then condition is checked. Completes all 3 loop types together. Good practice mixing different loop types.

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
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Armstrong numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++)
        if (isArmstrong(i))
            printf("%d ", i);
    printf("\n");

    return 0;
}
// Method 4 - Function  Logic is split into countDigits() and isArmstrong() functions. Main loop just calls isArmstrong() for each number in range. Code is clean reusable and very easy to read and maintain.

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
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Armstrong numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++) {
        int digits = countDigits(i);
        int sum = armstrongSum(i, digits);
        if (sum == i)
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}
// Method 5 - Recursion  Two recursive functions handle digit counting and sum calculation. countDigits() adds 1 each call until num is 0. armstrongSum() raises each digit to power and adds recursively.

// Method 6: Using Array to Store and Print
#include <stdio.h>
#include <math.h>
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    int result[1000], count = 0;

    for (int i = start; i <= end; i++) {
        int temp = i, sum = 0, digits = 0;

        while (temp != 0) { digits++; temp /= 10; }
        temp = i;
        while (temp != 0) { sum += pow(temp % 10, digits); temp /= 10; }

        if (sum == i)
            result[count++] = i;
    }

    printf("Armstrong numbers between %d and %d are: ", start, end);
    for (int i = 0; i < count; i++)
        printf("%d ", result[i]);
    printf("\n");

    return 0;
}
// Method 6 - Array  We store all found Armstrong numbers in a result array and print them at the end. Useful when you need to use the Armstrong numbers later in the program for further processing.

// Method 7: Using String for Digit Extraction
#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Armstrong numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++) {
        char numStr[20];
        sprintf(numStr, "%d", i);
        int digits = strlen(numStr);
        int sum = 0;

        for (int j = 0; j < digits; j++)
            sum += pow(numStr[j] - '0', digits);

        if (sum == i)
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}
// Method 7 - String  We convert each number to string using sprintf(). strlen() gives digit count directly. Each character is converted to digit by subtracting '0' then raised to power. No manual digit counting needed.

// Method 8: Without using pow() Function
#include <stdio.h>
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Armstrong numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++) {
        int temp = i, sum = 0, digits = 0;

        while (temp != 0) { digits++; temp /= 10; }
        temp = i;

        while (temp != 0) {
            int digit = temp % 10;
            int power = 1;
            for (int j = 0; j < digits; j++)
                power *= digit;
            sum += power;
            temp /= 10;
        }

        if (sum == i)
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}
// Method 8 - Without pow()  Instead of pow() from math.h we manually multiply digit by itself digits times using a small for loop. Avoids math.h header entirely and also avoids floating point precision issues of pow().

// Method 9: Using Ternary Operator
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
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Armstrong numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++)
        isArmstrong(i) ? printf("%d ", i) : 0;
    printf("\n");

    return 0;
}
// Method 9 - Ternary Operator  We use ternary inside the loop. If isArmstrong() returns 1 we print the number else we do nothing using 0. Short and compact way to print results without writing a full if block.

// Method 10: Using Macro
#include <stdio.h>
#include <math.h>

int armCheck(int n) {
    int d = 0, s = 0, t = n;
    while (t != 0) { d++; t /= 10; }
    t = n;
    while (t != 0) { s += pow(t % 10, d); t /= 10; }
    return s == n;
}

#define IS_ARMSTRONG(n) armCheck(n)

int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Armstrong numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++)
        if (IS_ARMSTRONG(i))
            printf("%d ", i);
    printf("\n");

    return 0;
}
// Method 10 - Macro  We define IS_ARMSTRONG as a macro that calls armCheck(). Wherever IS_ARMSTRONG(n) is written it gets replaced by armCheck(n). Good to know how macros wrap function calls cleanly in C.

// Method 11: Using Count with Output Message
#include <stdio.h>
#include <math.h>
int main() {
    int start, end, found = 0;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Armstrong numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++) {
        int temp = i, sum = 0, digits = 0;

        while (temp != 0) { digits++; temp /= 10; }
        temp = i;
        while (temp != 0) { sum += pow(temp % 10, digits); temp /= 10; }

        if (sum == i) {
            printf("%d ", i);
            found++;
        }
    }

    if (found == 0)
        printf("None");
    printf("\nTotal Armstrong numbers found: %d\n", found);

    return 0;
}
// Method 11 - Count with Message  We use a found counter to track how many Armstrong numbers exist in range. If found is 0 we print None. At the end we also print the total count. More complete and user friendly output.
