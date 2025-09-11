class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        queue<int> q;

        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) == m.end()) {
                q.push(i);  // first time seeing this char → push index
            }
            m[s[i]]++;  // count occurrences
        }

        // remove indices from queue until we find unique char
        while (!q.empty() && m[s[q.front()]] > 1) {
            q.pop();
        }

        return q.empty() ? -1 : q.front();
    }
};
