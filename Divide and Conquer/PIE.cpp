/**
* Description:  My birthday is coming up and traditionally I'm serving pie. Not just one pie, no, I have a number N of them, 
                of various tastes and of various sizes. F of my friends are coming to my party and each of them gets a piece of pie. 
                This should be one piece of one pie, not several small pieces since that looks messy. This piece can be one whole pie though. 
                My friends are very annoying and if one of them gets a bigger piece than the others, they start complaining. 
                Therefore all of them should get equally sized (but not necessarily equally shaped) pieces, even if this leads to some pie getting spoiled 
                (which is better than spoiling the party). Of course, I want a piece of pie for myself too, and that piece should also be of the same size. 
                What is the largest possible piece size all of us can get? All the pies are cylindrical in shape and they all have the same height 1, 
                but the radii of the pies can be different.
* Input:    One line with a positive integer: the number of test cases. Then for each test case:
                - One line with two integers N and F with 1≤N,F≤10000: the number of pies and the number of friends. 25% of tests has N,F≤10 and 25% of test has solution ≤0.1.
                - One line with N integers ri with 1≤ri≤10000: the radii of the pies.
* Output:   For each test case, output one line with the largest possible volume V such that me and my friends can all get a pie piece of size V. 
            The answer should be given as a floating point number rounding to 6 digits after the floating point (accept error ≤10−6).
*/



#include <bits/stdc++.h>
#include <cmath>
using namespace std;

const double pi = 3.14159265358979323846;
const int N = 10004;
int n, F;
int r[N];

int count_pie(double m){
    int cnt =0;

    for(int i=1; i <=n; i++){
        cnt += (int)floor(pi * r[i] * r[i] /m); // floor: hàm làm tròn xuống
    }
    return cnt;
}

int main(){
    int nTest;
    cin >>nTest;
    for(int tc =1; tc <= nTest; tc++){
        cin >>n >>F;
        for(int i =1; i<=n ; i++)
            cin >> r[i];

        double l =0, r =4e8;
        double esp = 1e-6;
        while (r - l > esp){
            double m = (l+r )/2;
            if(count_pie(m)>=F+1) l=m;
            else r=m;
        }
        printf("%.6f\n", l);
    }


    
}