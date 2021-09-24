/**
* Description:  There is a container having horizontal size W and vertical size H. There are N rectangle items 1, 2, ..., N 
                in which item i has horizontal size wi and vertical size hi. Find the way to place these N items into the container such that
                    - The sides of items are packed in parallel with the sides of the container
                    - The items cannot rotated
                    - No two items overlap.
* Input:    The input consists of following lines
                - Line 1: contains two integer H and W (1≤H,W≤30)
                - Line 2: contains N (1≤N≤12)
                - Line i+2 (∀i=1,…,N): contains two integers hi and wi
* Output:   The output contains a unique number 0 (if we cannot place items) or 1 (if we can place items)
*/



#include <bits/stdc++.h>
using namespace std;

const int MAX = 35;
int H, W, N;
int h[MAX];
int w[MAX];
int cnt;
bool fre[MAX][MAX];

bool check(int Wi, int Hi, int k){
    for(int wi = Wi; wi <= Wi+w[k]-1; wi++){
        for(int hi = Hi; hi <= Hi+h[k]-1; hi++){
            if(!fre[wi][hi]) return false;
        }
    }
    return true;
}

void mark(int Wi, int Hi, int k){
    for(int wi = Wi; wi <= Wi+w[k]-1; wi++){
        for(int hi = Hi; hi <= Hi+h[k]-1; hi++){
            fre[wi][hi] = false;
        }
    }
}

void unmark(int Wi, int Hi, int k){
    for(int wi = Wi; wi <= Wi+w[k]-1; wi++){
        for(int hi = Hi; hi <= Hi+h[k]-1; hi++){
            fre[wi][hi] = true;
        }
    }
}

void TRY(int k){
    for(int Wi = 1; Wi<= W-w[k]+1; Wi++){
        if(cnt == 1) break;
        for(int Hi=1; Hi<= H-h[k]+1; Hi++){
            if(cnt == 1) break;
            if(check(Wi, Hi, k)){
                if(k==N)
                    cnt++;
                else{
                    mark(Wi, Hi, k);
                    TRY(k+1);
                    unmark(Wi, Hi, k);
                }
            }
        }
    }
}

void input(){
    cin >> H >> W;
    cin >> N;
    for(int i =1; i<=N; i++){
        cin >> h[i] >> w[i];
    }
}

int main(){
    input();

    memset(fre, true, sizeof(fre));
    cnt = 0;

    TRY(1);
    cout << cnt << endl;

}