class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(string email:emails){
            int pos=email.find('@');//position of @
            string local=email.substr(0,pos);
            string domain=email.substr(pos+1);
            string cleaned="";
            for(char ch:local){
                if(ch=='+'){
                    break;
                }
                if(ch=='.'){
                    continue;
                }
                cleaned+=ch;
            }
            st.insert(cleaned+domain);
        }
        return st.size();
    }
};