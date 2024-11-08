#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> vec;

void getInput() {
    cin >> N;
    for (int i=0; i<N; i++) {
        int inp;
        cin >> inp;
        vec.push_back(inp);
    }
}


void getAnswer() {
    sort(vec.begin(), vec.end());
    int ans = 1;
    for (auto v: vec) {
        if (v > ans) break;
        ans += v;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 10:12 - 11:30
    // 도저히 모르겠어서 알고리즘 봄
    // 엥? 이게 그리디라고?
    // 도저히 모르겠어서 질문게시판에서 답 봄..

    // 뽑은 숫자가 지금까지 더한 숫자 보다
    // 작다면 그 수는 지금 까지의 더한 수(SUM) 부터 뽑은 수를 더한 값(SUM + ARR[i]) 까지 만들 수 있고
    // 크다면 지금까지 더한 숫자 +1이 만들 수 없는 최소의 수
    getInput();
    getAnswer();


    return 0;
}

