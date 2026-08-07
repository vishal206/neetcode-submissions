class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> subset;
        back_tracking(candidates, result, subset, 0, target);
        return result;
    }

    void back_tracking(vector<int>& candidates, vector<vector<int>>& result, vector<int> subset, int index, int target){
        if(target==0){
            result.push_back(subset);
            return;
        }
        if(target<0 || index==candidates.size()){
            return;
        }

        // Exclude current element, but skip all equal elements for exclusion
        int next = index + 1;
        while(next < (int)candidates.size() && candidates[next] == candidates[index]) next++;
        back_tracking(candidates, result, subset, next, target);
        
        subset.push_back(candidates[index]);
        back_tracking(candidates, result, subset, index+1, target-candidates[index]);
    }

};
