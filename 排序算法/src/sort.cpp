#include <iostream>
#include <ctime>
#include <cassert>
#include <algorithm>
#include "sort.h"

//冒泡排序
void bubbleSort(std::vector<int> &arr)
{
  int n = arr.size();
  if (n < 2)
    return;
  int temp = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
//选择排序
void selectionSort(std::vector<int> &arr)
{
  int n = arr.size();
  int Min_index = 0;
  for (int i = 0; i < n; i++)
  {
    Min_index = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[Min_index])
        Min_index = j;
    }
    if (i != Min_index)
    {
      int temp = arr[i];
      arr[i] = arr[Min_index];
      arr[Min_index] = temp;
    }
  }
}

//插入排序
void insertionSort(std::vector<int> &arr)
{
  int n = arr.size();
  for (int i = 1; i < n; i++)
  {
    int temp = arr[i];
    int j = i - 1;
    while (j >= 0 and temp < arr[j])
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
}

//快速排序
void quickSort(std::vector<int> &arr, int left, int right)
{
  // assert(left >= 0);
  // assert(right < int(arr.size()));
  if (left < right)
  {
    int pivot = arr[right];
    int i = left - 1;
    int temp = 0;

    // partition
    for (int j = left; j < right; j++)
    {
      if (arr[j] < pivot)
      {
        temp = arr[++i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    temp = arr[++i];
    arr[i] = pivot;
    arr[right] = temp;

    // recursion
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
  }
}

//堆排序
void heapify(std::vector<int> &arr,int n,int i)
{
  int largest = i;
  int left = 2*i+1;
  int right = 2*i+2;

  if(left < n and arr[left] > arr[largest])
    largest = left;
  if(right < n and arr[right] > arr[largest])
    largest = right;
  if(largest != i)
  {
    std::swap(arr[i],arr[largest]);
    heapify(arr,n,largest);
  }
}
void heapSort(std::vector<int> &arr)
{
  int n =arr.size();
  for(int i=n-1;i>=0;i--)
    heapify(arr,n,i);
  for(int i=n-1;i>=0;i--)
  {
    std::swap(arr[0],arr[i]);
    heapify(arr,i,0);
  }
  
}

/******************************************************************************************/
//随机生成大小为100的数组
std::vector<int> geneVector()
{
  srand(time(NULL));
  int n = (Rand_LE100);
  std::vector<int> arr(n);
  for (int i = 0; i < n; i++)
    arr[i] = Rand_LE100;
  return arr;
}
//随机生成大小为n的数组
std::vector<int> geneVector(int n)
{
  assert(n > 0);
  srand(time(NULL));
  std::vector<int> arr(n);
  for (int i = 0; i < n; i++)
    arr[i] = rand();
  return arr;
}
//打印数组
void print(std::vector<int> &arr)
{
  int n = arr.size();
  std::cout << "[";
  for (int i = 0; i < n; i++)
  {
    if (i == n - 1)
      std::cout << arr[i] << "]"
                << " size = " << n << std::endl;
    else
      std::cout << arr[i] << " ";
  }
}