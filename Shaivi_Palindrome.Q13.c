// Palindrome Program in C

// Method 1: Using while Loop (Brute Force)
#include <stdio.h>
int main() {
    int num, original, reversed = 0, remainder;

    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;

    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num = num / 10;
    }

    if (original == reversed)
        printf("%d is a Palindrome\n", original);
    else
        printf("%d is Not a Palindrome\n", original);

    return 0;
}
// Method 1 - While Loop  We reverse the number using %10 and /10 and store it in reversed. Then compare original with reversed. If both are equal the number reads same from both sides so it is palindrome.

// Method 2: Using for Loop
#include <stdio.h>
int main() {
    int num, original, reversed = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;

    for (; num != 0; num /= 10)
        reversed = reversed * 10 + (num % 10);

    if (original == reversed)
        printf("%d is a Palindrome\n", original);
    else
        printf("%d is Not a Palindrome\n", original);

    return 0;
}
// Method 2 - For Loop  Same logic as method 1 but written as a for loop. Initialization is empty since variables are already set. num /= 10 removes last digit each time. Compact and clean version.

// Method 3: Using do-while Loop
#include <stdio.h>
int main() {
    int num, original, reversed = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;

    do {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    } while (num != 0);

    if (original == reversed)
        printf("%d is a Palindrome\n", original);
    else
        printf("%d is Not a Palindrome\n", original);

    return 0;
}
// Method 3 - do-while Loop  Body runs first then condition is checked. Works same as while loop here. Completes all 3 loop types for this problem. Good to practice do-while with number reversal logic.

// Method 4: Using Function
#include <stdio.h>
int isPalindrome(int num) {
    int original = num, reversed = 0;
    while (num != 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return original == reversed;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPalindrome(num))
        printf("%d is a Palindrome\n", num);
    else
        printf("%d is Not a Palindrome\n", num);

    return 0;
}
// Method 4 - Function  The palindrome logic is placed in a separate function isPalindrome() that returns 1 if true and 0 if false. Main just takes input and prints. Clean reusable and well organized code.

// Method 5: Using Recursion
#include <stdio.h>
int reverseNum(int num, int rev) {
    if (num == 0)
        return rev;
    return reverseNum(num / 10, rev * 10 + (num % 10));
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int reversed = reverseNum(num, 0);

    if (num == reversed)
        printf("%d is a Palindrome\n", num);
    else
        printf("%d is Not a Palindrome\n", num);

    return 0;
}
// Method 5 - Recursion  We use a recursive function to reverse the number. It passes the reversed value as a second argument and builds it up each call. When num is 0 the final reversed number is returned.

// Method 6: Using String
#include <stdio.h>
#include <string.h>
int main() {
    char numStr[20];

    printf("Enter a number: ");
    scanf("%s", numStr);

    int len = strlen(numStr);
    int isPalin = 1;

    for (int i = 0; i < len / 2; i++) {
        if (numStr[i] != numStr[len - 1 - i]) {
            isPalin = 0;
            break;
        }
    }

    if (isPalin)
        printf("%s is a Palindrome\n", numStr);
    else
        printf("%s is Not a Palindrome\n", numStr);

    return 0;
}
// Method 6 - String  We take the number as a string and compare characters from both ends moving towards the middle. If any pair does not match it is not a palindrome. Good for practicing string logic in C.

// Method 7: Using Array
#include <stdio.h>
int main() {
    int num, digits[20], count = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    int original = num;

    while (num != 0) {
        digits[count++] = num % 10;
        num /= 10;
    }

    // digits array has digits in reverse order already
    // rebuild original from array and compare
    int rebuilt = 0;
    for (int i = 0; i < count; i++)
        rebuilt = rebuilt * 10 + digits[i];

    if (original == rebuilt)
        printf("%d is a Palindrome\n", original);
    else
        printf("%d is Not a Palindrome\n", original);

    return 0;
}
// Method 7 - Array  We store digits in an array using %10 which gives digits in reverse order. Then rebuild the number from the array and compare with original. Good practice combining arrays with number logic.

// Method 8: Using Ternary Operator
#include <stdio.h>
int reverseNum(int num, int rev) {
    return (num == 0) ? rev : reverseNum(num / 10, rev * 10 + (num % 10));
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int reversed = reverseNum(num, 0);

    (num == reversed)
        ? printf("%d is a Palindrome\n", num)
        : printf("%d is Not a Palindrome\n", num);

    return 0;
}
// Method 8 - Ternary Operator  We use recursive reversal to get reversed number then use ternary to print result in one statement. Short and clean version combining recursion and ternary together.

// Method 9: Using Two Pointer on String
#include <stdio.h>
#include <string.h>
int main() {
    char numStr[20];

    printf("Enter a number: ");
    scanf("%s", numStr);

    int left = 0, right = strlen(numStr) - 1;
    int isPalin = 1;

    // two pointers moving from both ends towards middle
    while (left < right) {
        if (numStr[left] != numStr[right]) {
            isPalin = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalin)
        printf("%s is a Palindrome\n", numStr);
    else
        printf("%s is Not a Palindrome\n", numStr);

    return 0;
}
// Method 9 - Two Pointer  We use two pointers left and right starting from both ends of the string. Move them towards the middle comparing characters at each step. If mismatch found it is not a palindrome.

// Method 10: Using switch Statement
#include <stdio.h>
int isPalindrome(int num) {
    int original = num, reversed = 0;
    while (num != 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return original == reversed;
}
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // isPalindrome() returns 1 if true and 0 if false
    switch (isPalindrome(num)) {
        case 1:
            printf("%d is a Palindrome\n", num);
            break;
        case 0:
            printf("%d is Not a Palindrome\n", num);
            break;
    }

    return 0;
}
// Method 10 - Switch Case  isPalindrome() returns 1 for palindrome and 0 for not palindrome. Switch works on these values. Case 1 means palindrome and case 0 means not palindrome. Good practice combining function with switch.

// Method 11: Using Macro
#include <stdio.h>

int reverseHelper(int num) {
    int rev = 0;
    while (num != 0) {
        rev = rev * 10 + (num % 10);
        num /= 10;
    }
    return rev;
}

#define IS_PALINDROME(n) ((n) == reverseHelper(n))

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (IS_PALINDROME(num))
        printf("%d is a Palindrome\n", num);
    else
        printf("%d is Not a Palindrome\n", num);

    return 0;
}
// Method 11 - Macro  We define IS_PALINDROME as a macro that compares num with its reverse. Wherever IS_PALINDROME(n) is written it gets replaced by the full comparison. Good to know how macros work in C.

// Method 12: Using abs() for Negative Numbers
#include <stdio.h>
#include <stdlib.h>
int main() {
    int num, reversed = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    // negative numbers are never palindrome but we handle it cleanly
    int temp = abs(num);
    int original = temp;

    while (temp != 0) {
        reversed = reversed * 10 + (temp % 10);
        temp /= 10;
    }

    if (num < 0)
        printf("%d is Not a Palindrome\n", num);
    else if (original == reversed)
        printf("%d is a Palindrome\n", num);
    else
        printf("%d is Not a Palindrome\n", num);

    return 0;
}
// Method 12 - Negative Numbers  Negative numbers are never palindromes because of the minus sign. We handle this cleanly by checking sign first. abs() from stdlib.h removes the minus for safe processing.
