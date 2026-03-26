// positive or negative number

//Method 1: Using Brute Force
#include <stdio.h>

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (num > 0) {
        printf("%d is Positive\n", num);
    }
    if (num < 0) {
        printf("%d is Negative\n", num);
    }
    if (num == 0) {
        printf("The number is Zero\n");
    }
    
    return 0;
}
//Method 1 - Simple if We write 3 separate if statements for positive, negative and zero. Each condition is checked one by one.Easy to understand but not the most efficient.


//Method 2: Using Nested if-else Statements
#include <stdio.h>

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (num > 0) {
        printf("%d is Positive\n", num);
    } else if (num < 0) {
        printf("%d is Negative\n", num);
    } else {
        printf("The number is Zero\n");
    }
    
    return 0;
}
//Method 2 - if else if Same as method 1 but once a condition is true the rest are skipped. This is better and cleaner than writing 3 separate if statements.


//Method 3: Using the ternary operator
#include <stdio.h>

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // condition ? "if true" : "if false"
    (num >= 0) ? printf("%d is Positive or Zero\n", num) 
               : printf("%d is Negative\n", num);
    
    return 0;
}
//Method 3 - Ternary Operator It is a short form of if else. We write condition then ? then true part then : then false part. Good for short and simple checks.


//Method 4: Using switch Statement
#include <stdio.h>

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // (num > 0) gives 1 if true, 0 if false
    // (num < 0) gives 1 if true, 0 if false
    switch (num > 0) {
        case 1:
            printf("%d is Positive\n", num);
            break;
        case 0:
            if (num < 0)
                printf("%d is Negative\n", num);
            else
                printf("The number is Zero\n");
            break;
    }
    
    return 0;
}
//Method 4 - Switch Case A condition like num > 0 returns 1 if true and 0 if false. Switch works on these values. Case 1 means positive and case 0 means negative or zero.


//Method 5: Using Function
#include <stdio.h>

void checkNumber(int num) {
    if (num > 0)
        printf("%d is Positive\n", num);
    else if (num < 0)
        printf("%d is Negative\n", num);
    else
        printf("The number is Zero\n");
}

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    checkNumber(num);
    
    return 0;
}
//Method 5 - Function We write the checking logic in a separate function and just call it in main. This is a good habit for writing clean and reusable code.


//Method 6: Using Bitwise Operator
#include <stdio.h>

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // right shift by 31 gives 0 for positive, -1 for negative
    if (num == 0)
        printf("The number is Zero\n");
    else if (num >> 31)
        printf("%d is Negative\n", num);
    else
        printf("%d is Positive\n", num);
    
    return 0;
}
//Method 6 - abs() abs() removes the minus sign from a number. So if abs(num) == num it means the number has no minus sign and is positive. We need to include stdlib.h to use it.


//Method 7: Using abs() Function
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // abs() gives absolute value (removes minus sign)
    if (num == 0)
        printf("The number is Zero\n");
    else if (abs(num) == num)
        printf("%d is Positive\n", num);
    else
        printf("%d is Negative\n", num);
    
    return 0;
}
//Method 7 - Bitwise This is slightly advanced. num >> 31 checks the sign bit of the number. Just know it exists for now and learn it later.
