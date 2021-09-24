/**
* Description:  Vanya walks late at night along a straight street of length l, lit by n lanterns. 
                Consider the coordinate system with the beginning of the street corresponding to the point 0, and its end corresponding to the point l. 
                Then the i-th lantern is at the point ai. The lantern lights all points of the street that are at the distance of at most d from it, 
                where d is some positive number, common for all lanterns.

                Vanya wonders: what is the minimum light radius d should the lanterns have to light the whole street?
* Input:    The first line contains two integers n, l (1 ≤ n ≤ 1000, 1 ≤ l ≤ 109) — the number of lanterns and the length of the street respectively.
            The next line contains n integers ai (0 ≤ ai ≤ l). Multiple lanterns can be located at the same point. The lanterns may be located at the ends of the street.
* Output:   Print the minimum light radius d, needed to light the whole street. The answer will be considered correct if its absolute or relative error doesn't exceed 10^-9.
*/



#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;
int n, l;
int a[MAX];

void input(){
    cin >> n >> l;
    
    for(int i = 1; i <= n; i ++ ){
        cin >>a[i];
    }
}


int main(){
    input();
    sort(a+1, a+n+1);

    int tmp = 0;

    for(int i=1; i<n; i++){
        tmp = max(tmp, a[i+1]-a[i]);
    }
    double d = (double)tmp /2.0;
    if(d<a[1]) d = (double)a[1];
    tmp = l-a[n];
    if(d<(tmp)) d= (double)tmp;
    
    printf("%.10f\n", d);
    return 0;

}


