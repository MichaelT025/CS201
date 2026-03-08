# CS 201 Homework 2 Report

**Name:** Michael Tesfaye  
**Email:** mktesfaye@crimson.ua.edu  
**Course Section:** Spring 2026 CS 201 – 002

---

## Performance Comparison

| Input File | # of Distinct Words | Time Taken Homework-1 | Time Taken using SymbolTable |
|------------|--------------------:|----------------------:|-----------------------------:|
| Input1.txt | 20                  | 0.000185              | 0.000207                     |
| Input2.txt | 9,895               | 0.253491              | 0.364004                     |
| Input3.txt | 19,712              | 0.393735              | 0.510044                     |

---

## Time Complexity Justification

All SymbolTable operations maintain the required complexities:

| Operation | Complexity | Implementation |
|-----------|------------|----------------|
| `operator[]` | O(log N) | Uses `Search()` then `Insert()` if not found |
| `insert()` | O(log N) | Uses `Search()` then `Insert()` |
| `remove(key)` | O(log N) | Uses parent `Remove()` method |
| `remove(iterator)` | O(1) amortized | Uses parent `RemoveNode()` directly |
| `find()` / `contains()` / `count()` | O(log N) | Uses parent `Search()` method |
| `toVector()` | O(N) | Inorder traversal of RBT |
| `size()` / `empty()` | O(1) | Direct member access |

The word frequency program has overall complexity **O(N log N)** where N is total words:
- Parsing: O(N)
- N insertions into ST: O(N log U) where U = unique words
- toVector() for sorted output: O(U)
- Total: O(N log N) worst case

---

## Explanation of Performance Differences

The SymbolTable implementation is **30-44% slower** than Homework 1 despite both using balanced BSTs with O(log N) operations:

1. **Implementation Quality:** HW1 used `std::map` (highly optimized production STL), while SymbolTable uses a custom educational RBT with additional overhead for color tracking, rotations, and tree visualization.

2. **Memory Allocation:** Custom RBT uses manual `new` per node; STL uses optimized memory pools.

3. **Constant Factors:** Both are O(log N), but the custom RBT has higher constants from more pointer chasing and rebalancing checks.

The key difference is **engineering optimization** versus educational clarity — the SymbolTable demonstrates the same asymptotic guarantees but with practical overhead.

---

## Conclusion

### ST.hpp Implementation

The SymbolTable class was successfully implemented by wrapping the provided Red-Black Tree implementation. All required methods achieve their specified complexities by delegating to parent class methods (`Search`, `Insert`, `Remove`, `RemoveNode`) where appropriate. The `toVector()` method performs an inorder traversal using a recursive lambda to produce sorted output in O(N) time. The implementation properly tracks `nodeCount` for O(1) size queries and handles edge cases (null iterators, empty trees) correctly.

### WordCount.cpp Implementation

The word frequency program demonstrates practical use of the SymbolTable by replacing `std::map` from Homework 1 with `ST<string, int>` for word counting and `ST<int, vector<string>>` for frequency grouping. The program maintains the same structure: parsing input, counting frequencies, grouping by count, sorting ties alphabetically, and outputting in descending frequency order. Timing instrumentation using `chrono` allows performance measurement for comparison.

### Key Takeaways

1. **Asymptotic vs Practical Performance:** Both implementations achieve O(N log N), but the custom RBT's higher constant factors make it measurably slower than STL's optimized `std::map`.

2. **Inheritance Benefits:** The ST class cleanly extends RBT functionality without modifying the underlying tree code, demonstrating proper use of class inheritance in C++.

3. **Red-Black Tree Properties:** The guaranteed O(log N) worst-case operations provide predictable performance regardless of input patterns, unlike hash-based structures which can degrade under collisions.

The assignment successfully demonstrates how balanced BSTs work under the hood while highlighting why production code uses highly optimized library implementations.
