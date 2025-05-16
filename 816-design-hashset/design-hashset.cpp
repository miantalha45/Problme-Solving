class MyHashSet {
public:
    
    int size = 10000;
    vector<list<int>> buckets;
    MyHashSet() {
        buckets.resize(size);
    }
    int GetIndex(int key)
    {
        return key % size;
    }
    void add(int key) {
        int index = GetIndex(key);
        for(int k : buckets[index])
        {
            if(k == key) return;
        }
        buckets[index].push_back(key);
    }
    
    void remove(int key) {
        int index = GetIndex(key);
        buckets[index].remove(key);
    }
    
    bool contains(int key) {
        int index = GetIndex(key);
        for(int k : buckets[index])
        {
            if(k == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */