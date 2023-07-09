#pragma once
#include <iostream>
#include "List.h"

using namespace std;

class HashTable
{
	static const int default_capacity = 8;
	

	list* arr;
	unsigned size;// количество занятых строк в таблице
	int capacity = 8;// текующий размер таблицы. Лбио степень 2, либо ноль
	int count;
public:

	HashTable()
	{
		capacity = default_capacity;
		size = 0;
		arr = new list[capacity];
		for (int i = 0; i < capacity; i++)
		{
			arr[i].first = nullptr; arr[i].last = nullptr;
		}
		count = 0;
	}

	HashTable(int _capacity)
	{
		capacity = _capacity;
		size = 0;
		arr = new list[capacity];
		for (int i = 0; i < capacity; i++)
		{
			arr[i].first = nullptr; arr[i].last = nullptr;
		}
		count = 0;
	}

	void add(string str)
	{
		/*if (size >= capacity)
			return;*/
		int h = hash_function(str);
		arr[h].push_back(str, h);
		count++;
	}

	~HashTable()
	{
		for (int i = 0; i < capacity; i++)
			if (!arr[i].is_empty())
			{
				arr[i].remove_first();
				arr[i].remove_last();
			}	
	}

	Node* search(string val)
	{
		int i = hash_function(val);	
		if (arr[i].find(val, count) != nullptr)
			return arr[i].find(val, count);
		else
			return NULL;
	}
	
	void del(string value)
	{
		int h = hash_function(value);
		arr[h].remove(value, count);
	}

	unsigned long hash_function(string str) 
	{
		unsigned long i = 0;
		for (int j = 0; str[j]; j++)
			i += str[j];
		return i % capacity;
	}
	int getCount()
	{
		return count;
	}
	void Print()
	{
		for (int i = 0; i < capacity; i++)
		{
			
			arr[i].print(); cout << endl;
		}
	}
};