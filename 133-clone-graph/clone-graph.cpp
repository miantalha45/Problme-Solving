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

class Solution {
public:
    unordered_map<Node*, Node*> map;
    Node* cloneGraph(Node* node) {

        if(node == nullptr) return node;

        if(map.count(node) > 0) return map[node];

        Node* newHead = new Node(node->val);
        map[node] = newHead;

        for(auto &n : node->neighbors) {
            newHead->neighbors.push_back(cloneGraph(n));
        }

        return newHead;
    }
};