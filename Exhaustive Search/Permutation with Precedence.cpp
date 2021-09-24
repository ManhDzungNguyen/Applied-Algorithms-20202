/**
* Description:  Given a positive integer n and a precedence set P of pairs {(a1,b1),…,(aK,bK)}. 
                Generated all permutations of 1,…,n such that ai must be before bi in each permutation (∀(ai,bi)∈P) in a lexicographic order.
* Input:    Line 1: contains a positive integer n and K (1≤n,K≤6)
            Line i+1 (i=1,…,K) contains ai and bi
* Output:   Each line: write a permutation (elements a reseparated by a space character) The final line contains the number of permutations generated.
*/



#include <bits/stdc++.h>
using namespace std;
int x[100];
int n;
int K;
int cnt;
int P[100][100];
bool visited[100];
bool check(int v, int k){
    if(visited[v]) return false;
    for(int i=1; i<=n; i++){
        if(P[v][i] ==1) return false;
    }
    return true;
}
void solution(){
    for(int i=1; i<=n; i++)
        cout<<x[i]<<" ";
    cout << endl;
    cnt++;
}

void Try(int k){// thu gia tri cho x[k] khi da biet x[1],..., x[k-1]
    for(int v=1; v<=n; v++){
        if(check(v,k)){
            x[k] = v;
            visited[v] = true;// update statue
            for(int i=1; i<=n; i++){
                if(P[i][v]==1) P[i][v]=-k;
            }
            if(k == n)
                solution();
            else Try(k+1);

            visited[v] = false;// recover when backtracking
            for(int i=1; i<=n; i++){
                if(P[i][v]==-k) P[i][v]=1;
            }
        }
    }
}

void input(){
    cin>>n>>K;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            P[i][j]=0;
        }
    }

    for(int i=1; i<=K; i++){
        int a,b;
        cin>>a>>b;
        P[b][a]=1;
    }

}

int main(){
    cnt=0;
    input();
    for(int v = 1; v <= n; v++) visited[v] = false;
    Try(1);
    cout<<cnt;
}
