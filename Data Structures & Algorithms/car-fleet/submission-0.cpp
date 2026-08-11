class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<float,int> timeMap;
        for(int i=0;i<position.size();i++){
            float t=(target-position[i])/speed[i];
            timeMap[t]++;
        }

        return timeMap.size();
    }
};
