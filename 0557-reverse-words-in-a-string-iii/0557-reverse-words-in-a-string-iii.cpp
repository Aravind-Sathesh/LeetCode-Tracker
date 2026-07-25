class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack <char> st;
        string res = "";
        s+=' ';

        for (int i=0 ; i<=n ; i++) {
            if (s[i]!=' ') st.push(s[i]);
            else {
                while (!st.empty()) {
                    res+=st.top();
                    st.pop();
                }
                if (i!=n) res+=' ';
            }
        }

        return res;
    }
};