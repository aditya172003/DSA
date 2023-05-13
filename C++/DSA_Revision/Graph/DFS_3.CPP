//copy the undirected graph 

#include<bits/stdc++.h>

using namespace std;



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


class Solution {
public:


    Node* dfs(Node*node , map<int,Node*>&mp)
    {
        if(node==NULL)return NULL;
        
        if(mp.find(node->val)!=mp.end())return mp[node->val];
        vector<Node*>nei;
        Node * p =new Node(node->val,nei);
        mp[node->val]=p;
       
        for(auto i : node->neighbors)
        {   
        
            p->neighbors.push_back(dfs(i,mp));
        }

        return p;
    }
    Node* cloneGraph(Node* node) {
        map<int,Node*>mp;

        return dfs(node,mp);
    }
};




/*

For simplicity, each node's value is the same as the node's index (1-indexed). 
For example, the first node with val == 1, the second node with val == 2, and so on. 
The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph.
Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy
of the given node as a reference to the cloned graph.


Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).



Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list.
The graph consists of only one node with val = 1 and it does 
not have any neighbors.



Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.

*/