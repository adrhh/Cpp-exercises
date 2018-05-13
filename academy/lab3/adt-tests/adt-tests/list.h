#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <memory>
#include "pch.h"

struct Node;

class List {
    Node *m_pHead {nullptr};
    int m_elemCount {0};
    void deleteElems(Node *pList);

public:
    static List* fromArray(int const arr[], int size); //factory method
    //List(int const arr[], int size);
    List() {}
    ~List();
    void insert(int value);
    void reverse();
    std::string toString() const;
    bool contains(int elem) const;
    int elemCount() const { return m_elemCount; }
};

void runListMethods();

#endif // LIST_H
