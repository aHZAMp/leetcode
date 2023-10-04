class MyHashMap {
public:
    map<int,int> m;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        m[key]=value;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end())
            return m[key];
        else
            return -1;
    }
    
    void remove(int key) {
        auto it=m.find(key);
        if(it!=m.end())
            m.erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */