cmake_minimum_required(VERSION 3.17)
project(Student_Tree)

set(CMAKE_CXX_STANDARD 14)

add_executable(Student_Tree main.cpp Student.cpp Student.h Date.cpp Date.h BTreeNode.cpp BTreeNode.h BSTree.cpp BSTree.h)