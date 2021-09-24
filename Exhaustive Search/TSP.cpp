/**
* Description:  Một người du lịch xuất phát từ thành phố thứ nhất muốn đi thăm quan tất cả n−1 thành phố khác, 
                mỗi thành phố đúng một lần, rồi quay trở lại thành phố xuất phát.
                Yêu cầu: Cho biết chi phí đi lại giữa các thành phố, hãy giúp người du lịch tìm hành trình với tổng chi phí là nhỏ nhất.
* Input:    Dòng đầu tiên chứa hai số nguyên dương n,m cách nhau bởi dấu cách (n≤20,m<400).
            m dòng tiếp theo mỗi dòng chứa ba số nguyên dương i,j,c (i,j≤n,c≤106) biểu thị chi phí đi trực tiếp từ thành phố i đến thành phố j là c.
            Lưu ý: nếu từ thành phố i đến thành phố j nào không mô tả chi phí đi lại thì có nghĩa là không có đường đi trực tiếp từ i đến j.
* Output:   Ghi ra duy nhất một số là tổng chi phí hành trình nhỏ nhất tìm được.
*/



#include <bits/stdc++.h>
using namespace std;

const int SIZE = 21;
const int MAX_INT = 1e9;

int n, m;
int C[SIZE][SIZE] = {0};
int visited[21] = {false};
int x[21] = {};
int T = 0, rs = MAX_INT;

void input(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int x, y, z;

    for (int h = 1; h <= m; h++)
    {
        cin >> x >> y >> z;
        C[x][y] = z;
    }

}

bool check(int i, int k){
    int tmp = C[x[k - 1]][i];
    return !visited[i] && tmp &&(T + tmp <= rs);
}

void TSP(int k)
{
    for (int i = 2; i <= n; i++)
        if (check(i, k))
        {
            x[k] = i;
            visited[i] = true;
            T += C[x[k - 1]][i];
            if (k == n)
            {
                if (C[i][1])
                    rs = min(T + C[i][1], rs);
            }
            else
                TSP(k + 1);
            visited[i] = false;
            T -= C[x[k - 1]][i];
        }
}

int main()
{
    input();
    visited[1] = true;
    x[1] = 1;
    TSP(2);
    cout << rs << endl;
    return 0;
}
