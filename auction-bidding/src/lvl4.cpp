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

pair<string, int> solve(const vector<string> &tokens) {
    unordered_map<string, int> bidderToPrice;

    for (int i = 2; i < (int)tokens.size(); i += 2) {
        const string bidder = tokens[i];
        const int price = stoi(tokens[i + 1]);
        bidderToPrice[bidder] = price;
    }

    int iniPrice = stoi(tokens[0]);
    if (bidderToPrice.size() == 1) {
        return make_pair(bidderToPrice.begin()->first, iniPrice);
    }

    int maxi1 = -1, maxi2 = -1;// maxi1 >= maxi2
    string bidder;
    for (auto it = bidderToPrice.cbegin(); it != bidderToPrice.cend(); it++) {
        int price = it->second;
        if (maxi1 <= price) {
            maxi2 = maxi1;
            maxi1 = price;
            bidder = it->first;
        } else if (maxi2 < price) {
            maxi2 = price;
        }
    }

    if (maxi2 == maxi1 || maxi2 == -1) {
        return make_pair(bidder, maxi1);
    } else {
        return make_pair(bidder, maxi2 + 1);
    }
}

int main() {
    freopen("data.txt", "r", stdin);
    string s;
    getline(cin, s);
    auto tokens = tokenize(s, ",");

    const int n = tokens.size();
    const int bnPrice = stoi(tokens[1]);
    cout << "-," << tokens[0] << ',';
    vector<pair<string, int>> ans;
    for (int i = 4; i <= n; i += 2) {
        auto p = solve(vector<string>(tokens.cbegin(), tokens.cbegin() + i));
        ans.push_back(p);
    }
    for (size_t i = 0; i < ans.size(); i++) {
        if (i && (ans[i] == ans[i - 1]));
        else {
            if (bnPrice && ans[i].second >= bnPrice) {
                cout << ans[i].first << ',' << bnPrice << ',';
                break;
            } else {
                cout << ans[i].first << ',' << ans[i].second << ',';
            }
        }


    }
    cout << endl;
    // w/o last comma
    return 0;
}
