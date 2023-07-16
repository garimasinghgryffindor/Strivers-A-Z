#include <bits/stdc++.h> 
// GREEDY
void swap(pair<int,int>&a, pair<int,int>&b){
    auto x = a;
    a = b;
    b = x;
}

vector<float> sjf(int n, vector<int> &arrivalTime, vector<int> &burstTime) 
{
    vector<pair<int,int>>process;
    int minArr = 0;
    for(int i=0 ; i<n ; i++) {
        process.push_back({arrivalTime[i], burstTime[i]});
        if(arrivalTime[i] < arrivalTime[minArr]) {
            minArr = i;
        } else if(arrivalTime[i]==arrivalTime[minArr] && burstTime[i]<burstTime[minArr]) {
            minArr = i;
        }
    }

    if(minArr != 0){
        swap(process[0], process[minArr]);
    }


    int ct=process[0].first + process[0].second, track = 1;

    for(int i = 1 ; i<n ; i++){
        int min = INT_MAX;
        int min_in = i;
        for(int j=i ; j<n ; j++){
            if(process[j].first <= ct && process[j].second < min){
                min = process[j].second;
                min_in = j;
            }
        }
        if(min_in != i){
            swap(process[i] , process[min_in]);
        }
        ct += process[i].second;
    }

    vector<int>tat(n,0);
    vector<int>wt(n,0);

    tat[0]=process[0].second;
    wt[0] = 0;
    int sum_wait=wt[0], sum_tat = tat[0];
    for(int i=1 ; i<n ; i++){
        wt[i] = wt[i-1] + process[i-1].second + process[i-1].first - process[i].first;
        tat[i] = wt[i] + process[i].second;
        sum_tat += tat[i];
        sum_wait += wt[i];
    }
    
    float avg_wait=(float)sum_wait/n , avg_tat=(float)sum_tat/n;

    return {avg_wait, avg_tat};

}
