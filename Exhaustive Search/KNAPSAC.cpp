/**
* Description:  Một nhà thám hiểm cần đem theo một cái túi có trọng lượng không quá b. Có n đồ vật có thể đem theo. 
                Đồ vật thứ j có trọng lượng aj và giá trị sử dụng cj. Hỏi nhà thám hiểm cần đem theo những đồ vật nào 
                để cho tổng giá trị sử dụng là lớn nhất mà tổng trọng lượng đồ vật mang theo cái túi không vượt quá b?
* Input:    Dòng đầu tiên chứa hai số nguyên dương n,b (n≤30,b≤106).
            Dòng thứ j trong số n dòng tiếp theo mỗi dòng ghi ra hai số nguyên dương aj,cj≤106.
* Output:   Ghi ra duy nhất một số là tổng giá trị lớn nhất tìm được của các đồ vật cho vào túi.
*/



#include <bits/stdc++.h>
using namespace std;
 
int n,b;
const int N = 50;
int a[N], c[N];
int p[N];
int ans = 0;
int sumA, sumC;
 
void input(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>b;
    int x, y;
    for(int i=1; i<=n; i++){
        cin>>x>>y;
        a[i]=x;
        c[i]=y;
    }
}
 
void solution(){
    sumA =0;
    sumC = 0;
    for(int i=1; i<=n; i++){
        sumA += p[i]*a[i];
        sumC += p[i]*c[i];
    }
    if(sumA <= b) ans = max(ans, sumC);
}
 
 
void TRY(int k){
    if(sumA>b) return;
    if(k>n){
        ans = max(ans, sumC);
        return;
    }
    for(int i=0; i<=1; i++){
        p[k]=i;
        sumA += p[k]*a[k];
        sumC += p[k]*c[k];
        TRY(k+1);
        sumA -= p[k]*a[k];
        sumC -= p[k]*c[k];
    }
}
 
 
 
int main(){
    input();
    TRY(1);
    cout<<ans<<endl;
}