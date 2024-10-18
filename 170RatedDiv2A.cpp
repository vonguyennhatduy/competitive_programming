#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 5;

int n,a[maxn];


int32_t main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;
    while(test--) {

        string s,t;
        cin >> s >> t;
        int ans = -1,idx = -1;
        for(int i = 0; i < min(s.size(),t.size()); i++) {
            string newS = s.substr(0,i + 1);
            string newT = t.substr(0,i + 1);
            if(newS == newT) {
                ans = i;
                idx = i;
            }
        }

        if(idx != -1) {
           
            int tmp1 = s.size() - idx - 1;
            int tmp2 = t.size() - idx - 1;

            ans++;
            ans++;
            ans += tmp1 + tmp2;

            cout << ans << endl;

        }else {
            cout << s.size() + t.size() << endl;
        }




        
        
    }






    return 0;
}
/*

*/
