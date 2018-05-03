#include<bits/stdc++.h> 
#define mp(a,b,c,d) (data){a,b,c,d}
#define inf 1000000000
#define ll long long
#define N 500005
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
//��Ԫ��(i, l, r)��ʾ�Ҷ˵�Ϊi����˵���[l, r]֮����������� 
struct data{int i,l,r,t;};
int bin[20],Log[N];
int n,K,L,R;
int a[N],mx[N][20];
ll ans;
void pre()
{ 
	Log[0]=-1;for(int i=1;i<=n;i++)	Log[i]=Log[i>>1]+1; //log[i]��ֵ��i��2�ļ��η�  �����������Դ����� ��������ȽϿ� 
	
	for(int i=1;i<=n;i++)	mx[i][0]=i; //mx[i][j]��ʾ��i�������2��j�η��������������� 
	
	for(int i=n;i;i--)
		for(int j=1;j<=18;j++)
			if(i+bin[j]-1<=n)
			{
				int t1=mx[i][j-1],t2=mx[i+bin[j-1]][j-1]; //������������� 
				mx[i][j]= a[t1]>a[t2] ? t1 : t2 ;	//�ϲ��ж� 
			}
			else break; //  ���Ǹ�СС���Ż� 
}
inline int query(int l,int r)
{
	if(l==r)return l;
	int t=Log[r-l+1];
	int t1=mx[l][t] , t2=mx[r-bin[t]+1][t];
	return a[t1] > a[t2] ? t1 : t2; 
}

inline bool operator<(data x,data y)
{
	return a[x.t]-a[x.i-1]<a[y.t]-a[y.i-1];
} // �ȴ�С ʵ���Ǳ�����͵Ĵ�С 

void solve()
{
	priority_queue<data,vector<data> >q;  //���ȶ��� ������ʹӴ�Сά�� 
	for(int i=1;i<=n;i++)
		if(i+L-1<=n)
		{
			int t=min(n,i+R-1);
			
			q.push(mp( i , i+L-1 , t , query(i+L-1,t) ) );
			
		}
	for(int i=1;i<=K;i++)
	{
		data t=q.top();	q.pop();
		ans += a[t.t] - a[t.i-1]; //���� i �� t �ĺ�  perfect�� 
		// data( i , l , r , t ) 
		// �� i �� l~r �� ���������t  
	    if(t.t-1>=t.l)	q.push(mp(t.i , t.l , t.t-1 , query(t.l,t.t-1) ) );  //��˵���i �Ҷ˵���l~~t-1 ֮�� 
		if(t.t+1<=t.r)	q.push(mp(t.i , t.t+1 , t.r , query(t.t+1,t.r) ) );  //��˵���i �Ҷ˵���t+1~~r ֮�� 
	}
}
int main()
{
	bin[0]=1;for(int i=1;i<20;i++)	bin[i]=bin[i-1]<<1; //bin[i]��ʾ��ʾ��1������iλ������������������ȽϿ죿 
	 
	n=read();K=read();L=read();R=read(); 
	//nΪ�����ĸ�����kΪ�����������ĳ������Ҹ�����L��R�ֱ��ǳ��������������������������޺����� 
	
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)a[i]+=a[i-1];  //ǰ׺���Ż�
	 
	pre();
	solve();
	
	printf("%lld",ans);
	return 0;
}
