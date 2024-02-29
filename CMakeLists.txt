cmake_minimum_required(VERSION 3.27)
project(dsa_implementation_analysis)

set(CMAKE_CXX_STANDARD 14)

include_directories(data_structures)

add_executable(dsa_implementation_analysis
        algorithms/Dijkstras.cpp
        algorithms/graph_traversals.cpp
        algorithms/hashing.cpp
        algorithms/recursion.cpp
        algorithms/sorting.cpp
        data_structures/bin_search_tree.hpp
        data_structures/graph.cpp
        data_structures/hash_table.hpp
        data_structures/heap.cpp
        data_structures/linked_list.hpp
        data_structures/min_spanning_trees.cpp
        data_structures/priority_queue.cpp
        data_structures/skip_list.cpp
        data_structures/topological_orders.cpp
        data_structures/union_find.cpp)
