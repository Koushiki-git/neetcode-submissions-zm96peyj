class MinStack {
public:
    stack<int> st;//class var
    stack<int> minst;//to store min ele till now
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minst.empty() || val <= minst.top()){
            minst.push(val);
        }
        else{
            minst.push(minst.top());
        }
        
    }
    
    void pop() {
        st.pop();
        minst.pop();//to keep both consistent i.e. both stacks must know that el got popped
        
    }
    
    int top() {
      
        return st.top();
        
    }
    
    int getMin() {
        return minst.top();


        
    }
};
