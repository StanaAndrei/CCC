#include <bits/stdc++.h>
using namespace std;

void parse(const string &s, int &length, int &iterations) {
    size_t lengthPos = s.find("Length=");
    size_t iterationsPos = s.find("Iterations=");

    string lengthStr = s.substr(lengthPos + 7, s.find(" ", lengthPos) - lengthPos - 7);
    string iterationsStr = s.substr(iterationsPos + 11, s.find(" ", iterationsPos) - iterationsPos - 11);

    length = std::stoi(lengthStr);
    iterations = std::stoi(iterationsStr);
}

int main() {
    freopen("data.txt", "r", stdin);
    string s;
    getline(cin, s);

    int length, iterations;
    parse(s, length, iterations);
    //cerr << length << ' ' << iterations << endl;

    int ans = 4 * length, cnt = 4;
    for (int i = 0; i < iterations; i++) {
        length /= 3;
        ans += cnt * length << 1;
        cnt *= 5;
    }
    cout << ans << endl;
    return 0;
}
