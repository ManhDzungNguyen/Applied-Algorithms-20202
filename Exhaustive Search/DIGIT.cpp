/**
* Description:  Write C program that reads an integer value N from stdin, prints to stdout the number Q ways to assign 
                values 1, 2, …, 9 to characters I,C,T,H,U,S,K (characters are assigned with different values) such that: ICT−K62+HUST=N
* Input:    Unique line contains an integer N (1≤N≤105)
* Output:   Write the value Q
*/



#include <bits/stdc++.h>
using namespace std;

int a[8];
bool visited[10];
int cnt = 0;
int N;
int mx[] = {0, 9, 9, 9, 1, 9, 9, 9};
int mn[] = {0, 1, 1, 1, 9, 1, 1, 1};


bool check(int i, int k){
    //cout<< "k1: " <<k  <<endl;
    if(visited[i]) return false;
    //cout<< "k2: " <<k  <<endl;
    if(k == 7){
        int result = a[1]*1000 + (a[2] + a[3] - a[4])*100 + (a[5] + a[6])*10 + 2*i - 62;
        if (result == N) return true;
        else return false;
    }

    int d[8];
    for(int j = 1; j < k; j++){
        d[j] = a[j];
    }
    d[k] = i;
    for(int j = k+1; j <= 7; j++){
        d[j] = mx[j];
    }
    int result = d[1]*1000 + (d[2] + d[3] - d[4])*100 + (d[5] + d[6])*10 + 2*d[7] - 62;
    if(result < N)
        return false;

    for(int j = k+1; j <= 7; j++){
        d[j] = mn[j];
    }
    result = d[1]*1000 + (d[2] + d[3] - d[4])*100 + (d[5] + d[6])*10 + 2*d[7] - 62;
    if(result > N)
        return false;

    return true;
}

void TRY(int k){
    for(int i = 1; i <=9; i++){
        if(check(i, k)){
            a[k] = i;
            visited[i] = true;
            if(k == 7)
                cnt++;
            else
                TRY(k+1);
            visited[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int v = 1; v <= 9; v++) visited[v] = false;
    cnt = 0;
    TRY(1);
    cout <<cnt<<endl;

    return 0;

}