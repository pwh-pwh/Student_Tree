//
// Created by CH on 2020/11/19.
//
#ifndef STUDENT_TREE_BTREENODE_H
#define STUDENT_TREE_BTREENODE_H
#include "Student.h"
class BTreeNode {
public:
    Student data;
    BTreeNode *rchild,*lchild;
    BTreeNode():lchild(NULL),rchild(NULL){};
    BTreeNode(Student d, BTreeNode *l=NULL, BTreeNode *r=NULL):data(d),lchild(l),rchild(r){}
    BTreeNode *getleft(){
        return lchild;
    }
    BTreeNode *getright(){
        return rchild;
    }
};
#endif //STUDENT_TREE_BTREENODE_H
