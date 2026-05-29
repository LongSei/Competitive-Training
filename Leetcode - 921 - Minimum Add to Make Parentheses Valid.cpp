class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st; 
        int s_size = s.size(); 
        for (int index = 0; index < s_size; index++) {
            if (st.empty() == false && (st.top() == '(' && s[index] == ')')) {
                    st.pop(); 
            } else {
                st.push(s[index]);
            }
        }
        return st.size(); 
    }
};
