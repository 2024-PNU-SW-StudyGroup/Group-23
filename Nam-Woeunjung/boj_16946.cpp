#include <bits/stdc++.h>

using namespace std;

int N, M;
int mymap[1001][1001], visited[1001][1001];
pair<int, int> mytag[1001][1001];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void getInput() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            char c;
            cin >> c;
            mymap[i][j] = c - '0';
        }
    }
}

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < N &&  y < M;
}

void movemove(int x, int y) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> vec;

    q.push({x, y});
    vec.push_back({x, y});
    visited[x][y] = 1;

    int cnt = 1;
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for (int k=0; k<4; k++) {
            int ti = i + dx[k], tj = j+dy[k];
            if (isValid(ti, tj) && mymap[ti][tj] == 0 && visited[ti][tj] == 0) {
                visited[ti][tj] = 1;
                q.push({ti, tj});
                vec.push_back({ti, tj});
                cnt++;
            }
        }
    }
    for (auto v: vec) {
        auto [i, j] = v;
        visited[i][j] = cnt;
        mytag[i][j] = {x, y};
    }
}

bool isConnected(int tx, int ty, vector<pair<int, int>> vec) {
    for (auto v: vec) {
        if (v == mytag[tx][ty]) {
            return true;
        }
    }
    return false;
}

int getCan(int x, int y) {
    int cnt = 1;
    vector<pair<int, int>> vec;
    for (int i=0; i<4; i++) {
        int tx = x+dx[i], ty = y+dy[i];
        // visited[tx][ty] != 0 안 달아줘서 1%에서 계속 에러남. 당연하지..
        if (isValid(tx, ty) && visited[tx][ty] != 0 && !isConnected(tx, ty, vec)) {
            cnt += visited[tx][ty];
            vec.push_back(mytag[tx][ty]);
        }
    }
    return cnt;
}

void getAnswer() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (visited[i][j] == 0 && mymap[i][j] == 0) {
                movemove(i, j);
            }
        }
    }
    for (int i=0; i<N; i++) {
        for (int j = 0; j < M; j++) {
            // 여기서 %10 을 해줘야 시간초과 안남
            if (mymap[i][j] == 0) cout << 0;
            else cout << getCan(i, j) % 10;
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 9:24 - 10:12
    // 질문게시판 반례 봄!
    getInput();
    getAnswer();


    return 0;
}

