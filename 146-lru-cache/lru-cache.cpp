//O(1) approach
class Node{
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int key, int val){
        this -> key = key;
        this -> val = val;
    }
};

class LRUCache {
public:
    // Initialize head and tail for the DLL
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int n;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        n = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(Node* node){
        Node* temp = head -> next;

        node -> next = temp;
        node -> prev = head;

        head -> next = node;
        temp -> prev = node;
    }

    void deleteNode(Node* node){
        Node* previous = node -> prev;
        Node* nextNode = node -> next;

        previous -> next = nextNode;
        nextNode -> prev = previous;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            // Key exists
            Node* resNode = mp[key];
            int res = resNode -> val;

            // add the node to the beginning of the DLL to make it most recently used
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);

            mp[key] = head -> next;

            return res;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            // Key exists
            Node* curr = mp[key];

            // Remove the node from the list and the map
            mp.erase(key);
            deleteNode(curr);
        }

        if(mp.size() == n){
            // Check if size is full
            mp.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }

        // Add the node to the map and the list
        addNode(new Node(key, value));
        mp[key] = head -> next;
    }
};

// O(N) approach
// class LRUCache {
// public:
//     vector<pair<int, int>> cache;
//     int n;

//     LRUCache(int capacity) {
//         n = capacity;    
//     }
    
//     int get(int key) {
//         for(int i = 0; i < cache.size(); i++){
//             if(cache[i].first == key){
//                 int val = cache[i].second;
//                 pair<int, int> temp = cache[i];

//                 cache.erase(cache.begin() + i);
//                 cache.push_back(temp);
//                 return val;
//             }
//         }

//         return -1;
//     }
    
//     void put(int key, int value) {
//         for(int i = 0; i < cache.size(); i++){
//             if(cache[i].first == key){
//                 cache.erase(cache.begin() + i);
//                 cache.push_back({key, value});
//                 return;
//             }
//         }

//         if(cache.size() == n){
//             cache.erase(cache.begin());
//             cache.push_back({key, value});
//         }else{
//             cache.push_back({key, value});
//         }
//     }
// };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */