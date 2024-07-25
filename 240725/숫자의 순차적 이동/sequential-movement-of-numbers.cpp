#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n, m;

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
    cin >> n >> m;

    // 8방향 이동을 위한 배열
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> matrix[y][x];
        }
    }

    // m번의 시뮬레이션 수행
    for (int simulation = 0; simulation < m; simulation++) {
        for (int num = 1; num <= n * n; num++) {
            pair<int, int> pos;
            bool found = false;
            
            // 주어진 숫자의 현재 위치를 찾음
            for (int y = 0; y < n && !found; y++) {
                for (int x = 0; x < n && !found; x++) {
                    if (matrix[y][x] == num) {
                        pos = {y, x};
                        found = true;
                    }
                }
            }

            int max_value = -1;
            pair<int, int> max_pos = pos;

            // 해당 위치에서 최대값 위치 찾기
            for (int i = 0; i < 8; i++) {
                int ny = pos.first + dy[i];
                int nx = pos.second + dx[i];

                if (InRange(ny, nx) && matrix[ny][nx] > max_value) {
                    max_value = matrix[ny][nx];
                    max_pos = {ny, nx};
                }
            }

            // 최댓값 위치와 현재 위치 교환
            swap(matrix[pos.first][pos.second], matrix[max_pos.first][max_pos.second]);
        }
    }

    // 최종 행렬 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}