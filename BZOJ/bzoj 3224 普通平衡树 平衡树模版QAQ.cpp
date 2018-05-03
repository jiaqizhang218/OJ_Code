//超时！！！！！ 什么鬼QAQ 
  #include<iostream>  
    #include<cstring>  
    #include<cstdio>  
    using namespace std;  
    #define MAXN 1000000  
    int ch[MAXN][2],f[MAXN],size[MAXN],cnt[MAXN],key[MAXN];  
    //f[i]表示i的父节点 ch[i][0/1] 表示i的左/右儿子 key[i]表示i的关键字(即节点i代表的那个数字)
//cnt[i]表示i节点的关键字出现的次数(相当于权值)，size[i]表示i的子树的大小
//sz为整棵树的大小，root为整棵树的根 
    int sz,root;  
    inline void clear(int x){  //清空某个点 
        ch[x][0]=ch[x][1]=f[x]=size[x]=cnt[x]=key[x]=0;  
    }  
    inline bool get(int x){  //探究这个点是左儿子还是右儿子 
        return ch[f[x]][1]==x;  
    }  
    inline void update(int x){  //更新这个点的size值 
        if (x){  
            size[x]=cnt[x];  
            if (ch[x][0]) size[x]+=size[ch[x][0]];  
            if (ch[x][1]) size[x]+=size[ch[x][1]];  
        }  
    }  
    inline void rotate(int x){  //伸展 
        int old=f[x],oldf=f[old],whichx=get(x);  
        ch[old][whichx]=ch[x][whichx^1]; f[ch[old][whichx]]=old;  
        ch[x][whichx^1]=old; f[old]=x;  
        f[x]=oldf;  
        if (oldf)  
            ch[oldf][ch[oldf][1]==old]=x;  
        update(old); update(x);  
    }  
    inline void splay(int x){  //伸展在伸展！！ 
        for (int fa;fa=f[x];rotate(x))  
          if (f[fa])  
            rotate((get(x)==get(fa))?fa:x);  
        root=x;  
    }  
    inline void insert(int x){  //插入操作 
        if (root==0){sz++; ch[sz][0]=ch[sz][1]=f[sz]=0; root=sz; size[sz]=cnt[sz]=1; key[sz]=x; return;}  
        int now=root,fa=0;  
        while(1){  
            if (x==key[now]){  
                cnt[now]++; update(now); update(fa); splay(now); break;  
            }  
            fa=now;  
            now=ch[now][key[now]<x];  
            if (now==0){  
                sz++;  
                ch[sz][0]=ch[sz][1]=0;  
                f[sz]=fa;  
                size[sz]=cnt[sz]=1;  
                ch[fa][key[fa]<x]=sz;  
                key[sz]=x;  
                update(fa);  
                splay(sz);  
                break;  
            }  
        }  
    }  
    inline int find(int x){  //找到这个数字排第几个 
        int now=root,ans=0;  
        while(1){  
            if (x<key[now])  
              now=ch[now][0];  
            else{  
                ans+=(ch[now][0]?size[ch[now][0]]:0);  
                if (x==key[now]){  
                    splay(now); return ans+1;  
                }  
                ans+=cnt[now];  
                now=ch[now][1];  
            }  
        }  
    }  
    inline int findx(int x){  //找到第x个数字是谁 
        int now=root;  
        while(1){  
            if (ch[now][0]&&x<=size[ch[now][0]])  
              now=ch[now][0];  
            else{  
                int temp=(ch[now][0]?size[ch[now][0]]:0)+cnt[now];  
                if (x<=temp) return key[now];  
                x-=temp; now=ch[now][1];  
            }  
        }  
    }  
    inline int pre(){  //找前驱 
        int now=ch[root][0];  
        while (ch[now][1]) now=ch[now][1];  
        return now;  
    }  
    inline int next(){  //找后继 
        int now=ch[root][1];  
        while (ch[now][0]) now=ch[now][0];  
        return now;  
    }  
    inline void del(int x){   //删除某个节点 
        if (cnt[root]>1){cnt[root]--; update(root); return;}  
        if (!ch[root][0]&&!ch[root][1]) {clear(root); root=0; return;}  
        if (!ch[root][0]){  
            int oldroot=root; root=ch[root][1]; f[root]=0; clear(oldroot); return;  
        }  
        else if (!ch[root][1]){  
            int oldroot=root; root=ch[root][0]; f[root]=0; clear(oldroot); return;  
        }  
        int leftbig=pre(),oldroot=root;  
        splay(leftbig);  
        ch[root][1]=ch[oldroot][1];  
        f[ch[oldroot][1]]=root;  
        clear(oldroot);  
        update(root);   
    }  
    int main(){  
        int n,opt,x;  
        scanf("%d",&n);  
        for (int i=1;i<=n;++i){  
            scanf("%d%d",&opt,&x);  
            switch(opt){  
                case 1: insert(x); break;  
                case 2: del(x); break;  
                case 3: printf("%d\n",find(x)); break;  
                case 4: printf("%d\n",findx(x)); break;  
                case 5: insert(x); printf("%d\n",key[pre()]); del(x); break;  
                case 6: insert(x); printf("%d\n",key[next()]); del(x); break;  
            }  
        }  
    }  
