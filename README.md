# Leetcode-2577.-Minimum-Time-to-Visit-a-Cell-In-a-Grid
# 🚀 Minimum Time to Reach Destination in a Grid

This repository contains a C++ solution to the problem of finding the **minimum time** needed to reach the **bottom-right corner** of a grid while following specific movement rules.

---

## 🧠 Problem Statement

You are given a grid where:
- Each cell contains a non-negative integer representing the earliest time you can enter that cell.
- Starting from `(0, 0)`, you can move **up**, **down**, **left**, or **right** at each time step.
- Find the minimum time required to reach the bottom-right cell `(m-1, n-1)`.

⚡ If it is **impossible** to reach the destination, return `-1`.

---

## 🛠️ Approach

- **Priority Queue (Min-Heap)** is used to always explore the cell with the **earliest available time** first.
- Movement is allowed if:
  - The cell is immediately accessible.
  - Otherwise, wait until the correct time according to parity (even or odd time differences).
- Standard **Dijkstra's algorithm** idea but adjusted for **dynamic timing constraints**.

---

## 📄 Code Overview

- **`direction` vector**: defines 4 possible moves.
- **Priority Queue (`pq`)**: stores `{time, {row, col}}` to prioritize the smallest time.
- **Visited Matrix**: ensures we don't reprocess a cell.
- **Result Matrix**: records the minimum time to reach each cell.

Special Handling:
- If both right `(0,1)` and down `(1,0)` neighbors are initially inaccessible (`>1`), return `-1`.

---

## 📈 Complexity Analysis

| Type           | Value                         |
|----------------|-------------------------------|
| Time Complexity | O(m * n * log(mn))              |
| Space Complexity | O(m * n)                      |

---

## 📦 How to Run

1. Clone the repository:
    ```bash
    git clone https://github.com/your-username/minimum-time-grid.git
    ```
2. Compile the code:
    ```bash
    g++ Solution.cpp -o solution
    ```
3. Run:
    ```bash
    ./solution
    ```

---

## 🏆 Example

Input:
```plaintext
grid = [
  [0, 2, 4],
  [1, 3, 5],
  [2, 6, 7]
]
Output: - 7
