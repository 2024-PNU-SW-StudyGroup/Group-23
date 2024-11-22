#include <bits/stdc++.h>

using namespace std;

int N, M, L, K;
vector<pair<int, int>> stars;
set<int> xset, yset;

int leftUp(int x, int y) {
    int cnt = 0;
    for (auto s: stars) {
        auto [tx, ty] = s;
        if (tx == x && ty == y) cnt++;
        else if (tx >= x && tx - x <= L && ty >= y && ty - y <= L) cnt++;
    }
    return cnt;
}

int rightUp(int x, int y) {
    int cnt = 0;
    for (auto s: stars) {
        auto [tx, ty] = s;
        if (tx == x && ty == y) cnt++;
        else if (tx <= x && x - tx <= L && ty >= y && ty - y <= L) cnt++;
    }
    return cnt;
}

int leftDown(int x, int y) {
    int cnt = 0;
    for (auto s: stars) {
        auto [tx, ty] = s;
        if (tx == x && ty == y) cnt++;
        else if (tx >= x && tx - x <= L && ty <= y && y - ty <= L) cnt++;
    }
    return cnt;
}

int rightDown(int x, int y) {
    int cnt = 0;
    for (auto s: stars) {
        auto [tx, ty] = s;
        if (tx == x && ty == y) cnt++;
        else if (tx <= x && x - tx <= L && ty <= y && y - ty <= L) cnt++;
    }
    return cnt;
}

void getAnswer() {
    int ans = 0;
    for (auto iter = xset.begin(); iter != xset.end(); iter++) {
        for (auto iter2 = yset.begin(); iter2 != yset.end(); iter2++) {
            int x = *iter, y =*iter2;
            int lu = leftUp(x, y);
            int ru = rightUp(x, y);
            int ld = leftDown(x, y);
            int rd = rightDown(x, y);
            // cout << x << " " << y << " " << lu << " " << ru << " ";
            // cout << ld << " " << rd << endl;
            vector<int> tmp = {ans, lu, ru, ld, rd};
            ans = *max_element(tmp.begin(), tmp.end());
        }
    }
    cout << K-ans << endl;
}

void getInput() {
    int x, y;
    cin >> N >> M >> L >> K;
    for (int i=0; i<K; i++) {
        cin >> x >> y;
        stars.push_back({x, y});
        xset.insert(x);
        yset.insert(y);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // 10:24 - 10:55
    // 질문게시판 반례 하나 보고 고침

    // 처음에는 star 기준 상하좌우 탐색했는데 아래같은 반례가 있어서 안됨
    //   *
    // *   *
    //   *
    getInput();
    getAnswer();

    return 0;
}

