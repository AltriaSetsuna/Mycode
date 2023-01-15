#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

LL binary_search(LL n)
{
    LL l = 1, r = 1e7;
    while(l<=r)
    {
        LL mid = (l + r) / 2;
        LL tol_R = mid * (mid + 1) / 2;
        LL tol_L = tol_R - mid + 1;
        if(tol_L>n)
        {
            r = mid - 1;
        }
        else if(tol_R<n)
        {
            l = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
LL sum_one(LL n)
{
    return n * (n + 1) / 2;
}
LL sum_two(LL n)
{
    return n * (n + 1) * (n + 2) / 6;
}
int main()
{
   LOCAL();

   LL n;
   cin >> n;
   while(n--)
   {
       LL l, r;
       cin >> l >> r;
       LL row_L = binary_search(l);
       LL row_R = binary_search(r);
       LL ans = sum_two(row_R - 1) + sum_one(r - sum_one(row_R - 1)) - sum_two(row_L - 1) - sum_one(l - 1 - sum_one(row_L - 1));
       cout << ans << endl;
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