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
#define continue(x) if(x){continue;}
#define break(x) if(x){break;}
void LOCAL();
using namespace std;

class tree_arrey//tree_arrey(vector<LL>&a),a的有效数据从下标0开始
{
   private:
      vector<LL> tree;
      LL lowbit(LL x)
      {
         return x & -x;
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

   public:
      tree_arrey(vector<LL>a)
      {
         tree = vector<LL>(a.size() + 1, 0);
         for (LL i = 1; i < tree.size();i++)
         {
            add(i, a[i - 1]);
         }
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
      LL query(LL l,LL r)
      {
         return sum(r) - sum(l - 1);
      }
};

inline void solve()
{
    LL len;
    cin >> len;
    string s;
    cin >> s;
    vector<queue<LL>> pos(26);
    pos[s[0] - 'a'].emplace(1);
    for (LL i = 1; i < len;i++)
    {
        if(s[i]==s[i-1])
        {
            pos[s[i] - 'a'].emplace(pos[s[i] - 'a'].back());
        }
        else
        {
            pos[s[i] - 'a'].emplace(i + 1);
        }
    }
    tree_arrey tree(vector<LL>(len, 0));
    reverse(all(s));
    LL ans = 0;
    for (LL i = 0; i < len;i++)
    {
        LL ch = s[i] - 'a';
        ans += tree.query(pos[ch].front() + 1, len);
        tree.add(pos[ch].front(), 1);
        pos[ch].pop();
    }
    cout << ans;
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
