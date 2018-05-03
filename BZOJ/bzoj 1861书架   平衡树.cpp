#include<stdio.h>  
#define MAXN 300000  
using namespace std;  
long s[MAXN],f[MAXN],ch[MAXN][2],data[MAXN],root,tot,n,m;  
void updata(long x)  
{  
    s[x]=1;if(ch[x][0]!=-1)s[x]+=s[ch[x][0]];if(ch[x][1]!=-1)s[x]+=s[ch[x][1]];  
}  
void rot(long x,int kind)  
{  
    long y=f[x];long z=f[y];  
    ch[y][!kind]=ch[x][kind];if(ch[x][kind]!=-1)f[ch[x][kind]]=y;  
    f[x]=z;if(z!=-1)ch[z][ch[z][1]==y]=x;  
    f[y]=x;ch[x][kind]=y;updata(y);updata(x);  
}  
void splay(long x,long place)  
{  
    while(f[x]!=place)  
    {  
        long y=f[x];long z=f[y];  
        if(z==-1||z==place)rot(x,ch[y][1]!=x);  
        else  
        {  
                    if(ch[y][1]==x&&ch[z][1]==y)rot(y,0),rot(x,0);  
            else    if(ch[y][1]==x&&ch[z][0]==y)rot(x,0),rot(x,1);  
            else    if(ch[y][0]==x&&ch[z][0]==y)rot(y,1),rot(x,1);  
            else    rot(x,1),rot(x,0);  
        }  
    }  
    if(place==-1)root=x;  
}  
void newnode(long fa,long dat){tot++;f[tot]=fa;s[tot]=1;ch[tot][0]=ch[tot][1]=-1;data[tot]=dat;}  
long getsize(long x){if(x==-1)return 0;else return s[x];}  
void insert(long x,long dat,long k)  
{  
    if(k==1&&ch[x][0]==-1){newnode(x,dat);ch[x][0]=tot;return;}  
    if(k==2+getsize(ch[x][0])&&ch[x][1]==-1){newnode(x,dat);ch[x][1]=tot;return;}  
    if(k<=1+getsize(ch[x][0]))insert(ch[x][0],dat,k);  
    else insert(ch[x][1],dat,k-1-getsize(ch[x][0]));  
    updata(x);  
}  
void del(long x)  
{  
    splay(x,-1);  
    if(ch[x][0]==-1&&ch[x][1]==-1){root=-1;return;}  
    if(ch[x][0]==-1){root=ch[x][1];f[ch[x][1]]=-1;return;}  
    if(ch[x][1]==-1){root=ch[x][0];f[ch[x][0]]=-1;return;}  
    long j=ch[x][0];while(ch[j][1]!=-1)j=ch[j][1];  
    splay(j,x);  
    ch[j][1]=ch[x][1];  
    f[ch[x][1]]=j;f[j]=-1;root=j;  
    updata(j);  
}  
long find(long k)  
{  
    long p=k;  
    long a=root;  
    while(true)  
    {  
        if(k==1+getsize(ch[a][0]))return a;  
        if(k>1+getsize(ch[a][0]))k-=1+getsize(ch[a][0]),a=ch[a][1];  
        else a=ch[a][0];  
    }  
}  
long get(long x)  
{  
    splay(x,-1);  
    return getsize(ch[x][0])+1;  
}  
long pos[100000];long a[100000];  
int main()  
{  
    scanf("%ld%ld",&n,&m);for(long i=1;i<=n;i++)scanf("%ld",&a[i]),pos[a[i]]=i;tot=0;root=-1;  
    for(long i=1;i<=n;i++)  
    {  
        if(i==1)newnode(-1,a[i]),root=tot;  
        else{insert(root,a[i],i);if(i&1)splay(tot,-1);}  
    }  
    for(long ip=1;ip<=m;ip++)  
    {  
        char p[100];long j,k,i;  
        scanf("%s%ld",&p,&i);  
        if(p[0]=='I')scanf("%ld",&j);  
        if(p[0]=='T'){del(pos[i]);insert(root,i,1);pos[i]=tot;splay(tot,-1);}  
        if(p[0]=='B'){del(pos[i]);insert(root,i,n);pos[i]=tot;splay(tot,-1);}  
        if(p[0]=='I'){long u=get(pos[i]);u=u-1+j;del(pos[i]);insert(root,i,u+1);splay(tot,-1);pos[i]=tot;}  
        if(p[0]=='A'){printf("%ld\n",get(pos[i])-1);}  
        if(p[0]=='Q'){printf("%ld\n",data[find(i)]);}   
    }   
    return 0;  
}  
