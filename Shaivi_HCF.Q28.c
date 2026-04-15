// HCF Of Two Numbers | C Program
// Method 1 Using for loop (Brute Force)
#include <stdio.h>
int main() {
    int a, b, hcf = 1;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    for (int i = 1; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0)
            hcf = i;
    }

    printf("HCF = %d\n", hcf);
    return 0;
}
// We loop from 1 to the smaller number. Every time both a and b are divisible by i, we update hcf. After the loop ends, hcf holds the greatest such divisor. Simple to understand but not efficient for large numbers

// Method 2 Using while loop (Subtraction — Euclid)
#include <stdio.h>
int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    while (a != b) {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }

    printf("HCF = %d\n", a);
    return 0;
}
// Euclid's original subtraction method. Keep subtracting the smaller number from the larger one until both are equal. That equal value is the HCF. Works correctly but is slow when numbers are far apart.

// Method 3 Using Euclidean Algorithm (Modulo)
#include <stdio.h>
int main() {
    int a, b, temp;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    printf("HCF = %d\n", a);
    return 0;
}
// The fastest and most standard method. We replace a with b and b with a%b repeatedly until b becomes 0. When b is 0, a holds the HCF. This is the algorithm used in real-world programs and competitive coding.

// Method 4 Using Recursive Function
#include <stdio.h>

int hcf(int a, int b) {
    if (b == 0)
        return a;
    return hcf(b, a % b);
}

int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    printf("HCF = %d\n", hcf(a, b));
    return 0;
}
// Euclidean modulo logic written as a recursive function. Base case: if b is 0, return a. Otherwise call hcf(b, a%b) again. Clean and elegant. Very commonly asked in interviews to test recursion understanding.

// Method 5 Using do-while loop
#include <stdio.h>
int main() {
    int a, b, temp;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    do {
        temp = b;
        b = a % b;
        a = temp;
    } while (b != 0);

    printf("HCF = %d\n", a);
    return 0;
}
// Same Euclidean modulo method but using do-while instead of while. The body always executes at least once. Since we always have two valid positive integers, this is safe and produces the same correct result.

// Method 6 Using Ternary Operator (Recursive)
#include <stdio.h>

int hcf(int a, int b) {
    return b == 0 ? a : hcf(b, a % b);
}

int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    printf("HCF = %d\n", hcf(a, b));
    return 0;
}
// The full recursive function collapsed into a single return line using the ternary operator. If b is 0 return a, else recurse. Very compact. Good to write once you clearly understand the recursive version first

// Method 7 Using Non-recursive Function
#include <stdio.h>

int findHCF(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    printf("HCF = %d\n", findHCF(a, b));
    return 0;
}

// Euclidean modulo logic placed inside a separate non-recursive function. Main only handles input and output. This is the cleanest and most reusable approach. Good coding practice to separate logic from I/O.

// Method 8 Using Temp Variable (Swap method)
#include <stdio.h>
int main() {
    int a, b, temp;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    while (a % b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }

    printf("HCF = %d\n", b);
    return 0;
}
// A variation of the Euclidean method where we check if a%b is 0 in the condition itself. We store a%b in temp, shift b to a and temp to b. When a%b becomes 0, b at that point is the HCF. Slightly different swap style.

// Method 9 Using Prime Factorization
#include <stdio.h>

int minVal(int x, int y) {
    return (x < y) ? x : y;
}

int main() {
    int a, b, hcf = 1;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    for (int i = 2; i <= minVal(a, b); i++) {
        while (a % i == 0 && b % i == 0) {
            hcf *= i;
            a /= i;
            b /= i;
        }
    }

    printf("HCF = %d\n", hcf);
    return 0;
}
// We find common prime factors of both numbers. For each prime i starting from 2, if both a and b are divisible by i, multiply hcf by i and divide both. Repeat until no more common primes remain. Good for understanding factorization.

// Method 10 Using Array of Divisors
#include <stdio.h>
int main() {
    int a, b, hcf = 1;
    int smaller = (a < b) ? a : b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    smaller = (a < b) ? a : b;

    for (int i = smaller; i >= 1; i--) {
        if (a % i == 0 && b % i == 0) {
            hcf = i;
            break;
        }
    }

    printf("HCF = %d\n", hcf);
    return 0;
}

// Instead of going upward from 1, we loop downward from the smaller number. The very first i that divides both a and b is immediately the HCF. We break out early. Fewer iterations on average compared to the upward brute force approach.

// Method 11 Using __gcd() Built-in Function
#include <stdio.h>
#include <algorithm>
int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    printf("HCF = %d\n", __gcd(a, b));
    return 0;
}
// C++ provides a built-in __gcd() function in <algorithm> that computes GCD directly. Works in competitive programming and quick solutions. Not available in pure C standard but supported by GCC compiler for both C and C++ files.

// Method 12 Using Bitwise AND (Power of 2 check)
#include <stdio.h>

int hcf(int a, int b) {
    if (a == b) return a;
    if (a == 0) return b;
    if (b == 0) return a;

    if (~a & 1) {
        if (b & 1)
            return hcf(a >> 1, b);
        else
            return hcf(a >> 1, b >> 1) << 1;
    }
    if (~b & 1)
        return hcf(a, b >> 1);

    return (a > b) ? hcf(a - b, b) : hcf(a, b - a);
}

int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    printf("HCF = %d\n", hcf(a, b));
    return 0;
}
// Binary GCD algorithm (Stein's algorithm). Uses bitwise right shift (>>) to halve even numbers and bitwise AND (&1) to check odd/even. Avoids division entirely. More efficient on hardware where division is expensive. Advanced topic — learn after basics.

//Method 12 Using Bitwise AND (Power of 2 check)
#include <stdio.h>

int hcf(int a, int b) {
    if (a == b) return a;
    if (a == 0) return b;
    if (b == 0) return a;

    if (~a & 1) {
        if (b & 1)
            return hcf(a >> 1, b);
        else
            return hcf(a >> 1, b >> 1) << 1;
    }
    if (~b & 1)
        return hcf(a, b >> 1);

    return (a > b) ? hcf(a - b, b) : hcf(a, b - a);
}

int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    printf("HCF = %d\n", hcf(a, b));
    return 0;
}
// Binary GCD algorithm (Stein's algorithm). Uses bitwise right shift (>>) to halve even numbers and bitwise AND (&1) to check odd/even. Avoids division entirely. More efficient on hardware where division is expensive. Advanced topic — learn after basics.

