// GREEDY
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int start = 0;
        int end = n-1;
        // two-pointer approach
        while(start <= end) {
            if(newInterval[0] == intervals[start][0]) {
                break;
            }
            if(newInterval[0] > intervals[start][0]) {
                start++;
            } else if(newInterval[0] < intervals[end][0]) {
                end--;
            }
        }
        
        intervals.insert(intervals.begin()+start, newInterval);
        
        // now we can perform merging
        // I'll be using a separate DS for that
        vector<vector<int>>res;
        res.push_back(intervals[0]);
        
        for(int i=1 ; i<=n ; i++) {
            if(res.back()[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            } else {
                // merge
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        
        return res;
    }
};
