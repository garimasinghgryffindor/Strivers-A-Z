// // BRUTE FORCE
// // using recursion
// class Solution {
// public:
//     void recur(vector<int>nums,int idx,int&ans,int temp) {
//         if(idx == nums.size()-1) {
//             ans = min(ans, temp);
//             return;
//         }
        
//         int maxJump = idx + nums[idx];
//         int n = nums.size()-1;
//         int maxJumpPosition = min(maxJump,n);
//         for(int i=idx+1 ; i<=maxJumpPosition ; i++) {
//             recur(nums,i,ans,temp+1);
//         }
//     }
    
//     int jump(vector<int>& nums) {
//         // we have to return minimum number of jumps
//         int n = nums.size();
//         int ans = INT_MAX;
//         int temp = 0;
//         recur(nums,0,ans,temp);
//         return ans;
//     }
// };



// // BRUTE FORCE
// // using recursion
// class Solution {
// public:
//         int recur(vector<int>nums, int idx) {
//         if(idx >= nums.size()-1) {
//             return 0;
//         }
        
//         int minJumps = 10001;
//         for(int i=1 ; i<=nums[idx] ; i++) {
//             minJumps = min(minJumps, 1 + recur(nums,idx+i));
//         }
//         return minJumps;
//     }
    
//     int jump(vector<int>& nums) {
//         // we have to return minimum number of jumps
//         return recur(nums,0);
//     }
// };



// // BRUTE FORCE
// // using memoization
// class Solution {
// public:
//     int recur(vector<int>nums,int idx,vector<int>&dp) {
//         if(idx == nums.size()-1) {
//             return dp[idx] = 0;
//         }
        
//         int maxJump = idx + nums[idx];
//         int n = nums.size()-1;
//         int maxJumpPosition = min(maxJump,n);
//         for(int i=idx+1 ; i<=maxJumpPosition ; i++) {
//             dp[idx] = min(dp[idx], 1 + recur(nums,i,dp));
//         }
//         return dp[idx];
//     }
    
//     int jump(vector<int>& nums) {
//         // we have to return minimum number of jumps
//         int temp = 0;
//         vector<int>dp(nums.size(),10001);
//         return recur(nums,0,dp);
//     }
// };



// // BRUTE FORCE
// // using tabulation
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         // we have to return minimum number of jumps
//         int n = nums.size();
//         vector<int>dp(n,10001);
//         dp[n-1] = 0;
        
//         for(int i=n-2 ; i>=0 ; i--) {
//             int maxJump = i + nums[i];
//             int maxJumpPosition = min(maxJump,n-1);
//             for(int j=i+1 ; j<=maxJumpPosition ; j++) {
//                 dp[i] = min(dp[i], 1 + dp[j]);
//             }
//         }
        
//         return dp[0];
//     }
// };



// OPTIMAL APPROACH
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumpIndex = 0 , maxJump = 0 , jump = 0;
        
        for(int i=0 ; jumpIndex<nums.size()-1 ; i++)
        {
            maxJump = max(maxJump , i+nums[i]);
            if(i==jumpIndex)
            {
                jumpIndex = maxJump;
                jump++;
            }
        }
        
        return jump;
    }
};
