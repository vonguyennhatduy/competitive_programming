#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
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
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        int ans,l = 0,r = 1e12;

        while(l <= r) {
            int mid = (l + r) / 2,tmp = 0;
            bool  ok = true;
            for(int i = n; i >= 1; i--) {
                if(a[i] >= mid) {
                    tmp -= (a[i] - mid);
                }else tmp += (mid - a[i]);

                if(tmp < 0) {
                    ok = false;
                    break;
                }
            }

            if(ok) {
                ans = mid;
                r = mid - 1;
            }else l = mid + 1;

        }

        int res = ans;
        l = 0,r = ans;
        while(l <= r) {
            int mid = (l + r) / 2;
            int sum = 0;
            for(int i = n; i >= 1; i--) {
                if(a[i] >= mid) {
                    sum -= (a[i] - mid);
                    sum = max(sum, (int)0);
                }else sum += (mid - a[i]);
            }

            if(sum == 0) {
                res = ans - mid;
                l = mid + 1;
            }else r = mid - 1;
        }

        cout << res << endl;
    }


}

/*




*/