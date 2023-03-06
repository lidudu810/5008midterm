# Iterative approach
def fib_iterative(n):
    first = 0
    second = 1

    for i in range(n):
        if i <= 1:
            next_val = i
        else:
            next_val = first + second
            first = second
            second = next_val

    return next_val

# Recursive approach
def fib_recursive(n):
    if n <= 1:
        return n

    return fib_recursive(n-1) + fib_recursive(n-2)

# Dynamic Programming approach
def fib_dynamic(n):
    fib = [0]*(n+1)
    fib[0] = 0
    fib[1] = 1

    for i in range(2, n+1):
        fib[i] = fib[i-1] + fib[i-2]

    return fib[n]


# Print 1..N Fibonacci numbers
def print_fib(n):
    first = 0
    second = 1

    print("The first {} numbers in the Fibonacci series are:".format(n))

    for i in range(n):
        if i <= 1:
            next_val = i
        else:
            next_val = first + second
            first = second
            second = next_val

        print(next_val, end=" ")

    print()

# Just the Nth number in the Fibonacci Series
def print_fib_nth(n):
    print("The {}th number in the Fibonacci series is: {}".format(n, fib_dynamic(n)))

# Executing correctly without printing anything
def fib_no_print(n):
    fib = [0]*(n+1)
    fib[0] = 0
    fib[1] = 1

    for i in range(2, n+1):
        fib[i] = fib[i-1] + fib[i-2]

    return fib[n]
