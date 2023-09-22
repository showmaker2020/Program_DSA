#include <bits/stdc++.h>
using namespace std;
// breadth first search
int n, m;
vector<int> adj[1001];
bool visited[1001];

void input(){
	cin >> n >> m;
	for(int i = 1; i <=m ; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		//adj[y].push_back(x); // them vao la do thi vo huong khong them la do thi co huong
	}
	memset(visited, false, sizeof(visited));
}

void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int v = q.front(); // lay dinh o dau hang doi
		q.pop();
		cout << v << ' ';
		for(int x : adj[v]){
			if(!visited[x]){
				q.push(x);
				visited[x] = true;
			}
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
	bfs(1);
}