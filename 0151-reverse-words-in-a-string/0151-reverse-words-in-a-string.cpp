class Solution {
public:
    string reverseWords(string s) {
        // Remove leading/trailing spaces
        int left = 0, right = s.size() - 1;
        while (left <= right && s[left] == ' ') left++;
        while (right >= left && s[right] == ' ') right--;

        // Split words
        vector<string> words;
        string word;
        for (int i = left; i <= right; i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        if (!word.empty()) words.push_back(word);

        // Reverse order of words
        reverse(words.begin(), words.end());

        // Join with single space
        string result;
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) result += ' ';
        }
        return result;
    }
};
