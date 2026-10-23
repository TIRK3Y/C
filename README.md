# C

A collection of data structures and algorithms practice programs written in C, mostly from university lab exercises. Most programs are interactive console applications driven by a menu and `scanf` input.

## Contents

### Linked lists

| File | Description |
| --- | --- |
| `E1.c` | Singly linked list: insert at head, end, or any position; delete; search; display. |
| `Exp1.c` | Singly linked list with insertion at first, last, and any position, deletion, and display (heavily commented). |
| `Exp2.c` | Doubly linked list with insertion, deletion, and display. |
| `2.c` | Same doubly linked list program as `Exp2.c`, with line-by-line comments. |

### Stacks and expressions

| File | Description |
| --- | --- |
| `E3_Array.c` | Stack implemented with an array (push, pop, display). Uses `conio.h`. |
| `E3.c`, `E3_LL.c`, `Efour.c` | Stack implemented with a singly linked list (push, pop, display). These files are near-identical copies. |
| `E4.c` | Infix to postfix expression conversion using a character stack. |

### Queues

| File | Description |
| --- | --- |
| `E5array.c` | Linear queue implemented with a fixed-size array. |
| `E5.c` | Queue implemented both with an array and with a singly linked list in one program. |
| `E5LL.c` | Circular queue implemented with a linked list (interactive input). |
| `E6.c` | Circular queue implemented with a linked list. |

### Trees

| File | Description |
| --- | --- |
| `E7_2.c` | Binary tree built manually, with inorder, preorder, and postorder traversals. |
| `tempCodeRunnerFile.c` | Editor scratch copy of `E7_2.c`. |
| `Binary treeeeee.c` | Binary search tree insertion with preorder, inorder, and postorder traversals. |
| `E8.c` | Binary search tree insertion, search, and inorder traversal. |
| `E9_3.c` | Binary search tree with iterative insertion, preorder traversal, and search. |
| `E9.c` | AVL tree insertion with left and right rotations, and inorder traversal. |
| `E9_2.c`, `9_AVL.c` | AVL tree insertion with rotations (menu driven); two near-identical versions. |
| `E8.cpp` | C++ binary search tree of auction bids loaded from a CSV file (insert, remove, in-order listing). The header credits a third-party course template. It calls `csv::Parser` but does not include the parser header, so it does not compile as committed. |

### Hashing and graphs

| File | Description |
| --- | --- |
| `E10.c` | Hash table with linear probing (insert, search, display) and a table-full check. |
| `10_BFS.c` | Earlier version of the linear probing hash table (despite the file name, it is not a BFS program). |
| `E11.c` | Breadth-first search on a graph given as an adjacency matrix. |
| `E12.c` | Depth-first search on a graph given as an adjacency matrix. |
| `bfs.c` | Breadth-first search on an adjacency-list graph using a queue. |
| `dfs.c` | Recursive depth-first search on an adjacency-list graph. |

### Other

| File | Description |
| --- | --- |
| `SLL.c` | Windows-only example that loads `MyDll.dll` at runtime with `LoadLibrary` and calls an exported `add` function. The DLL is not included. |
| `Hello.c` | Empty file. |

## Tech stack

- C
- C++ (`E8.cpp` only)

## Getting started

Each `.c` file is a standalone program with its own `main`. Compile and run one at a time, for example with GCC:

```bash
gcc E11.c -o e11
./e11
```

Notes:

- `E3_Array.c` includes `conio.h`, which is only available with Windows compilers such as MinGW.
- `SLL.c` requires Windows and a `MyDll.dll` exporting `add`.
- Quote file names that contain spaces, for example `gcc "Binary treeeeee.c" -o bst`.

## License

No license has been specified for this project.
