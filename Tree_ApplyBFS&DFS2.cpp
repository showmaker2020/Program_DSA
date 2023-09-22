#include <bits/stdc++.h>
using namespace std;

int n, m ,s ,t;
char a[1001][1001];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = { 0, -1, 1, 0};
bool visited[1001][10001];

bool dfs(int i , int j){
	cout << i << ' ' << j << endl;
	if(a[i][j] == 'B'){
		return true;
	}
	a[i][j] = 'x';
	// duyet dinh ke
	for(int k = 0; k < 4; k++){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1 >= 1 && i1 <=n && j1 >=1 && j1 <= m && a[i1][j1] != 'x'){
			if(dfs(i1, j1)) return true;
		}
	}
	return false;
}

bool bfs(int i, int j){
	queue<pair<int,int>> q;
	q.push({i , j});
	a[i][j] = 'o';
	cout << i << ' ' << j << endl;
	while(!q.empty()){
		pair<int, int> top = q.front();
		q.pop();
		for(int k = 0; k < 4; k++){
			int i1 = top.first + dx[k];
			int j1 = top.second + dy[k];
			if(i1 >= 1 && i1 <=n && j1 >=1 && j1 <= m && a[i1][j1] != 'x'){
				cout << i1 << ' ' << j1 << endl;
				if(a[i][j] == 'B') return true;
				q.push({i1, j1});
				a[i1][j1] = 'o';
			}
	}
	}
	return false;
}


void input(){
	cin >> n >> m;
	for(int i = 1 ; i<= n; i++){
		for(int j = 1; j <= m;j++){
			cin >> a[i][j];
			if(a[i][j] == 'A'){
				s = i;
				t = j;
			}
		}
	}
	memset(visited, false, sizeof(visited));
	if(dfs(s,t)){
		cout << "YES" << endl;

	} else cout << "NO" << endl;
}



int main(){
	#ifndef ONLINE_JUDGE
	freopen("lck1.in", "r", stdin);
	freopen("lck2.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
}