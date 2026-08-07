class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap; 
    //this data format is used to have minHeap, by default priority queue is max-heap
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int num : nums){
            minHeap.push(num);
            if(minHeap.size()>k){
                minHeap.pop(); // removes the minimum
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>k){
            minHeap.pop();
        }
        return minHeap.top();
    }
};
