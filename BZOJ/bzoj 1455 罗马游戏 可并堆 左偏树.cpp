// 又看了集训队论文QAQ 
#include<bits/stdc++.h>
using namespace std;
const int N = 1000000 + 5;
int n,m,fa[N],l[N],r[N],d[N],v[N];
bool die[N];
int x,y,p,q;
int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int merge(int x,int y)
{
	if(!x) return y;
	else if (!y) return x;
	else if(v[x] > v[y]) swap(x,y);
	
	r[x] = merge(r[x],y);
	if (d[r[x]] > d[l[x]] ) swap(l[x],r[x]);
	d[x] = d[r[x]] + 1;
	return x;
}

void init ()
{
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++)
		scanf("%d",&v[i]),fa[i]=i;
}
void solve()
{
	d[0] = -1;
	char ch[2];
	scanf("%d",&m);
	for(int i = 1 ; i <= m ; i++)
	{
		scanf("%s",ch);
		if(ch[0] == 'M')
		{
			scanf("%d%d",&x,&y);
			if(die[x] || die[y]) continue;
			int p = find (x) , q = find (y);
			if(p != q)
			{
				int t = merge(p,q);
				fa[p] = fa[q] = t;
			}
		}
		else
		{
			scanf("%d",&x);
			if(die[x]) printf("0\n");
			else 
			{
				int p = find(x) ; die[p] = 1;
				printf("%d\n",v[p]);
				fa[p] = merge(l[p],r[p]);
				fa[fa[p]] = fa[p];
			}
		}
	}
}
int main()
{
	init();
	solve();
	return 0;
}