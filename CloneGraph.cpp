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
// Answer starts from below (BFS)

class Solution {
public:
    unordered_map<Node* , Node*> mp; // Declaring map to store a clone graph
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) // If node is empty
        {
            return NULL; // Return null
        }
        
        Node* first = new Node(node -> val, {}); // Make a copy to store first node
        mp[node] = first; // 
        
        queue<Node*> q; // Create queue.
        q.push(node); // add node to queue.
        
        while(q.empty() == false) // Repeat until q becomes empty
        {
            Node* curr = q.front(); // Assign the first element of q to curr
            q.pop(); // And remove the first element
            
            for(auto adj: curr -> neighbors) // Range based loop from neighbor of curr.
            {
                if(mp.find(adj) == mp.end()) // If nothing is in map
                {
                    mp[adj] = new Node(adj -> val, {}); // create copy
                    q.push(adj); // and add adj to q.
                    
                }
                
                mp[curr] -> neighbors.push_back(mp[adj]); // push adj node to curr node
            }
        }
        
        return mp[node]; // Return a clone graph.
    }
};
