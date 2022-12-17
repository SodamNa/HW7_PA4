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
// Answer starts from below

class Solution {
public:
    unordered_map<Node* , Node*> mp; // Declaring map to store a clone graph
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) // If node is empty
        {
            return NULL; // Return null
        }
        
        Node* first = new Node(node -> val, {}); // Make a copy to store first node
        mp[node] = first;
        
        queue<Node*> q; // 
        q.push(node); 
        
        while(q.empty() == false) 
        {
            Node* curr = q.front(); 
            q.pop(); 
            
            for(auto adj: curr -> neighbors)
            {
                if(mp.find(adj) == mp.end()) 
                {
                    mp[adj] = new Node(adj -> val, {}); 
                    q.push(adj);
                    
                }
                
                mp[curr] -> neighbors.push_back(mp[adj]); // in current node push adjcant node
            }
        }
        
        return mp[node];
    }
};
