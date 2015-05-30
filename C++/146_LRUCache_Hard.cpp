/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item. 

Tags: Data Structure
*/
class LRUCache{
private:
    struct item_t {
        int key, val;
        item_t(int k, int v) : key(k), val(v) {}
    };
    typedef list<item_t> list_t;
    typedef unordered_map<int, list_t::iterator> map_t;
    map_t  m_map;
    list_t m_list;
    int    m_capacity;
    
public:
    LRUCache(int capacity) : m_capacity(capacity) {
        
    }
    
    int get(int key) {
        map_t::iterator i = m_map.find(key);
        if(i == m_map.end())    return -1;
        m_map[key] = promote(i->second);
        return m_map[key]->val;
    }
    
    void set(int key, int value) {
        map_t::iterator i = m_map.find(key);
        if(i != m_map.end()) {
            m_map[key] = promote(i->second);
            m_map[key]->val = value;
        }
        else {
            if(m_map.size() < m_capacity)
                m_map[key] = m_list.insert(m_list.end(), item_t(key, value));
            else {
                m_map.erase(m_list.front().key);
                m_list.pop_front();
                m_map[key] = m_list.insert(m_list.end(), item_t(key, value));
            }
        }
    }
    
    list_t::iterator promote(list_t::iterator i) {
        list_t::iterator inew = m_list.insert(m_list.end(), *i);
        m_list.erase(i);
        return inew;
    }
};
