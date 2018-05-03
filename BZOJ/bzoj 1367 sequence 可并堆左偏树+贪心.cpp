#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9;
const int eps = 1e-10;
const int maxn = 1000000 + 10;
int n,a[maxn] , v[maxn] , lx[maxn] , rx[maxn] , sz[maxn] , dis[maxn] , root[maxn] , L[maxn] , R[maxn];
// v �����ʾ ���ֵ    lx ��ʾ���� rx ��ʾ����  sz ��ʾ���Ĵ�С  dis ��ʾ���� 
struct left_tree
{
	int top(int x)
	{
		return v[x];
	}
	
	int merge(int x,int y)
	{
		if(!x) return y;
		if(!y) return x;
		if(v[x] < v[y]) swap(x,y);
		
		rx[x] = merge(rx[x],y);
		
		sz[x] = sz[lx[x]] + sz[rx[x]] + 1;
		
		if(dis[rx[x]] > dis[lx[x]]) swap(rx[x],lx[x]);
		
		dis[x] = dis[rx[x]] + 1;
		
		return x;
		}	
}heap; 

void init ()
{
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++)
		scanf("%d",&a[i]),a[i]-=i;  //��˵����һ�����½����� 
}

void solve()
{
	int top = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		sz[i]  = 1;
		dis[i] = lx[i] = rx[i] = 0;  
		v[i] = a[i];
		root[++top] = i;
		L[top] = R[top] = i;
		//��Ҫ�ӵ� �Ͱѵ�����һ��ֻ��һ����������� 
		while(top > 1 && heap.top(root[top-1]) > heap.top(root[top]))
		{
			//��ǰһ����������ʱ�� 
			top--;
			
			root[top] = heap.merge(root[top] , root[top+1]);
			
			R[top] = R[top + 1];
			
			int tot = R[top] - L[top] + 1; 
			
			while (sz[root[top]] << 1 > tot + 1)
			{
				root[top] = heap.merge(lx[root[top]],rx[root[top]]);
			}
		}
	}
	ll ans = 0;
	
	for(int i = 1 ; i <= top ; i++)
	{
		int mid = heap.top(root[i]);
		
		for(int j = L[i] ; j <= R[i] ; j++) ans += abs(a[j] - mid);
	}
	printf("%lld",ans);
}
int main()
{
	init();
	solve();
	return 0;
 } 
