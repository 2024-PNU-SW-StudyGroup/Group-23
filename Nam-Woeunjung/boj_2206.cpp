#include <bits/stdc++.h>

using namespace std;

int N, M;
char mymap[1001][1001];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pair<bool, pair<int, int>>> q;
int visited[1001][1001][4];

int isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

void getAnswer() {
    q.push({true, {0, 0}});
    visited[0][0][0] = 1;
    visited[0][0][1] = 1;

    while (!q.empty()) {
        auto [breakable, pos] = q.front();
        auto [x, y] = pos;
        q.pop();

        // cout << x << " " << y << " " << visited[x][y][0] << " " << visited[x][y][1] << endl;

        for (int i=0; i<4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (isValid(tx, ty) && !visited[tx][ty][breakable]) {
                if (mymap[tx][ty] == '0') {
                    visited[tx][ty][breakable] = visited[x][y][breakable] + 1;
                    q.push({breakable, {tx, ty}});
                }
                if (mymap[tx][ty] == '1' && breakable) {
                    visited[tx][ty][false] = visited[x][y][breakable] + 1;
                    q.push({false, {tx, ty}});
                }
            }
        }
    }
    // for (int i=0; i<N; i++) {
    //     for (int j=0; j<M; j++) {
    //         for (int k=0; k<2; k++) {
    //             cout << i << " " << j << " " << k << " "  << visited[i][j][k] << endl;
    //         }
    //     }
    // }
    int a = visited[N-1][M-1][0], b = visited[N-1][M-1][1];
    if (a == 0 && b == 0) cout << -1;
    if (a == 0 && b != 0) cout << b;
    if (a != 0 && b == 0) cout << a;
    if (a != 0 && b != 0) cout << min(a,b);
}

void getInput() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
             cin >> mymap[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    getInput();
    getAnswer();

    return 0;
}
