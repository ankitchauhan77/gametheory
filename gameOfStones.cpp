//https://codeforces.com/contest/768/problem/E
//https://cp-algorithms.com/game_theory/sprague-grundy-nim.html
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define rsrt(v) sort(v.begin(), v.end(), greater<int>())
#define fi(i,a,b) for(int i=a;i<b;i++)
#define srt(v) sort(v.begin(),v.end())
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define int long long
ll md = 1000000007;
#define X first
#define Y second
using namespace std;
#define dbg(x) cerr << #x << " = " << x << endl;
template <typename T>
T pw(T a, T b) {T c = 1, m = a%md;while(b) {if (b & 1) c=(c*m); m=(m*m); b/=2;} return c;}
template <typename T>
T ceel(T a, T b){if (a%b==0) return a/b; else return a/b + 1;}
template <typename T>
T gcd(T a, T b) {return b == 0 ? a : gcd(b, a % b);}
ll pwmd(ll a, ll b) {ll c = 1, m = a;while(b) {if (b & 1) c=(c*m)%md; m=(m*m)%md; b/=2;} return c;}
ll modinv(ll n){return pwmd(n, md - 2);}
//--------------------------------theartofwar-------------------------------------------//
map<int, int> dp[61];
int grundy(int n, int mask) {
    if (n == 0) return 0;
    if (dp[n].find(mask) != dp[n].end()) return dp[n][mask];
    set<int> nxt;
    fi(i, 1, n + 1) {
        if (!(mask & (1ll << i))) nxt.insert(grundy(n - i, mask | (1ll << i)));
    }
    int mex = 0;
    while (nxt.find(mex) != nxt.end()) mex++;
    dp[n][mask] = mex;
    return mex;
}
signed main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n, a[61];
    cin >> n;
    fi(i, 1, 61) a[i] = grundy(i, 0), cerr<<i<<"\n";
    int ans = 0;
    fi(i, 0, n) {
        int x;
        cin >> x;
        ans ^= a[x];
    }
    if (ans) cout << "NO";
    else cout << "YES";
}
