/**
* Description:  Farmer John has built a new long barn, with N (2≤N≤100,000) stalls. The stalls are located along a straight line at positions x1,…,xN (0≤xi≤1,000,000,000).
                His C (2≤C≤N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, 
                FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
* Input:    t – the number of test cases, then t test cases follows.
                - Line 1: Two space-separated integers: N and C
                - Lines 2…N+1: Line i+1 contains an integer stall location, xi
* Output:   For each test case output one integer: the largest minimum distance.
*/



#include <bits/stdc++.h>
using namespace std;

const int max_N  = 1e6 +5;
int N, C;
long long x[max_N];

bool check(int step){
    int cow_left = C-1;
    int last_stall = x[1];
    for(int i=2; i<=N; i++){
        if(x[i]- last_stall >= step){
            cow_left--;
            last_stall = x[i];
            if(cow_left == 0)
                return true;
        }
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        cin >> N >> C;
        for(int i=1; i<=N; i++){
            cin >> x[i];
        }

        sort(x+1, x+N+1);

        int l = 0;
        int r = x[N]- x[1]+1;

        while(r-l>1){
            int mid = (r+l)/2;
            if(check(mid)){
                l=mid;
            } else{
                r=mid;
            }
        }
        cout << l << endl;

    }

    return 0;
}