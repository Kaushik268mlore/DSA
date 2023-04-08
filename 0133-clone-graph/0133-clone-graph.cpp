/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
//a weird problem, i kinda figured the difference b\w referencing and actually copying in real time 
//cuz for obvious reasons my brain didnt think that Node* clone=node;return clone is just transferring the reference address. lol
class Solution {
    unordered_map<Node*,Node*>map;
    void clone(Node*key){
            Node* nnode=new Node(key->val);
            map[key]=nnode;
            for(auto it:key->neighbors){
                if(map.find(it)==map.end()){
                    clone(it);
                }
                nnode->neighbors.push_back(map[it]);
            }
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        clone(node);
        return map[node];
    }
};