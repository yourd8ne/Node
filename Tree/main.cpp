#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
    binary_tree tr(5);
    int i = 0;
    /*while (i < 100000)
    {
        tr.insert(rand());
        i++;
    }*/
    tr.insert(2);
    tr.insert(2);
    //tr.insert(1);
    //tr.insert(3);
    //tr.insert(7);
    //tr.insert(6);
    //tr.insert(8);
    //tr.erase(7);
    tr.print();
    if (tr.find(6))
        cout << "isFound" << endl;
    else
        cout << "notFound" << endl;
    cout << tr.getCount() << endl;
}
