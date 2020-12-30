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

#define WHITE 1
#define GREY 2
#define BLACK 3

int adj[100][100];
int color[100];

int Time = 1;
int stime[100];
int ftime[100];

int node, edge;

void dfsVisit(int x) {
	color[x] = GREY;
	//some work
	stime[x] = Time;
	Time++;
	for (int i = 0; i < node; i++) {
		if (adj[x][i] == 1) {
			if (color[i] == WHITE) {
				dfsVisit(i);
			}
		}
	}
	color[x] = BLACK;
	ftime[x] = Time;
	Time++;
}

void dfs() {
	for (int i = 0; i < node; i++) {
		color[i] = WHITE;
	}
	for (int i = 0; i < node; i++) {
		if (color[i] == WHITE) {
			dfsVisit(i);
		}
	}
}

void test() {
	cin >> node >> edge;
	int n1, n2;
	for (int i = 0; i < edge; i++) {
		cin >> n1 >> n2;
		adj[n1][n2] = 1;
		adj[n2][n1] = 1;
	}
	dfs();
	for (int i = 0; i < node; i++) {
		cout << "Node: " << (char)('A' + i) << " " << stime[i] << " " << ftime[i] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//~ cin >> t;
	while (t--) {
		test();
	}
	return 0;
}
