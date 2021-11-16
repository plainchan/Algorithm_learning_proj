#ifndef ROTATE_HPP
#define ROTATE_HPP

#include <iostream>
#include <vector>
#include <ctime>

#define  rand_le9  rand()%10;


//给定尺寸,随机生成 n x n数组
std::vector<std::vector<int>> geneNArray(int n)
{
    if(n == 1)
        throw "dimension less equal 1";
    std::vector<std::vector<int>> m(n);
    for(int i =0;i<n;i++)
        m[i].resize(n);
    
    srand(time(NULL));
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            m[i][j] = rand_le9;
        }
    }
    return m; 
}
// 随机生成 n x n数组
std::vector<std::vector<int>> geneNArray()
{
    srand(time(NULL));

    int n = rand()%8+2;
    std::vector<std::vector<int>> m(n);
    for(int i =0;i<n;i++)
        m[i].resize(n);
    
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            m[i][j] = rand()%10;
        }
    }
    return m; 
}


//旋转数组类
class RoateArray
{
public:
    void rotateN(std::vector<std::vector<int>> &m); //旋转n x n 二维数组
    void print(std::vector<std::vector<int>> &m);
};

void RoateArray::rotateN(std::vector<std::vector<int>> &m)
{
    int len = m.size();
    int temp;
    for(int i=0;i<len;i++)
    {
        for(int j=i;j<len;j++)
        {
            if(i==j or i == len-1-j)
            {

            }
            else
            {
                // std::cout << "("<< i<<"," << j<<") " ;
                temp = m[i][j];
                m[i][j] = m[j][len-i-1];
                m[j][len-i-1] =temp;
            }
            
        }


    }
    std::cout << std::endl;
}
void RoateArray::print(std::vector<std::vector<int>> &m)
{
    int len = m.size();
    std::cout << "[";
    for (int i = 0; i < len; i++)
    {
        if(i==0)
            std::cout << "[";
        else
            std::cout << " [";
        for (int j = 0; j < len; j++)
        {
            if (j == len - 1)
                std::cout <<m[i][j];
            else
                std::cout << m[i][j] << " ";
        }
        if (i == len - 1)
            std::cout << "]";
        else
            std::cout << "]" << std::endl;
    }
    std::cout << "] " << len << " x " << len << std::endl;
}
#endif