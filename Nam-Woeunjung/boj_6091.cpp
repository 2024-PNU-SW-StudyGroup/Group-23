#include <bits/stdc++.h>

using namespace std;

int N, X;
vector<pair<int, pair<int, int>>> vec;
int parent[1025];

int getParent(int num) {
    if (parent[num] == num) return num;
    return getParent(parent[num]);
}

void getAnswer() {
    vector<vector<int>> ans(N+1);
    int num = 0;

    while (num < N-1) {
        auto [a, b] = vec.back();
        auto [u, v] = b;
        vec.pop_back();

        int up = getParent(u), vp = getParent(v);
        if (up != vp) {
            if (up < vp) parent[vp] = up;
            else parent[up] = vp;

            num++;
            ans[u].push_back(v);
            ans[v].push_back(u);
        }
    }

    for (int i=1; i<=N; i++) {
        cout << ans[i].size() << " ";
        sort(ans[i].begin(), ans[i].end());
        for (auto a: ans[i]) {
            cout << a << " ";
        }
        cout << endl;
    }

}

void getInput() {
    cin >> N;
    for (int i=1; i<=N; i++) {
        for (int j=i+1; j<=N; j++) {
            int inp;
            cin >> inp;
            vec.push_back({inp, {i, j}});
        }
        parent[i] = i;
    }
    sort(vec.begin(), vec.end(), greater<>());
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    getInput();
    getAnswer();


    return 0;
}

