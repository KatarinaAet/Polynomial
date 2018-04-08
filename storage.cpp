#include "storage.h"
#include <iostream>
#include <ostream>
using namespace std;


Storage::Storage()
{
    Head = NULL;
    Tail = NULL;
    size = 0;
}

Storage::~Storage()
{
    while (size!=0){
        Node *temp = Head->next;
        delete Head;
        Head = temp;
        size--;
    }
}

void Storage::Add(Function*_func)
{
    size++;
    Node *temp = new Node;
    temp->next = Head;
    temp->func = _func;

    if (Head!=NULL){
        Tail->next = temp;
        Tail = temp;
    }
    else Head = Tail = temp;
}

void Storage::show()
{
    Node *tempHead = Head;
    int temp = size;
    while (temp!=0){
            //cout << "id:" << tempHead->func->id << endl;
            tempHead->func->show();
            cout << endl;
        tempHead = tempHead->next;
        temp--;
    }

}

/*void Storage::show_by_id(int id_input)
{
    Node *tempHead = Head;
    int temp = size;
    while (temp!=0){
        if (tempHead->func->id == id_input){
            tempHead->func->show();
            cout << endl;
        }
        tempHead = tempHead->next;
        temp--;
    }

}*/

int Storage::Count()
{
    return size;
}

double Storage::operator ()(double x) const
{
    Node *tempHead = Head;
    int temp = size;
    double res;
    while (temp!=0){
        res = tempHead->func->operator ()(x);
        if (tempHead->func->check(x)){
            tempHead->func->show();
            cout << endl;
            cout << "Here is the meaning:";
            cout << res << endl;
        }
        else{
            cout << "Such function is not defined in "<< x <<" point:" << endl;
            tempHead->func->show();
            cout << endl;
            tempHead->func->show_not_def(x);
        }
        tempHead = tempHead->next;
        temp--;
    }
    return res;
}


