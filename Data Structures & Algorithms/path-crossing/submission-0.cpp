class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0,y=0;
        set<pair<int,int>> st;
        st.insert({0,0});
        for(char ch:path){
            if(ch=='N') y++;
            else if(ch=='S') y--;
            else if(ch=='E') x++;
            else x--;

            if(st.count({x,y})) return true;
                
            st.insert({x,y});
        }
        return false;
       

        
    }
};