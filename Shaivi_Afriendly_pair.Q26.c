```c
// C Program to Check if the Given Two Numbers are Friendly Pair or Not

// Method 1: Using for Loop (Brute Force)
#include <stdio.h>
int main() {
    int a, b, sumA = 0, sumB = 0;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    // find sum of proper divisors of a
    for (int i = 1; i <= a; i++)
        if (a % i == 0)
            sumA += i;

    // find sum of proper divisors of b
    for (int i = 1; i <= b; i++)
        if (b % i == 0)
            sumB += i;

    // friendly pair condition: sumA/a == sumB/b
    // cross multiply to avoid division: sumA * b == sumB * a
    if (sumA * b == sumB * a)
        printf("(%d, %d) are a Friendly Pair\n", a, b);
    else
        printf("(%d, %d) are Not a Friendly Pair\n", a, b);

    return 0;
}
// Method 1 - For Loop  We find the sum of all divisors of both numbers including themselves. Two numbers form a friendly pair if their abundancy ratio is equal meaning sumA/a == sumB/b. We cross multiply to avoid float division.

// Method 2: Using while Loop
#include <stdio.h>
int main() {
    int a, b, sumA = 0, sumB = 0;
    int i = 1;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    // sum of divisors of a
    while (i <= a) {
        if (a % i == 0)
            sumA += i;
        i++;
    }

    i = 1;

    // sum of divisors of b
    while (i <= b) {
        if (b % i == 0)
            sumB += i;
        i++;
    }

    if (sumA * b == sumB * a)
        printf("(%d, %d) are a Friendly Pair\n", a, b);
    else
        printf("(%d, %d) are Not a Friendly Pair\n", a, b);

    return 0;
}
// Method 2 - While Loop  Same logic as method 1 but using while loops for both divisor sums. We reset i to 1 before the second loop. Good practice to write the same friendly pair logic using different loop types.

// Method 3: Using do-while Loop
#include <stdio.h>
int main() {
    int a, b, sumA = 0, sumB = 0;
    int i = 1;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    // sum of divisors of a using do-while
    do {
        if (a % i == 0)
            sumA += i;
        i++;
    } while (i <= a);

    i = 1;

    // sum of divisors of b using do-while
    do {
        if (b % i == 0)
            sumB += i;
        i++;
    } while (i <= b);

    if (sumA * b == sumB * a)
        printf("(%d, %d) are a Friendly Pair\n", a, b);
    else
        printf("(%d, %d) are Not a Friendly Pair\n", a, b);

    return 0;
}
// Method 3 - do-while Loop  Body runs first then condition is checked. Works same as while loop here. Completes all 3 loop types for this problem. Good to practice do-while with divisor sum calculation for both numbers.

// Method 4: Using Square Root Optimization
#include <stdio.h>
#include <math.h>
int main() {
    int a, b;
    long long sumA = 0, sumB = 0;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    // optimized divisor sum using sqrt
    for (int i = 1; i <= sqrt(a); i++) {
        if (a % i == 0) {
            sumA += i;
            if (i != a / i)
                sumA += a / i;
        }
    }

    for (int i = 1; i <= sqrt(b); i++) {
        if (b % i == 0) {
            sumB += i;
            if (i != b / i)
                sumB += b / i;
        }
    }

    if (sumA * b == sumB * a)
        printf("(%d, %d) are a Friendly Pair\n", a, b);
    else
        printf("(%d, %d) are Not a Friendly Pair\n", a, b);

    return 0;
}
// Method 4 - Square Root  Divisors come in pairs. If i divides n then n/i is also a divisor. We check only up to sqrt and add both at once. long long is used to prevent overflow in cross multiplication. Much faster method.

// Method 5: Using Function
#include <stdio.h>
long long divisorSum(int num) {
    long long sum = 0;
    for (int i = 1; i <= num; i++)
        if (num % i == 0)
            sum += i;
    return sum;
}
int isFriendlyPair(int a, int b) {
    return divisorSum(a) * b == divisorSum(b) * a;
}
int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    if (isFriendlyPair(a, b))
        printf("(%d, %d) are a Friendly Pair\n", a, b);
    else
        printf("(%d, %d) are Not a Friendly Pair\n", a, b);

    return 0;
}
// Method 5 - Function  Logic is split into divisorSum() and isFriendlyPair() functions. divisorSum() finds total divisor sum. isFriendlyPair() checks the abundancy ratio equality. Main just takes input and prints. Clean and reusable.

// Method 6: Using Recursion
#include <stdio.h>
long long divisorSum(int num, int i) {
    if (i > num) return 0;
    if (num % i == 0) return i + divisorSum(num, i + 1);
    return divisorSum(num, i + 1);
}
int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    long long sumA = divisorSum(a, 1);
    long long sumB = divisorSum(b, 1);

    if (sumA * b == sumB * a)
        printf("(%d, %d) are a Friendly Pair\n", a, b);
    else
        printf("(%d, %d) are Not a Friendly Pair\n", a, b);

    return 0;
}
// Method 6 - Recursion  divisorSum() checks if i divides num and adds it then calls itself with i+1. When i exceeds num it returns 0. We call it separately for both a and b. Good practice using recursion for divisor sums.

// Method 7: Using GCD to Simplify Ratio
#include <stdio.h>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
long long divisorSum(int num) {
    long long sum = 0;
    for (int i = 1; i <= num; i++)
        if (num % i == 0)
            sum += i;
    return sum;
}
int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    long long sumA = divisorSum(a);
    long long sumB = divisorSum(b);

    // simplify ratios sumA/a and sumB/b using GCD
    int g1 = gcd(sumA, a);
    int g2 = gcd(sumB, b);

    long long ratioA_num = sumA / g1, ratioA_den = a / g1;
    long long ratioB_num = sumB / g2, ratioB_den = b / g2;

    printf("Abundancy ratio of %d = %lld/%lld\n", a, ratioA_num, ratioA_den);
    printf("Abundancy ratio of %d = %lld/%lld\n", b, ratioB_num, ratioB_den);

    if (ratioA_num == ratioB_num && ratioA_den == ratioB_den)
        printf("(%d, %d) are a Friendly Pair\n", a, b);
    else
        printf("(%d, %d) are Not a Friendly Pair\n", a, b);

    return 0;
}
// Method 7 - GCD Ratio  We simplify the abundancy ratio sumA/a and sumB/b using GCD. Then compare numerators and denominators separately. This shows the exact ratio clearly and is more mathematically correct than cross multiplying.

// Method 8: Using Ternary Operator
#include <stdio.h>
long long divSum(int n) {
    long long s = 0;
    for (int i = 1; i <= n; i++)
        if (n % i == 0) s += i;
    return s;
}
int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    // condition ? true : false
    (divSum(a) * b == divSum(b) * a)
        ? printf("(%d, %d) are a Friendly Pair\n", a, b)
        : printf("(%d, %d) are Not a Friendly Pair\n", a, b);

    return 0;
}
// Method 8 - Ternary Operator  We call divSum() for both numbers inside the ternary condition directly. If the cross products are equal print yes else print no. All output handled in one clean single statement. Compact version.

// Method 9: Using switch Statement
#include <stdio.h>
long long divSum(int n) {
    long long s = 0;
    for (int i = 1; i <= n; i++)
        if (n % i == 0) s += i;
    return s;
}
int isFriendly(int a, int b) {
    return divSum(a) * b == divSum(b) * a;
}
int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    // isFriendly() returns 1 if true and 0 if false
    switch (isFriendly(a, b)) {
        case 1:
            printf("(%d, %d) are a Friendly Pair\n", a, b);
            break;
        case 0:
            printf("(%d, %d) are Not a Friendly Pair\n", a, b);
            break;
    }

    return 0;
}
// Method 9 - Switch Case  isFriendly() returns 1 for friendly pair and 0 for not friendly. Switch works on these values. Case 1 means friendly pair and case 0 means not. Good practice combining function with switch statement.

// Method 10: Checking Multiple Pairs
#include <stdio.h>
long long divSum(int n) {
    long long s = 0;
    for (int i = 1; i <= n; i++)
        if (n % i == 0) s += i;
    return s;
}
int main() {
    int t;

    printf("Enter number of pairs to check: ");
    scanf("%d", &t);

    while (t--) {
        int a, b;
        printf("Enter pair: ");
        scanf("%d %d", &a, &b);

        if (divSum(a) * b == divSum(b) * a)
            printf("(%d, %d) are a Friendly Pair\n", a, b);
        else
            printf("(%d, %d) are Not a Friendly Pair\n", a, b);
    }

    return 0;
}
// Method 10 - Multiple Pairs  We take number of test cases t and check each pair one by one. Same logic is applied for each pair. Useful when you need to check many pairs at once. Good for competitive programming style input.

// Method 11: Printing Detailed Information
#include <stdio.h>
long long divSum(int n) {
    long long s = 0;
    for (int i = 1; i <= n; i++)
        if (n % i == 0) s += i;
    return s;
}
int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    long long sumA = divSum(a);
    long long sumB = divSum(b);

    printf("Sum of divisors of %d = %lld\n", a, sumA);
    printf("Sum of divisors of %d = %lld\n", b, sumB);
    printf("Abundancy ratio of %d = %lld/%d\n", a, sumA, a);
    printf("Abundancy ratio of %d = %lld/%d\n", b, sumB, b);

    if (sumA * b == sumB * a)
        printf("Ratios are equal. (%d, %d) are a Friendly Pair\n", a, b);
    else
        printf("Ratios are not equal. (%d, %d) are Not a Friendly Pair\n", a, b);

    return 0;
}
// Method 11 - Detailed Output  We print the divisor sums and abundancy ratios of both numbers before the final verdict. This makes the output more informative and educational showing exactly why the pair is or is not friendly.

// Method 12: Using Array to Store Divisors
#include <stdio.h>
int main() {
    int a, b;
    long long sumA = 0, sumB = 0;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    int divA[a], divB[b];
    int cA = 0, cB = 0;

    for (int i = 1; i <= a; i++)
        if (a % i == 0) { divA[cA++] = i; sumA += i; }

    for (int i = 1; i <= b; i++)
        if (b % i == 0) { divB[cB++] = i; sumB += i; }

    printf("Divisors of %d: ", a);
    for (int i = 0; i < cA; i++) printf("%d ", divA[i]);
    printf("\nDivisors of %d: ", b);
    for (int i = 0; i < cB; i++) printf("%d ", divB[i]);
    printf("\n");

    if (sumA * b == sumB * a)
        printf("(%d, %d) are a Friendly Pair\n", a, b);
    else
        printf("(%d, %d) are Not a Friendly Pair\n", a, b);

    return 0;
}
// Method 12 - Array  We store all divisors of both numbers in separate arrays and print them. Sums are calculated while storing. This gives full visibility into which divisors were found for each number before the final verdict.

// Method 13: Using Macro
#include <stdio.h>

long long dsHelper(int n) {
    long long s = 0;
    for (int i = 1; i <= n; i++)
        if (n % i == 0) s += i;
    return s;
}

#define IS_FRIENDLY_PAIR(a, b) (dsHelper(a) * (b) == dsHelper(b) * (a))

int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    if (IS_FRIENDLY_PAIR(a, b))
        printf("(%d, %d) are a Friendly Pair\n", a, b);
    else
        printf("(%d, %d) are Not a Friendly Pair\n", a, b);

    return 0;
}
// Method 13 - Macro  We define IS_FRIENDLY_PAIR as a macro that checks the abundancy ratio equality directly. Wherever IS_FRIENDLY_PAIR(a,b) is written it gets replaced by the full expression. Good to know how macros work in C.
```
