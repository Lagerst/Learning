// ConsoleApplication3.cpp: 定义控制台应用程序的入口点。
//普通字典树 Trie CF291C

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

const int maxn = 300010;

int l = 0, cnt = 0;
string st;
int trie[maxn * 100][3] = {0};
bool adjustable = true;
bool finish[maxn * 100] = {0};

void trie_insert() {
  int j = 0;
  for (int i = 0; i < l; i++) {
    if (!trie[j][st[i] - 'a']) {
      cnt++;
      trie[j][st[i] - 'a'] = cnt;
    }
    j = trie[j][st[i] - 'a'];
  }
  finish[j] = 1;
}

bool trie_search(int k, int j) {
  if (k == l && !adjustable && finish[j]) {
    return 1;
  } else if (k == l) {
    return 0;
  }
  bool flag = 0;
  if (trie[j][st[k] - 'a'] && !flag) {
    flag = flag + trie_search(k + 1, trie[j][st[k] - 'a']);
  }
  if (adjustable) {
    adjustable = false;
    if (trie[j][(st[k] - 'a' + 1) % 3] && !flag)
      flag = flag + trie_search(k + 1, trie[j][(st[k] - 'a' + 1) % 3]);
    if (trie[j][(st[k] - 'a' + 2) % 3] && !flag)
      flag = flag + trie_search(k + 1, trie[j][(st[k] - 'a' + 2) % 3]);
    adjustable = true;
  }
  return flag;
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> st;
    l = st.length();
    trie_insert();
  }
  for (int i = 1; i <= m; i++) {
    cin >> st;
    l = st.length();
    if (trie_search(0, 0)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  system("pause");
  return 0;
}
