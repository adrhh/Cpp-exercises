#include "list.h"
#include "pch.h"

struct Node {
    int value;
    Node *pNext;
    ~Node() { /*std::cout << "destruction of " << value << std::endl;*/ }
};

void runListMethods()
{
    using namespace std;
    cout << "*** Testing l1 = [1,2,3,4,5,6,7,8,9] ***" << endl;

    constexpr int arr1[] = {1,2,3,4,5,6,7,8,9};
    unique_ptr<List> pL1(List::fromArray(arr1, 9));
    cout << "L1 = " << pL1->toString() << endl;

    cout << "L1.contains(3) = " << pL1->contains(3) << endl;
    cout << "L1.contains(10) = " << pL1->contains(10) << endl;

    cout << "*** Reversing L1... " << endl;
    pL1->reverse();
    cout << "L1 = " << pL1->toString() << endl;
    cout << endl;

    cout << "*** Testing list L2 = [] ***" << endl;

    unique_ptr<List> pL2(new List);
    cout << "L2 = " << pL2->toString() << endl;

    cout << "L2.contains(1) = " << pL2->contains(1) << endl;

    cout << "*** Reversing L2... " << endl;
    pL2->reverse();
    cout << "L2 = " << pL2->toString() << endl;
}

List* List::fromArray(int const arr[], int size)
{
    List* pL = new List;

    for (int i = size - 1; i >= 0; --i) {
        pL->insert(arr[i]);
    }

    return pL;
}

List::~List()
{
    deleteElems(m_pHead);
    this->m_elemCount = 0; //?
}

void List::insert(int elem)
{
    Node *pCurrHead = this->m_pHead;

    Node *pCurrNode = new Node;
    pCurrNode->value = elem;
    pCurrNode->pNext = pCurrHead;

    this->m_pHead = pCurrNode;
    this->m_elemCount++;
}

std::string List::toString() const
{
    using std::string; using std::to_string; // vs. using namespace
    string result {"["};

    for (Node *pNode = this->m_pHead; pNode != nullptr; pNode = pNode->pNext) {
        result += to_string(pNode->value);
        if (pNode->pNext != nullptr) {
            result += ',';
        }
    }

    result += "]";
    return result;
}

bool List::contains(int elem) const
{
    for (Node *pNode = this->m_pHead; pNode != nullptr; pNode = pNode->pNext) {
        if (pNode->value == elem) {
            return true;
        }
    }

    return false;
}

void List::reverse()
{
    Node *pPrevNode = nullptr, *pNode = this->m_pHead, *pNextNode;

    while (pNode != nullptr) {
        // swap/reconnect
        pNextNode = pNode->pNext;
        pNode->pNext = pPrevNode;

        // move to the next node
        pPrevNode = pNode;
        pNode = pNextNode;
    }

    this->m_pHead = pPrevNode;
}

void List::deleteElems(Node *pList)
{
    Node *pCurrHead = pList;

    if (pCurrHead != nullptr) {
        deleteElems(pCurrHead->pNext);
        delete pCurrHead;
    }
}
