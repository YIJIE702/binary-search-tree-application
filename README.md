# 🌳 Binary Search Tree (BST) Application
## 📌 Overview
This project is a **Binary Search Tree (BST) application** implemented in **C++**.  
It demonstrates key operations on a BST such as **insertion, deletion, searching, finding minimum/maximum elements, and traversals (inorder, preorder, postorder)** in a menu-driven program.

---

## 🎯 Objectives
- Implement a **Binary Search Tree** with dynamic memory allocation.
- Provide options to:
  - Insert elements.
  - Delete elements (handling leaf, single-child, and two-child cases).
  - Search for elements.
  - Find the minimum and maximum element.
  - Display traversals (inorder, preorder, postorder).
- Build a robust menu system with proper input validation.

---

## 🏗️ System Design
### 🔗 Data Structure
A **Binary Search Tree** where:
- Left subtree contains nodes with keys **less than** the parent.
- Right subtree contains nodes with keys **greater than** the parent.
- Each node has at most **two children**.

### 📂 Program Flow
1. Create BST – User must first create a tree (choice 1).
2. Insert Elements – Repeated insertion allowed (y/n prompt).
3. Delete Elements – Handles:
 - Leaf node deletion.
 - Node with one child.
 - Node with two children (using inorder successor).
4. Display Traversals – Shows inorder, preorder, and postorder traversals (choice 4).
5. Find Minimum & Maximum – Navigates to leftmost/rightmost node to retrieve value.
6. Search Elements – Confirms whether an element exists in the BST.
7. Exit – Ends program (choice 8).

---

## ⚡ Complexity Analysis
Operation	(Best/Average Case)
- Insert/Search/Delete:	O(log n) (balanced BST)	
- Traversals:	O(n) (visit each node once)

---

## 📈 Suggested Improvements
- Graphical Tree Visualization – Show tree structure dynamically after insert/delete.
- Unit Testing – Add automated tests for insert, delete, and search functions.
- Error Handling – Better input validation for non-numeric input.
- Balancing Algorithms – Implement AVL/Red-Black rotations for efficiency.

---

## 📜 License
- This project was created for educational purposes under EKT 224 – Algorithm and Data Structures coursework.
- You are free to modify and use this code for learning, with proper credit to the original author.
