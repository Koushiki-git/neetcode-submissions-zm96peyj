class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;//max heap
        //add elements in pq
        for(int num:stones){
            pq.push(num);
        }

        //Till we have 0 or 1 element in pq
        while(pq.size()>1){
            int x=pq.top();pq.pop();//first largest
            int y=pq.top();pq.pop();//second largest
            if(x!=y) pq.push(x-y);
            //if x==y both destroyed so do nothing

        }
        if(pq.empty()){
            return 0;
        }
        return pq.top();


        
    }
};
