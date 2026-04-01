// Sum of N Natural Numbers

// Method 1: Using for Loop (Brute Force)
#include <stdio.h>
int main() {
    int n, sum = 0;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        sum = sum + i;
    }

    printf("Sum of %d natural numbers = %d\n", n, sum);

    return 0;
}
// Method 1 - Simple for Loop  We start sum at 0 and keep adding each number from 1 to n. The loop runs n times and adds i each time. Most basic and easy to understand method.

// Method 2: Using while Loop
#include <stdio.h>
int main() {
    int n, sum = 0, i = 1;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    while (i <= n) {
        sum += i;
        i++;
    }

    printf("Sum of %d natural numbers = %d\n", n, sum);

    return 0;
}
// Method 2 - While Loop  Same as method 1 but with a while loop. We initialize i before the loop and increment it inside. Good practice to understand how while loop works.

// Method 3: Using do-while Loop
#include <stdio.h>
int main() {
    int n, sum = 0, i = 1;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    do {
        sum += i;
        i++;
    } while (i <= n);

    printf("Sum of %d natural numbers = %d\n", n, sum);

    return 0;
}
// Method 3 - do-while Loop  The body runs first then condition is checked. So it always executes at least once. Completes all 3 loop types in C - for, while and do-while.

// Method 4: Using Mathematical Formula
#include <stdio.h>
int main() {
    int n;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    // Formula: sum = n * (n + 1) / 2
    int sum = n * (n + 1) / 2;

    printf("Sum of %d natural numbers = %d\n", n, sum);

    return 0;
}
// Method 4 - Formula  No loop at all. The formula n*(n+1)/2 gives the answer in one line directly. This is the most efficient method. Very important formula to remember always.

// Method 5: Using Function
#include <stdio.h>
int findSum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i;
    return sum;
}
int main() {
    int n;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    printf("Sum of %d natural numbers = %d\n", n, findSum(n));

    return 0;
}
// Method 5 - Function  The sum logic is written in a separate function findSum() and called from main. This makes code clean and reusable. A good habit for writing organized programs.

// Method 6: Using Recursion
#include <stdio.h>
int sumRecursive(int n) {
    if (n == 0)
        return 0;
    return n + sumRecursive(n - 1);
}
int main() {
    int n;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    printf("Sum of %d natural numbers = %d\n", n, sumRecursive(n));

    return 0;
}
// Method 6 - Recursion  The function calls itself with n-1 each time. When n reaches 0 it stops and returns 0. Then adds all values on the way back. Good for learning recursion concept.

// Method 7: Using Array
#include <stdio.h>
int main() {
    int n;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    printf("Sum of %d natural numbers = %d\n", n, sum);

    return 0;
}
// Method 7 - Array  Numbers 1 to n are stored in an array first then added in a second loop. Not the most efficient way but great for practising arrays and loops together in C.
