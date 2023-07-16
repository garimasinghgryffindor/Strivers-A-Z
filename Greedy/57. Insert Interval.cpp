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


// GREEDY
// APPROACH 2
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        int i=0;
        int n = intervals.size();
        while(i < n && newInterval[0] > intervals[i][1]) {
            res.push_back(intervals[i]);
            i++;
        }
        
        // merging the overlapping intervals;
        while(i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        
        // merging ends here
        while(i < n) {
            res.push_back(intervals[i]);
            i++;
        }
        
        return res;
    }
};
