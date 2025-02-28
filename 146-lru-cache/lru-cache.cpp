class LRUCache {
public:
    map<int, int> val, cnt;
    int cap;
    int cur = 0;
    deque<int> q;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (cnt[key] == 0) return -1;
        cnt[key]++;
        q.push_back(key);
        return val[key];
    }
    
    void put(int key, int value) {
        val[key] = value;
        cnt[key]++;
        q.push_back(key);
        if (cnt[key] == 1) {
            cur++;
            while (cur > cap) {
                int num = q.front(); q.pop_front();
                cnt[num]--;
                if (cnt[num] == 0) cur--;
            }
        }        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */