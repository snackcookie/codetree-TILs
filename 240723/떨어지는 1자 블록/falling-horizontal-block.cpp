#include<iostream>
#include<vector>

using namespace std;

int n, m, k;

bool InRange(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < n; // 인덱스는 0부터 n-1까지
}

int main() {
    cin >> n >> m >> k;

    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int col;

    for(int i = 0; i < n; i++)
    {
        for(int j = k - 1; j < k + m - 2; j++) // k는 1부터 시작하므로 k-1로 조정
        {
            if(InRange(i, j) && InRange(i + 1, j) && matrix[i + 1][j] == 1)
            {   
                col = i - 1;
                break;
            }
        }
    }
    for(int x = k - 1; x < k + m - 1; x++) // k는 1부터 시작하므로 k-1로 조정
    {   
        if(InRange(col, x)) // 범위 검사
            matrix[col][x] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}