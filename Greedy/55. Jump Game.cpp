// BRUTE FORCE
class Solution {
public:
    void recur(vector<int>&nums,bool&ans,int idx) {
        if(ans) {
            return;
        }
        if(idx == nums.size()-1) {
            ans = true;
            return;
        }
        
        int maxJump = nums[idx];
        for(int jump = 1 ; jump <= maxJump ; jump++) {
            int jumpPosition = idx+jump;
            int maxPossibleJump = nums.size()-1;
            int newIndex = min(maxPossibleJump, jumpPosition);
            recur(nums,ans,newIndex);
            if(ans) {
                return;
            }
        }
    }
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // let us try recursion
        bool ans = false;
        recur(nums,ans,0);
        return ans;
    }
};


// DP
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) {
            return true;
        }
        
        vector<bool>dp(n-1,false);
        dp[0] = true;
        
        for(int i=0 ; i<n ; i++) {
            int maxJump = nums[i];
            if(dp[i]) {
                for(int jump=1 ; jump<=maxJump ; jump++) {
                    int maxPossibleIdx = nums.size()-1;
                    int jumpIdx = i+jump;
                    int newIdx = min(jumpIdx, maxPossibleIdx);
                    dp[newIdx] = true;
                    if(newIdx == n-1) {
                        return true;
                    }
                }
            }
        }
        
        return dp[n-1];
    }
};


// MEMOIZATION
class Solution {
public:
    bool recur(vector<int>nums,vector<int>&dp,int idx) {
        if(idx == nums.size()-1) {
            return true;
        }
        if(nums[idx] == 0) {
            return false;
        }
        if(dp[idx] != -1) {
            return dp[idx];
        }
        
        for(int jump = 1 ; jump<=nums[idx] ; jump++) {
            int jumpPosition = idx + jump;
            if(jumpPosition < nums.size() && recur(nums,dp,jumpPosition)) {
                dp[jumpPosition] = true;
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return recur(nums,dp,0);
    }
};



// GREEDY APPROACH
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // ALL YOU NEED TO DO IS CALCULATE MAXIMUM REACH
        // resembles kadane's algorithm
        int reach = 0;
        for(int i=0 ; i<n ; i++) {
            if(reach < i) {
                return false;
            }
            reach = max(reach, i + nums[i]);
        }
        return true;
    }
};




