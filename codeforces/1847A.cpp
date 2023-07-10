#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n' 
#define YESNO(x) cout << (x ? "YES" : "NO") << endl
#define yesno(x) cout << (x ? "yes" : "no") << endl
#define YES() cout << "YES" << endl
#define NO() cout << "NO" << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) ((x) + (k) - 1) / (k)
void LOCAL();
using namespace std;


inline void solve()
{
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n), val;
    cin >> a[0];
    LL sum = 0;
    for (LL i = 1; i < n;i++)
    {
        cin >> a[i];
        val.emplace_back(abs(a[i] - a[i - 1]));
        sum += abs(a[i] - a[i - 1]);
    }
    sort(all(val), greater<LL>());
    for (LL i = 0; i + 1 < k;i++)
    {
        sum -= val[i];
    }
    cout << sum << endl;
    return;
}


int main()
{
   LOCAL();
   LL t;
   cin >> t;
   while(t--)
   {
       solve();
   }
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
