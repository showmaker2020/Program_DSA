#include <bits/stdc++.h>
using namespace std;

int n, m, s ,t;
vector<int> adj[1001];
int parent[1001];
bool visited[1001];

void input(){
	cin >> n >> m >> s >> t;
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
			// ghi nhan cha cua v la u
			parent[v] = u;
			dfs(v);
		}
	}
}

void Path(int s, int t){
	memset(visited, false, sizeof(visited));
	memset(parent, 0, sizeof(parent));
	dfs(s);
	if(!visited[t]){
		cout << "Khong co duong di! ";
	}
	else {
		vector<int> path;
		while(t != s){
			path.push_back(t);
			t = parent[t];
		}
		path.push_back(s);
		reverse(path.begin(), path.end());
		for(int x : path){
			cout << x << ' ';
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
	Path(s,t);
}