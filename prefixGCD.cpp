#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int nt = 1e6 + 5;
const int mod = 1e9 + 7;

int n,a[maxn];

int32_t main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;
    while(test--) {

        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1,a + n + 1);
        int minGcdValue = a[1],cnt = 1,ans = minGcdValue;
        while(1) {
            int gcd = minGcdValue;
            for(int i = 1; i <= n; i++) {
                int x = __gcd(minGcdValue, a[i]);
                if(x < gcd)
                    gcd = x;
            }

            if(gcd == minGcdValue) {
                ans += 1LL * gcd * (n - cnt);
                break;
            }
            ans += gcd;
            minGcdValue = gcd;
            cnt++;
        }

        cout << ans << endl;
    }


}

/*

5
3
4 2 2
2
6 3
3
10 15 6
5
6 42 12 52 20
4
42 154 231 66




*/
