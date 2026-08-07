class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }

        unordered_set<int> visited;
        vector<vector<int>> adj(n);

        for(const auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        if(!dfs(0,-1,visited,adj)) return false;

        return visited.size() == n;

    }

    bool dfs(int node, int parent, unordered_set<int>& visited, vector<vector<int>> adj){
        if(visited.count(node)){
            return false;
        }

        visited.insert(node);

        for(int nei: adj[node]){
            if(nei == parent){
                continue; //Ignore the parent
            }
            if(!dfs(nei, node, visited, adj)){
                false;
            }
        }

        return true;
    }
};
