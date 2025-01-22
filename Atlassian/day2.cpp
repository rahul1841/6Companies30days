1600. Throne Inheritance

class ThroneInheritance {
public:
    unordered_map<string,vector<string>> bche;
    unordered_map<string,bool> dead;
    string king;
    ThroneInheritance(string kingName) {
        king=kingName;
    }
    void birth(string parentName, string childName) {
        bche[parentName].push_back(childName);
    }
    void death(string name) {
        dead[name]=1;
    }
    void dfs(vector<string>& ans,string papa){
        if(!dead[papa]) ans.push_back(papa);
        for(auto bcha:bche[papa]){
            dfs(ans,bcha);
        }
    }
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(ans,king);
        return ans;
    }
};
/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */



146. LRU Cache

class LRUCache {
public:

    class Node{

        public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int key, int val){
            this->key = key;
            this->val = val;
        }

    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int capacity;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void insertAfterHead(Node* node){
        Node* currNodeAfterHead = head->next;
        node->next = currNodeAfterHead;
        node->prev = head;
        head->next = node;
        currNodeAfterHead->prev = node;
    }

    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            deleteNode(node);
            insertAfterHead(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            if(mp.size() == capacity){
                Node* node = tail->prev;
                mp.erase(node->key);
                deleteNode(node);
                delete node;
            }

            Node* node = new Node(key, value);
            mp[key] = node;
            insertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



3006. Find Beautiful Indices in the Given Array I


class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> matchA, matchB;
        for (int i = 0; (i + a.size()) <= s.size(); i++) {
            if (s.substr(i, a.size()) == a) matchA.push_back(i);
        }
        for (int i = 0; (i + b.size()) <= s.size(); i++) {
            if (s.substr(i, b.size()) == b) matchB.push_back(i);
        }
        vector<int> result;
        for (auto& i : matchA) {
            auto it = lower_bound(matchB.begin(), matchB.end(), i - k);
            if ((it != matchB.end()) && (abs(*it - i) <= k)) result.push_back(i);
        }
        return result;
    }
};



