#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;

vector<LL> mydata;//需要自己初始化
vector<LL> tree;//需要自己初始化
LL lowbit(LL x)
{
   return x & -x;
}
void add(LL index,LL addend)
{
   while(index<tree.size())
   {
       tree[index] += addend;
       index += lowbit(index);
   }
   return;
}
void add(LL l,LL r,LL addend)//区间[l,r]加上addend
{
   add(l, addend);
   add(r + 1, -addend);
}
LL sum(LL index)
{
   LL ans = 0;
   while(index)
   {
       ans += tree[index];
       index -= lowbit(index);
   }
   return ans;
}
LL query(LL index)//查询第index个数
{
   return mydata[index] + sum(index);
}

int main()
{
   LOCAL();

   LL n, m;
   cin >> n >> m;
   mydata = vector<LL>(n + 1);
   tree = vector<LL>(n + 1, 0);
   for (LL i = 1; i <= n;i++)
   {
        cin >> mydata[i];
   }
   for (LL i = 0; i < m;i++)
   {
        LL op;
        cin >> op;
        if(op==1)
        {
            LL x, y, k;
            cin >> x >> y >> k;
            add(x, y, k);
        }
        else
        {
            LL x;
            cin >> x;
            cout << query(x) << endl;
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