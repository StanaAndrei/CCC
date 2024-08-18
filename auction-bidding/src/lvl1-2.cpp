#include <bits/stdc++.h>
using namespace std;

vector<string> tokenize(string s, string sep) {
    vector<string> r;
    char *arr = &s[0];
    for (char *tok = strtok(arr, sep.c_str()); tok; tok = strtok(NULL, sep.c_str())) {
        r.push_back(tok);
    }
    return r;
}

int main() {
    freopen("data.txt", "r", stdin);
    string s;
    getline(cin, s);
    auto tokens = tokenize(s, ",");

    unordered_map<string, int> bidderToPrice;

    for (int i = 1; i < (int)tokens.size(); i += 2) {
        const string bidder = tokens[i];
        const int price = stoi(tokens[i + 1]);
        bidderToPrice[bidder] = price;
    }

    int iniPrice = stoi(tokens[0]);
    if (bidderToPrice.size() == 1) {
         return cout << bidderToPrice.begin()->first << "," << iniPrice << endl, 0;
    }

    int maxi1 = -1, maxi2 = -1;// maxi1 >= maxi2
    string bidder;
    for (auto it = bidderToPrice.cbegin(); it != bidderToPrice.cend(); it++) {
        int price = it->second;
        if (maxi1 <= price) {
            maxi2 = maxi1;
            maxi1 = price;
            bidder = it->first;
        } else if (maxi2 <= price) {
            maxi2 = price;
        }
    }

    if (maxi2 == maxi1 || maxi2 == -1) {
        cout << bidder << "," << maxi1 << endl;
    } else {
        cout << bidder << "," << maxi2 + 1 << endl;
    }
    return 0;
}
