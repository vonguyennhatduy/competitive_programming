#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn = 1e5 + 5;

int n,k;

bool cmp (pair <int,int> a,pair <int,int> b) {
    return a.second < b.second;
}

int32_t main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;
    while(test--) {
 
        cin >> n >> k;
        pair <int,int> a[n];
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            a[i].first = x;
        }
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            a[i].second = x;
        }

        sort(a, a + n, cmp);

        int ans = 0,idx = 0;
        while(idx < n && k > 0) {
            ans += k;
            while(a[idx].first <= ans && idx < n)  {
                idx++;
            }
            k -= a[idx].second;
            if(k <= 0) break;
        } 

        cout << (idx == n ? "YES\n" : "NO\n");
        
    }
}

