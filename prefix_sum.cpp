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

const int nax = 1e3 + 10;
int a[nax][nax];
long long pf[nax][nax];

int b[500];
long long sum[500];

// pre-computation using prefix sum in 1D Array

void prefix_sum_1D() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    sum[i] = sum[i - 1] + b[i];
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << sum[r] - sum[l - 1] << "\n";
  }
}

// pre-computation using prefix sum in 2D Array

void frefix_sum_2D() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      pf[i][j] = a[i][j] + pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1];  
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << pf[c][d] - pf[a - 1][d] - pf[c][b - 1] + pf[a - 1][b - 1] << "\n";
  }
}

void test() {
  
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