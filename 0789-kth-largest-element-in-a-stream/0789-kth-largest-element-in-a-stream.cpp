class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int thresh;

    KthLargest(int k, vector<int>& nums) {
        thresh = k;

        for (int& x: nums){
            pq.push(x);

            if (pq.size() > thresh)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);

        if (pq.size() > thresh)
            pq.pop();

        return pq.top();
    }
};