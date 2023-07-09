#include <iostream>
#include "Table.h"

using namespace std;

int main()
{
	HashTable t;
	t.add("a");
	t.add("b");
	t.add("c");
	t.add("d");
	t.add("z");
	t.add("e");
	t.add("f");
	t.add("h"); t.add("g");
	t.Print();
	t.del("b");
	cout << "after del" << endl;
	t.Print();
	if (t.search("d") == nullptr)
		cout << "empty" << endl;
	else
	{
		cout << t.search("z")->key << t.search("z")->val << endl;
	}
	cout << t.getCount() << endl;
	return 0;
}
