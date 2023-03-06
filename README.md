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



## Language Analysis


### Language 1: C



### Language 2: UPDATE



### Comparison and Discussion Between Experiences


## Conclusions / Reflection


