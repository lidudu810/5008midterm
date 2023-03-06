#include <stdio.h>

// Iterative approach
int fib_iterative(int n) {
    int first = 0, second = 1, next_val;

    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next_val = i;
        } else {
            next_val = first + second;
            first = second;
            second = next_val;
        }
    }

    return next_val;
}

// Recursive approach
int fib_recursive(int n) {
    if (n <= 1) {
        return n;
    }

    return fib_recursive(n-1) + fib_recursive(n-2);
}

// Dynamic Programming approach
int fib_dynamic(int n) {
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    return fib[n];
}

// Print 1..N Fibonacci numbers
void print_fib(int n) {
    int first = 0, second = 1, next_val;

    printf("The first %d numbers in the Fibonacci series are: ", n);

    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next_val = i;
        } else {
            next_val = first + second;
            first = second;
            second = next_val;
        }

        printf("%d ", next_val);
    }

    printf("\n");
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Iterative: The %dth value of the Fibonacci series is %d\n", n, fib_iterative(n));
    printf("Recursive: The %dth value of the Fibonacci series is %d\n", n, fib_recursive(n));
    printf("Dynamic Programming: The %dth value of the Fibonacci series is %d\n", n, fib_dynamic(n));

    print_fib(n);

    return 0;
}
