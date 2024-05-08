# Data Structures & Algorithms Implementation & Analysis

## Data Structures
Culmination of common data structures and algorithms for usage in development of software for high-performance compute, operating systems logic, database systems with efficient information retrieval. Purpose of this repository is to keep notes of efficient alternates for the different tasks of computers.

* **Singly, Doubly, Circular [Linked List](https://en.wikipedia.org/wiki/Linked_list)**: useful for dynamic memory management and in the implementation of queues and stacks, used in hardware for managing hardware tasks and processing data.
* [**Graph**](https://en.wikipedia.org/wiki/Graph_(abstract_data_type)):
Used extensively in hardware environments for circuit design, simulating components including logic gates, registers, and memory elemnents, while edges represent connections between the components. These data structures are put to use by graph algorithms, which are employed to optimize the layout, reduce power consumption and performance of the circuits.
* **[Binary Tree](https://en.wikipedia.org/wiki/Binary_tree#:~:text=In%20computer%20science%2C%20a%20binary,child%20and%20the%20right%20child.)**: Represent hierarchical structures, such as memory hierarchies, search trees for optimizing algorithms, and organizing data in parallel processing architectures.
* **[Hash Table](https://en.wikipedia.org/wiki/Hash_table)**: Used to implement associative arrays and used for caching, indexing and acceleration of data access.
* **[Matrix](https://en.wikipedia.org/wiki/Matrix_(mathematics))**: Represent data in multi-dimensional spaces, such as in image processing, linear algebra operations, and neural network computations.
* **[Priority Queue](https://en.wikipedia.org/wiki/Priority_queue)**: Utilized in hardware for tasks like scheduling and resource allocation, where the order of processing tasks is based on certain priority criteria.
* **[Tries](https://en.wikipedia.org/wiki/Trie)**: Used for efficient string storage and retrieval, which is important in hardware for tasks like pattern matching and data compression.
* **[Bloom Filters](https://en.wikipedia.org/wiki/Bloom_filter)**: Probabilistic data structures used for set membership testing and are useful in hardware for tasks like caching and filtering.

## General Purpose Algorithms
* Recursive & Iterative DFS, BFS
* Graph Reductions
* Hashing Algorithms
* BST Traversals
* Dijkstras Algorithm
* A* Search
* MST & Topological Sorting
* Search & Sorting Algorithms
* Bit Manipulation Algorithms

Performance of these algorithms will be compared using time complexity and space complexity. Their advantages and disadvantages will be listed briefly for appropriate usage.


## OS Data Structures
* **Process Control Blocks (PCB)**: Data structures that are essential for process manipulation, state handling, allocation and deallocation of resources, termination or control of child processes. Utilizes a unique hierarchy to organize parent and children processes (avoids linked lists). Contains generic fields that specify the state of the process, resources that are allocated, children, younger sibling, older sibling, and parent process.
* **Resource Control Blocks (RCB)**: Data structures that are used to manage the state of resources again for transfer of allocation from one process to another upon termination, suspension, or simply finishing up the process requirements.

## CPU Scheduling Algorithms & Logic (To Be Implemented)
- First-Come, First-Served (FCFS)
- Shortest Job Next (SJN) / Shortest Job First (SFJ)
- Shortest Remaining Time (SRT)
- Round Robin (RR)
- Priority Scheduling
- Multilevel Queue Scheduling
- Multilevel Feedback Queue Scheduling

Followed by the general logic for scheduling, process creation/termination, resource creation/termination for demonstration of understanding of the material taught in Principles of Operating Systems CS 143A class at the UCI ICS. Understandably, this material is complex due to being able to simulate the inner workings per algorithm. Test cases would need to simulate adding new process, but would require *time* as a factor order of organization etc. Thus, these are to be implemented with testing.
