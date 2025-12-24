# Fibonacci Performance Experiments (C++)

This repository explores how different algorithmic approaches to computing
Fibonacci numbers affect performance under a fixed time budget.

The goal is **not** to compute a single Fibonacci number fast, but to measure
how much computational work can be completed within a given time limit.

---

## Motivation

Many beginner implementations of Fibonacci look correct but perform extremely
poorly. This project demonstrates, through direct benchmarking, how algorithm
choice dominates performance.

---

## Structure

Each chapter introduces a new approach:

- `chapter1_naive_fibonacci.cpp`
  - Recursive definition
  - Exponential time complexity
  - Demonstrates recomputation explosion

- `chapter2_iterative_fibonacci.cpp`
  - Iterative dynamic programming
  - Linear time complexity
  - Massive performance improvement

Future chapters will explore:
- Fast doubling (O(log n))
- Big integer arithmetic
- Threaded batch computation
- CPU saturation and benchmarking

---

## Benchmarking Methodology

Instead of measuring a single execution, each program:

1. Runs Fibonacci computation in a loop
2. Stops after a fixed time limit (e.g. 2 seconds)
3. Counts how many executions completed

This measures **throughput**, not just latency.

---

## Example Result

On the same machine, with the same time limit:

- Naive recursion (`fib(30)`): ~500 executions
- Iterative DP (`fib(30)`): ~42,000,000 executions

This illustrates the dramatic effect of eliminating redundant computation.

---

## Key Takeaways

- Algorithmic complexity matters more than hardware
- Recursion is not inherently slow, but careless recursion is
- Benchmarking must avoid I/O and focus on controlled timing
- Performance experiments should be reproducible

---

## Build & Run

```bash
g++ -O2 chapter2_iterative_fibonacci.cpp
./a.out
