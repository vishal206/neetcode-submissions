class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> posSpeed;
        for(int  i=0; i<position.size(); i++){
            posSpeed.push_back({position[i],speed[i]});
        }

        sort(posSpeed.rbegin(), posSpeed.rend()); //reverse order sorting - O(logn)
        vector<double> stack;

        for(auto& p : posSpeed){
            stack.push_back((double)(target - p.first) / p.second);
            if(stack.size() >= 2 && stack.back() <= stack[stack.size()-2])//stack atleast have 2 cars only then u have collision
            { //stack.back gives the last element
            //condition compares last elemet and last before
            stack.pop_back();
            }
        }

        return stack.size();
    }
};
