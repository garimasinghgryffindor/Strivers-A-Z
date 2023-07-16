// GREEDY 1
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int prevEnd = intervals[0][1];
        int n = intervals.size();
        for(int i=1 ; i<n ; i++) {
            if(intervals[i][0] >= prevEnd) {
                prevEnd = intervals[i][1];
            } else {
                prevEnd = min(prevEnd, intervals[i][1]);
                count++;
            }
        }
        
        return count;
    }
};


// the famous interval scheduling problem.
// GREEDY 2 (anyhoo, they are same, effectively)
class Solution {
public:
    static bool compare(vector<int> &a,vector<int> &b) {
        return a[1]<b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;
        sort(intervals.begin(), intervals.end(), compare);
        int nonOverLapCount = 1;
        int currEnd = intervals[0][1];
        for(int i=1 ; i<n ; i++) {
            if(intervals[i][0] >= currEnd) {
                nonOverLapCount++;
                currEnd = intervals[i][1];
            }  
        }
        
        return n - nonOverLapCount;
    }
};


