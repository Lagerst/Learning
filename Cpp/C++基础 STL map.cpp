// ConsoleApplication2.cpp: 定义控制台应用程序的入口点。
// STL map

#include "stdafx.h"
#define scanf scanf_s

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

long long a[150015] = {0};

int main() {
  map<int, string> mapStudent;

  mapStudent[1] = "student_one";

  mapStudent.insert(pair<int, string>(2, "student_two"));

  mapStudent.insert(map<int, string>::value_type(3, "student_three"));
  //三种方法等效(2)(3)不可覆盖

  int nSize = mapStudent.size();
  cout << nSize << endl;

  map<int, string>::iterator iter;

  for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)

    cout << iter->first << ' ' << iter->second << endl;

  //	map<int,string>::reverse_iterator iter;

  //	for (iter=mapStudent.rbegin(); iter!=mapStudent.rend(); iter++)

  //		cout<<iter->first<<"  "<<iter->second<<endl;

  iter = mapStudent.find(1);

  if (iter != mapStudent.end())

    cout << "Find, the value is " << iter->second << endl;

  else

    cout << "Do not Find" << endl;

  mapStudent.erase(iter);

  for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)

    cout << iter->first << ' ' << iter->second << endl;

  system("pause");
  return 0;
}