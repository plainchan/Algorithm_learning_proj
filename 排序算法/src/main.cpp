#include <iostream>
#include <ctime>
#include <chrono>
#include <unistd.h>
#include "sort.h"
#include <cassert>

using namespace std;

int main()
{
  vector<int> v=geneVector(10000);
  //开始计时
  chrono::high_resolution_clock::time_point start  = chrono::high_resolution_clock::now();

  quickSort(v,0,v.size()-1);
  // bubbleSort(v);
  

  //结束计时
  chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
  chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(end - start);
  //显示耗时
  // print(v);
  cout << "The running time is " << time_span.count() << " seconds." << endl; 
  return 0;
}