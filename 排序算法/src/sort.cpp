#include <iostream>
#include <ctime>
#include <cassert>
#include "sort.h"

//冒泡排序
void bubbleSort(std::vector<int> &v)
{
  int n = v.size();
  if (n < 2)
    return;
  int temp = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (v[j] > v[j + 1])
      {
        temp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = temp;
      }
    }
  }
}
//插入排序
void insertionSort(std::vector<int> &v)
{
}
//选择排序
void selectionSort(std::vector<int> &v)
{
}
//快速排序
void quickSort(std::vector<int> &v, int left, int right)
{
  assert(left >= 0);
  assert(right < int(v.size()));
  if (left < right)
  {
    int pivot = v[right];
    int i = left - 1;
    int temp = 0;

    // partition
    for (int j = left; j < right; j++)
    {
      if (v[j] < pivot)
      {
        temp = v[++i];
        v[i] = v[j];
        v[j] = temp;
      }
    }
    temp = v[++i];
    v[i] = pivot;
    v[right] = temp;

    // recursion
    quickSort(v, left, i - 1);
    quickSort(v, i + 1, right);
  }
}
//堆排序
void heapSort()
{
}

/******************************************************************************************/
//随机生成100个数组
std::vector<int> geneVector()
{
  srand(time(NULL));
  int n = (Rand_LE100);
  std::vector<int> v(n);
  for (int i = 0; i < n; i++)
    v[i] = Rand_LE100;
  return v;
}
//随机生成n个数组
std::vector<int> geneVector(int n)
{
  assert(n > 0);
  srand(time(NULL));
  std::vector<int> v(n);
  for (int i = 0; i < n; i++)
    v[i] = Rand_LE100;
  return v;
}
//打印数组
void print(std::vector<int> &v)
{
  int n = v.size();
  std::cout << "[";
  for (int i = 0; i < n; i++)
  {
    if (i == n - 1)
      std::cout << v[i] << "]"
                << " size = " << n << std::endl;
    else
      std::cout << v[i] << " ";
  }
}