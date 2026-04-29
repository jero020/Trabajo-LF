# KMP Algorithm - Pattern Search Project

This project implements the **Knuth-Morris-Pratt (KMP) Algorithm**, an efficient pattern matching algorithm for text strings.

## Environment and Tools

- **Operating System:** macOS
- **Programming Language:** C++ (C++11 or later)
- **Compiler:** g++ (Apple LLVM)
- **Build Method:** Command line compilation

---

## FirstTask - Failure Function

### Description

Computes the **Failure Function** (also called the **LPS array** - Longest Proper Prefix which is also Suffix), a crucial component of the KMP algorithm. This is the preprocessing step that enables efficient pattern matching.

### Algorithm Explanation

The **Failure Function** stores the length of the longest proper prefix that is also a suffix at each position in the pattern.

**Example for pattern "ababaa":**
- Position 0: 0 (no proper prefix/suffix)
- Position 1: 0 (prefix "a" ≠ suffix "b")
- Position 2: 1 (prefix "a" = suffix "a")
- Position 3: 2 (prefix "ab" = suffix "ab")
- Position 4: 3 (prefix "aba" = suffix "aba")
- Position 5: 0 (prefix "abab" ≠ suffix "baa")

**Output:** `0 0 1 2 3 0`

### How to Compile and Run

#### Prerequisites
Ensure you have g++ installed on your system.

#### Compilation
```bash
cd /Users/jerovelez/Trabajo-LF
g++ -o FirstTask FirstTask.cpp
```

#### Execution
```bash
./FirstTask
```

#### Expected Output
```
0 0 1 2 3 0
```

---

## SecondTask - Complete KMP Algorithm

### Description

Full implementation of the KMP algorithm that searches for a pattern within a text string and determines if the keyword exists in the given chain.

### Algorithm Explanation

The KMP algorithm uses the Failure Function to achieve O(n + m) time complexity (where n is the pattern length and m is the text length), making it significantly faster than naive pattern matching.

### How to Compile and Run

#### Prerequisites
Ensure you have g++ installed on your system.

#### Compilation
```bash
cd /Users/jerovelez/Trabajo-LF
g++ -o SecondTask SecondTask.cpp
```

#### Execution
```bash
./SecondTask
```

#### Expected Output
```
Execution with 'abababaab' as string and 'ababaa' as keyword
yes
Execution with 'abababbaa' as string and 'ababaa' as keyword
no
```
This implementation follows the description from:

Compilers: Principles, Techniques, and Tools (Aho et al., 2nd edition), Section 3.4.5.

The solution is divided into two main components:

1️⃣ Failure Function — FailureFunction(keyword)
Computes an array f[]
Each position f[s] stores:
The length of the longest proper prefix of b1...bs that is also a suffix

📌 Purpose:

Avoid redundant comparisons
Reuse previously matched information when mismatches occur
2️⃣ KMP Search — KMP(chain, keyword)
Iterates over the text string
Maintains a counter s for matched characters
On mismatch:
s = f[s];
On full match (s == n):
return "yes"
If no match is found:
return "no"
🚀 Key Advantages
Linear time complexity: O(m + n)
No backtracking in the text
Efficient for large-scale text processing
Useful in lexical analysis and compiler design
🤖 AI Assistance
This README and project documentation were adapted with the assistance of ChatGPT.

📚 References
📖 Books
Aho, A. V., Lam, M. S., Sethi, R., & Ullman, J. D.
Compilers: Principles, Techniques, and Tools (2nd ed.).
Pearson, 2007. Section 3.4.5, Figures 3.19–3.20.
🎥 Videos
https://www.youtube.com/watch?v=ynv7bbcSLKE
https://www.youtube.com/watch?v=V5-7GzOfADQ