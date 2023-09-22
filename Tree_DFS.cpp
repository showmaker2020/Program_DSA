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
		//adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

void dfs(int u){
	cout << u <<' ';
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("lck1.in", "r", stdin);
	freopen("lck2.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	dfs(1);
}