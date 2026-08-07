class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> maxHeap;

        for(auto& point : points){
            int dist = pow(point[0],2) + pow(point[1],2); //As we are comparing the distance, doesn't matter if we add sqrt
            maxHeap.push({dist, {point[0],point[1]}});
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }

        vector<vector<int>> res;
        while (!maxHeap.empty()){
            res.push_back({maxHeap.top().second.first, maxHeap.top().second.second});
            maxHeap.pop();
        }

        return res;

    }
};
