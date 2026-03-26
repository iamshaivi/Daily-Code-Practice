//The number is Even or Odd Program in C

//1. Using Modulus Operator %
#include <stdio.h>
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n % 2 == 0)
        printf("%d is Even\n", n);
    else
        printf("%d is Odd\n", n);
    return 0;
}

//2. Using Bitwise AND Operator &
#include <stdio.h>
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n & 1)
        printf("%d is Odd\n", n);
    else
        printf("%d is Even\n", n);
    return 0;
}

//3. Using Ternary Operator ? :
#include <stdio.h>
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("%d is %s\n", n, (n % 2 == 0) ? "Even" : "Odd");
    return 0;
}

//4. Using Division (Without Modulus)
#include <stdio.h>
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if ((n / 2) * 2 == n)
        printf("%d is Even\n", n);
    else
        printf("%d is Odd\n", n);
    return 0;
}

//5. Using a Function
#include <stdio.h>

int isEven(int n) {
    return (n % 2 == 0);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (isEven(n))
        printf("%d is Even\n", n);
    else
        printf("%d is Odd\n", n);
    return 0;
}

//6. Using Recursion
#include <stdio.h>

int isEven(int n) {
    if (n < 0) n = -n;   // handle negatives
    if (n == 0) return 1;
    if (n == 1) return 0;
    return isEven(n - 2);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("%d is %s\n", n, isEven(n) ? "Even" : "Odd");
    return 0;
}

//7. Using Bitwise XOR ^

#include <stdio.h>
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if ((n ^ 1) == n + 1)
        printf("%d is Even\n", n);
    else
        printf("%d is Odd\n", n);
    return 0;
}

//8. Using Right Shift >>
#include <stdio.h>
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (((n >> 1) << 1) == n)
        printf("%d is Even\n", n);
    else
        printf("%d is Odd\n", n);
    return 0;
}

//9. Using printf without if
//(n%2==0) evaluates to 0 or 1
#include <stdio.h>
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    char *results[] = {"Odd", "Even"};
    printf("%d is %s\n", n, results[n % 2 == 0]);
    return 0;
}

//Conclusion:

//Explored multiple ways to check whether a number is even or odd in C language.
//Each method gives the same result but works differently internally.
//The modulus operator is the simplest and most commonly used method.
//The bitwise AND operator is the most efficient at the hardware level since it directly checks the last bit of the number.
//Methods like recursion and XOR are not practical for this problem but help in understanding how logic can be applied in different ways.
