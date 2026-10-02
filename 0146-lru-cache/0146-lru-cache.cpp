class LRUCache {
public:
    list<int> dll;
    unordered_map<int, pair<list<int> :: iterator, int>> dict;
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }
    
    void makeRecent(int key){
        dll.erase(dict[key].first);
        dll.push_front(key);
        dict[key].first = dll.begin();
    }

    int get(int key) {
        if(dict.find(key) == dict.end()){
            return -1;
        }

        makeRecent(key);
        return dict[key].second;
    }
    
    void put(int key, int value) {
        if(dict.find(key) != dict.end()){
            dict[key].second = value;
            makeRecent(key);
        }
        else{
            dll.push_front(key);
            dict[key] = {dll.begin(), value};
            n--;
        }

        if(n < 0){
            int del = dll.back();
            dict.erase(del);
            dll.pop_back();

            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */