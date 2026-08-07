class Solution {
public:
    vector<int> output;
    vector<int> indegree; // number of pre-req
    vector<vector<int>> adj;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Looks like we find the end of the graph ( nodes without a pre req)
        // and start going upwards.

        adj = vector<vector<int>>(numCourses);
        indegree = vector<int>(numCourses,0);

        for(auto& pre : prerequisites){
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]); 
            // in course 1, we added course and it's pre req
            // here, we add course and it's direct dependecies.
        }

        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                dfs(i);
            }
        }

        if(output.size() != numCourses) return {};

        return output;
    }

    void dfs(int node){
        output.push_back(node); // add nodes with no indegree.
        indegree[node]--; // reduce it to -1, so that we don't come back to the same course / node again in the for loop
        for(int dependent : adj[node]){
            // now the dependents are free as the pre req is completed
            indegree[dependent]--;
            if(indegree[dependent]==0){
                dfs(dependent);
            }
        }
    }
};
