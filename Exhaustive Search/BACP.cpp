/**
* Description:  The BACP is to design a balanced academic curriculum by assigning periods to courses in a way 
                that the academic load of each period is balanced . There are N courses 1,2,…,N that must be assigned 
                to M periods 1,2,…,M. Each courses i has credit ci and has some courses as prerequisites. 
                The load of a period is defined to be the sum of credits of courses assigned to that period. 
                The prerequisites information is represented by a matrix AN×N in which Ai,j = 1 indicates that 
                courses i must be assigned to a period before the period to which the course j is assigned. 
                Compute the assignment such that the maximum load for all periods is minimal.
* Input:    Line 1 contains N and M (2≤N≤16,2≤M≤5)
            Line 2 contains c1,c2,…,cN
            Line i+2(i=1,…,N) contains the ith line of the matrix A
* Output:   Unique line contains that maximum load for all periods of the solution found
*/



#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int N, M;
int c[MAX];
int A[MAX][MAX];
int assigned[MAX];
int load[MAX];
int result;

int max_load(){
    int res = -1;
    for(int i = 1; i<=M; i++)
        res = max(res, load[i]);
    return res;
}

bool check(int k, int sem){
    if(assigned[k] > 0) return false;
    for(int i=0; i<N; i++){
        if (A[i][k] == 1 && assigned[i]>sem) return false;
        if (A[k][i] == 1 && assigned[i]<sem && assigned[i]>0) return false;
    }
    if (load[sem]+c[k]>=result) return false;
    return true;
}

void TRY(int k){
    for(int sem=1; sem<=M; sem++){
        if(check(k, sem)){
            load[sem] += c[k];
            assigned[k] = sem;
            if(k==N)
                result = min(result, max_load());
            else{
                TRY(k+1);
            }
            assigned[k] = 0;
            load[sem] -= c[k];

        }

    }
}


void input(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> c[i];
    }

    memset(A, 0, sizeof(A));
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin >>A[i][j];

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    memset(load, 0, sizeof(load));
    memset(assigned, 0, sizeof(assigned));
    result = INT_MAX;
    TRY(1);
    cout << result << endl;
    return 0;


}