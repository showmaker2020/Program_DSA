#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];

void input(){
	cin >> n >> m;
	for(int i = 1; i <=m ; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void dfs(int u){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
}

void connectedComponent(){
	int ans = 0;
	memset(visited, false, sizeof(visited));
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			++ans;
			dfs(i);
		}
	}
	cout << ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("lck1.in", "r", stdin);
	freopen("lck2.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	connectedComponent();
}