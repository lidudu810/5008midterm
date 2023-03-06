#include <stdio.h>
#include <time.h>

int recursive_fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return recursive_fibonacci(n-1) + recursive_fibonacci(n-2);
}

int iterative_fibonacci(int n) {
    int fib[n+1], i;
    fib[0] = 0;
    fib[1] = 1;
    for (i = 2; i <= n; i++)
        fib[i] = fib[i-1] + fib[i-2];
    return fib[n];
}

int dynamic_fibonacci(int n) {
    int F[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    power(F, n-1);
    return F[0][0];
}

void multiply(int F[2][2], int M[2][2]) {
    int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
    int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
    int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
    int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(int F[2][2], int n) {
    int i;
    int M[2][2] = {{1,1},{1,0}};

    for (i = 2; i <= n; i++)
        multiply(F, M);
}

double get_execution_time(int n, int algorithm) {
    clock_t start, end;
    double time_spent;
    start = clock();

    switch(algorithm) {
        case 0:
            recursive_fibonacci(n);
            break;
        case 1:
            iterative_fibonacci(n);
            break;
        case 2:
            dynamic_fibonacci(n);
            break;
    }

    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    return time_spent;
}

void print_table(int n) {
    int i;
    printf("| n | Recursive C | Iterative C | Dynamic Programming C |\n");
    printf("|---|-------------|-------------|------------------------|\n");
    for (i = 1; i <= n; i++) {
        printf("| %d | %11.5f | %11.5f | %11.5f |\n", i, get_execution_time(i, 0), get_execution_time(i, 1), get_execution_time(i, 2));
    }
}

int main(int argc, char* argv[]) {
    int n, i;
    if (argc > 1) {
        n = atoi(argv[1]);
    } else {
        n = 30;
    }
    print_table(n);
    return 0;
}
