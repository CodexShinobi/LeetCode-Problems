class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        for(int num:nums)
{
    if(num!=0)temp.push_back(num);
}    
while(temp.size()<nums.size()){
    temp.push_back(0);
}
nums=temp;
    }
};