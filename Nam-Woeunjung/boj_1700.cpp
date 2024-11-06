#include <bits/stdc++.h>

using namespace std;

int N, K;
int electronics[101];

void getInput() {
    cin >> N >> K;
    for (int i=0; i<K; i++) {
        cin >> electronics[i];
    }
}

int getDist(int cur, int index, vector<int> vec) {
    for (int j=index+1; j<K; j++) {
        if (electronics[j] == vec[cur]) {
            return j;
        }
    }
    return K;
}

int getBestEraseIndex(int index, vector<int> vec) {
    int sz = vec.size();
    int max_dist = 0, max_index = 0;
    for (int i=0; i<sz; i++) {
        int dist = getDist(i, index, vec);
        if (dist > max_dist) {
            max_dist = dist;
            max_index = i;
        }
    }
    return max_index;
}

bool isHit(int index, vector<int> vec) {
    for (auto v: vec) {
        if (electronics[index] == v) {
            return true;
        }
    }
    return false;
}

void getAnswer() {
    vector<int> vec;
    int answer = 0;
    for (int i=0; i<K; i++) {
        if (isHit(i, vec)) continue;
        else if (vec.size() < N) {
            vec.push_back(electronics[i]);
        }
        else {
            int index = getBestEraseIndex(i, vec);
            vec.erase(vec.begin()+index);
            vec.push_back(electronics[i]);
            answer++;
        }
    }
    cout << answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 8:41 - 9:10
    // 페이지 교체 알고리즘 중 최적 알고리즘으로 풀이
    getInput();
    getAnswer();

    return 0;
}

