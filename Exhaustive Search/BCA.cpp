/**
* Description:  At the beginning of the semester, the head of a computer science department D have to assign courses 
                to teachers in a balanced way. The department D has m teachers T={1,2,...,m} and n courses C={1,2,...,n}. 
                Each teacher t∈T has a preference list which is a list of courses he/she can teach depending on his/her specialization. 
                We known a list of pairs of conflicting two courses that cannot be assigned to the same teacher as these courses have been 
                already scheduled in the same slot of the timetable. The load of a teacher is the number of courses assigned to her/him. 
                How to assign n courses to m teacher such that each course assigned to a teacher is in his/her preference list, 
                no two conflicting courses are assigned to the same teacher, and the maximal load is minimal.
* Input:    The input consists of following lines
                - Line 1: contains two integer m and n (1≤m≤10, 1≤n≤30)
                - Line i+1: contains an positive integer k and k positive integers indicating the courses that teacher i can teach (∀i=1,…,m)
                - Line m+2: contains an integer k
                - Line i+m+2: contains two integer i and j indicating two conflicting courses (∀i=1,…,k)
* Output:   The output contains a unique number which is the maximal load of the teachers in the solution found and the value -1 if not solution found.
*/



#include <bits/stdc++.h>
using namespace std;

const int N = 35;
int m, n;
vector<int> courseTeacher[N];
vector<int> courseConflict[N];
int teacherLoad[N];
int assigned[N];
int result;


void Try(int k, int currLoad){
    if(k>n){
        result = min(result, currLoad);
        return;
    }

    if(result < currLoad)
        return;

    for(auto teacher = courseTeacher[k].begin(); teacher != courseTeacher[k].end(); teacher++){
        bool ok = true;
        for(auto course = courseConflict[k].begin(); course != courseConflict[k].end(); course++){
            int teacherOfConfictCourse = assigned[*course];
            if(teacherOfConfictCourse == *teacher)
                ok = false;
        }
        if(ok){
            assigned[k] = *teacher;
            teacherLoad[*teacher]++;
            Try(k+1, max(currLoad, teacherLoad[*teacher]));
            teacherLoad[*teacher]--;
            assigned[k] = 0;
        }
    }


}


void input(){
    cin>>m>>n;
    int k, x, y;
    for(int i=1; i<=m; i++){
        cin>>k;
        for(int j=1; j<=k; j++){
            cin>>x;
            courseTeacher[x].push_back(i);
        }
    }
    cin>>k;
    for(int j=1; j<=k; j++){
        cin >>x>>y;
        courseConflict[x].push_back(y);
        courseConflict[y].push_back(x);
    }

}

int main(){
    input();
    result = N;
    memset(assigned, 0, sizeof(assigned));
    memset(teacherLoad, 0, sizeof(teacherLoad));

    Try(1, 0);
    if(result == N)
        result = -1;

    cout << result << endl;
    return 0;

}