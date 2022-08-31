#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

/**
 * @brief 生成数据
 */
std::vector<int> geneVector(int n)
{
  srand(time(NULL));
  std::vector<int> arr(n);
  for (int i = 0; i < n; i++)
    arr[i] = rand();
  return arr;
}

//随机生成大小为n的数组
std::vector<int> geneVector(int n,int min,int max)
{
  srand(time(NULL));
  std::vector<int> arr(n);
  for (int i = 0; i < n; i++)
    arr[i] = rand()%(max-min+1)+min;
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


/**
 * @brief 冒泡排序
 */
void bubblesort(vector<int> &arr)
{
    int n = arr.size();
    for(int i=0;i<n;++i)
    {
        for(int j=1;j<n-i;++j)
        {
            if(arr[j]<arr[j-1])
                swap(arr[j],arr[j-1]);
        }
    }
}
/**
 * @brief 选择排序
 */
void selectsort(vector<int> &arr)
{
    int n = arr.size();
    for(int i=0;i<n;++i)
    {
        int minIndex=i;
        for(int j=i+1;j<n;++j)
        {
            if(arr[minIndex]>arr[j])
            {
                minIndex=j;
            }
        }
        if(minIndex!=i)
        {
            swap(arr[i],arr[minIndex]);
        }
    }
}
/**
 * @brief 插入排序
 */
void insertsort(vector<int> &arr)
{
    //1 2 3 4 5 4
    int n = arr.size();
    for(int i=1;i<n;++i)
    {
        int j=i-1;
        int temp =arr[i];
        while(j>=0&&temp<arr[j])
        {
            arr[j+1]=arr[j];
            --j;
        }
        arr[j+1] = temp;
    }
}
/**
 * @brief 希尔排序
 */
void shellsort(vector<int> &arr)
{

}
/**
 * @brief 归并排序
 */
void merge(vector<int> &arr,int left,int mid,int right)
{
    int left_size = mid-left+1;
    int right_size = right - mid;
    vector<int>LEFT_V(left_size);
    vector<int>RIGHT_V(right_size);

    for(int i=0;i<left_size;++i)
        LEFT_V[i]=arr[i+left];
    for(int j=0;j<right_size;++j)
        RIGHT_V[j]=arr[j+mid+1];

    int i=0,j=0,k=left;
    while(i<left_size || j<right_size)
    {
        if( j>=right_size || (i<left_size&&LEFT_V[i]<RIGHT_V[j]))
        {
            arr[k]=LEFT_V[i];
            ++i;
        }
        else
        {
            arr[k]=RIGHT_V[j];
            ++j;
        }
        ++k;
    }
}
void mergesort(vector<int> &arr,int left,int right)
{
    if(left<right)
    {
        int mid =(right-left)/2+left;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
/**
 * @brief 快速排序
 */
void quicksort(vector<int> &arr,int left,int right)
{
    if(left<right)
    {
        int pivot = arr[right];
        int i=left;
        for(int j=left;j<right;++j)
        {
            if(arr[j]<pivot)
            {
                swap(arr[j],arr[i++]);
            }
        }
        swap(arr[right],arr[i]);
        quicksort(arr,left,i-1);
        quicksort(arr,i+1,right);

    }
}

/**
 * @brief 堆排序
 */
void heapify(vector<int> &arr,int n,int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && arr[largest]<arr[left])
        largest = left;
    if(right<n && arr[largest]<arr[right])
        largest = right;
    if(largest !=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapsort(vector<int> &arr)
{
    int n =arr.size();
    for(int i=n-1;i>=0;--i)
        heapify(arr,n,i);
    for(int i=n-1;i>=0;--i)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}


#define SIZE 20
int main()
{
    vector<int> arr = geneVector(SIZE,1,20);
    vector<int> arr1(arr);

    sort(arr1.begin(), arr1.end());
    mergesort(arr,0,arr.size()-1);

    print(arr);
    print(arr1);
    if (arr1 == arr)
            cout << "same," << SIZE << endl;
    return 0;
}