/**
* Description:  The Kingdom ALPHA has n warehouses of golds located on a straight line and are numbered 1,2,...,n. 
                The warehouse i has amount of ai (ai is non-negative integer) and is located at coordinate i (i=1,...,n). 
                The King of ALPHA opens a competition for hunters who are responsible to find a subset of gold warehouses 
                having largest total amount of golds with respect to the condition that the distance between two selected 
                warehouses must be greater than or equal to L1 and less than or equal to L2.
* Input:    Line 1 contains n, L1, and L2 (1≤n≤100000,1≤L1≤L2≤n)
            Line 2 contains n integers a1,a2,…,an
* Output:   Contains only one single integer denoting the total amount of golds of selected warehouses.
*/



#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6+5;
int n, L1, L2;
int a[MAX];
int F[MAX];

int u_index(int x){
    if(x<1)
        return 1;
    return x;
}

int main(){
    cin >> n >> L1 >> L2;
    memset(F, 0, sizeof(F));
    int res = 0;
    for(int i=1; i<=L1; i++){
        cin >> a[i];
        F[i] = a[i];
        res = max(res, F[i]);
    }
    for(int i=L1+1; i<=n; i++){
        cin >> a[i];
        for(int j = u_index(i-L2); j<=u_index(i-L1); j++)
            F[i] = max(F[i], F[j]+a[i]);
        res = max(res, F[i]);
    }

    cout << res <<endl;

}