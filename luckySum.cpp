#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int nt = 1e6 + 5;
const int mod = 1e9 + 7;
const int max_next = 4444444444;

int32_t main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;
    test = 1;
    while(test--) {

        int l,r;
        cin >> l >> r;

        vector <int> tmp;
        queue <int> q;
        q.push(4);
        q.push(7);
        tmp.push_back(4);
        tmp.push_back(7);

        while(q.front() < max_next) {
            int top = q.front(); q.pop();

            q.push(1LL * top * 10 + 4);
            q.push(1LL * top * 10 + 7);

            tmp.push_back(1LL * top * 10 + 4);
            tmp.push_back(1LL * top * 10 + 7);

        }

        int firstIdx = lower_bound(tmp.begin(),tmp.end(),l) - tmp.begin();
        int secondIdx = lower_bound(tmp.begin(),tmp.end(),r) - tmp.begin();

        if(firstIdx == secondIdx) {
            cout << 1LL * (r - l + 1) * tmp[secondIdx];
            return 0;
        }

        int ans = 0;
        ans += 1LL * (tmp[firstIdx] - l + 1) * tmp[firstIdx];

        for(int i = firstIdx + 1; i < secondIdx; i++) {
            ans += 1LL * (tmp[i]) * (tmp[i] - tmp[i - 1]);
        }

        ans += 1LL * tmp[secondIdx] * (r - tmp[secondIdx - 1]);

        cout << tmp.size();
    }


}

/*

*/
