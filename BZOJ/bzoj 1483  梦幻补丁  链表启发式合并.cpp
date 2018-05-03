#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000009;
int N, M, ans, H;
int c[maxn], C, sz[maxn], Id[maxn];
struct Link {
	int p;
	Link* next;
} *head[maxn], *last[maxn], pool[maxn], *pt = pool;
void Add(int c, int p) {
	if(!head[c])
		last[c] = pt;
	pt->p = p;
	pt->next = head[c];
	head[c] = pt++;
} 
 
void Init() {
	
	memset(sz, 0, sizeof sz);
	
	C = 0; ans = 1;
	
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; i++) {
		scanf("%d", c + i);
		Add(Id[c[i]] = c[i], i);
		sz[c[i]]++;
		if(i && c[i] != c[i - 1]) ans++;
	}
	
}
 
void Change(int oc, int nc) {
	
	for(Link* r = head[oc]; r; r = r->next) {
		if(r->p > 0 && c[r->p - 1] == nc) ans--;
		if(r->p + 1 < N && c[r->p + 1] == nc) ans--;
	}
	
	for(Link* r = head[oc]; r; r = r->next) c[r->p] = nc;
		
	last[nc]->next = head[oc];
	last[nc] = last[oc];
	
}
 
int main() {
	
	Init();	
	while(M--) {
		int opt;
		scanf("%d", &opt);
		if(opt == 2)
			printf("%d\n", ans);
		else {
			int oc, nc;
			scanf("%d%d", &oc, &nc);
			if(sz[Id[oc]] > sz[Id[nc]]) 
				swap(Id[oc], Id[nc]);
			oc = Id[oc]; nc = Id[nc];
			if(!sz[oc] || oc == nc) continue;
			sz[nc] += sz[oc]; sz[oc] = 0;
			Change(oc, nc);
		}
	}
	return 0;
}
