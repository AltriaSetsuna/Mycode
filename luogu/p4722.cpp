#include<bits/stdc++.h>
#define maxn 1300
#define maxm 120010
typedef long long LL;
using namespace std;
struct edge{
	LL u,v,cap;
}e[maxm];
struct Dinic{
	LL tp,s,t,dis[maxn],cur[maxn],que[maxn];
	vector<edge>e;vector<LL>v[maxn];
	void AddEdge(LL x,LL y,LL flw){
		e.push_back(edge{x,y,flw});
		e.push_back(edge{y,x,0});
		v[x].push_back(e.size()-2);
		//v[y].push_back(e.size()-1);
	}
	LL bfs(){
		memset(dis,0x3f,sizeof dis);
		LL l=1,r=1;que[1]=s;dis[s]=0;
		while(l<=r){
			LL p=que[l++],to;
			for(LL i:v[p])if(e[i].cap && dis[to=e[i].v]>1e9)
				dis[to]=dis[p]+1,que[++r]=to;
		}
		return dis[t]<1e9;
	}
	LL dfs(LL p,LL a){
		if(p==t || !a)return a;
		LL sf=0,flw;
		for(LL &i=cur[p],to;i<(LL)v[p].size();++i){
			edge &E=e[v[p][i]];
			if(dis[to=E.v]==dis[p]+1 && (flw=dfs(to,min(a,E.cap)))){
				E.cap-=flw;e[v[p][i]^1].cap+=flw;
				a-=flw;sf+=flw;
				if(!a)break;
			}
		}
		return sf;
	}
	LL dinic(LL s,LL t,LL tp=1){
		this->s=s;this->t=t;this->tp=tp;
		LL flw=0;
		while(bfs()){
			memset(cur,0,sizeof cur);
			flw+=dfs(s,INT_MAX);
		}
		return flw;
	}
}sol;
LL n,m,i,s,t,ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s >> t;
    for(i=0;i<m;i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].cap;
    }
	sort(e,e+m,[](edge a,edge b){return a.cap>b.cap;});
	for(LL tp:{0,1})for(LL p=1<<30,i=0;p;p/=2){
		while(i<m && e[i].cap>=p){
			if(tp)sol.v[e[i].v].push_back(i*2+1);
			else sol.AddEdge(e[i].u,e[i].v,e[i].cap);
			i++;
		}
		ans+=sol.dinic(s,t,tp);
	}
    cout << ans;
    return 0;
}