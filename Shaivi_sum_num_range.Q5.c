// Program to find the Sum of numbers in a given range in C

// Method 1: Using for Loop (Brute Force)
#include <stdio.h>
int main() {
    int start, end, sum = 0;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    for (int i = start; i <= end; i++) {
        sum = sum + i;
    }

    printf("Sum of numbers from %d to %d = %d\n", start, end, sum);

    return 0;
}
// Method 1 - Simple for Loop  We run the loop from start to end and keep adding each number to sum. Very easy to understand. Most basic and straightforward way to solve this problem.

// Method 2: Using while Loop
#include <stdio.h>
int main() {
    int start, end, sum = 0;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    int i = start;
    while (i <= end) {
        sum += i;
        i++;
    }

    printf("Sum of numbers from %d to %d = %d\n", start, end, sum);

    return 0;
}
// Method 2 - While Loop  Same logic as method 1 but using a while loop. We initialize i before the loop and increment it inside. Good practice to learn while loop with range problems.

// Method 3: Using do-while Loop
#include <stdio.h>
int main() {
    int start, end, sum = 0;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    int i = start;
    do {
        sum += i;
        i++;
    } while (i <= end);

    printf("Sum of numbers from %d to %d = %d\n", start, end, sum);

    return 0;
}
// Method 3 - do-while Loop  Body runs first then condition is checked. Works the same as while loop here. Completes all 3 loop types. Note: gives wrong result if start is greater than end.

// Method 4: Using Mathematical Formula
#include <stdio.h>
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    // Formula: sum of 1 to end minus sum of 1 to (start-1)
    int sum = (end * (end + 1) / 2) - ((start - 1) * start / 2);

    printf("Sum of numbers from %d to %d = %d\n", start, end, sum);

    return 0;
}
// Method 4 - Formula  We use n*(n+1)/2 twice. First get sum from 1 to end then subtract sum from 1 to (start-1). What remains is the sum of the range. No loop needed at all.

// Method 5: Using Function
#include <stdio.h>
int rangeSum(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++)
        sum += i;
    return sum;
}
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Sum of numbers from %d to %d = %d\n", start, end, rangeSum(start, end));

    return 0;
}
// Method 5 - Function  The loop logic is placed inside a separate function rangeSum() which takes start and end as parameters. Main just handles input and output. Clean and reusable code.

// Method 6: Using Recursion
#include <stdio.h>
int sumRecursive(int start, int end) {
    if (start > end)
        return 0;
    return start + sumRecursive(start + 1, end);
}
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Sum of numbers from %d to %d = %d\n", start, end, sumRecursive(start, end));

    return 0;
}
// Method 6 - Recursion  The function adds start to the result of calling itself with start+1. It keeps going until start is greater than end then returns 0. Good for learning recursion logic.

// Method 7: Using Array
#include <stdio.h>
int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);

    int size = end - start + 1;
    int arr[size];

    for (int i = 0; i < size; i++)
        arr[i] = start + i;

    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];

    printf("Sum of numbers from %d to %d = %d\n", start, end, sum);

    return 0;
}
// Method 7 - Array  We calculate the size as end-start+1 and store all numbers of the range in an array. Then add them in a second loop. Good for practising arrays with range logic.
