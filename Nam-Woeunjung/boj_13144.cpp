#include <bits/stdc++.h>

using namespace std;
int N;
int arr[100001];
int visited[100001];

void getAnswer() {
    long long answer = 0;
    int i = 0, j = 0;
    for (i=0; i<N; i++) {
        while (j < N) {
            if (visited[arr[j]]) break;
            visited[arr[j]] = 1;
            j++;
        }
        answer += (j - i);
        visited[arr[i]] = false;
    }
    cout << answer;
}

void getInput() {
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
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
