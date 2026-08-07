class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea =0;
        vector<pair<int,int>> stack;

        for(int i =0;i<heights.size();i++){
            int h = heights[i];
            int start = i;
            while(!stack.empty() and stack.back().second>h){
                pair<int,int> last = stack.back();
                stack.pop_back();
                int index = last.first;
                int height = last.second;

                maxArea = max(maxArea, height*(i-index));
                start = index;
            }
            stack.push_back({start, h});
        }

        for(int i=0; i<stack.size(); i++){
            int start = stack[i].first;
            int h = stack[i].second;
            maxArea = max(maxArea, h * ((int)heights.size() - start));
            // if the element is still there , then it can cover till the end.      
        }

        return maxArea;
    }
};
