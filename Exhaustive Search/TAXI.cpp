/**
* Description:  There are n passengers 1,2,…,n. The passenger i want to travel from point i to point i+n(i=1,2,…,n). 
                There is a taxi located at point 0 for transporting the passengers. Given the distance matrix c(2n+1)∗(2n+1) 
                in which c(i,j) is the traveling distance from point i to point j(i,j=0,1,…,2n) 
                Compute the shortest route for the taxi, serving n passengers and coming back to point 0 such that at any moment, 
                there are no more than one passenger in the taxi, and no point is visited more than once (except for point 0, which can be visited up to twice).
* Input:    Line 1 contains n(1≤n≤11). Line i+1(i=1,2,…,2n+1) contains the ith line of the matrix c.
* Output:   Unique line contains the length of the shortest route.
*/



#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int n;
int c[2*N+1][2*N+1];
int min_c = INT_MAX;
bool visited[N];
int state[N];
int min_route = INT_MAX;
int cur_route;

void TRY(int k){
    if(k == n){
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                state[k] = i;
                cur_route += c[state[k-1] + n][i];
                cur_route += c[i + n][0];

                min_route = min(min_route, cur_route);

                cur_route -= c[state[k-1] + n][i];
                cur_route -= c[i + n][0];
            }

        }
    } else{
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                visited[i] = true;
                state[k] = i;
                cur_route += c[state[k-1] + n][i];
                
                int best_route = cur_route + (n+1-k)*min_c;
                if (best_route <= min_route){
                    TRY(k+1);
                }
                cur_route -= c[state[k-1] + n][i];
                visited[i] = false;
            }

        }
    }

}

int main(){
    cin >> n;
    for(int i =0; i<=2*n; i++)
        for(int j=0; j<=2*n; j++){
            cin>>c[i][j];
            min_c = min(min_c, c[i][j]);
        }
    
    memset(visited, false, sizeof(visited));
    
    int cash_route = 0;
    for(int i=1; i<=n; i++){
        cash_route += c[i][i+n];
    }

    cur_route = 0;
    for(int i=1; i<=n; i++){
        state[1] = i;
        visited[i] = true;
        cur_route += c[0][i];
        TRY(2);
        cur_route -= c[0][i];
        visited[i] = false;
    }

    int total_route = cash_route + min_route;
    cout << total_route;

    return 0;
}