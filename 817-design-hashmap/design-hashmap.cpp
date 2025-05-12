#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
public:
    struct Node {
        int Key, Value;
        Node* next;
        Node(int key, int val, Node* Next = nullptr) {
            Key = key;
            Value = val;
            next = Next;
        }
    };

private:
    int size = 1000;
    vector<Node*> buckets;

public:
    MyHashMap() {
        buckets.resize(size, nullptr);
    }

    void put(int key, int value) {
        int index = GetIndex(key);
        Node* prev = FindElement(index, key);

        if (prev->next == nullptr) {
            prev->next = new Node(key, value);
        } else {
            prev->next->Value = value;
        }
    }

    int get(int key) {
        int index = GetIndex(key);
        Node* prev = FindElement(index, key);
        return (prev->next == nullptr) ? -1 : prev->next->Value;
    }

    void remove(int key) {
        int index = GetIndex(key);
        Node* prev = FindElement(index, key);
        if (prev->next != nullptr) {
            Node* toDelete = prev->next;
            prev->next = prev->next->next;
            delete toDelete;
        }
    }

private:
    int GetIndex(int key) {
        return key % size;
    }

    Node* FindElement(int index, int key) {
        if (buckets[index] == nullptr) {
            buckets[index] = new Node(-1, -1);
        }

        Node* prev = buckets[index];
        while (prev->next != nullptr && prev->next->Key != key) {
            prev = prev->next;
        }

        return prev;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */