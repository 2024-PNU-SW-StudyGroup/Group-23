#include <bits/stdc++.h>

using namespace std;

int N, X;
bool flag = false;

bool isInvalid(string &s) {
    if (s.size() == 0) return false;
    for (int i=1; i<=s.size(); i++) {
        for (int j=0; i+i+j<=s.size(); j++) {
            string s1 = s.substr(j, i);
            string s2 = s.substr(i+j, i);
            if (s1 == s2) return true;
        }
    }
    return false;
}

void getAnswer(string s) {
    if (flag || isInvalid(s)) {
        return;
    }
    if (s.size() == N) {
        cout << s << endl;
        flag = true;
        return;
    }
    getAnswer(s+"1");
    getAnswer(s+"2");
    getAnswer(s+"3");
}

void getInput() {
    cin >> N;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    getInput();
    string s = "";
    getAnswer(s);


    return 0;
}

