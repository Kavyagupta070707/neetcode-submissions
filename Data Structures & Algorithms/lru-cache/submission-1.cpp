class LRUCache {
   public:
    unordered_map<int, int> m;
    deque<int> q;
    int n;
    LRUCache(int capacity) { n = capacity; }

    int get(int key) {
        if (!m.count(key)) return -1;
        for (auto it=q.begin(); it!= q.end(); it++) {
            if (*it == key) {
                q.erase(it);
                break;
            }
        }
        q.push_back(key);
        

        return m[key];
    }

    void put(int key, int value) {
        if (m.count(key)) {
            for (auto it=q.begin(); it!= q.end(); it++) {
                if (*it == key) {
                    q.erase(it);
                    break;
                }
            }
            q.push_back(key);
            m[key] = value;
            return;
        }

        if (q.size() == n) {
            int k = q.front();
            m.erase(k);
            q.pop_front();
        }

        q.push_back(key);
        m[key] = value;
    }
};
