# Midterm p1: Report on Analysis of Fibonacci Series
* **Author**: Chengyi Li 
* **GitHub**: https://github.com/lidudu810/5008midterm.git
* **Semester** Spring 2023
* **Languages Used**: c, Python

## Overview
This report compares the speed of different implementations of the Fibonacci series. The Fibonacci series is a sequence of numbers where each number is the sum of the two preceding ones, starting from 0 and 1. It can be presented mathematically as:

F(n) = F(n-1) + F(n-2)

The first few numbers in the Fibonacci series are:

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

In this report, we will compare the speed of three different algorithms to find the nth number in the Fibonacci series:

The iterative approach calculates the nth number by starting from the first two numbers in the series and iteratively calculating the next number until the nth number is reached. The recursive approach uses a recursive function to calculate the nth number by summing the (n-1)th and (n-2)th numbers in the series. The dynamic programming approach stores the previously calculated numbers in an array to avoid recalculating them, resulting in a faster execution time.

To compare the algorithms, we will find the nth number of the Fibonacci series for a range of values of n, from 1 to 100. We will then measure the execution time of each algorithm and compare their performance.

There are multiple ways to implement the Fibonacci Series with code, each discussed in more detail below. However, for the implementations used in this report, the following chart represents the Big O value.

<img width="394" alt="Screenshot 2023-03-03 at 10 19 07 PM" src="https://user-images.githubusercontent.com/113164818/222873907-eba9239e-7e39-4cd9-8e69-702bb26ac128.png">

The iterative version of the Fibonacci Series implementation has two nested for loops that generate each term in the sequence by summing the previous two terms. This implementation needs to store the previous line, causing an increase in memory usage. There is a version that uses a constant amount of memory with a single variable, but it fails on larger values of N.

The recursive version of the Fibonacci Series implementation is given in pseudocode below:

```text
for i..n 
    RV(n, i)

RV(n,i)
   if i == 1 or i == n: return 1
   return  RV(n - 1, i) + RV(n - 1, i - 1)
```

Each row of the Fibonacci sequence contains one more element than the previous row. To generate the nth term, the algorithm must calculate n elements, each of which is the sum of two elements in the previous row. This means that the algorithm must make O(2^n) recursive calls to generate the entire nth term. However, the only memory it needs to keep is the final term itself (or if printing, no memory is used), making the space used either O(1) or O(n).

The dynamic programming version of the Fibonacci Series implementation stores the value of (n,i) for each call, making the second branch constant time and bringing the worst case time complexity back to O(n), but at the cost of O(n^2) memory usage.

For this analysis, I selected Python as my second language. The reason for this selection, other than it being a well-known language, is that it has built-in functions to assist with dynamic programming, such as lru_cache and cache in the built-in functools library. This allowed me to experiment with the built-in tools while also writing in a language designed for quick development and experimentation.

## Empirical Data & Discussion 
For all empirical results, I maxed out the time interval to 60 seconds. This allowed for execution of code in a timely manner, while still being able to run multiple iterations.

The iterative and dynamic programming versions are much faster than the recursive versions.

