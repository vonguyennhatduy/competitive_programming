#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

int n,p,m;
pair <pair <int,int> ,int> pacman[10005];
pair <char,int> q[100005];
int f[55][100005];

int rotateAction(int initState, int chageState) {
    int r = initState + (chageState % 4);
    if(r > 4) r %= 4;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> p >> m;
    for(int i = 1; i <= p; i++) {
        cin >> pacman[i].first.first >> pacman[i].first.second >> pacman[i].second;
    }

    for(int i = 1; i <= m; i++) {
        cin >> q[i].first >> q[i].second;
    }


    for(char i = 'A'; i <= 'Z'; i++) {
        f[i - 'A' + 1][m + 1] = 0;
    }

    for(int i = m; i >= 1; i--) {
        if(q[i].first == 'Z') {
            break;
        }else {
            f[q[i].first - 'A' + 1][i] = f[q[i].first - 'A' + 1][i + 1] + q[i].second;
        }
    }


    vector <pair <char,int> > sumQ;
    int Zindex = -1;
    for(int i = m; i >= 1; i--) {
        if(q[i].first == 'Z') {
            Zindex = i;
            sumQ.push_back({'Z',q[i].second});
            break;
        }else {
            char ch = q[i].first;
            int idx = i;
            while(q[idx].first == ch) idx--;
            idx++;
            i = idx;
            sumQ.push_back({ch,f[ch - 'A' + 1][idx]});
        }

    }
    reverse(sumQ.begin(),sumQ.end());

    int sumR = 0;
    if(Zindex != -1) {
        for(int i = 1; i <= Zindex - 1; i++) {
            if(q[i].first == 'R') {
                sumR += q[i].second;
            }
        }
    }

    sumR %= 4;
    for(int i = 1; i <= p; i++) {
        int u = pacman[i].first.first;
        int v = pacman[i].first.second;
        int direction = pacman[i].second;
        int r = rotateAction(direction,sumR);
        bool ok = false;
        if(sumQ[0].first == 'Z') {
            u = sumQ[0].second / n;
            v = sumQ[0].second % n;
            ok = true;
        }


        for(int j = (ok ? 1 : 0); j < sumQ.size(); j++) {

            if(sumQ[j].first == 'A') {
                int val = sumQ[j].second;

                val %= n;
                if(r == 1) { u -= val; if(u < 0) u += n; }

                else if(r == 2) { v += val; if(v > n - 1) v -= n; }

                else if(r == 3) { u += val; if(u > n - 1) u -= n; }

                else if(r == 4) { v -= val; if(v < 0) v += n; }

            }else {
                r = rotateAction(r,sumQ[j].second % 4);
            }
        }

        cout << u << " " << v << endl;
    }

    return 0;
}

/*
5 3 4
1 1 2
2 3 1
3 1 4
A 3
R 3
A 1
A 3

*/
