#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define RVC(i, S) for (int i = 0; i < S.size(); ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
  
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> VI;
  
inline int read(){
    int x = 0, ch = getchar(), f = 1;
    while (!isdigit(ch)){if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}
 
const int N = 100005, M = 30005, INF = 0x3f3f3f3f;
 
int n, m, T, mnv[M], val[M], mnp[M], sz[M];
VI ins[N], del[N];
 
int fa[M], ch[M][2], rev[M], on_tree[M], ban[M], tot_ban;
 
#define lc ch[x][0]
#define rc ch[x][1]
#define dir(x) (ch[fa[x]][1] == x)
 
int isrt(int x){return ch[fa[x]][0] != x && ch[fa[x]][1] != x;}
 
void pu(int x){
    mnv[x] = min(val[x], min(mnv[lc], mnv[rc]));
    if (mnv[x] == val[x]) mnp[x] = x;
    else if (mnv[x] == mnv[lc]) mnp[x] = mnp[lc];
    else if (mnv[x] == mnv[rc]) mnp[x] = mnp[rc];
    sz[x] = sz[lc] + sz[rc] + (x <= n); // only real vertices count
}
 
void rever(int x){
    rev[x] ^= 1;
    swap(lc, rc);
}
 
void pd(int x){
    if (rev[x]){
        rever(lc); rever(rc);
        rev[x] = 0;
    }
}

void gop(int x){if (!isrt(x)) gop(fa[x]);pd(x);}
 
void rot(int x){
    int p = fa[x], d = dir(x);
    fa[x] = fa[p];
    if (!isrt(p)) ch[fa[p]][dir(p)] = x;
    ch[p][d] = ch[x][d ^ 1];	fa[ch[x][d ^ 1]] = p;
    ch[x][d ^ 1] = p;	fa[p] = x;
    pu(p);
}
 
void splay(int x){
    gop(x);
    while (!isrt(x)){
        if (isrt(fa[x])) rot(x);
        else if (dir(fa[x]) == dir(x)) rot(fa[x]), rot(x);
        else rot(x), rot(x);
    }
    pu(x);
}
 
void access(int x){
    for (int y = 0; x; x = fa[y = x])
        splay(x), fa[rc = y] = x, pu(x);
}
 
void mkrt(int x){
    access(x);splay(x);
    rever(x);pu(x);
}
 
void link(int x, int y){
    mkrt(x); fa[x] = y;
}
 
void cut(int x, int y){
    mkrt(x); access(y);
    splay(y); fa[x] = ch[y][0] = 0;
}
 
int findrt(int x){
    return fa[x] ? findrt(fa[x]) : x;
}
 
struct Edge{
    int u, v, w;
} E[M];
 
int main(){
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
    n = read(), m = read(), T = read();
    mnv[0] = val[0] = INF;
    REP(i, 1, n){ // real vertices 1 .. n
        mnv[i] = val[i] = INF;
        mnp[i] = i; sz[i] = 1;
    }
    REP(i, 1, m){ // imaginary vertices n + 1 .. n + m
        E[n + i].u = read();
        E[n + i].v = read();
        int st = read() + 1, ed = read() + 1;
        mnv[n + i] = val[n + i] = E[n + i].w = ed;
        mnp[n + i] = n + i;
        sz[n + i] = 0;
        ins[st].pb(n + i);
        del[ed].pb(n + i);
    }
    REP(i, 1, T){
        RVC(j, ins[i]) {
            int id = ins[i][j];
            Edge e = E[id];
            if (findrt(e.u) != findrt(e.v)){
                link(e.u, id) , link(e.v, id);
                on_tree[id] = 1;
            }
            else{
                mkrt(e.u); access(e.v);
                splay(e.u);
                int p = mnp[e.u], d = sz[e.u];
                if (val[id] <= val[p]){
                    if (d & 1) {
                        ban[id] = 1;
                        ++tot_ban;
                    }
                }
                else{
                    Edge f = E[p];
                    cut(f.u, p);
                    cut(f.v, p);
                    on_tree[p] = 0;
                    link(e.u, id);
                    link(e.v, id);
                    on_tree[id] = 1;
                    e = f; id = p;
                    mkrt(e.u); access(e.v);
                    splay(e.u);
                    p = mnp[e.u], d = sz[e.u];
                    if (d & 1){
                        ban[id] = 1;
                        ++tot_ban;
                    }
                }
            }
        }
        RVC(j, del[i]){
            int id = del[i][j];
            Edge e = E[id];
            if (on_tree[id]){
                cut(e.u, id);
                cut(e.v, id);
            }
            else if (ban[id]){
                ban[id] = 0;
                --tot_ban;
            }
        }
        if (tot_ban == 0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
