#include <cstdio>
#include <queue>
#define N 300010
using namespace std;
int inline read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void swap(int &x,int &y){int t=x;x=y,y=t;}
int n,m,add,root;
char com[10];
struct zps
{
    int ch[N][2],val[N],dis[N],f[N],mark[N];
    void clear(int x){f[x]=ch[x][0]=ch[x][1]=0;}
    int sum(int x)
    {
        int ans=0;
        while(x=f[x]) ans+=mark[x];
        return ans;
    }
    void pushdown(int x)
    {
        if (ch[x][0])
            val[ch[x][0]]+=mark[x],
            mark[ch[x][0]]+=mark[x];
        if (ch[x][1])
            val[ch[x][1]]+=mark[x],
            mark[ch[x][1]]+=mark[x];
        mark[x]=0;
    }
    int merge(int x,int y)
    {
        if (x*y==0)
            return x+y;
        if (val[x]<val[y])
            swap(x,y);
        pushdown(x);
        ch[x][1]=merge(ch[x][1],y);
        f[ch[x][1]]=x;
        if (dis[ch[x][0]]<dis[ch[x][1]])
            swap(ch[x][0],ch[x][1]);
        dis[x]=dis[ch[x][1]]+1;
        return x;
    }
    int getf(int x)
    {
        while(f[x]) x=f[x];
        return x;
    }
    int del_pos(int x)
    {
        pushdown(x);
        int q=f[x],p=merge(ch[x][0],ch[x][1]);
        f[p]=q;
        if (q)
            ch[q][ch[q][1]==x]=p;
        while(q)
        {
            if (dis[ch[q][0]]<dis[ch[q][1]])
                swap(ch[q][0],ch[q][1]);
            if (dis[ch[q][1]]+1==dis[q])
                return root;
            dis[q]=dis[ch[q][1]]+1;
            p=q;
            q=f[q];
        }
        return p;
    }
    void add_tree(int x,int v)
    {
        int fx=getf(x);
        val[fx]+=v;
        mark[fx]+=v;
    }
    int add_point(int x,int v)
    {
        int fx=getf(x);
        if (fx==x)
            if (ch[x][0]+ch[x][1]==0)
            {
                val[x]+=v;
                return x;
            }
            else
                if (ch[x][0])
                    fx=ch[x][0];
                else
                    fx=ch[x][1];
        del_pos(x);
        val[x]+=v+sum(x);
        clear(x);
        return merge(getf(fx),x);
    }
    int build()
    {
        queue<int>que;
        for (int i=1;i<=n;i++)
            que.push(i);
        while(que.size()>1)
        {
            int x=que.front();que.pop();
            int y=que.front();que.pop();
            int z=merge(x,y);
            que.push(z);
        }
        return que.front();
    }
}h1,h2;
 
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
    n=read();
    h1.dis[0]=h2.dis[0]=-1;
    for (int i=1;i<=n;i++)
        h1.val[i]=read(),h2.val[i]=h1.val[i];
    root=h2.build();
    m=read();
    for (int i=1;i<=m;i++)
    {
        scanf("%s",com);
        if (com[0]=='U')
        {
            int x=read(),y=read();
            int temp,fx=h1.getf(x),fy=h1.getf(y);
            if (fx!=fy)
            {
                temp=h1.merge(fx,fy);
                if (temp==fx)
                    root=h2.del_pos(fy);
                else
                    root=h2.del_pos(fx);
            }
        }
        else 
        if (com[0]=='A')
            if (com[1]=='1')
            {
                int x=read(),v=read();
                root=h2.del_pos(h1.getf(x));
                int y=h1.add_point(x,v);
                h2.val[y]=h1.val[y];
                h2.clear(y);
                root=h2.merge(root,y);
            }
            else if (com[1]=='2')
            {
                int x=read(),v=read(),fx=h1.getf(x);
                root=h2.del_pos(fx);
                h1.val[fx]+=v;
                h1.mark[fx]+=v;
                h2.val[fx]=h1.val[fx];
                h2.clear(fx);
                root=h2.merge(root,fx);
            }
            else if (com[1]=='3')
            {
                int v=read();
                add+=v;
            }
            else;
        else if (com[0]=='F')
            if (com[1]=='1')
            {
                int x=read();
                printf("%d\n",h1.val[x]+add+h1.sum(x));
            }
            else if (com[1]=='2')
            {
                int x=read();
                printf("%d\n",h1.val[h1.getf(x)]+add);
            }
            else if (com[1]=='3')
                printf("%d\n",h2.val[root]+add);
 
    }
}
