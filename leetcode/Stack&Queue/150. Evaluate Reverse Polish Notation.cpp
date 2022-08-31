class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int s = st.top();
                st.pop();
                int f= st.top();
                st.pop();
                if (tokens[i] == "+") st.push(f + s);
                if (tokens[i] == "-") st.push(f - s);
                if (tokens[i] == "*") st.push(f * s);
                if (tokens[i] == "/") st.push(f / s);
            }
            else{
                st.push(stoi(tokens[i]));
            }
                
        }
        return st.top();
    }
};
