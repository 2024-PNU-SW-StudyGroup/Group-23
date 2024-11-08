#include <bits/stdc++.h>

using namespace std;

int N;
long long max_num = 0;

vector<vector<long long>> move_up(vector<vector<long long>> vec) {
    vector<vector<int>> visited(N, vector<int>(N, 0));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (vec[j][i] == 0) continue;
            for (int k=j-1; k>=0; k--) {
                if (vec[k][i] != 0 ) {
                    if (vec[k][i] == vec[j][i] && visited[k][i] == 0) {
                        vec[k][i] *= 2;
                        vec[j][i] = 0;
                        max_num = max(vec[k][i], max_num);
                        visited[k][i] = 1;
                    }
                    break;
                }
            }
            for (int k=0; k<j; k++) {
                if (vec[k][i] == 0) {
                    vec[k][i] = vec[j][i];
                    vec[j][i] = 0;
                    break;
                }
            }
        }
    }
    return vec;
}

vector<vector<long long>> move_down(vector<vector<long long>> vec) {
    vector<vector<int>> visited(N, vector<int>(N, 0));
    for (int i=0; i<N; i++) {
        for (int j=N-1; j>=0; j--) {
            if (vec[j][i] == 0) continue;
            for (int k=j+1; k<N; k++) {
                if (vec[k][i] != 0 ) {
                    if (vec[k][i] == vec[j][i]&& visited[k][i] == 0) {
                        vec[k][i] *= 2;
                        vec[j][i] = 0;
                        max_num = max(vec[k][i], max_num);
                        visited[k][i] = 1;
                    }
                    break;
                }
            }
            for (int k=N-1; k>j; k--) {
                if (vec[k][i] == 0) {
                    vec[k][i] = vec[j][i];
                    vec[j][i] = 0;
                    break;
                }
            }

        }
    }
    return vec;
}

vector<vector<long long>> move_left(vector<vector<long long>> vec) {
   vector<vector<int>> visited(N, vector<int>(N, 0));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (vec[i][j] == 0) continue;
            for (int k=j-1; k>=0; k--) {
                if (vec[i][k] != 0) {
                    if (vec[i][k] == vec[i][j] && visited[i][k] == 0) {
                        vec[i][k] *= 2;
                        vec[i][j] = 0;
                        max_num = max(vec[i][k], max_num);
                        visited[i][k] = 1;
                    }
                    break;
                }
            }
            for (int k=0; k<j; k++) {
                if (vec[i][k] == 0) {
                    vec[i][k] = vec[i][j];
                    vec[i][j] = 0;
                    break;
                }
            }
        }
    }
    return vec;
}

vector<vector<long long>> move_right(vector<vector<long long>> vec) {
    vector<vector<int>> visited(N, vector<int>(N, 0));
    for (int i=0; i<N; i++) {
        for (int j=N-1; j>=0; j--) {
            if (vec[i][j] == 0) continue;
            for (int k=j+1; k<N; k++) {
                if (vec[i][k] != 0 ) {
                    if (vec[i][k]  == vec[i][j] && visited[i][k] == 0) {
                        vec[i][k]  *= 2;
                        vec[i][j] = 0;
                        max_num = max(vec[i][k], max_num);
                        visited[i][k] = 1;
                    }
                    break;
                }
            }
            for (int k=N-1; k>j; k--) {
                if (vec[i][k]  == 0) {
                    vec[i][k] = vec[i][j];
                    vec[i][j] = 0;
                    break;
                }
            }

        }
    }
    return vec;
}

void getAnswer(int depth, vector<vector<long long>> vec) {
//    for (int i=0; i<N; i++) {
//        for (int j=0; j<N; j++) cout << vec[i][j] << " ";
//        cout << endl;
//    }
//    cout << endl;
    if (depth == 5) {
        return;
    }
    getAnswer(depth+1, move_up(vec));
    getAnswer(depth+1, move_down(vec));
    getAnswer(depth+1, move_left(vec));
    getAnswer(depth+1, move_right(vec));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 2:52 - 3:33
    cin >> N;
    vector<vector<long long>> vec;
    for (int i=0; i<N; i++) {
        vector<long long> tmp;
        long long inp;
        for (int j=0; j<N; j++) {
            cin >> inp;
            tmp.push_back(inp);
            max_num = max(max_num, inp);
        }
        vec.push_back(tmp);
    }
    getAnswer(0, vec);
    cout << max_num;

    return 0;
}

