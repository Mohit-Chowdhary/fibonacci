# Fibonacci Performance Experiments (C++)

This repository is a **performance-driven exploration** of Fibonacci computation in C++, focusing on how **algorithm choice and implementation details** affect real-world throughput.

Rather than timing a single call, each implementation is benchmarked under a **fixed time budget** to measure how much useful work can be completed.

---

## Why Fibonacci?

Fibonacci is deceptively simple:

* the math is trivial
* the implementations vary wildly
* the performance gap spans **orders of magnitude**

That makes it a perfect sandbox to study:

* algorithmic complexity
* recursion vs iteration
* constant factors
* CPU-level behavior

---

## Benchmark Philosophy

This project measures **throughput**, not latency.

Each program:

1. Repeatedly computes `fib(n)`
2. Runs for a fixed time window (e.g. 2000 ms)
3. Counts how many computations finish

This avoids noisy microbenchmarks and highlights **steady-state performance**.

---

## Implementations

### 1. Naive Recursive Fibonacci

**Complexity:** O(φⁿ)

* Direct mathematical definition
* Massive recomputation
* Included as a baseline and cautionary example

---

### 2. Iterative Dynamic Programming

**Complexity:** O(n)

* Linear-time loop
* Eliminates recomputation
* Huge improvement over naive recursion

---

### 3. Matrix Exponentiation

**Complexity:** O(log n)

Uses the identity:

```
|1 1|^n = |F(n+1) F(n)  |
|1 0|     |F(n)   F(n-1)|
```

* General technique for linear recurrences
* Iterative, branch-predictable
* Strong baseline for logarithmic-time methods

---

### 4. Fast Doubling (Recursive)

**Complexity:** O(log n)

Uses the identities:

```
F(2k)   = F(k) * (2*F(k+1) − F(k))
F(2k+1) = F(k+1)^2 + F(k)^2
```

* Fewer operations than matrix exponentiation
* Elegant mathematically
* Recursive structure introduces overhead

---

### 5. Fast Doubling (Iterative, Bitwise)

**Complexity:** O(log n)

This is the **final and fastest** version.

* Removes recursion entirely
* Iterates over bits of `n`
* No stack usage, no function calls
* Lower constant factors than matrix exponentiation

This version consistently achieves the **highest throughput**.

---

## Sample Results (2 seconds)

| Method                        | fib(30) executions |
| ----------------------------- | ------------------ |
| Matrix Exponentiation         | ~31 million        |
| Fast Doubling (recursive)     | ~34 million        |
| **Fast Doubling (iterative)** | **~53 million**    |

*(Exact numbers depend on compiler and CPU)*

---

## Key Observations

* Asymptotic complexity is necessary but **not sufficient**
* Recursive elegance can lose to iterative structure
* Constant factors and branch predictability matter
* Theoretically optimal algorithms still need careful implementation
* Fast doubling is Fibonacci-specific and beats general methods in practice

---

## Build & Run

```bash
g++ -O2 fast_doubling_iterative.cpp -o fib
./fib
```

For best results:

* use `-O2` or `-O3`
* avoid debug builds
* keep I/O outside the benchmark loop

---

## What This Project Is (and Isn’t)

**This is:**

* a performance experiment
* an algorithmic comparison
* a study in implementation details

**This is not:**

* a big integer Fibonacci library
* a numerical accuracy demo
* a premature optimization contest

---

## Takeaway

The biggest performance wins rarely come from clever tricks —
they come from **choosing the right algorithm and removing unnecessary work**.

This repository demonstrates that principle end-to-end.

---
