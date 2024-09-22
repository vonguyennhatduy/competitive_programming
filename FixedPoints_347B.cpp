#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn = 1e5 + 5;

int n,a[maxn];

int32_t main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;
    test = 1;
    while(test--) {

        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        map <pair <int,int>,int> mp;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(i == a[i]) {
                ans++;
            }else mp[{i,a[i]}]++;
        }

        if(ans < n) ans++;
        
        for(int i = 0; i < n; i++) {
            if(i != a[i] && mp[{i,a[i]}] > 0 && mp[{a[i],i}] > 0) {
                ans++;
                break;
            }
        }
        
        cout << ans << endl;

    }
}

/*


*/

