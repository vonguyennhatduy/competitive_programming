#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn = 1e5 + 5;

int n,k,a[55];

int32_t main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;
    while(test--) {
 
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int cnt = 0,ans = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i] >= k) {
                cnt += a[i];
            }else {
                if(a[i] == 0) {
                    if(cnt) {
                        cnt--;
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
        
    }
}

