#define LOCAL
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
ostream& operator <<(ostream& out, const pair<A, B>& a) {
  out << "(" << a.first << "," << a.second << ")";
  return out;
}
template <typename T, size_t N>
ostream& operator <<(ostream& out, const array<T, N>& a) {
  out << "["; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& a) {
  out << "["; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream& out, const set<T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "}";
  return out;
}
template <typename U, typename T, class Cmp>
ostream& operator <<(ostream& out, const map<U, T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& p : a) { out << (first ? "" : ", "); out << p.first << ":" << p.second; first = 0;} out << "}";
  return out;
}
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

int A[5][5];
bool visited[5][5];

int dx[] = {-1, 1,  0, 0, -1, -1,  1, 1};
int dy[] = {0,  0, -1, 1, -1,  1, -1, 1};

//~ knight moves
//~ int kx[] = {1, 1, 2, 2, -1, -1, -2, -2};
//~ int ky[] = {2, -2, 1, -1, 2, -2, 1, -1};

bool valid(int x, int y) {
	return (x >= 0 && x < 5 && y >= 0 && y < 5 && !visited[x][y]);
}

void dfs(int x, int y) {
	//~ visit the cell
	if (!visited[x][y]) return;
	visited[x][y] = 1;
	for (int i = 0; i < 8; i++) {
		int next_x = dx[i] + x;
		int next_y = dy[i] + y;
		if (valid(next_x, next_y)) {
			dfs(next_x, next_y);
		}
	}
}

struct node {
	int x, y;
};

void bfs(int sx, int sy) {
	queue<node> Q;
	Q.push({sx, sy});
	visited[sx][sy] = 1;
	while (!Q.empty()) {
		int x = Q.front().x;
		int y = Q.front().y;
		Q.pop();
		for (int i = 0; i < 8; i++) {
			int next_x = dx[i] + x;
			int next_y = dy[i] + y;
			if (valid(next_x, next_y)) {
				visited[next_x][next_y] = 1;
				Q.push({next_x, next_y});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	bfs(2, 2);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
