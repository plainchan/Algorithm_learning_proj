#ifndef SORT_H
#define SORT_H

#include <vector>

#define Rand_LE100 rand()%100+1

//choice of algorithm
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

//sort
void bubbleSort(std::vector<int> &arr);
void selectionSort(std::vector<int> &arr);
void insertionSort(std::vector<int> &arr);
void shellSort(std::vector<int> &arr);
void quickSort(std::vector<int> &arr, int left, int right);
void heapSort(std::vector<int> &arr);
void mergeSort(std::vector<int> &arr,int left,int right);



//generate random array
void print(std::vector<int> &arr);
std::vector<int> geneVector();
std::vector<int> geneVector(int n);
std::vector<int> geneVector(int n,int min,int max);
std::vector<int> geneVector(int min,int max);




#endif