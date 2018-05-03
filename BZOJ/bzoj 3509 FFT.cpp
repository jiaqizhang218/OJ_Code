#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rpg(i,x) for(register int i=fir[x];i;i=e[i].nxt)
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define bin(i) (1<<i)
#define cls(x,y) memset(x,y,sizeof x)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
const int K = 44;
/*const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc() //*/
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 1e5 + 10;
const double pi = acos(-1.0);
struct Cp {
	double x,y;
	Cp (double _x=0,double _y=0) {x=_x,y=_y;}
	friend Cp operator + (Cp a,Cp b) {return Cp(a.x+b.x,a.y+b.y);}
	friend Cp operator - (Cp a,Cp b) {return Cp(a.x-b.x,a.y-b.y);}
	friend Cp operator * (Cp a,Cp b) {return Cp(a.x*b.x-a.y*b.y,a.x*b.y+b.x*a.y);}
}L[1<<16],R[1<<16],x,w,w0;
int M,rev[MXN<<1],num[MXN],before[30050],behind[30500],in[30500];
inline void FFT(Cp *A,int f) {
	int i,j,k;for(i=0;i<M;++i) if(rev[i]>i) swap(A[i],A[rev[i]]);
	for(i=1;i<M;i<<=1) {
		w.x=cos(pi/i),w.y=sin(pi/i)*f;
		for(j=0;j<M;j+=i<<1) {
			w0.x=1;w0.y=0;
			for(k=0;k<i;++k) {
				x=A[j+k];
				A[j+k]=x+(w0*A[j+k+i]);
				A[j+k+i]=x-(w0*A[j+k+i]);
				w0=w0*w;
			}
		}
	}
	if(f==-1) for(i=0;i<M;++i) A[i].x/=M;
}
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	int t,N,maxNum=1;
	rd(N);
	rep(i,1,N) rd(num[i]),behind[num[i]]++,maxNum=max(maxNum,num[i]);
	for(M=1,t=0;M<=maxNum*2;M<<=1,++t);
	for(int i=1;i<M;++i) rev[i]=(rev[i>>1]>>1)|((i&1)<<(t-1));
	int block=min(K,N);
	int siz=N/block;
	if(N%block) siz++;
	LL ans=0;
	rep(pos,1,block) {
		int s=siz*(pos-1)+1,e=siz*pos;
		if(e>N) e=N;
		rep(t,s,e) behind[num[t]]--;
		rep(i,s,e) {
			rep(j,i+1,e) {
				int ak=2*num[i]-num[j];
				if(ak>=1 && ak <=30000) {
					ans+= in[ak]; //三个数再同一块中时, 枚举的是后两个数, 询问同一块的in数组 
					//枚举后两个数在同一块, 第一个数不在时  
					ans+= before[ak];
				}
				ak = 2*num[j] - num[i];//枚举前两个数时, 第三个数再后面的块中  
				if(ak>=1 && ak<=30000) {
					ans += behind[ak];
				}
			}
			in[num[i]]++;
		}
		//接下来是三个数分布在三块中的情况, 枚举中间数, 对前后部分作FFT  
		rep(i,0,maxNum) {
			L[i]=Cp(before[i]*1.,0);
			R[i]=Cp(behind[i]*1.,0);
		}
		rep(i,maxNum+1,M-1) 
			L[i]=Cp(0,0),R[i]=Cp(0,0);
		FFT(L,1),FFT(R,1);
		rep(i,0,M-1) L[i]=L[i]*R[i];
		FFT(L,-1);
		rep(i,s,e) ans+=(LL)(L[2*num[i]].x+0.5);
		for(int t = s; t <= e; t++)//更新before数组, 还原in数组 
        	before[num[t]]++, in[num[t]]--; 
	}
	printf("%lld\n",ans);
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
