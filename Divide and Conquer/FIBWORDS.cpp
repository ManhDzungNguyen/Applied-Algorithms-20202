/**
* Description:  The Fibonacci word sequence of bit strings is defined as:
                                F(n) =  0 if n = 0
                                     =  1 if n = 1
                                     =  F(n − 1) + F(n − 2) if n ≥ 2
                Here denotes concatenation of strings. The first few elements are:
                n                               F(n)
                0                                 0
                1                                 1
                2                                10
                3                               101
                4                              10110
                5                             10110101
                6                           1011010110110
                7                       101101011011010110101
                8               1011010110110101101011011010110110
                9   1011010110110101101011011010110110101101011011010110101
                Given a bit pattern p and a number n, how often does p occur in F(n)?
* Input:    The first line of each test case contains the integer n (0 ≤ n ≤ 100). The second line contains the bit
            pattern p. The pattern p is nonempty and has a length of at most 100 000 characters.
* Output:   For each test case, display its case number followed by the number of occurrences of the bit pattern p in
            F(n). Occurrences may overlap. The number of occurrences will be less than 2^63.
*/



#include <bits/stdc++.h>
using namespace std;

const int M =25;
string fibo[M+5];
long long dp[105];

long long count_p(string st, string p){
    long long ans = 0;
    for(int i=0; i + p.size()-1 <st.size(); i++){
        bool ok = true;
        for(int j=0; j<p.size(); j++){
            if(p[j] != st[i+j]){
                ok = false;
                break;
            }
        }
        ans += ok ? 1 : 0;
    }
    return ans;
}

string suffix(string st, int l){
    return st.substr(st.size() -l);
}

string prefix(string st, int l){
    return st.substr(0,l);
}

long long calc(int n, string p){
    if (n < M){
        return count_p(fibo[n], p);
    }

    long long ret = dp[n];
    if (ret != -1)
        return ret;

    ret = calc(n-1, p) + calc(n-2, p);
    int l = p.size();
    string mid = suffix(fibo[M + (n%2)], l-1) + prefix(fibo[M], l-1);
    ret += count_p(mid, p);
    dp[n] = ret;
    return ret;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string p;
    int ntest =1;
    while (cin >>n >> p){
        fibo[0] = "0";
        fibo[1] = "1";
        for(int i = 2; i <= M+1; i++){
            fibo[i] = fibo[i-1] + fibo [i-2];
        }
        memset(dp, -1, sizeof(dp));
        cout << "Case " << ntest << ": " 
             << calc(n, p) << endl;
        ntest++;
    }
    return 0;
}