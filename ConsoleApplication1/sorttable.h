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
    void Sort()
    {
        string tmps;
        int tmpi;
        for (int i = 0; i < rsize - 1; i++)
        {
            for (int j = 0; j < rsize - i - 1; j++)
            {
                if (arr[j].key > arr[j + 1].key)
                {
                    tmps = arr[j].key;
                    tmpi = arr[j].value;
                    arr[j].key = arr[j + 1].key;
                    arr[j].value = arr[j + 1].value;
                    arr[j + 1].key = tmps;
                    arr[j + 1].value = tmpi;
                }
                if (arr[j].key == "---")
                {
                    int m = j;
                    while (m < rsize - 1)
                    {
                        arr[m].key = arr[m + 1].key;
                        arr[m].value = arr[m + 1].value;
                        arr[m + 1].key = "---";
                        arr[m + 1].value = 0;
                        m++;
                    }
                }
            }
        }
    }

public:
    Table(int _size)
    {
        size = _size;
        arr = new Node[size];
        count = 0, rsize=0;
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
    int search(string _key, int flag)
    {
        
        int l = 0, r = rsize - 1;
        int index, res;
        flag = 0;
        //op_count = 0;
        do
        {
            index = (r + l) / 2;
            if (r < 0)
                return 0;
            if (arr[index].key == _key)
            {
                count++;
                flag = 1;
                return index;
                break;
            }
            if (arr[index].key > _key)
                r = index - 1;
            if (arr[index].key < _key)
                l = index + 1;
            count++;
        } while (flag != 1 && l <= r);
        return l;
        
        
        
        
        /*int ind = -1;
        for (int i = 0; i < rsize; i++)
        {
            count++;
            if (arr[i].key == _key)
            {
                ind = i; break;
            }

        }
        return ind;*/
    }
    void add(string _key, int _value)
    {
        if (isFull())
            return;
        int pos, flag{}, tmpi;
        //string tmps;
        pos = search(_key, flag);
        //cout << "Add op_count = " << op_count << endl;
        if (flag == 0)
        {
            if (rsize != 1)
            {
                rsize++;
                
                for (int i = rsize - 1; i > pos; i--)
                {
                    arr[i].key = arr[i - 1].key;
                    arr[i].value = arr[i - 1].value;
                }
                arr[pos].key = _key;
                arr[pos].value = _value;
            }
            else
            {
                arr[pos].key = _key;
                arr[pos].value = _value;
                rsize++;
            }
        }
        else
        {
            arr[pos].value += _value;
        }
    }


    int del(string key)
    {
        int flag{};
        int index = search(key,flag);
        if (index == -1)
            return -1;// idk
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
