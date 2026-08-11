class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<float,int> timeMap;
        for(int i=0;i<position.size();i++){
            float t=(float)(target-position[i])/speed[i];
            timeMap[t]++;
            cout<<t<<"-"<<timeMap[t]<<endl;
        }

        return timeMap.size();
    }
};
