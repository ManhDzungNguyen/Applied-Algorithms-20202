/**
* Description:  There are n passengers 1,2,…,n. The passenger i want to travel from point i to point i+n(i=1,2,…,n). 
                There is a bus located at point 0 and has k places for transporting the passengers 
                (it means at any time, there are at most k passengers on the bus). 
                You are given the distance matrix c in which c(i,j) is the traveling distance from point i to point j(i,j=0,1,…,2n). 
                Compute the shortest route for the bus, serving n passengers and coming back to point 0 without visiting any point more than once (except for the point 0).
* Input:    Line 1 contains n and k(1≤n≤11,1≤k≤10). 
            Line i+1(i=1,2,…,2n+1) contains the (i−1)th line of the matrix c (rows and columns are indexed from 0,1,2,..,2n).
* Output:   Unique line contains the length of the shortest route.
*/



#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int n, K;
int c[MAX][MAX];
int min_c;
int visited[MAX];
int x[MAX];
int load;
int result;
int curr_route;

bool check(int i, int k){
    if(visited[i]) return false;
    if((i<=n) && (load>=K)) return false;
    if((i>n) && (!visited[i-n])) return false;
    int best_opt = curr_route + c[x[k-1]][i] + min_c*(2*n-k+1);
    if(best_opt >= result) return false;
    return true;
}


void TRY(int k){
    for(int i = 1; i<=2*n; i++){
        if(check(i, k)){
            x[k] = i;
            if(k == 2*n){
                curr_route += c[x[k-1]][i];
                curr_route += c[i][0];
                result = min(result, curr_route);
                curr_route -= c[i][0];
                curr_route -= c[x[k-1]][i];
            }
            else{
                if(i<=n) load++;
                else load--;
                visited[i] = true;
                curr_route += c[x[k-1]][i];


                TRY(k+1);

                curr_route -= c[x[k-1]][i];
                visited[i] = false;
                if(i<=n) load--;
                else load++;
            }
        }
    }
}

void input(){
    cin >> n >> K;
    min_c = INT_MAX;
    for(int i =0; i<=2*n; i++){
        for(int j=0; j<=2*n; j++){
            cin >> c[i][j];
            if(i!=j)
                min_c = min(min_c, c[i][j]);
        }

    }
}

int main(){
    input();

    result = INT_MAX;
    x[0] = 0;
    load = 0;
    curr_route = 0;
    memset(visited, false, sizeof(visited));


    TRY(1);

    cout << result << endl;
    return 0;
}