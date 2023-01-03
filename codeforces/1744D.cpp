#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) puts(x?"YES":"NO")
#define all(x) x.begin(),x.end()
void LOCAL();
using namespace std;

vector<LL> init(LL n)
{
    vector<LL> ans;
    vector<LL> a(n + 1, 0);
    for (LL i = 1; i <= n;i++)
    {
        if(!(i&1))
        {
            a[i] += 1 + a[i >> 1];
            ans.push_back(a[i]);
        }
    }
    sort(all(ans), greater<LL>());
    return ans;
}

inline void solve()
{
    LL n;
    cin >> n;
    vector<LL> a = init(n);
    LL sum = 0;
    for (LL i = 0; i < n;i++)
    {
        LL x;
        cin >> x;
        while(!(x&1))
        {
            x >>= 1;
            sum++;
        }
    }
    LL step = 0;
    for (LL i = 0; sum < n&&i<a.size();i++,step++)
    {
        sum += a[i];
    }
    if (sum < n)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << step << endl;
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