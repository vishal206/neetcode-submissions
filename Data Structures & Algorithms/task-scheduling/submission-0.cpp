class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for(char task : tasks){
            count[task -'A']++;
        }

        priority_queue<int> maxHeap;
        for(int cnt: count){
            if(cnt>0){
                maxHeap.push(cnt);
            }
        }

        int time =0;
        queue<pair<int,int>> q; // remaining count & time when it can be used next

        while(!maxHeap.empty() || !q.empty()){
            time++;

            if(maxHeap.empty()){
                time = q.front().second; 
                //this will avoid unnessacary loops till the wait time adds up after the heap is empty
            }else{
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if(cnt>0){
                    q.push({cnt, time + n}); // Next time when this cnt can be used - time + n;
                }
            }

            if(!q.empty() && q.front().second == time){
                maxHeap.push(q.front().first); 
                // push ot when the time is / passes the usable time
                q.pop();
            }
        }

        return time;
    }
};
