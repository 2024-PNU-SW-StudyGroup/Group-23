#include <bits/stdc++.h>

using namespace std;

int N, M, X;
vector<pair<int, int>> vec[1001];
int dist[1001][1001] = {0, };

void makeDistance(int start) {
    priority_queue<int, vector<int>, greater<int>> q;
    int visited[10001] = {0, };
    for (int i=1; i<=N; i++) visited[i] = 1e9;

    q.push(start);
    visited[start] = 0;

    while (!q.empty()) {
        int pq = q.top();
        q.pop();

        for (auto v: vec[pq]) {
            auto [x, y] = v;
            if (visited[x] > visited[pq] + y) {
                visited[x] = visited[pq] + y;
                dist[start][x] = min(dist[start][x], visited[x]);
                q.push(x);
            }
        }
    }


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> X;
    for (int i=0; i<M; i++) {
        int sp, ep, ti;
        cin >> sp >> ep >> ti;
        vec[sp].push_back({ep, ti});
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            dist[i][j] = 1e9;
        }
    }
    for (int i=1; i<=N; i++) {
        makeDistance(i);
    }

    int answer = 0;
    for (int i=1; i<=N; i++) {
        int mtime = dist[i][X] + dist[X][i];
        if (mtime < 100000) {
            answer = max(answer, mtime);
        }
    }
    cout << answer;
    return 0;
}

