#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <unistd.h>
#include "sort.h"
#include <cassert>

using namespace std;
using namespace chrono;


#define SIZE 80000000
sort_type type= shell;
int main()
{
  high_resolution_clock::time_point start, end;
  duration<double> time_span;

  vector<int> arr = geneVector(SIZE);

  vector<int> arr1(arr);
  sort(arr1.begin(), arr1.end());
  // sort(arr.begin(), arr.end());
  // print(arr1);

  start = high_resolution_clock::now();
  string method;
  switch (type)
  {
  case bubble:bubbleSort(arr);method="BubbleSort"s;break;
  case selection:selectionSort(arr);method="SelectionSort"s;break;
  case insertion:insertionSort(arr);method="InsertionSort"s;break;
  case shell:shellSort(arr);method="ShellSort"s;break;
  case quick:quickSort(arr, 0, SIZE - 1);method="QuickSort"s;break;
  case merging:mergeSort(arr, 0, SIZE - 1);method="MergeSort"s;break;
  case heap:heapSort(arr);method="HeapSort"s;break;
  default:break;
  }
  end = high_resolution_clock::now();
  time_span = duration_cast<duration<double>>(end - start);

  // print(arr);
  if (arr1 == arr)
    cout << method << "." 
         << "The sorting time is " << time_span.count() << " seconds." 
         << " size = " << SIZE << endl;
  return 0;
}