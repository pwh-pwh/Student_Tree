#include <iostream>
#include "BSTree.h"
using namespace std;
void showMenu(){
    cout<<"    **  ��ӭ����ѧ����������ϵͳ  **"<<endl;

    cout<<"1�½�ѧ��������"<<endl;
    cout<<"2����ѧ����Ϣ"<<endl;
    cout<<"3ɾ��ѧ����Ϣ"<<endl;
    cout<<"4���ļ��ж�ȡ��������Ϣ"<<endl;
    cout<<"5���ļ�д��ѧ����������Ϣ"<<endl;
    cout<<"6��ѯѧ����Ϣ����ѧ��ѧ�������в��ң�"<<endl;
    cout<<"7ȫ��ѧ����Ϣ"<<endl;
    cout<<"8�˳�"<<endl;
    cout<<"�����Ӧ����ѡ����"<<endl;

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
                cout<<"����id"<<endl;
                cin>>id;
                t.deleteNode(id);
                cout<<"ɾ���ɹ�"<<endl;
                system("pause");
                system("cls");
                break;
            }
            case 8:
                cout << "��ӭ��һ��ʹ��"<<endl;
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
                cout<<"����id"<<endl;
                cin>>id;
                t.sear(id,t.root);
                system("pause");
                system("cls");
                break;
            default:
                cout << "��������������ѡ��" << endl;
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