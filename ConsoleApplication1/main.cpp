#include <iostream>
//#include "table.h"
#include "sorttable.h"
using namespace std;
int main()
{
    
    Table table(4);
    //table.add("keyqr", 1);
    //table.add("qwertyui", 2);
    //table.add("asdfgh", 3);
    //
    //cout << table;
    ////table.Sort();
    //cout << table.search("keyqr") << endl;

    ////table.del("keyqr");
    //
    //cout << table;
    //table.add("aaa", 1323);
    //cout << table;
    //table.del("qwertyui");
    //cout << "---" << endl;
    ////table.Sort();
    //cout << table;
    table.add("aa3", 2);
    //table.add("aa3", 3);
    table.add("aaa", 1);
    table.add("qpo", 21);
    table.add("abcd", 245);
    
    table.add("23pl[p2l", 14);
    table.add("cat", 21);
    //table.del("cat");
    cout << table << endl << "count: " << table.getCount() << endl;
}
