class Solution {
public:
   int findfirst(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int result=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                result=mid;
                e=mid-1;
            }else if (nums[mid]<target){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
return result;
    }
   int findlast(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int result=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                result=mid;
                s=mid+1;
            }else if (nums[mid]<target){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
return result;
    }
    vector<int>searchRange(vector<int>&nums,int target){
        int first=findfirst(nums,target);
        int last=findlast(nums,target);
        return {first,last};
    }
};