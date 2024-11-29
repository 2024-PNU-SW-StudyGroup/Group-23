#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int miro[1001][1001];
int visited[11][1001][1001];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void getInput() {
    cin >> N >> M >> K;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            char c;
            cin >> c;
            if (c == '1') miro[i][j] = 1;
        }
    }
}

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < M;
}


void getAnswer() {
    queue<pair<int, pair<int, int>>> q;
    visited[0][0][0] = 1;
    q.push({0, {0, 0}});

    int answer = 1e9;
    while (!q.empty()) {
        auto [floor, pos] = q.front();
        auto [x, y] = pos;
        q.pop();
        if (x == N-1 && y == M-1) {
            if (visited[floor][x][y] > 0) {
                answer = min(answer, visited[floor][x][y]);
            }
        }

        for (int i=0; i<4; i++) {
            int tx = x+dx[i], ty = y+dy[i];
            if (!isValid(tx,ty)) continue;

            if (miro[tx][ty] == 0 && visited[floor][tx][ty] == 0) {
                visited[floor][tx][ty] = visited[floor][x][y] + 1;
                q.push({floor, {tx, ty}});
            }
            if (miro[tx][ty] == 1 && visited[floor + 1][tx][ty] == 0 && floor < K) {
                visited[floor + 1][tx][ty] = visited[floor][x][y] + 1;
                q.push({floor + 1, {tx, ty}});
            }
        }
    }
    if (answer == 1e9) answer = -1;
    cout << answer;
//    for (int i=0; i<=K; i++) {
//        for (int j=0; j<N; j++) {
//            for (int k=0; k<M; k++) {
//                cout << visited[i][j][k] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 9:11 - 10:21
    // 중간에 다익스트라도 해보고 dfs도 해보고 bfs도 해봤는데 다 시간초과 날 것 같길래
    // 블로그에서 어떤 식으뢰 동작하는지 파악 > floor 을 두고 벽 부술 때마다 층 높이기
    // 이걸 어떻게 아냐고~~ ㅜㅜ
    
    getInput();
    getAnswer();


    return 0;
}

