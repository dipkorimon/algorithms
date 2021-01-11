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

#define nax 110

vector<int> graph[nax];
bool mark[nax];
bool vis[nax];
int dist[nax];

void bfs(vector<int> sources) {
  queue<int> Q;
  for (int i = 0; i < (int)sources.size(); i++) {
    int source = sources[i];
    vis[source] = 1;
    dist[source] = 0;
    Q.push(source);
  }
  while (!Q.empty()) {
    int node = Q.front();
    Q.pop();
    for (int i = 0; i < graph[node].size(); i++) {
      int next = graph[node][i];
      if (vis[next] == 0) {
        vis[next] = 1; //visit
        dist[next] = dist[node] + 1; //update
        Q.push(next); //push to queue
      }
    }
  }
}

void test() {
  int nodes, edges;
  cin >> nodes >> edges;
  for (int i = 1; i <= edges; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int numOfSources;
  cin >> numOfSources;
  vector<int> sources;
  for (int i = 1; i <= numOfSources; i++) {
    int source;
    cin >> source;
    mark[source] = 1; //mark source node
    sources.push_back(source);
  }
  bfs(sources);
  // cout << "From node " << source << "\n";
  for (int i = 1; i <= nodes; i++) {
    if (mark[i] == 1) continue; //avoid printing source node
    cout << "Distance of " << i << " is : " << dist[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) {
    test();
  }
  return 0;
}