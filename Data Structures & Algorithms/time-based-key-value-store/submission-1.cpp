class TimeMap {
public:
    //hashmap to store key--> (timestamp,value)
    unordered_map<string,vector<pair<int,string>>> mpp;

    //comnstructor
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});

        
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key)==mpp.end()){
            return "";
        }
        auto &vec=mpp[key];//reference to the vector of (timestamp,value) pairs
        int l=0;int r=vec.size()-1;
        string res="";
        while(l<=r){
            int mid=l+(r-l)/2;
            int curr_time=vec[mid].first;
            string curr_val=vec[mid].second;
            if(curr_time==timestamp){
                return curr_val;
            }
            if(curr_time<timestamp){
                res=curr_val;
                l=mid+1;
            }
            else{
                r=mid-1;
            }

        }
        return res;






    }
};
