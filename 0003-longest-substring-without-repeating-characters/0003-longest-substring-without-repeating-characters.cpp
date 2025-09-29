class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    // vector<int> lastIndex(256,-1);
    // int maxLen=0,start=0;

    // for(int i=0;i<s.size();i++){
    //     if(lastIndex[s[i]]>=start){
    //         start=lastIndex[s[i]]+1;
    //     }
    //     lastIndex[s[i]]=i;
    //     maxLen=max(maxLen,i-start+1);
    // }
    // return maxLen;
        
        unordered_set<char> window;
        int left=0,maxLen=0;

        for(int right=0;right<s.size();right++){
            while(window.count(s[right])){
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};