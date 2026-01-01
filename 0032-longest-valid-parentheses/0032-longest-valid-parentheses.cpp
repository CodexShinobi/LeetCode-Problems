class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> st;
        // base index
        st.push(-1);

        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    // new base index
                    st.push(i);
                } else {
                    int len = i - st.top();
                    maxLen = max(maxLen, len);
                }
            }
        }

        return maxLen;
    }
};
