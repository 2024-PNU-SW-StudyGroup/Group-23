#include <bits/stdc++.h>

using namespace std;

int R, C;
char arr[21][21];
int dist[21][21];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int answer = 1;

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < R && y < C;
}

void getAnswer(int x, int y, vector<int> alpha) {
    for (int i=0; i<4; i++) {
        int tx = x + dx[i], ty = y + dy[i];
        if (isValid(tx, ty) && !alpha[arr[tx][ty] - 'A'] &&!dist[tx][ty]) {
            dist[tx][ty] = dist[x][y] + 1;
            alpha[arr[tx][ty] - 'A'] = 1;
            answer = max(answer, dist[tx][ty]);
            getAnswer(tx, ty, alpha);
            dist[tx][ty] = 0;
            alpha[arr[tx][ty] - 'A'] = 0;
        }
    }
}

void getInput() {
    cin >> R >> C;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> arr[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    getInput();
    vector<int> alpha(30, 0);
    dist[0][0] = 1;
    alpha[arr[0][0] - 'A'] = 1;
    getAnswer(0, 0, alpha);
    cout << answer;

    return 0;
}
