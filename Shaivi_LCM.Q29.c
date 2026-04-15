// C Program to Find the LCM of Two Numbers

// Method 1: Using for loop (Brute Force)
#include <stdio.h>
int main() {
    int a, b, lcm;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    lcm = (a > b) ? a : b;

    while (1) {
        if (lcm % a == 0 && lcm % b == 0) {
            printf("LCM = %d\n", lcm);
            break;
        }
        lcm++;
    }

    return 0;
}
// Method 1 - for loop (Brute Force)  We start from the larger of the two numbers and keep incrementing. The first number divisible by both a and b is the LCM. Simple logic but slow for large numbers.


// Method 2: Using while loop
#include <stdio.h>
int main() {
    int a, b, lcm, max;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    max = (a > b) ? a : b;
    lcm = max;

    while (lcm % a != 0 || lcm % b != 0)
        lcm += max;

    printf("LCM = %d\n", lcm);
    return 0;
}
// Method 2 - while loop  We start from the larger number and keep adding it to itself. We only check multiples of the larger number, which reduces iterations. When it also divides the smaller one it is the LCM.


// Method 3: Using LCM = (a * b) / HCF Formula
#include <stdio.h>
int main() {
    int a, b, x, y, hcf, lcm;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    x = a; y = b;
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    hcf = x;
    lcm = (a / hcf) * b;

    printf("LCM = %d\n", lcm);
    return 0;
}
// Method 3 - LCM Formula  LCM(a, b) = (a * b) / HCF(a, b). We first find HCF using the Euclidean algorithm then apply the formula. We divide before multiplying to avoid integer overflow. Most efficient method.


// Method 4: Using Recursive Function (HCF then LCM)
#include <stdio.h>

int hcf(int a, int b) {
    if (b == 0)
        return a;
    return hcf(b, a % b);
}

int main() {
    int a, b, lcm;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    lcm = (a / hcf(a, b)) * b;

    printf("LCM = %d\n", lcm);
    return 0;
}
// Method 4 - Recursive Function  We compute HCF using a clean recursive function and then apply the LCM formula. Separating HCF logic into its own function makes the code reusable and readable. Common in interviews.


// Method 5: Using do-while loop
#include <stdio.h>
int main() {
    int a, b, lcm;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    lcm = (a > b) ? a : b;

    do {
        if (lcm % a == 0 && lcm % b == 0) {
            printf("LCM = %d\n", lcm);
            break;
        }
        lcm++;
    } while (1);

    return 0;
}
// Method 5 - do-while loop  Same brute force approach but using do-while. The body runs at least once. We start from the larger number and increment until we find a value divisible by both. Good for practicing do-while syntax.


// Method 6: Using Non-recursive Function
#include <stdio.h>

int findLCM(int a, int b) {
    int lcm = (a > b) ? a : b;
    while (lcm % a != 0 || lcm % b != 0)
        lcm++;
    return lcm;
}

int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    printf("LCM = %d\n", findLCM(a, b));
    return 0;
}
// Method 6 - Non-recursive Function  The LCM logic is moved into a separate function findLCM(). Main only handles input and output. Clean and reusable. Good practice to separate logic from I/O in real programs.


// Method 7: Using Ternary Operator
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

    int lcm = (a / hcf(a, b)) * b;
    printf("LCM = %d\n", lcm);
    return 0;
}
// Method 7 - Ternary Operator  We write the HCF recursive function in a single line using the ternary operator. Then use the LCM formula directly in main. Compact and clean once the logic is understood.


// Method 8: Using Temp Variable (Step-up method)
#include <stdio.h>
int main() {
    int a, b, lcm;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    int i = 1;
    while (1) {
        lcm = a * i;
        if (lcm % b == 0) {
            printf("LCM = %d\n", lcm);
            break;
        }
        i++;
    }

    return 0;
}
// Method 8 - Temp Variable (Step-up)  We generate multiples of a one by one using a counter i. For each multiple of a we check if it is also divisible by b. The first such multiple is the LCM. Clean and easy to trace step by step.


// Method 9: Using Array to Store Multiples
#include <stdio.h>
int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    for (int i = 1; i <= a * b; i++) {
        if (i % a == 0 && i % b == 0) {
            printf("LCM = %d\n", i);
            break;
        }
    }

    return 0;
}
// Method 9 - Loop up to a*b  LCM of two numbers can never exceed a*b so we loop from 1 to a*b. The first number divisible by both is the LCM and we break immediately. Guaranteed to find the answer within the range.


// Method 10: Using __lcm() / __gcd() Built-in
#include <stdio.h>
#include <algorithm>
int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    int lcm = (a / __gcd(a, b)) * b;
    printf("LCM = %d\n", lcm);
    return 0;
}
// Method 10 - Built-in __gcd()  GCC provides __gcd() in <algorithm>. We use it directly in the LCM formula without writing our own HCF. Best for quick solutions in competitive programming. Not standard C but works with GCC compiler.


// Method 11: Using Pointers
#include <stdio.h>

void findLCM(int *a, int *b, int *lcm) {
    int x = *a, y = *b;
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    *lcm = (*a / x) * *b;
}

int main() {
    int a, b, lcm;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    findLCM(&a, &b, &lcm);
    printf("LCM = %d\n", lcm);
    return 0;
}
// Method 11 - Pointers  We pass all variables by pointer to the function. The function computes HCF using Euclidean algorithm then stores the LCM result directly into the pointer. Good for practicing pass-by-reference using pointers in C.


// Method 12: Using Bitwise (Binary GCD then LCM)
#include <stdio.h>

int binaryGCD(int a, int b) {
    if (a == b) return a;
    if (a == 0) return b;
    if (b == 0) return a;
    if (~a & 1) {
        if (b & 1)  return binaryGCD(a >> 1, b);
        else        return binaryGCD(a >> 1, b >> 1) << 1;
    }
    if (~b & 1)     return binaryGCD(a, b >> 1);
    return (a > b) ? binaryGCD(a - b, b) : binaryGCD(a, b - a);
}

int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    int lcm = (a / binaryGCD(a, b)) * b;
    printf("LCM = %d\n", lcm);
    return 0;
}
// Method 12 - Bitwise (Stein's Algorithm)  We compute GCD using the Binary GCD (Stein's) algorithm which uses bitwise shifts and AND instead of division. Then apply LCM formula. No modulo or division used inside GCD. Advanced topic for after basics are done.
