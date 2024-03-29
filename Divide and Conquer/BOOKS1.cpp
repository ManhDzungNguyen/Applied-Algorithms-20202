/**
* Description:  Before the invention of book-printing, it was very hard to make a copy of a book. 
                All the contents had to be re-written by hand by so called scribers. 
                The scriber had been given a book and after several months he finished its copy. 
                One of the most famous scribers lived in the 15th century and his name was Xaverius Endricus Remius Ontius Xendrianus (Xerox). 
                Anyway, the work was very annoying and boring. And the only way to speed it up was to hire more scribers.

                Once upon a time, there was a theater ensemble that wanted to play famous Antique Tragedies. The scripts of these plays were divided 
                into many books and actors needed more copies of them, of course. So they hired many scribers to make copies of these books. 
                Imagine you have m books (numbered 1,2,…,m) that may have different number of pages (p1,p2,…,pm) and you want to make one copy of each of them. 
                Your task is to divide these books among k scribes, k≤m. Each book can be assigned to a single scriber only, 
                and every scriber must get a continuous sequence of books. That means, there exists an increasing 
                succession of numbers 0=b0<b1<b2,…<bk−1≤bk=m such that i-th scriber gets a sequence of books with numbers between bi−1+1 and bi. 
                The time needed to make a copy of all the books is determined by the scriber who was assigned the most work. 
                Therefore, our goal is to minimize the maximum number of pages assigned to a single scriber. Your task is to find the optimal assignment.
* Input:    The input consists of N cases (equal to about 200). The first line of the input contains only positive integer N. 
            Then follow the cases. Each case consists of exactly two lines. At the first line, there are two integers m and k, 1≤k≤m≤500. 
            At the second line, there are integers p1,p2,…,pm separated by spaces. All these values are positive and less than 10000000.
* Output:   For each case, print exactly one line. The line must contain the input succession p1,p2,…,pm divided into exactly k parts 
            such that the maximum sum of a single part should be as small as possible. Use the slash character ('/') to separate the parts. 
            There must be exactly one space character between any two successive numbers and between the number and the slash.
            If there is more than one solution, print the one that minimizes the work assigned to the first scriber, 
            then to the second scriber etc. But each scriber must be assigned at least one book.
*/



#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int max_m  = 505;
ll m, k;
ll p[max_m];
ll curr_idx[max_m];
ll valid_idx[max_m];


void update_idx(int idx, ll mid){
    ll sum = 0;
    ll max_step = curr_idx[idx];

    for(ll i = curr_idx[idx+1]-1; i>=max_step; i-- ){
        sum += p[i];
        if(sum == mid){
            curr_idx[idx] = i;
            break;
        } else if (sum > mid){
            curr_idx[idx]= i+1;
            break;
        }
    }
}

bool check(ll mid){
    for(int i=0; i<k; i++)
        curr_idx[i]=i;
    curr_idx[k] = m;

    for(int i=k-1; i>=0; i--)
        update_idx(i, mid);

    if(curr_idx[0]>0)
        return false;
    return true;
}


void solution(){
    for(int i=0; i<k-1; i++){
        for(int j=valid_idx[i]; j<valid_idx[i+1]; j++)
            cout << p[j] << " ";
        cout << "/ ";
    }

    for(int i=valid_idx[k-1]; i<m; i++){
        cout << p[i];
        if(i == m-1) break;
        cout << " ";
    }
    cout << endl;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int tc=0; tc<N; tc++){
        cin >> m >> k;

        ll max_page = 0; 
        ll sum_page = 0;


        for(int i=0; i<m; i++){
            cin >> p[i];
            if(p[i] > max_page) max_page = p[i];
            sum_page += p[i];
        }

        ll left  = max_page;
        ll right = sum_page;

        while(left<right){
            ll mid = (right + left)/2;
            if(check(mid)){
                right=mid;
                for(int i=0; i <k; i++){
                    valid_idx[i] = curr_idx[i];
                }
            } else{
                left=mid+1;
            }
        }

        solution();

    }

    return 0;
}