class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        map<int,int> numsMap;
        for(auto num:nums){
            numsMap[num]++;
        }

        for(auto entry:numsMap){
            if(entry.second>=k){
                result.push_back(entry.first);
            }
        }

        return result;
    }
};
