// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

// 01字典树 Trie CF948D

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <string.h>

const int maxn = 300010;
int n, a[maxn] = {0}, cnt = 0;
int value[maxn * 32] = {0};
int ch[32 * maxn][2] = {0}, visited[32 * maxn] = {0};

using namespace std;

void init() { memset(ch[0], 0, sizeof(a)); } //清空字典树

void Trie_insert(int a) {
  int u = 0;
  for (int i = 31; i >= 0; i--) {
    int c = ((a >> i) & 1);
    if (!ch[u][c]) {
      ch[u][c] = ++cnt;
    }
    value[ch[u][c]] = value[u] * 2 + c;
    u = ch[u][c];
    visited[u]++;
  }
  value[u] = a;
} //在字典树中插入 a

int Trie_query(int a) {
  int u = 0;
  for (int i = 31; i >= 0; i--) {
    int c = ((a >> i) & 1);
    if (ch[u][c] && visited[ch[u][c]]) {
      visited[ch[u][c]]--;
      u = ch[u][c];
    } else if (ch[u][c ^ 1] && visited[ch[u][c ^ 1]]) {
      visited[ch[u][c ^ 1]]--;
      u = ch[u][c ^ 1];
    }
  }
  return value[u];
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int p;
  for (int j = 1; j <= n; j++) {
    cin >> p;
    Trie_insert(p);
  }
  for (int i = 1; i <= n; i++) {
    cout << (Trie_query(a[i]) ^ a[i]) << ' ';
  }
  cout << endl;
  return 0;
}