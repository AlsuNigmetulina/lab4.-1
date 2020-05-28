#include <iostream>
#include "hhh.h"

using namespace std;

int main()
{
    CyclicalList<int> a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.print();
    a.deleteAtPos(3);
    a.print();
    a.insertAtPos(4,3);
    a.print();
    CyclicalList<char> b;
    b.insert('H');
    b.print();
    return 0;
}
