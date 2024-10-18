#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 5;

int n,k;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {

        cin >> n >> k;
        vector <int> a;
        map <int,int> mp;
        for(int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if(mp[x] == 0) {
                a.push_back(x);
                mp[x]++;
            }
        }

        sort(a.begin(),a.end());
        vector <pair <int,int> > tmp;
        int st = -1,en = -1;
        for(int i = 0; i < a.size(); i++) {
            int l = i,r = min((int)a.size() - 1,i + k),x = i;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(a[mid] - a[l] == mid - l) {
                    x = mid;
                    l = mid + 1;
                }else r = mid - 1;
            }

            tmp.push_back({a[l],a[x]});
        }

        for(auto x : tmp) {
            cout << x.first << " " << x.second << endl;
        }



    }






    return 0;
}
/*

*/
