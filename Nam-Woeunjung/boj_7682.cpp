#include <bits/stdc++.h>

using namespace std;

int getBingo(char c, string s) {
    int cnt = 0;

    // 가로
    for (int i=0; i<3; i++) {
        bool flag = true;
        for (int j=0; j<3; j++) {
            if (s[i*3+j] != c) flag = false;
        }
        if (flag) cnt++;
    }

    // 세로
    for (int i=0; i<3; i++) {
        bool flag = true;
        for (int j=0; j<3; j++) {
            if (s[i+j*3] != c) flag = false;
        }
        if (flag) cnt++;
    }

    // 대각선
    if (s[0] == c && s[4] == c && s[8] == c) cnt++;
    if (s[2] == c && s[4] == c && s[6] == c) cnt++;

    return cnt;
}

int getCount(char c, string s) {
    int cnt = 0;
    for (auto ss: s) {
        if (ss == c) cnt++;
    }
    return cnt;
}

bool getAnswer(string s) {
    int first = getBingo('X', s);
    int second = getBingo('O', s);

    int first_cnt = getCount('X', s);
    int second_cnt = getCount('O', s);

    // first && second 떄문에 틀림..
    if (first && second) return false;
    
    if (!first && second) return first_cnt == second_cnt;
    if (first && !second) return first_cnt == second_cnt+1;
    return first_cnt == 5 && second_cnt == 4;
}

void getInput() {
    string s;
    while (true) {
        cin >> s;
        if (s == "end") break;
        if (getAnswer(s)) cout << "valid" << endl;
        else cout << "invalid" << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    // 9: 40 - 10:40
    getInput();
//    getAnswer();

    return 0;
}

