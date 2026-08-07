class DSU{
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n){
        //DSU - Disjoint Set Union
        // Here we initialize the parents and ranks
        rank.resize(n + 1, 1); //every node initial rank will be give as 1.
        
        parent.resize(n + 1); // next step we initialize the immediate parent of all nodes
        for( int i = 0; i<=n; i++){
            parent[i]=i;
        }
    }

    // find root parent
    int find(int node){
        int rp = node;
        while(rp != parent[rp]){
            // rp = parent[rp] - > A node itself it's parent, that is the root.
            parent[rp] = parent[parent[rp]]; // setting up grand-parent
            rp = parent[rp];
        }
        return rp;
    }

    //union components together
    bool unionSets(int u, int v){
        int rpu = find(u);
        int rpv = find(v);
        if(rpu == rpv){
            return false; //same root parent, so no need for new union;
        }
        if(rank[rpv]>rank[rpu]){
            parent[rpu] = rpv;
            rank[rpv] += rank[rpu];
        }else{
            parent[rpv] = rpu;
            rank[rpu] += rank[rpv];
        }

        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        for(auto& edge : edges){
            if(!dsu.unionSets(edge[0], edge[1])){
                return vector<int>{ edge[0], edge[1] };
            }
        }

        return {};
    }
};