#pragma once

#include <iostream>
using namespace std;

struct Node {
    string val;
    Node* next;
    int key;
    Node(string _val) : val(_val), next(nullptr), key(NULL) {}
};


struct list {
    Node* first;
    Node* last;
    bool isEmpty;
    list() : first(nullptr), last(nullptr), isEmpty(1) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(string _val, int h) {
        Node* p = new Node(_val);
        p->key = h;
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void print() {
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            cout << p->key << " - " << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    Node* find(string _val, int count) {
        Node* p = first;
        while (p && p->val != _val)
        {
            p = p->next;
            count++;
        }
        return (p && p->val == _val) ? p : nullptr;
    }

    void remove_first() {
        if (is_empty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

    void remove_last() {
        if (is_empty()) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    void remove(string _val, int count) {
        if (is_empty()) return;
        if (first->val == _val) {
            remove_first();
            return;
        }
        else if (last->val == _val) {
            remove_last();
            return;
        }
        Node* slow = first;
        Node* fast = first->next;
        while (fast && fast->val != _val) {
            count++;
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            cout << "This element does not exist" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }

    Node* operator[] (const int index) {
        if (is_empty()) return nullptr;
        Node* p = first;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }

};
