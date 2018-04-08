#ifndef STORAGE_H
#define STORAGE_H
#include "function.h"

class Storage
{
    struct Node{
        Function *func;
        Node *next;
    };
    Node *Head, *Tail;
    int size; //число элементов в списке

public:
    Storage();
    ~Storage();
    void Add(Function *_pol);
    void show();
    void show_by_id(int id_input);
    int Count();
    double operator ()(double x) const;
};

#endif // STORAGE_H
