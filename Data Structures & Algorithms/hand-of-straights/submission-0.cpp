class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        unordered_map<int, int> count;

        for(int n:hand){
            count[n]++;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto& pair: count){
            minHeap.push(pair.first);
        } 

        while(!minHeap.empty()){
            int first = minHeap.top();
            for (int i= first; i < first+groupSize;i++)// because the elemets coming next should be +1 of before
            {
                if(count.find(i) == count.end()) return false; // if there is no +1 element;

                count[i]--;
                if(count[i]==0){
                    if(i != minHeap.top()) return false; // if not minimum value are over like we have 1 but no 2 then we can't make group with +1

                    minHeap.pop(); 
                }
            }
        }

        return true;
    }
};
