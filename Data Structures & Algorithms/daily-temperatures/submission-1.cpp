class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);//to store the result
        stack<int> st;//to store the indices

        for(int i=0;i<n;i++){
            //while today is warmer than previous days
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                int prev=st.top();
                st.pop();
                ans[prev]=i-prev;

            }
            st.push(i);
        }
        return ans;

        
    }
};
