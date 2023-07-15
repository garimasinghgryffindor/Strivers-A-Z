// // BRUTE FORCE
// // using RECUSION
class Solution {
public:
    void recur(string s,int idx,bool&ans,int sum) {
        if(ans == true || idx == s.length()) {
            if(sum == 0) {
                ans = true;
            }
            return;
        }
        
        if(s[idx] == '(') {
            recur(s,idx+1,ans,sum+1);
        } else if(s[idx] == ')') {
            recur(s,idx+1,ans,sum-1);
        } else {
            // it can be used either as '(' 
            recur(s,idx+1,ans,sum+1);
            // or as ')'
            recur(s,idx+1,ans,sum-1);
            // or as empty
            recur(s,idx+1,ans,sum);
        }
    }
    
    bool checkValidString(string s) {
        bool ans = false;
        int sum = 0;
        recur(s,0,ans,sum);
        return ans;
    }
};


// GREEDY APPROACH
class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, right = 0;
        for(auto x: s) {
            if(x == '(') {
                left++;
                right++;
            } else if(x == ')') {
                left--;
                right--;
            } else {
                left--;
                right++;
            }
            
            // because -> )( is invalid
            if(right < 0) {
                break;
            }
            
            // because -> ((****))
            left = max(0, left);
        }
        
        return left == 0;
    }
};

