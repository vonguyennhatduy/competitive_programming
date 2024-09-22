#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn = 1e5 + 5;

int n,d,k,l[maxn],r[maxn];
pair <int,int> a[maxn];


void reset () {
    for(int i = 1; i <= n; i++) {
        l[i] = r[i] = 0;
    }
}

int32_t main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;
    while(test--) {
 
        cin >> n >> d >> k;
        for(int i = 1; i <= k; i++) {
            cin >> a[i].first >> a[i].second;
            l[a[i].first]++;
            r[a[i].second]++;
        }

        int sum = 0;
        for(int i = 1; i <= d; i++) {
            sum += l[i];
        }

        // sliding window 
        int ans = sum,res = sum,idxBro = 1,idxMo = 1;
        for(int i = d + 1; i <= n; i++) {

            sum += l[i];
            sum -= r[i - d];

            if(sum > ans) {
                ans = sum;
                idxBro = i - d + 1;
            }

            if(sum < res) {
                res = sum;
                idxMo = i - d + 1;
            }

        }

        cout << idxBro << " " << idxMo << endl;
        
        reset();

    }
}
/*



*/
