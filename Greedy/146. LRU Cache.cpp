class LRUCache
{
    public:
        int size;
        list<pair<int,int>>lis;
        unordered_map<int, list<pair<int,int>>::iterator >mp;
        LRUCache(int capacity)
        {
            size=capacity;
        }
        int get(int key)
        {
            if(mp.find(key) != mp.end()) {
                lis.splice(lis.begin(),lis,mp[key]);
                return mp[key]->second;
            } else {
                return -1;
            }
        }
        void put(int key, int value)
        {
            if(mp.find(key) != mp.end()) {
                lis.splice(lis.begin(), lis, mp[key]);
                mp[key]->second = value;
            } else {
                if(lis.size() == size) {
                    // LRU element has to be evicted
                    int lru = (lis.back()).first;
                    mp.erase(lru);
                    lis.pop_back();
                    
                    // new element has to be inserted
                    lis.push_front({key, value});
                    mp[key] = lis.begin();
                } else {
                    lis.push_front({key,value});
                    mp[key] = lis.begin();
                }
            }
        }
};



