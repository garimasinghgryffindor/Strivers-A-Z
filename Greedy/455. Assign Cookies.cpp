// BRUTE FORCE
class Solution {
public:
    void recur(vector<int>g,vector<int>s,int idx,int ans,vector<bool>cookies,int&content) {
        content = max(content, ans);
        if(idx == g.size()) {
            return;
        }
        
        // child g[idx] can have any of the valid cookies provided it is not taken by anyone else
        for(int i=0 ; i<s.size() ; i++) {
            if(cookies[i] == false && g[idx] <= s[i]) {
                // i can have that cookie
                cookies[i] = true;
                recur(g,s,idx+1,ans+1,cookies,content);
                cookies[i] = false;
            }
            recur(g,s,idx+1,ans,cookies,content);
        }
    }
    
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int content = 0;
        // since I have to see the number of possibilities or combinations
        // I will be using recursion for brute force
        // let's give it a try
        
        int ans = 0;
        vector<bool>cookies(s.size(),false);
        recur(g,s,0,ans,cookies,content);
        
        return content;
    }
};



// GREEDY APPROACH

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        if(s.size()==0 || g.size()==0)
            return 0;
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int content=0;
        int i=0, j=0;
        
        // i-> index of children  &  j-> index of cookies
        for(j=0 ; j<s.size() ; j++) {
            if(s[j] >= g[i]) {
                content++;
                i++;
            }
            if(i == g.size()) {
                break;
            }
        }
        
        return content;
    }
};
