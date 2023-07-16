// my first approach
// TLE

class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 0;
        int n = ratings.size();
        int x = n;
        if(n == 1) {
            return 1;
        }
        // firstly i would be finding the minimest point
        // i.e; that point which is less that equal to its neighbours
        // that would be our termination point
        // there could be a possibility that there are more than one termination points
        vector<int>candies(n,-1);
        for(int i=0 ; i<n ; i++) {
            if(i == 0) {
                // first child
                if(ratings[i] <= ratings[i+1]) {
                    candies[i] = 1;
                    x--;
                } 
            }
            else if(i == n-1) {
                // last child
                if(ratings[i] <= ratings[i-1]) {
                    candies[i] = 1;
                    x--;
                }
            }
            else {
                if(ratings[i] <= ratings[i-1] && ratings[i] <= ratings[i+1]) {
                    candies[i] = 1;
                    x--;
                }
            }
        }
        
        
        // now all the termination points are set
        // and we will set all the other elements
        
        while(x) {
            
        
        for(int i=0 ; i<n ; i++) {
            if(candies[i] == -1) {
                if(i == 0 && candies[i+1] != -1) {
                    // first element
                    candies[i] = candies[i+1] + 1;
                    x--;
                }
                else if(i == n-1 && candies[i-1] != -1) {
                    // last element
                    candies[i] = candies[i-1] + 1;
                    x--;
                }
                else if(i>0 && i<n) {
                    int flag = 0;
                    if(ratings[i] > ratings[i-1] && candies[i-1] != -1 && ratings[i]<=ratings[i+1]) {
                        candies[i] = candies[i-1] + 1;
                        flag = 1;
                    }
                    else if(ratings[i] > ratings[i+1] && candies[i+1] != -1 && ratings[i]<=ratings[i-1]) {
                        candies[i] = max(candies[i+1] + 1, candies[i]);
                        flag = 1;
                    } else {
                        if(candies[i-1] != -1 && candies[i+1] != -1) {
                            candies[i] = max(candies[i-1], candies[i+1]) + 1;
                            flag = 1;
                        }
                    }
                    
                    if(flag) {
                        x--;
                    }
                }
            }
        }
            
        }
        
        for(auto x: candies) {
            cout<<x<<"   ";
            res += x;
        }
        return res;
    }
};



// BRUTE FORCE
// USING EXTRA O(N) SPACE
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n <= 1) {
            return n;
        }
        vector<int>candies(n, 1);
        map<int,vector<int>>mp;
        
        for(int i=0 ; i<n ; i++) {
            mp[ratings[i]].push_back(i);
        }
        
        
        for(auto rating: mp) {
            for(auto pos: rating.second) {
                // comparing with left candidates
                if(pos > 0 && ratings[pos] > ratings[pos-1]) {
                    candies[pos] = max(candies[pos], candies[pos-1] + 1);
                }
                
                 // comparing with right candidates
                if(pos < n-1 && ratings[pos] > ratings[pos+1]) {
                    candies[pos] = max(candies[pos], candies[pos+1] + 1);
                }
                
            }
        }
        
        int res = 0;
        for(int x: candies)
            res += x;
        
        return res;
    }
};



// GREEDY
// USING EXTRA O(N) SPACE
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n <= 1) {
            return n;
        }
        vector<int>candies(n, 1);
        
        // comparing with left candidates
        for(int i=1 ; i<n ; i++) {
            if(ratings[i] > ratings[i-1]) {
                candies[i] = 1 + candies[i-1];
            }
        }
        
        // comparing with right candidates
        for(int i=n-2 ; i>=0 ; i--) {
            if(ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], 1 + candies[i+1]);
            }
        }
        
        int res = 0;
        for(int x: candies)
            res += x;
        
        return res;
    }
};


// [1 , 2, 3, 1 , 3, 2 , 1]


