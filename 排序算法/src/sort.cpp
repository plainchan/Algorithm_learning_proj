#include <iostream>
#include <ctime>
#include <cassert>
#include "sort.h"
void bubbleSort(std::vector<int> &v)
{
  int n = v.size();
  if(n <2)
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

std::vector<int> geneVector()
{
  srand(time(NULL));
  int n = (Rand_LE100);
  std::vector<int> v(n);
  for (int i = 0; i < n; i++)
    v[i] = Rand_LE100;
  return v;
}
std::vector<int> geneVector(int n)
{
  assert(n > 0);
  srand(time(NULL));
  std::vector<int> v(n);
  for (int i = 0; i < n; i++)
    v[i] = Rand_LE100;
  return v;
}
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