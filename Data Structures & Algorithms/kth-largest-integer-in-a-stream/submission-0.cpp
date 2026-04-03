class KthLargest {
public:
    //these are class variables or data members(attributes) of the class
    // they do not belong to any specific function
    int k;
    priority_queue<int,vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;//assign value of parameter k to the class variable k
        for(int num:nums){
            pq.push(num);
            if(pq.size()>k){
                pq.pop();//pop the smallest
            }

        }

        
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k){
            pq.pop();
        }
        return pq.top();//min element=top of heap




        
    }
};
