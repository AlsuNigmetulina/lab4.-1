#ifndef HHH_H_INCLUDED
#define HHH_H_INCLUDED

#include <iostream>
using namespace std;
template<typename T>
class CyclicalList
{
private:
struct Node{
 Node* left;
 Node* right;
 T p;
    };
 Node* Next;
 Node* Head;
public:
CyclicalList();
CyclicalList(T const p);
CyclicalList(CyclicalList const &c);
~CyclicalList();
int const insert(T const p);
int const insertAtPos(T const p,int pos);
int const delete_1(T const p);
int const deleteCur();
int const deleteAtPos(int pos);
void clear();
int const shiftLeft();
int const shiftRight();
T const getCurrent();
int const isContains(T const p) const;
int const isEmpty() const;
int const size();
void print() const;
CyclicalList& operator= (CyclicalList const &c);
};

template<typename T>
    CyclicalList<T>::CyclicalList()
    {
 Head = 0;
 Next = 0;
    }
template<typename T>
    CyclicalList<T>::CyclicalList(T const p)
    {
 Head = new Node();
 Head->p = p;
 Head->left = Head;
 Head->right = Head;
 Next = Head;
    }
template<typename T>
    CyclicalList<T>::CyclicalList(CyclicalList const &c)
    {
        c->Next=c->Head;
        Head = new Node();
        Head->p = c->Next->p;
        Head->left = Head;
        Head->right = Head;
        Next = Head;
        c->Next=c->Next->right;
    }
template<typename T>
    CyclicalList<T>::~CyclicalList()
    {
        Head->left->right = 0;
        while(Next != 0)
        {
            Next = Head;
            Head = Head->right;
            delete Next;
            Next = 0;
        }
    }
template<typename T>
        int const CyclicalList<T>::insert(T const p)
    {
        if(Head == 0)
        {
            Head = new Node();
            Next = Head;
            Next->p = p;
            Next->left = Head;
            Next->right = Head;
            return true;
        }
        Node *temp = new Node();
        temp->p = p;
        temp->left = Next;
        temp->right = Next->right;
        Next->right->left = temp;
        Next->right = temp;
        Next = Next->right;
        return true;
    }
template<typename T>
    int const CyclicalList<T>::insertAtPos(T const p,int pos)
    {
        if ((pos == 1)||(pos>2))
        {
             if(pos == 1)
        {
            Node *temp = new Node();
            temp->p = p;
            temp->left = Head->left;
            Head->left->right = temp;
            temp->right = Head;
            Head->left = temp;
            Head = temp;
            Next = temp;
            return true;
        }
        if((Head == 0)&&(pos == 1))
        {
            Head = new Node();
            Head->p = p;
            Head->left = Head;
            Head->right = Head;
            Next = Head;
            return true;
        }
        Next = Head;
        while(pos>2)
        {
            --pos;
            Next = Next->right;
            if(Next == Head)
                cout << "not exist";
        }
        Node *temp = new Node();
        temp->p = p;
        temp->left = Next;
        temp->right = Next->right;
        Next->right->left = temp;
        Next->right = temp;
        Next = temp;
        return true;}
        else {cout << "not exist";}
    }
template<typename T>
     int const CyclicalList<T>::delete_1(T const p)
    {
        if(Head == 0)
            cout << "not exist";
        int  count_1 = 0;
        Next = Head;
        do
        {
            if(Next->p == p)
            {
                deleteCur();
                ++count_1;
            }else
            {
                Next = Next->right;
            }
        }
        while((Next != Head)&&(Next != 0));
        Next = Head;
        if(count_1 == 0)
            cout << "not exist";
        return true;
    }
template<typename T>
    int const CyclicalList<T>::deleteCur()
    {
        if(Next == 0)
            cout << "not exist";
        if(Next == Next->right)
        {
            delete Next;
            Next = 0;
            Head = 0;
            cout<<"\nRemote";
            return true;
        }
        Next->left->right=Next->right;
        Next->right->left=Next->left;
        Node *temp = Next;
        if(Next == Head)
            Head = Head->right;
        Next = Next->right;
        delete[] temp;
        temp = 0;
        return true;
    }
template<typename T>
     int const CyclicalList<T>::deleteAtPos(int pos)
    {
        if((Head == 0)||(pos < 1))
            cout << "not exist";
        Node *tmpNext = Next;
        Next = Head;
        for(int i = pos; i >1; --i)
        { Next = Next->right;
            if(Next == Head)
            {
                Next = tmpNext;
                cout << "not exist";
            }}
        if(tmpNext == Next)
            tmpNext  = tmpNext->right;
        deleteCur();
        if(tmpNext != 0)
            Next = tmpNext;
        else
            Next = Head;
        return true;
    }
template<typename T>
    void CyclicalList<T>::clear()
    {
        Next = Head;
        while(Next != 0)
        {
            if(Next == Next->left)
            {
                delete Next;
                Head = 0;
                Next = 0;
            }
            Node *temp = Next;
            Next->left->right = Next->right;
            Next->right->left = Next->left;
            Next = Next->right;
            delete temp;
        }
    }
template<typename T>
     int const CyclicalList<T>::shiftLeft()
    {
        if(Head == 0)
            cout << "not exist";
        Next = Next->left;
        return true;
    }
template<typename T>
      int const CyclicalList<T>::shiftRight()
    {
        if(Head == 0)
            cout << "not exist";
        Next = Next->right;
        return true;
    }
template<typename T>
       T const CyclicalList<T>::getCurrent()
    {
        return Next->p;
    }
 template<typename T>
        int const CyclicalList<T>::isContains(T const p) const
    {
        if(Head == 0)
            cout << "not exist";
        Node *temp = Head;
        do
        {
            if(temp->p == p)
                return true;
            temp = temp->right;
        }while(temp != Head);
        cout << "not exist";
    }
template<typename T>
    int const CyclicalList<T>::isEmpty() const
    {
        if(Head == 0)
            cout << "exists";
        cout << "not exist";
    }
template<typename T>
      int const CyclicalList<T>::size()
    {
        if(Head == 0)
            return 0;
          int count_1 = 0;
        Node *temp = Head;
        do
        {
            ++count_1;
            temp = temp->right;
        }while(temp != Head);
        return count_1;
    }
template<typename T>
 void CyclicalList<T>::print() const
    {
        if(Head == 0)
        {
            cout<<"empty list";
            return;
        }
        Node *temp = Head;
        do
        {
            cout<<temp->p<<" ";
            temp = temp->right;
        }while(temp != Head);
    }
template<typename T>
    CyclicalList<T>& CyclicalList<T>::operator= (CyclicalList const &c)
    {
        if(c->Head == 0)
        {
            Head = 0;
            Next = 0;
            return *this;
        }
        c->Next=c->Head;
        Head = new Node();
        Next = Head;
        do
        {
            Next->p = c->Next->p;
            Next->left = c->Next->left;
            Next->right = c->Next->right;
            c->Next = c->Next->right;
        }while(c->Next != c->Head);
        return *this;
    }


#endif // HHH_H_INCLUDED
