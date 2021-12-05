#ifndef SORT_H
#define SORT_H

#include <vector>

#define Rand_LE100 rand()%100+1

void bubbleSort(std::vector<int> &arr);
void selectionSort(std::vector<int> &arr);
void insertionSort(std::vector<int> &arr);
void quickSort(std::vector<int> &arr, int left, int right);
void heapSort(std::vector<int> &arr);



void print(std::vector<int> &arr);
std::vector<int> geneVector();
std::vector<int> geneVector(int n);















#endif