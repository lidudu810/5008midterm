import subprocess
import time
import sys
import math
from typing import Union

COMMON_ARG_FORMAT = "python3 Fibonacci.py {n} {algo}"
FORMAT = "markdown"
TIMEOUT = 60

LAST_RUN_TRACKER = {"0": 0.0, "1": 0.0, "2": 0.0}


def run_single(n: int, typ: Union[int, str], command=COMMON_ARG_FORMAT) -> float:
    """Run a single instance collecting the total execution time

    Args:
        command:
        n (int): the Fibonacci number to compute
        typ (int): the type of algorithm to use

    Returns:
        float: the time it took, or nan if TIMEOUT is reached first
    """
    command = command.format(n=n, algo=typ)
    if math.isnan(LAST_RUN_TRACKER[str(typ)]):
        return math.nan  # skip running if we are already timing out
    try:
        start = time.time()
        subprocess.run(command.split(), timeout=TIMEOUT)
        end = time.time()
        result = end - start

    except subprocess.TimeoutExpired:
        result = math.nan
    LAST_RUN_TRACKER[str(typ)] = result
    return result


def build_row(n: int) -> str:
    """Builds a row to print to the screen either in csv format or markdown

    Args:
        n (int): the Fibonacci number to compute

    Returns:
        str: a markdown formatted or csv string of the result
    """
    results_lst = []
    for t in range(0, 3):
        result = run_single(n, t)
        results_lst.append("-" if math.isnan(result) else f"{result:.5f}")
    recursive, iterative, dynamic_Programming = results_lst

    if FORMAT == "markdown":
        return f"| {n:<4} | {recursive.center(8, ' ')} | {iterative.center(8, ' ')} | {dynamic_Programming.center(8, ' ')} |"
    return f"{n},{recursive},{iterative},{dynamic_Programming}"


def table_header() -> str:
    """Returns a markdown table header for this data set"""
    if FORMAT == "markdown":
        return "| n | Recursive P | Iterative P | Dynamic Programming P |\n" + \
            "|--|:--:|:--:|:--:|"
    return "n,Recursive P,Iterative P,Dynamic Programming P"


def main(n):
    print(table_header())
    for i in range(n + 1):
        print(build_row(i))


# note while using argv directly, there are better tools for this like pip click
if __name__ == "__main__":
    _n = 30 if len(sys.argv) < 2 else int(sys.argv[1])
    if len(sys.argv) == 3:
        FORMAT = "csv"
    main(_n)
