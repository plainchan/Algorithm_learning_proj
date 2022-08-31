#ifndef TSORT_HPP
#define TSORT_HPP

#include <vector>
#include <ctime>
#include <cassert>
#include <typeinfo>

#define Rand_LE100 rand()%101

enum sort_type
{
  bubble,
  selection,
  insertion,
  shell,
  quick,
  merging,
  heap
};



//冒泡排序
template<typename T>
void bubbleSort(std::vector<T> &arr)
{
  size_t n = arr.size();
  if (n < 2)
    return;
  for (size_t i = 0; i < n - 1; i++)
  {
    for (size_t j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
        std::swap(arr[j],arr[j + 1]);
    }
  }
}
//选择排序
template<typename T>
void selectionSort(std::vector<T> &arr)
{
  size_t n = arr.size();
  size_t min_index = 0;
  for (size_t i = 0; i < n; i++)
  {
    min_index = i;
    for (size_t j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min_index])
        min_index = j;
    }
    if (i != min_index)
        std::swap(arr[i],arr[min_index]);  
  }
}

//插入排序
template<typename T>
void insertionSort(std::vector<T> &arr)
{
  size_t n = arr.size();
  for (size_t i = 1; i < n; i++)
  {
    size_t temp = arr[i];
    size_t j = i - 1;
    while (j >= 0 and temp < arr[j])
    {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = temp;
  }
}

template<typename T>
void shellSort(std::vector<T> &arr)
{
  size_t len =arr.size();

#ifndef other
  for(size_t gap=len/2;gap>0;gap/=2)
  {
    for(size_t i=gap;i <len;i++)
      for(size_t j=i-gap;j>=0;j-=gap)
      {
        if(arr[j]<arr[j+gap])
          break;
        else
        {
          std::swap(arr[j],arr[j+gap]);
        }
      }
  }
#else

#endif

#undef other
}
//快速排序
template<typename T>
void quickSort(std::vector<T> &arr, int left, int right)
{
  // assert(left >= 0);
  // assert(right < int(arr.size()));
  if (left < right)
  {
    size_t pivot = arr[right];
    size_t i = left - 1;
    size_t temp = 0;

    // partition
    for (size_t j = left; j < right; j++)
    {
      if (arr[j] < pivot)
        std::swap(arr[j],arr[++i]);
    }
    std::swap(arr[right],arr[++i]);

    // recursion
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
  }
}
// 归并排序
template<typename T>
void merge(std::vector<T> &arr,int l,int m,int r)
{
  size_t L_SIZE=m-l+1;
  size_t R_SIZE=r-m;

  std::vector<T>L(L_SIZE);
  std::vector<T>R(R_SIZE);

  for(size_t i=0;i<L_SIZE;i++) L[i]=arr[i+l];
  for(size_t j=0;j<R_SIZE;j++) R[j]=arr[j+m+1];

  size_t i=0,j=0,k=l;
  while(i<L_SIZE or j<R_SIZE)
  {
    if(j>=R_SIZE or (i<L_SIZE and L[i]<R[j]))
    {
      arr[k]=L[i];
      ++i;
    }
    else
    {
      arr[k]=R[j];
      ++j;
    }
    ++k;
  }

}
template<typename T>
void mergeSort(std::vector<T> &arr,int left,int right)
{
  if(left < right)
  {
    size_t mid =left+(right-left)/2;
  
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
  }
}

//堆排序
//https://www.cnblogs.com/chengxiao/p/6129630.html
template<typename T>
void heapify(std::vector<T> &arr,int n,int i)
{
  size_t largest = i;
  size_t left = 2*i+1;
  size_t right = 2*i+2;

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
template<typename T>
void heapSort(std::vector<T> &arr)
{
  size_t n =arr.size();
  for(int i=n-1;i>=0;i--)
    heapify(arr,n,i);
  for(size_t i=n-1;i>=0;i--)
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
//随机生成大小为n的数组
std::vector<int> geneVector(int n,int min,int max)
{
  assert(n > 0);
  srand(time(NULL));
  std::vector<int> arr(n);
  for (int i = 0; i < n; i++)
    arr[i] = rand()%(max-min+1)+min;
  return arr;
}
//生成大小为[min,max]的数组,步长为1
std::vector<int> geneVector(int min,int max)
{
  std::vector<int> arr={min};
  int step=1;
  if(min>max)
    step=-1;
  while(min!=max)
  {
    arr.emplace_back(min+=step);
  }
  return arr;
}

//打印数组
template<typename T>
void print(std::vector<T> &arr)
{
  int n = arr.size();
  std::cout << "[";
  for (size_t i = 0; i < n; i++)
  {
    if (i == n - 1)
      std::cout << arr[i] << "]"
                << " size = " << n << std::endl;
    else
      std::cout << arr[i] << " ";
  }
}




















#endif