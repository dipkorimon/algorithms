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

int n; // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
	visited[v] = true;
	for (int u : adj[v]) {
		if (!visited[u]) {
			dfs(u);
		}
	}
	ans.push_back(v);
}

void topological_sort() {
	visited.assign(n, false);
	ans.clear();
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	reverse(ans.begin(), ans.end());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	return 0;
}
