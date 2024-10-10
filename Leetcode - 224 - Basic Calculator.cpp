class Solution {
public:
    int calculate(string s) {
        stack<string> st;
        int result; 
        s = "(" + s + ")";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (s[i] == ')') {
                    int acc = 0;
                    while (st.empty() == false && st.top() != "(") {
                        int value = stoi(st.top());
                        st.pop();
                        if (st.empty() == false && (st.top() == "+" || st.top() == "-")) {
                            int symbol = (st.top() == "+" ? 1 : -1);
                            value *= symbol;
                            st.pop();
                        }
                        acc += value;
                    }
                    st.pop();
                    st.push(to_string(acc));
                }
                else if (s[i] == '(') {
                    string add = "";
                    add += s[i];
                    st.push(add);
                }
                else {
                    if (s[i] == '+' || s[i] == '-') {
                        string add = "";
                        add += s[i];
                        st.push(add);
                    }
                    else {
                        string newAdd = "";
                        newAdd += s[i];
                        while (i + 1 < s.size() && s[i + 1] != '(' && s[i + 1] != ')' && s[i + 1] != '+' && s[i + 1] != '-' && s[i + 1] != ' ') {
                            i += 1;
                            newAdd += s[i];
                        }
                        st.push(newAdd);
                    }
                }
            }
        }
        return stoi(st.top());
    }
};