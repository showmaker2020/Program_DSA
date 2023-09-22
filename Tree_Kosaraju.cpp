#include <bits/stdc++.h>
using namespace std;

int n, m;
const  int maxn = 1001;
vector<int> adj[maxn] , r_adj[maxn];
bool used[maxn];
stack <int> st;
void input(){
	cin >> n >> m;
	for(int i = 1; i <=m ; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		r_adj[y].push_back(x);
	}
}

void dfs1(int u){
	used[u] = true;
	for(int v : adj[u]){
		if(!used[v]){
			dfs1(v);
		}
	}
	cout << u << ' ';
	st.push(u);
}

void dfs2(int u){
	used[u] = true;
	cout << u << ' ';
	for(int v : r_adj[u]){
		if(!used[v]){
			dfs2(v);
		}
	}
}

void SCC(){
	memset(used, false , sizeof(used));
	for(int i = 1; i <= n;i++){
		if(!used[i]){
			dfs1(i);
		}
	}
	cout << endl;
	memset(used, false , sizeof(used));
	while(!st.empty()){
		int u = st.top();
		st.pop();
		if(!used[u]){
			dfs2(u);
			cout << endl;
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("lck1.in", "r", stdin);
	freopen("lck1.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	SCC();
}