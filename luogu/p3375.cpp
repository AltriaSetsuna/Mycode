#include <bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define yesno(x) cout << (x ? "YES" : "NO") << endl
#define all(x) x.begin(),x.end()
#define ceil_LL(x, k) (x + k - 1) / k
void LOCAL();
using namespace std;


vector<LL> get_next(string s)
{
    vector<LL> next(s.size());
    LL pos = -1;
    next[0] = -1;
    for (LL i = 1; i < s.size();i++)
    {
        while(pos>=0&&s[pos+1]!=s[i])
        {
            pos = next[pos];
        }
        if(s[pos+1]==s[i])
        {
            pos++;
        }
        next[i] = pos;
    }
    return next;
}
vector<LL> kmp(string sub,string s)//返回值记录sub在s出现的第一个位置
{
    vector<LL> next(sub.size());
    next[0] = -1;
    LL pos = -1;
    for (LL i = 1;i < sub.size();i++)
    {
        while(pos>=0&&sub[i]!=sub[pos+1])
        {
            pos = next[pos];
        }
        if(sub[i]==sub[pos+1])
        {
            pos++;
        }
        next[i] = pos;
    }
    vector<LL> ans;
    pos = -1;
    for (LL i = 0; i < s.size();i++)
    {
        while(pos>=0&&sub[pos+1]!=s[i])
        {
            pos = next[pos];
        }
        if(sub[pos+1]==s[i])
        {
            pos++;
        }
        if(pos+1==sub.size())
        {
            ans.emplace_back(i - pos + 1);
            pos = next[pos];
        }
    }
    return ans;
}

int main()
{
   LOCAL();

   string s, sub;
   cin >> s >> sub;
   vector<LL> ans = kmp(sub, s);
   for (LL i = 0; i < ans.size();i++)
   {
        cout << ans[i] << endl;
   }
   vector<LL> next = get_next(sub);
   for (LL i = 0; i < next.size();i++)
   {
        cout << next[i] + 1 << ' ';
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