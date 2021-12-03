#ifndef SORT_H
#define SORT_H

#include <vector>

#define Rand_LE100 rand()%100+1

void bubbleSort(std::vector<int> &v);
void quickSort(std::vector<int> &v, int left, int right);


void print(std::vector<int> &v);
std::vector<int> geneVector();
std::vector<int> geneVector(int n);















#endif