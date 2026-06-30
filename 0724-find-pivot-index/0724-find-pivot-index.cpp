class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int totalSum=0;
      for(int num:nums)totalSum+=num;

      int leftSum=0;

      for(int i=0;i<nums.size();i++)
{
    int rightsum=totalSum-leftSum-nums[i];

    if(leftSum==rightsum)
    return i;

    leftSum+=nums[i];
}    
return -1;
}
};