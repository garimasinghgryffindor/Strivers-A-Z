// GREEDY APPROACH

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        // sort(bills.begin(), bills.end());
        int n = bills.size();
        int i;
        for(i=0 ; i<n ; i++) {
            if(bills[i] == 5) {
                // A Ok
                five++;
            } else if(bills[i] == 10) {
                // i will have to give a change of 5 back to the user
                // so i need to check if i have 5 or not
                if(five == 0) {
                    return false;
                } else {
                    ten++;
                    five--;
                }
            } else {
                // i will have to give a change of 15 back to the user
                // so there are two ways in which i can do so
                // -> 5 + 10
                // -> 5 + 5 + 5
                if(five >= 1 && ten >= 1) {
                    twenty++;
                    five--;
                    ten--;
                } else if(five >= 3) {
                    // good
                    twenty++;
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};
