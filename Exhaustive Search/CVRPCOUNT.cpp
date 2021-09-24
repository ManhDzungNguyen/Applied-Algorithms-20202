/**
* Description:  A fleet of K identical trucks having capacity Q need to be scheduled to delivery pepsi packages from a central depot 0 to 
                clients 1,2,…,n. Each client i requests d[i] packages.
                    - Each client is visited exactly by one route
                    - Total number of packages requested by clients of each truck cannot exceed its capacity
                    - Each truck must visit at least one client
                Goal
                    - Compute number R of solutions
                Note that: the orders of clients in a route is important, e.g., routes 0 -> 1 -> 2 -> 3 -> 0 and 0 -> 3-> 2 -> 1 -> 0 are different.
* Input:    Line 1: n,K,Q (2≤n≤10,1≤K≤5,1≤Q≤20)
            Line 2: d[1],...,d[n] (1≤d[i]≤10)
* Output:   R mod 10^9+7
*/



#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n; // number of clients
int K; // number of trucks
int Q; // capacity of a truck
int d[N]; // demand of clients

// data structures for backtracking search
int y[N]; // y[k] the first client point of the route k
int x[N]; // x[v] is the next point of v on the route
bool visited[N];
int load[N]; // accumulated demand on the route under construction
int segments; // number of segments of the solution
int cnt; // number of solution

bool checkX(int v, int k){
    if(v == 0) return true;
    if(visited[v]) return false;
    if(load[k] + d[v] > Q) return false;
    return true;
}

void TryX(int s, int k){
    // try value for the next point of s (x[s]) on the kth route
    for(int v = 0; v <= n; v++){
        if(checkX(v,k)){
            x[s] = v;
            visited[v] = true;
            load[k] += d[v];
            segments += 1;
            if(v == 0){// return to he depot
                    if(k == K){
                        if(segments == n + K)
                            cnt++;
                    }else{
                        TryX(y[k+1],k+1);
                    }
            }else{
                TryX(v,k);
            }
            // recover
            visited[v] = false;
            load[k] = load[k] - d[v];
            segments = segments - 1;
        }
    }
}

bool checkY(int v, int k){
    if(visited[v]) 
        return false;
    if(load[k] +d[v] > Q) 
        return false;
    return true;
}

void TryY(int k){
    for(int v = y[k-1]+1; v <= n; v++){
        if(checkY(v,k)){
            y[k] = v;
            visited[v] = true;
            load[k] = load[k] + d[v];
            segments += 1;
            if(k == K){
                    // After assign initial values ​​to y[], start trying x[i] from y[1];
                    TryX(y[1],1);
            }else{
                TryY(k+1);
            }
            // recover when backtracking
            segments -= 1;
            visited[v] = false;
            load[k] = load[k] - d[v];
        }
    }
}


void input(){
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
}

void solve(){
    y[0] = 0;
    d[0] = 0;
    segments = 0;
    cnt =0;
    memset(load, 0, sizeof(load));
    memset(visited, false, sizeof(visited));

    TryY(1);

    cout << cnt << endl;
}

int main(){
    input();
    solve();

}