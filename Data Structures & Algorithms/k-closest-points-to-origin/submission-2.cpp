class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        //coordinates of origin
        int x2=0;
        int y2=0;
        priority_queue<
            pair<int, vector<int>>,
            vector<pair<int, vector<int>>>,
            greater<pair<int, vector<int>>>
        > pq;
        for(auto &p:points){
            int x2=p[0];
            int y2=p[1];
            int dist=(x2*x2+y2*y2);
            pq.push({dist,p});
        }

        vector<vector<int>> res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;

        
    }
};
