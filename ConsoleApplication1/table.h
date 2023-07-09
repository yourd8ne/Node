#pragma once

#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    int value;
    string key;
};

class Table 
{
    Node* arr;
    unsigned size;
    unsigned rsize;
    int count;
public:
    Table(int _size)
    {
        count = 0, rsize = 0;
        size = _size;
        arr = new Node[size];
    }
    Table(const Table& t)
    {
        size = t.size;
        if (arr != NULL)
            delete arr;
        arr = new Node[size];
        for (int i = 0; i < size; i++)
        {
            arr[i].value = t.arr[i].value;
            arr[i].key = t.arr[i].key;
        }
    }
    ~Table()
    {
        delete[] arr;
        size = 0;
    }

    int getCount()
    {
        return count;
    }

    bool isFull()
    {
        bool res = 0;
        if (size == rsize)
            res = 1;
        return res;
    }
    int getValue(int i)
    {
        return arr[i].value;
    }
    int search(string _key)
    {
        
        int ind = -1;
        for (int i = 0; i < rsize; i++)
        {
            count++;
            if (arr[i].key == _key)
            {
                ind = i; break;
            }
            
        }
        return ind;
    }
    void add(string key, int value)
    {

        if (isFull())
            return;
        int i;
        i = search(key);
        if (i >= 0)
        {
            arr[i].key += value;
        }
        else
        {
            arr[rsize].key = key;
            arr[rsize].value = value;
            rsize++;
        }
       
    }


    int del(string key)
    {
        int index = search(key);
        if (index == -1)
            return  -1;
        int res = arr[index].value;
        for (int i = index; i < rsize - 1; i++)
        {
            arr[i].key = arr[i + 1].key;
            arr[i].value = arr[i + 1].value;
        }
        rsize--;
        return res;
    }


    friend ostream& operator<<(ostream& os, Table& t)
    {
        for (int i = 0; i < t.rsize; i++)
        {
            os << setw(5) << t.arr[i].key << setw(10) << t.arr[i].value << endl;
        }
        return os;
    }
};