#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <unistd.h>
#include "sort.h"
#include <cassert>

using namespace std;
using namespace chrono;

enum sort_type
{
  bubble,
  selection,
  insertion,
  quick,
  heap
};

#define SIZE 100000000
sort_type type= heap;
int main()
{
  high_resolution_clock::time_point start, end;
  duration<double> time_span;

  vector<int> arr = geneVector(SIZE);
  vector<int> arr1(arr);
  sort(arr1.begin(), arr1.end());
  // print(arr1);
  switch (type)
  {
  case bubble:
    start = high_resolution_clock::now();
    bubbleSort(arr);
    end = high_resolution_clock::now();
    break;
  case selection:
    start = high_resolution_clock::now();
    selectionSort(arr);
    end = high_resolution_clock::now();
    break;
  case insertion:
    start = high_resolution_clock::now();
    insertionSort(arr);
    end = high_resolution_clock::now();
    break;
  case quick:
    start = high_resolution_clock::now();
    quickSort(arr, 0, SIZE - 1);
    end = high_resolution_clock::now();
    break;
  case heap:
    start = high_resolution_clock::now();
    heapSort(arr);
    end = high_resolution_clock::now();
    break;
  default:break;
  }

  time_span = duration_cast<duration<double>>(end - start);
  // print(arr);
  if (arr1 == arr)
    cout << "Right."   
         << "The sorting time is " << time_span.count() << " seconds." 
         << " size = " << SIZE << endl;
  return 0;
}