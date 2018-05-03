#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int Q,mx,cnt;
struct data{
	int n,m,a,id;
}q[40005];
bool mark[100005];
int pri[100005],mu[100005],t[100005];
int ans[40005];
pair <int,int> F[100005];
bool operator <(data a,data b) {
	return a.a<b.a;
} 
inline void add(int x,int val) {
	for(;x<=mx;x+=(x&-x))t[x] += val;	
}
inline int query(int x) {
	int tmp = 0;
	for(;x;x-=(x&-x))	tmp += t[x];
	return tmp;
}
inline void pre() {
	mu[1] =1;
	for(int i=2;i<=mx;i++) {
		if(!mark[i])	pri[++cnt]=i,mu[i]=1;
		for(int j=1;j<=cnt&&i*pri[j]<=mx;j++) {
			mark[i*pri[j]] = true;
			if(i%pri[j]==0)	{
				mu[i*pri[j]] = 0;
				break;
			}
			else mu[i*pri[j]] = -mu[j];
		}
	}
	for(int i=1;i<=mx;i++) {
		for(int j=1;j<=mx;j+=i) {
			F[j].first+=i;
		}
	}
	for(int i=1;i<=mx;i++) F[i].second = i;
}
inline void solve(int x) {
	int id = q[x].id , n = q[x].n , m = q[x].m;
	for(int i=1,j;i<=q[x].n;i=j+1) {
		j = min(n/(n/i),m/(m/i));
		ans[id] += (n/i) * (m/i) * (query(j)-query(i-1)); 
	}
}
int main()
{
	Q = read();
	for(int i=1;i<=Q;i++) {
		q[i].n=read(),q[i].m=read(),q[i].a=read(),q[i].id=i;
		if(q[i].n > q[i].m)	swap(q[i].n,q[i].m);
		mx = mx > q[i].n ? mx : q[i].n;
	}
	pre();
	sort(q+1,q+Q+1);
	sort(F+1,F+mx+1);
	int now=0;
	for(int i=1;i<=Q;i++) {
		while(now+1<=mx&&F[now+1].first<=q[i].a) {
			now++;
			for(int j=F[now].second;j<=mx;j+=F[now].second) {
				add(j,F[now].first*mu[j/F[now].second]);
			}
		}
		solve(i);
	}
	for(int i=1;i<=Q;i++) 
		printf("%lld\n",ans[i]&INF);
	return 0;
}
