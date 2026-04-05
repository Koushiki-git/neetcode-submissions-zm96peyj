class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c:s){

            //if opening bracket then push into stack
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }

            else{
                if(st.empty()) return false;//no opening bracket found

                if((c==')' && st.top()=='(') || (c=='}' && st.top()=='{')|| (c==']' && st.top()=='[')){
                    // opening and closing in order then
                    st.pop();
                }
                else{
                    return false;//mismatch in order
                }
            }
        }
        return st.empty();
           
        
    }
};
