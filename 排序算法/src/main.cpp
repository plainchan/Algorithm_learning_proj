#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <unistd.h>
#include "tsort.hpp"
#include <cassert>
#include <future>
using namespace std;
using namespace chrono;


#define SIZE 10000000
sort_type type= merging;
int main()
{
  high_resolution_clock::time_point total_start, total_end;
  total_start = high_resolution_clock::now();

  high_resolution_clock::time_point start, end;
  duration<double> time_span;

  auto arr = geneVector(SIZE);

  auto arr1=arr;
  
  std::future<void> stl_sort = std::async([&]()
  {
    
    high_resolution_clock::time_point start1,end1;
    duration<double> time_span1;
    start1 = high_resolution_clock::now();
    sort(arr1.begin(),arr1.end());
    end1 = high_resolution_clock::now();
    // print(arr1);
    time_span1 = duration_cast<duration<double>>(end1 - start1);
    cout << "STL sort" << "." 
         << "The sorting time is " << time_span1.count() << " seconds." 
         << " size = " << SIZE << endl;
  });


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

  stl_sort.get();
  // print(arr);
  if (arr1 == arr)
    cout << method << "." 
         << "The sorting time is " << time_span.count() << " seconds." 
         << " size = " << SIZE << endl;
  else
    cout << "Yourself sort algorithm is wrong" <<endl;

  total_end = high_resolution_clock::now();
  time_span = duration_cast<duration<double>>(total_end  - total_start);
  cout << "runtime " << time_span.count() << "s" <<endl;
  return 0;
}