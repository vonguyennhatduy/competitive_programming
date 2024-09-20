#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn = 1e5 + 5;

int n,k,a[maxn];

int32_t main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;
    while(test--) {
 
       cin >> n >> k;
       for(int i = 1; i <= k; i++){
        cin >> a[i];
       } 

       if(k == 1){
        cout << "YES\n";
        continue;
       }

       vector <int> tmp;
       for(int i = 2; i <= k; i++) {
        tmp.push_back(a[i] - a[i - 1]);
       }

       if(!is_sorted(tmp.begin(),tmp.end())) {
        cout << "NO\n";
        continue;
       }

       if(a[1] > (a[2] - a[1]) * (n - k + 1)){
        cout << "NO\n";
        continue;
       }

       cout << "YES\n";

    }
}

