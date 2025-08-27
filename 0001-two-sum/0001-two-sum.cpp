class Solution {
public:
    vector<int> twoSum(vector<int>&nums, int target) {
    //     int n=arr.size();
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             if(i==j)continue;
    //             if(arr[i]+arr[j]==target){
    //                 return{i,j};
    //             }
    //         }
    //     }
    //     return{};
    // }
    //by using hashing
    //by using greedy
    // int n=arr.size();
    // vector<pair<int,int>>temp;
    // for(int i =0;i<n;i++){
    //     temp.push_back({arr[i],i});
    // }
    // sort(temp.begin(),temp.end());
    // int left=0;
    // int right=n-1;
    // sort(arr.begin(),arr.end());
    // while(left<right){
    //     int sum=arr[left].first+arr[right].first;
    //     if(sum==target){
    //         return{temp[left].second,temp[right].first};
    //         if(sum==target){
    //         return {temp[left].second, temp[right].second};
    //     }
    //     else if(sum<target)left++;
    //     else right--;
    // }
    // return {};
   unordered_map<int,int> m; // value -> index

        for(int i=0; i<nums.size(); i++){
            int need = target - nums[i];
            
            if(m.find(need) != m.end()){ 
                return {m[need], i}; // found the pair
            }
            
            m[nums[i]] = i; // store index of current number
        }
        return {};
    }  
};