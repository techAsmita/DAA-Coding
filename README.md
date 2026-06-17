# 📘 DAA Coding — Design & Analysis of Algorithms

A structured collection of C++ implementations covering core algorithmic paradigms studied in the **Design and Analysis of Algorithms** course at **Thapar Institute of Engineering and Technology**.

Each assignment targets a specific algorithm design strategy, with clean, well-commented solutions built from scratch.

---

## 📂 Repository Structure

```
DAA-Coding/
├── Assignment 1/   → Divide & Conquer
├── Assignment 2/   → Greedy Algorithms
├── Assignment 3/   → Dynamic Programming
├── Assignment 4/   → Backtracking
├── Assignment 5/   → Graph Algorithms
├── Assignment 6/   → Network Flow
├── Assignment 7/   → String Matching
└── lps.cpp         → Standalone: Longest Palindromic Subsequence
```

---

## 🗂️ Assignment Breakdown

### Assignment 1 — Divide & Conquer
| File | Algorithm |
|------|-----------|
| `program1.cpp` | Binary Search |
| `program2.cpp` | Merge Sort |
| `program3.cpp` | Quick Sort |
| `program4.cpp` | Maximum Subarray Sum (D&C) |

### Assignment 2 — Greedy Algorithms
| File | Algorithm |
|------|-----------|
| `Q1.cpp` | Activity Selection |
| `Q2.cpp` | Minimum Railway Platforms |
| `Q3.cpp` | Job Scheduling with Deadlines |
| `Q4.cpp` | Fractional Knapsack |
| `Q5.cpp` | Huffman Coding (encode + decode) |

### Assignment 3 — Dynamic Programming
| File | Algorithm |
|------|-----------|
| `Q1.cpp` | Longest Common Subsequence (LCS) |
| `Q1b.cpp` | Longest Palindromic Subsequence (LPS) |
| `Q2.cpp` | Matrix Chain Multiplication |
| `Q3.cpp` | 0/1 Knapsack with item traceback |
| `Q4.cpp` | Maximal Square of 1s in Binary Matrix |

### Assignment 4 — Backtracking
| File | Algorithm |
|------|-----------|
| `Q1.cpp` | N-Queens Problem (8×8) |
| `Q2.cpp` | Sudoku Solver |
| `Q3.cpp` | Graph Coloring |

### Assignment 5 — Graph Algorithms
| File | Algorithm |
|------|-----------|
| `Q1.cpp` | Hamiltonian Cycle |
| `Q2.cpp` | Topological Sort — Kahn's Algorithm (BFS) |
| `Q2b.cpp` | Topological Sort — DFS-based |
| `Q3.cpp` | Kosaraju's Algorithm (SCCs) |

### Assignment 6 — Network Flow
| File | Algorithm |
|------|-----------|
| `Q1.cpp` | Ford-Fulkerson / Edmonds-Karp (Max Flow) |

### Assignment 7 — String Matching
| File | Algorithm |
|------|-----------|
| `Q1.cpp` | Brute Force + Rabin-Karp + KMP (all in one) |

---

## 🛠️ How to Run

All programs are written in standard C++. Compile and run using `g++`:

```bash
g++ filename.cpp -o output
./output
```

**Example:**
```bash
g++ "Assignment 7/Q1.cpp" -o string_match
./string_match
```

---

## 🧠 Concepts Covered

- **Divide & Conquer** — Recursive problem decomposition
- **Greedy** — Locally optimal choices (Huffman, Knapsack, Scheduling)
- **Dynamic Programming** — Overlapping subproblems and optimal substructure
- **Backtracking** — Constraint-based search with pruning
- **Graph Algorithms** — Traversal, SCCs, Hamiltonian paths, topological ordering
- **Network Flow** — Augmenting paths, residual graphs
- **String Matching** — Hash-based and failure-function approaches

---

## 🏫 Course Info

**Course:** Design and Analysis of Algorithms  
**Institute:** Thapar Institute of Engineering and Technology  
**Batch:** 2023–2027  

---

## 👩‍💻 Author

**Asmita** — [@techAsmita](https://github.com/techAsmita)  
B.E. Computer Engineering | AI/ML Enthusiast  
[LinkedIn](https://linkedin.com/in/techasmita)
