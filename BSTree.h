//
// Created by CH on 2020/11/19.
//
#ifndef STUDENT_TREE_BSTREE_H
#define STUDENT_TREE_BSTREE_H
#include <iostream>
#include "BTreeNode.h"
#include "Student.h"
using namespace std;
class BSTree {
public:
    BTreeNode *root;
    BSTree(BTreeNode *p=nullptr):root(p){

    }
    void inst(Student &stu){
        BTreeNode *node=new BTreeNode(stu);

        inst(node,this->root);
    }
    void inst(){
        Student stu=*new Student;
        stu.input();
        inst(stu);

    }
    void inst(BTreeNode *p,BTreeNode *&bst){

        if (bst==nullptr)
            bst=p;
        else if (p->data.id < bst->data.id )
            inst(p,bst->lchild);
        else
            inst(p,bst->rchild);
    }
    void preorder(BTreeNode * p){ //-前序遍历递归算法


        if(p!=nullptr){
            p->data.toString();
        }else{
            return;
        }
        preorder(p->lchild);
        preorder(p->rchild);
    }
    void preorder1(){ //前序遍历非递归算法
        BTreeNode *stack[10],*p;
        int top=0;
        p=root;
        while(top>=0){
            while(p!=nullptr){
                p->data.toString();
                stack[top++]=p;
                p=p->lchild;
            }
            top--;
            p=stack[top];
            if(p!=nullptr){
                p=p->rchild;
            }
        }

    }
void inorder(BTreeNode *p){ //中序遍历递归算法
        if(p==nullptr){
            return;
        }
        inorder(p->lchild);
        p->data.toString();
        inorder(p->rchild);
    }
    void inorder1(){//中序遍历非递归算法
        BTreeNode *stack[10],*p;
        int top=0;
        stack[top]=root;
        while(top>=0){
            while(stack[top]!=nullptr){
                p=stack[top]->lchild;
                stack[++top]=p;

            }
            top--;
            if(top>=0){
                p=stack[top];
                p->data.toString();
                stack[top]=p->rchild;
            }
        }
    }
    void posorder(BTreeNode *p){ //后序遍历递归算法
        if(p!=nullptr){
            posorder(p->lchild);
            posorder(p->rchild);
            p->data.toString();
        }
    }
    void posorder1(BTreeNode *&bt){//后序遍历非递归算法
        BTreeNode *stack[20];
        BTreeNode *result[20];
        int top1 = -1,top2=-1;
        stack[++top1]=bt;
        while(top1!=-1){
            bt=stack[top1--];
            result[++top2]=bt;
            if(bt->lchild!=nullptr){
                stack[++top1]=bt->lchild;
            }
            if(bt->rchild!=nullptr){
                stack[++top1]=bt->rchild;
            }
        }
        while(top2!=-1){
            bt=result[top2--];
            bt->data.toString();
        }


    }
    int dep(BTreeNode *p){ //求树高
        int max;
        if(p==nullptr){
            return 0;
        }else{
            max=dep(p->lchild);
            if(dep(p->rchild)>max){
                max=dep(p->rchild);
                return max+1;
            }
        }
    }
    int num(BTreeNode *p){//结点个数

        if(p==nullptr){
            return 0;
        }
        else
            return num(p->lchild)+num(p->rchild)+1;
    }
    int countleaf(){//求叶子总数
        return (num(root)+1)/2;
    }

    BTreeNode * deleteNode(BTreeNode *&p,int id){
        BTreeNode *pfather=this->root,*qfather=nullptr,*q=nullptr;
        int k;
        while(p!=nullptr){
            k=id-p->data.id;
            if(k<0){
                pfather=p;
                p=p->lchild;
            }
            else if(k>0){
                pfather=p;
                p=p->rchild;
            }
            else
                break;
        }
        if(p==nullptr){
            cout<<"找不到该同学信息，删除失败!"<<endl;
            return nullptr;
        }
        else if(p->lchild!=nullptr&&p->rchild!=nullptr){
            BTreeNode *tmp=p->rchild;
            while(tmp->lchild){
                tmp=tmp->lchild;
            }
            p->data=tmp->data;
            p->rchild=deleteNode(p->rchild,tmp->data.id);
        }
        else{
            if(p->lchild== nullptr&&p->rchild==nullptr){
                if(p==this->root){
                    this->root=nullptr;
                }
                else if(p==pfather->lchild){
                    pfather->lchild=nullptr;
                }
                else{
                    pfather->rchild=nullptr;
                }

            }
            else if(p->lchild==nullptr){
                if(p==this->root){
                    this->root=p->rchild;
                }else{
                    if(p==pfather->lchild){
                        pfather->lchild=p->rchild;
                    }
                    else{
                        pfather->rchild=p->rchild;
                    }
                }


            }
            else if(p->rchild==nullptr){
                if(p==this->root){
                    p=p->lchild;
                }else{
                    if(p==pfather->lchild){
                        pfather->lchild=p->lchild;
                    }
                    else{
                        pfather->rchild=p->lchild;
                    }
                }


            }
        }

return p;
    }
    BTreeNode * deleteNode(int id){
        BTreeNode *p=this->root;
        return deleteNode(p,id);
    }
    void sear(int id,BTreeNode *bst){
        if(bst==nullptr){
            cout<<"未找到"<<endl;
            return;
        }else{
            if(id-bst->data.id==0){
                bst->data.toString();
            }
            else if(id-bst->data.id<0){
                sear(id,bst->lchild);
            }
            else{
                sear(id,bst->rchild);
            }

        }




    }
void readTable() {
        ifstream isf;
        isf.open("data.txt",ios::in);
        int id;
        string name;
        int gender;
        string health;
        int year;
        int month,day;
        this->root=nullptr;
        while(isf>>id>>name>>gender>>health>>year>>month>>day){
            Student stu=*new Student;
            stu.id=id;
            stu.name=name;
            stu.gender=gender;
            stu.health=health;
            stu.birthday.year=year;
            stu.birthday.month=month;
            stu.birthday.day=day;
            inst(stu);

        }
        cout<<"已经从文件读取完成"<<endl;

        isf.close();
    }
void writeTable(){
        ofstream of;
        of.open("data.txt",ios::trunc);
        BTreeNode *stack[10],*p;
        int top=0;
        p=root;
        while(top>=0){
            while(p!=nullptr){
                of<<p->data.id<<" "
                  <<p->data.name<<" "
                  <<p->data.gender<<" "
                  <<p->data.health<<" "
                  <<p->data.birthday<<" "<<endl;
                stack[top++]=p;
                p=p->lchild;
                cout<<"======="<<endl;
            }
            top--;
            p=stack[top];
            if(p!=nullptr){
                p=p->rchild;
            }
        }


cout<<"文件已经写入"<<endl;

    }

};


#endif //STUDENT_TREE_BSTREE_H
