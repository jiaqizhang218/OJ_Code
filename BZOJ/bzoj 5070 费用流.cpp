#include<bits/stdc++.h>
#define pos(i,j,k) (k*n*m+(i-1)*m+j)
#define t n*m*2+2
#define s n*m*2+1
using namespace std;
const int N=200+5;
int n,m,p,r,flow,ans,tot=1,head[N],dis[N],pree[N],prev[N];
queue<int>q;
struct node{
	int v,nxt,w,c;
}e[N*2];
inline int rd(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
void add(int u,int v,int w,int c){
	e[++tot].v=v;e[tot].nxt=head[u];e[tot].w=w;e[tot].c= c;head[u]=tot;
	e[++tot].v=u;e[tot].nxt=head[v];e[tot].w=0;e[tot].c=-c;head[v]=tot;
}
bool spfa(){
	for(int i=1;i<=t;i++) dis[i]=INT_MAX;
	while(!q.empty()) q.pop();
	dis[s]=0,q.push(s);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=head[x];i;i=e[i].nxt){
			int j=e[i].v;
			if(e[i].w&&dis[j]>dis[x]+e[i].c){
				dis[j]=dis[x]+e[i].c;
				pree[j]=i,prev[j]=x;
				q.push(j);
			}
		}
	}
	return dis[t]!=INT_MAX;
}
int main(){
	n=rd(),m=rd();
	for(int i=1,x;i<=n;i++)
		for(int j=1;j<=m;j++)
			x=rd(),add(pos(i,j,0),pos(i,j,1),1,x);
	r=rd();
	while(r--){
		int a=rd(),b=rd(),c=rd(),d=rd();
		add(pos(a,b,1),pos(c,d,0),1,0);
		add(pos(c,d,1),pos(a,b,0),1,0);
	}
	p=rd();
	for(int i=1,a,b;i<=p;i++) a=rd(),b=rd(),add(s,pos(a,b,0),1,0);
	for(int i=1,a,b;i<=p;i++) a=rd(),b=rd(),add(pos(a,b,1),t,1,0);
	while(spfa()){
		flow++,ans+=dis[t];
		int x=t;
		while(x!=s){
			e[pree[x]].w--,e[pree[x]^1].w++;
			x=prev[x];
		}
	}
	if(flow<p) puts("-1");
	else printf("%d",ans);
}
