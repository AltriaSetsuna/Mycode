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
    LL n;
    cin >> n;
    vector<LL> a(n + 1);
    for (LL i = 1; i <= n;i++)
    {
        cin >> a[i];
    }
    if(a.back()==1)
    {
        NO();
    }
    else
    {
        YES();
        vector<LL> tag(n + 2, 0);
        vector<LL> ans;
        for (LL i = n; i >= 1; i--)
        {
            tag[i] ^= tag[i + 1];
            if(a[i-1]==0)
            {
                ans.emplace_back(i - 1);
                tag[i - 2] ^= 1;
            }
            else if(a[i]==1)
            {
                ans.emplace_back(i);
                tag[i - 1] ^= 1;
            }
        }
        cout << 0 << ' ';
        reverse(all(ans));
        for (LL i = 0; i < ans.size();i++)
        {
            cout << ans[i] << " \n"[i + 1 == ans.size()];
        }
    }

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
