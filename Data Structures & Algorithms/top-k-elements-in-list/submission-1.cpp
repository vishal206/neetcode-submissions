class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        map<int,int> numsMap;
        int n=nums.size();
        vector<vector<int>> buckets(n+1);

        for(auto num:nums){
            numsMap[num]++;
        }

        for(auto entry:numsMap){
            buckets[entry.second].push_back(entry.first);
        }

        for(int i=n;i>=0 && result.size()<k;--i){
            for(int num:buckets[i]){
                result.push_back(num);
                if (result.size() == k) break;
            }
        }

        return result;
    }
};
