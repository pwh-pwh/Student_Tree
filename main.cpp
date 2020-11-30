#include <iostream>
#include "BSTree.h"
using namespace std;
void showMenu(){
    cout<<"    **  欢迎来到学生健康管理系统  **"<<endl;

    cout<<"1新建学生健康表"<<endl;
    cout<<"2插入学生信息"<<endl;
    cout<<"3删除学生信息"<<endl;
    cout<<"4从文件中读取健康表信息"<<endl;
    cout<<"5向文件写入学生健康表信息"<<endl;
    cout<<"6查询学生信息（按学生学号来进行查找）"<<endl;
    cout<<"7全部学生信息"<<endl;
    cout<<"8退出"<<endl;
    cout<<"输入对应数字选择功能"<<endl;

}
void init();
int main() {

    BSTree t;

    int id;
    int select=0;
    while(true){
        showMenu();
        cin>>select;
        switch (select) {
            case 1:
                init();
                break;
            case 2:
                t.inst();
                system("pause");
                system("cls");
                break;
            case 7:{
                t.preorder(t.root);
                //t.preorder1();
                system("pause");
                system("cls");
                break;
            }
            case 3:{
                cout<<"输入id"<<endl;
                cin>>id;
                t.deleteNode(id);
                cout<<"删除成功"<<endl;
                system("pause");
                system("cls");
                break;
            }
            case 8:
                cout << "欢迎下一次使用"<<endl;
                system("pause");
                return 0;
            case 4:
               t.readTable();
               system("pause");
               system("cls");
                break;
            case 5:
                t.writeTable();
                system("pause");
                system("cls");

                break;
            case 6:
                cout<<"输入id"<<endl;
                cin>>id;
                t.sear(id,t.root);
                system("pause");
                system("cls");
                break;
            default:
                cout << "输入有误，请重新选择！" << endl;
                system("pause");
                system("cls");
                break;




        }
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
void init() {
    ofstream of;
    of.open("data.txt",ios::trunc);
    of.close();
    system("pause");
    system("cls");
}