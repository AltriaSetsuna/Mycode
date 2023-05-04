#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n' 
#define YESNO(x) cout << (x ? "YES" : "NO") << endl
#define yesno(x) cout << (x ? "yes" : "no") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / (k)
void LOCAL();
using namespace std;


inline void solve()
{
    LL n, q;
    cin >> n >> q;
    vector<LL> a(n + 1);
    for (LL i = 1; i <= n;i++)
    {
        cin >> a[i];
    }
    vector<LL> pos(n + 1);
    for (LL i = 2; i < n;i++)
    {
        pos[i] = pos[i - 1] + (a[i - 1] >= a[i] && a[i] >= a[i+1]);
    }
   
    while(q--) 
    {
        LL l, r;
        cin >> l >> r;
        if(l==r)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << r - l + 1 - (pos[r - 1] - pos[l]) << endl;
        }
    }
    return;
}



int main()
{
   LOCAL();
   solve();
   return 0;
}
void LOCAL()
{
   #ifdef OY_LOCAL
   freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
   #endif
   ios::sync_with_stdio(false);
   cin.tie(0);cout.tie(0);
}
