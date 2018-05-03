#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
inline void exgcd(LL a,LL b,LL &g,LL &x,LL &y)
{
	if(!b)	g = a , x = 1 , y = 0;
	else exgcd(b,a%b,g,y,x),y-=x*(a/b);
}
inline LL inv(LL x,LL p)
{
	LL g,res,tmp;
	exgcd(x,p,g,res,tmp);
	return (res%p+p)%p;
}
inline LL bsgs(LL a,LL b,LL p)
{
	a %= p , b %= p;
	map<LL,LL> mp;
	LL m = ceil(sqrt(p)) , t = 1;
	for(int i = 0 ; i < m ; i++)
	{
		if(!mp.count(t)) mp[t] = i;
		t = t * a % p;
	}
	LL k = inv(t,p) , w = b;
	for(int i = 0 ; i < m ; i++)
	{
		if(mp.count(w)) return i * m + mp[w];
		w = w * k % p; 
	}
	return -1;
}
inline LL solve(LL p,LL a,LL b,LL x1,LL t)
{
	if(t == x1)	return true;
	else if(a == 0)	return b == t ? 2 : -1;
	else if(a == 1)
	{
		if(!b)	return -1;
		return (((t - x1) % p + p) % p * inv(b,p) % p) + 1;
	}
	else {
		LL q = inv(1-a+p,p);
		LL d = (((t - b * q) % p + p) % p) * inv(((x1-b*q)%p+p)%p,p);
		LL ans = bsgs(a,d,p);
		if(ans == -1)	return -1;
		else return ans + 1;
	}
}
int main()
{
	int T = read(); 
    while (T--) {
        int p, a, b, x1, t;
        scanf("%d %d %d %d %d", &p, &a, &b, &x1, &t);
        printf("%lld\n", solve(p, a, b, x1, t));
    }
}
