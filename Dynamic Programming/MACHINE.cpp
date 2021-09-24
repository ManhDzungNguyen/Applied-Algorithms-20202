/**
* Description:  An engineer needs to schedule a machine to run on some given periods 1,…,n to produce a chemical product C. 
                Each period i is represented by a starting time point si and terminating time point ti (si<ti). Due to a technical constraint, 
                the machine must run on exactly two periods that are not overlap (two periods i and j are not overlap if ti<sj or tj<si). 
                If the machine is runned on the period i, then the amount of C it will produce is equal to the duration of the period i (which is equal to ti−si). 
                Help the engineer to select two not-overlap periods to run the machine such that the amount of C produced is maximal.
* Input:    Line 1: contains the positive integer n (2≤n≤2*10^6)
            Line i+1: contains two positive integer si and ti (1≤si<ti≤2*10^6)
* Output:   The output consists of only one single integer which is the amount of product C the machine will produce in the two selected periods. 
            In case there is no solution (there does not exist two periods that are not overlap), the output contains the value -1.
*/



#include <bits/stdc++.h>
using namespace std;

const unsigned  int MAX_N = 2e6 + 5;
int n;
int s[MAX_N], t[MAX_N], maxs[MAX_N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n;
    memset(maxs, 0, sizeof(maxs));
    for(int i = 0; i < n; i++){
        cin >> s[i]  >> t[i];
        maxs[t[i]] = max(maxs[t[i]], t[i] - s[i]);
    }

    for(int i = 1; i < MAX_N; i++){
        maxs[i]= max(maxs[i-1], maxs[i]);
    }

    int ans = -1;
    for(int i = 0; i < n; i++){
        if(maxs[s[i]-1]>0){
            ans = max(ans, maxs[s[i]-1] + t[i]-s[i]);
        }
    }
    cout << ans << endl;


}
