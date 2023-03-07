#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n'
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

LL maxd;
vector<LL> ans, temp;
LL gcd(LL a,LL b)
{
    return b == 0 ? a : gcd(b, a % b);
}
LL get_start(LL numerator,LL denominator)
{
    return denominator / numerator + 1LL;
}
bool better()
{
    for (LL i = ans.size() - 1; i >= 0;i--)
    {
        if(ans[i]!=temp[i])
        {
            return temp[i] < ans[i];
        }
    }
    return false;
}
bool dfs(LL deep,LL start,LL numerator,LL denominator)
{
    if(deep==maxd)
    {
        if(denominator%numerator)
        {
            return false;
        }
        else
        {
            temp[deep] = denominator / numerator;
        }
        if(ans.size()<temp.size()||better())
        {
            ans = temp;
        }
        return true;
    }
    bool flag = false;
    for (LL i = start;;i++)
    {
        if(denominator*(maxd+1LL-deep)<=i*numerator)
        {
            break;
        }
        temp[deep]=i;
        LL n = numerator * i - denominator, d = i * denominator;
        LL g = gcd(n, d);
        n /= g, d /= g;
        if(dfs(deep+1,get_start(n,d),n,d))
        {
            flag = true;
        }
    }
    return flag;
}
int main()
{
   LOCAL();

   LL n, m;
   cin >> n >> m;
   for ( maxd = 0; maxd < 1000;maxd++)
   {
        temp.clear();
        temp.resize(maxd + 1);
        if (dfs(0, get_start(n, m), n, m))
        {
            sort(all(ans));
            for (LL i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << ' ';
            }
            return 0;
        }
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
