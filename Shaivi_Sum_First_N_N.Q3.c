// Sum of First N Natural Numbers

// Method 1: Using a Loop (Brute Force)
#include <stdio.h>
int main() {
    int n, sum = 0;

    printf("Enter a positive number: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        sum = sum + i;
    }

    printf("Sum of first %d natural numbers = %d\n", n, sum);

    return 0;
}
// Method 1 - Simple for Loop  We start sum at 0 and add every number from 1 to n one by one. Easy to understand and works for any beginner. Most basic way to do it.

// Method 2: Using while Loop
#include <stdio.h>
int main() {
    int n, sum = 0, i = 1;

    printf("Enter a positive number: ");
    scanf("%d", &n);

    while (i <= n) {
        sum += i;
        i++;
    }

    printf("Sum of first %d natural numbers = %d\n", n, sum);

    return 0;
}
// Method 2 - While Loop  Same logic as method 1 but using a while loop instead. We manually write i++ to move forward. Good to know both for and while do the same job differently.

// Method 3: Using Mathematical Formula
#include <stdio.h>
int main() {
    int n;

    printf("Enter a positive number: ");
    scanf("%d", &n);

    // Formula: sum = n * (n + 1) / 2
    int sum = n * (n + 1) / 2;

    printf("Sum of first %d natural numbers = %d\n", n, sum);

    return 0;
}
// Method 3 - Formula  No loop needed at all. The formula n*(n+1)/2 gives the answer directly in one step. This is the fastest and smartest method. Very useful to remember.

// Method 4: Using Recursion
#include <stdio.h>
int sumRecursive(int n) {
    if (n == 0)
        return 0;
    return n + sumRecursive(n - 1);
}
int main() {
    int n;

    printf("Enter a positive number: ");
    scanf("%d", &n);

    printf("Sum of first %d natural numbers = %d\n", n, sumRecursive(n));

    return 0;
}
// Method 4 - Recursion  The function calls itself with n-1 each time until n becomes 0. Then it adds all the values as it comes back. Good for understanding how recursion works.

// Method 5: Using Function (Non-Recursive)
#include <stdio.h>
int findSum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i;
    return sum;
}
int main() {
    int n;

    printf("Enter a positive number: ");
    scanf("%d", &n);

    printf("Sum of first %d natural numbers = %d\n", n, findSum(n));

    return 0;
}
// Method 5 - Function  The loop logic is moved into a separate function findSum(). Main just takes input and prints. This keeps the code clean and reusable. Good coding habit.

// Method 6: Using do-while Loop
#include <stdio.h>
int main() {
    int n, sum = 0, i = 1;

    printf("Enter a positive number: ");
    scanf("%d", &n);

    do {
        sum += i;
        i++;
    } while (i <= n);

    printf("Sum of first %d natural numbers = %d\n", n, sum);

    return 0;
}
// Method 6 - do-while Loop  Works like while loop but checks condition after running the body once. So it always runs at least one time. Useful to know all 3 loop types in C.

// Method 7: Using Array
#include <stdio.h>
int main() {
    int n;

    printf("Enter a positive number: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    printf("Sum of first %d natural numbers = %d\n", n, sum);

    return 0;
}
// Method 7 - Array  We first store all numbers 1 to n in an array then add them up in a second loop. Not the most efficient but helps practice working with arrays in C.
