// C Program to Reverse a Given Number

// Method 1: Using while Loop (Brute Force)
#include <stdio.h>
int main() {
    int num, reversed = 0, remainder;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num = num / 10;
    }

    printf("Reversed number = %d\n", reversed);

    return 0;
}
// Method 1 - While Loop  We extract the last digit using %10 and build the reversed number by multiplying reversed by 10 and adding the digit. Then remove last digit using /10. Repeat until num is 0.

// Method 2: Using for Loop
#include <stdio.h>
int main() {
    int num, reversed = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    for (; num != 0; num /= 10)
        reversed = reversed * 10 + (num % 10);

    printf("Reversed number = %d\n", reversed);

    return 0;
}
// Method 2 - For Loop  Same logic as method 1 but written as a for loop. Initialization is empty since reversed is already set. num /= 10 removes last digit each time. Compact and clean version.

// Method 3: Using do-while Loop
#include <stdio.h>
int main() {
    int num, reversed = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    do {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    } while (num != 0);

    printf("Reversed number = %d\n", reversed);

    return 0;
}
// Method 3 - do-while Loop  Body runs first then condition is checked. Works same as while loop here. Completes all 3 loop types for this problem. Good to know for single digit numbers it still works fine.

// Method 4: Using Function
#include <stdio.h>
int reverseNumber(int num) {
    int reversed = 0;
    while (num != 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return reversed;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Reversed number = %d\n", reverseNumber(num));

    return 0;
}
// Method 4 - Function  The reverse logic is placed in a separate function reverseNumber() that returns the result. Main just takes input and prints. Clean reusable and well organized code structure.

// Method 5: Using Recursion
#include <stdio.h>
int reverseRecursive(int num, int reversed) {
    if (num == 0)
        return reversed;
    return reverseRecursive(num / 10, reversed * 10 + (num % 10));
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Reversed number = %d\n", reverseRecursive(num, 0));

    return 0;
}
// Method 5 - Recursion  The function passes the reversed number as a second argument. Each call extracts the last digit and builds reversed. When num becomes 0 the final reversed number is returned.

// Method 6: Using String
#include <stdio.h>
#include <string.h>
int main() {
    char numStr[20];

    printf("Enter a number: ");
    scanf("%s", numStr);

    int len = strlen(numStr);
    // swap characters from both ends towards middle
    for (int i = 0; i < len / 2; i++) {
        char temp = numStr[i];
        numStr[i] = numStr[len - 1 - i];
        numStr[len - 1 - i] = temp;
    }

    printf("Reversed number = %s\n", numStr);

    return 0;
}
// Method 6 - String  We take the number as a string and swap characters from both ends moving towards the middle. No math needed at all. Good for practicing string manipulation and character swapping in C.

// Method 7: Using Array
#include <stdio.h>
int main() {
    int num, digits[20], count = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num != 0) {
        digits[count++] = num % 10;
        num /= 10;
    }

    printf("Reversed number = ");
    for (int i = 0; i < count; i++)
        printf("%d", digits[i]);
    printf("\n");

    return 0;
}
// Method 7 - Array  We extract digits one by one and store them in an array. Since %10 always gives the last digit the array naturally stores digits in reverse order. Then we just print the array.

// Method 8: Using Stack Logic
#include <stdio.h>
int main() {
    int num, stack[20], top = -1;

    printf("Enter a number: ");
    scanf("%d", &num);

    // push digits onto stack
    while (num != 0) {
        stack[++top] = num % 10;
        num /= 10;
    }

    // pop digits from stack to get reversed number
    printf("Reversed number = ");
    while (top >= 0)
        printf("%d", stack[top--]);
    printf("\n");

    return 0;
}
// Method 8 - Stack  We push each digit onto a stack array. Since stack follows Last In First Out order popping gives digits in reverse. A great way to understand stack concept using arrays in C.

// Method 9: Using Ternary Operator
#include <stdio.h>
int reverseNum(int num, int rev) {
    return (num == 0) ? rev : reverseNum(num / 10, rev * 10 + (num % 10));
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Reversed number = %d\n", reverseNum(num, 0));

    return 0;
}
// Method 9 - Ternary Operator  The recursive function is rewritten using ternary in a single line. If num is 0 return rev else recurse with updated values. Compact and clean version of method 5.

// Method 10: Using abs() for Negative Numbers
#include <stdio.h>
#include <stdlib.h>
int main() {
    int num, reversed = 0, isNegative = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    // handle negative numbers
    if (num < 0) {
        isNegative = 1;
        num = abs(num);
    }

    while (num != 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }

    if (isNegative)
        printf("Reversed number = -%d\n", reversed);
    else
        printf("Reversed number = %d\n", reversed);

    return 0;
}
// Method 10 - Negative Numbers  Normal methods fail for negative numbers because % gives negative remainder in C. We store the sign first using a flag then use abs() to process normally and add sign back at end.

// Method 11: Using Macro
#include <stdio.h>

int reverseHelper(int num) {
    int reversed = 0;
    while (num != 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return reversed;
}

#define REVERSE(n) reverseHelper(n)

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Reversed number = %d\n", REVERSE(num));

    return 0;
}
// Method 11 - Macro  We define REVERSE as a macro that calls the helper function. Wherever REVERSE(n) is written it gets replaced by reverseHelper(n). Good to know how macros wrap functions cleanly in C.