**Recursive Versions**
![Recurive C](https://user-images.githubusercontent.com/113164818/223066748-32c7b522-66a1-484a-83b1-638c525fd014.png)
![Recursive P](https://user-images.githubusercontent.com/113164818/223066771-5d79348d-1902-4d61-81dd-1fe4e4e1f963.png)
Compare to Python and C, C has much more quicker than python, we can see the difference during the chart.

**Iterative and Dynamic Programming Versions**

![C Comparison](https://user-images.githubusercontent.com/113164818/223066858-52f48702-57ca-420d-b730-f006f8d6a94d.png)
![P Comparison](https://user-images.githubusercontent.com/113164818/223066859-b326e54a-4833-4b17-ac19-79f38121ad67.png)
During the chart we can see that the C speed are still quicker than the Python.


## Language Analysis
[Fibonacci.c](https://github.com/lidudu810/5008midterm/blob/main/Fibonacci.c). -- implementation of functions in c

[Fibonacci.py](https://github.com/lidudu810/5008midterm/blob/main/Fibonacci.py). -- implementation of function in python

[test_runner.py](https://github.com/lidudu810/5008midterm/blob/main/test_runner.py). -- run script to help with tests and keep timings

Initially, I began writing code in C as I had prior experience with it from the examples given in class. Eventually, I transitioned to Python and replicated the same code examples. However, I soon found myself experimenting with different implementations in Python before updating the C versions based on those discoveries.

### Language 1: C
Originally, for the C version, I was taking inspiration from [random Google research](https://www.programiz.com/c-programming/examples/fibonacci-series). They mentioned how to generate it up to n terms And Fibonacci Sequence Up to a Certain Number, these two methods will help me in my subsequent research and study. After reading this, I have an idea, and based on this, I made my own changes and some Format changes.

```text
#include <stdio.h>
int main() {

   int i, n;

   // initialize first and second terms
   int t1 = 0, t2 = 1;

   // initialize the next term (3rd term)
   int nextTerm = t1 + t2;

   // get no. of terms from user
   printf("Enter the number of terms: ");
   scanf("%d", &n);

   // print the first two terms t1 and t2
   printf("Fibonacci Series: %d, %d, ", t1, t2);

   // print 3rd to nth terms
   for (i = 3; i <= n; ++i) {
     printf("%d, ", nextTerm);
     t1 = t2;
     t2 = nextTerm;
     nextTerm = t1 + t2;
   }

   return 0;
}
```

I referred to this code and made several changes based on this code, which gained a lot of inspiration.
n terms of the code structure, I added a recursion helper function that computes the Nth number of the Fibonacci series, which is then used by another function to compute every number up to N.

Here is the updated code for generating the Fibonacci series using recursion in C:

```text
ull fibonacci_r(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci_r(n-1) + fibonacci_r(n-2);
}
```

The above code uses recursion to generate the nth Fibonacci number. It checks if the input n is either 0 or 1, and if so, it returns the corresponding Fibonacci number. Otherwise, it recursively calculates the n-1th and n-2th Fibonacci numbers and returns their sum, which is the nth Fibonacci number.

In order to make the code more efficient, I needed to add a recursion helper function that would either only generate the nth number, or that would generate every number up to n.

Additionally, for the C versions, I used unsigned long long for my data type as they can store larger numbers than int, and had to write my own print functions along with help functions for the final program.

### Language 2: Python
For the Python version of the Fibonacci sequence, I initially started with a recursive implementation:

```text
def fib_r(n: int) -> int:
if n <= 1:
return n
return fib_r(n-1) + fib_r(n-2)
```

However, this recursive approach quickly becomes inefficient as n grows larger, so I implemented a dynamic programming version using a cache to avoid recomputing already-calculated values:

from functools import lru_cache

@lru_cache(maxsize=None)
def fib_dp(n: int) -> int:
if n <= 1:
return n
return fib_dp(n-1) + fib_dp(n-2)

To handle larger values of n more efficiently, I also implemented a "build up" approach where I computed smaller values of n before larger ones. Additionally, I used the Click library to handle program arguments and made use of PyPy to take advantage of its just-in-time compiler to speed up the execution of the code."

### Comparison and Discussion Between Experiences
In comparing the performance of the iterative and recursive approaches for generating the Fibonacci series in C and Python, it was found that the C implementation ran significantly faster than the Python implementation in every case. Additionally, the iterative approach was found to be faster than the dynamic programming approach, despite the fact that their Big O complexities are the same. However, it should be noted that there are further optimizations that could be applied to the recursive version, such as taking advantage of the symmetry of the sequence, which would be more complex to implement in the iterative version.

While the caching mechanism in Python was found to be a simple and effective way to speed up the dynamic programming implementation, the speed difference of nearly a factor of 10 between C and Python implementations may not make the simplicity of caching worth it.

In exploring further optimizations, the idea of "precaching" the sequence was considered. This involved generating and storing the first N numbers of the sequence to a file, which could then be loaded and accessed by the dynamic programming implementation, resulting in faster access times at the cost of a slower start-up time for the program. This idea was inspired by the initial Python runs where the dynamic programming version ran much faster due to the cache remaining in memory and not unloading. Additionally, it was found that since the caching mechanism in Python is a pure function, it is possible to run a separate thread to generate the needed N numbers before the program generates it. While this may not be effective for a single script run, it could be advantageous for an interactive program where a client is requesting various runs of the sequence, or if the sequence is being used for other computations.


## Conclusions / Reflection
In my experience implementing the Fibonacci sequence algorithm in both Python and C, I found that there were trade-offs between simplicity and performance. C performed faster than Python, but the process of adding caching to Python was simple, making it a viable option in some situations. However, the speed difference between the two languages may not always justify the additional effort required for optimization.

In addition, I found that the iterative code was more complex to write and debug than the other versions. Despite this, it may be a better option for certain applications where performance is critical.

Overall, my experiences highlighted the trade-offs between simplicity and performance when choosing between Python and C, as well as the importance of optimizing algorithms and utilizing specific language features.

## References
1. "Programiz. (n.d.). Fibonacci Series Program in C. Retrieved from https://www.programiz.com/c-programming/examples/fibonacci-series"