#include<bits/stdc++.h>
#define ll long long
const int INF = 0x7fffffff;
const int mx = 30005;
const double eps = 1e-5;
using namespace std;
int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x * f;
}
//f[i]���״̬��ʾa��������i���ӣ�b��������f[i]����  ����ֵ�״̬... 
int n,m,f[30001],a[6001],b[6001],c[6001];
int main()
{
	n = read();
	for(int i = 1 ; i <= n ; i++)
	{
		a[i] = read(),b[i] = read(),c[i] = read();
		if(!a[i]) a[i] = mx; if(!b[i]) b[i] = mx; if(!c[i]) c[i] = mx;	
		int t = mx;
		t = min(min(t,min(a[i],b[i])),c[i]);//t�ǵ�x��������Ҫ������ʱ�� 
		m += t;//m����Ҫ������ʱ����ܺ� 
	}
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = m ; j >= 0 ; j--)
		{	
			int t = mx;
			if(j - a[i] >= 0)
				t = min(t,f[j-a[i]]);
			t = min(t,f[j]+b[i]);
			if(j - c[i] >= 0)
				t = min(t,f[j-c[i]]+c[i]);
			//������������ת�Ʒ��̿ɵ�  �������ȫ��ת��һ�¾������Ž� 
			f[j] = t;
		}
	}
	int ans = mx;
	for(int i = 0 ; i <= m ; i++)	ans = min(ans,max(i,f[i]));//��ȡһ����ȡС 
	printf("%d",ans);
	return 0;
}

