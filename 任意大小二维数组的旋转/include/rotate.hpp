#ifndef ROTATE_HPP
#define ROTATE_HPP

#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>

#define Rand_LE9 rand() % 10;
#define Rand_GE2_LE9 rand() % 8 + 2

//给定尺寸k,随机生成 k x k数组
std::vector<std::vector<int>> geneNArray(int n)
{
    assert(n > 1);
    std::vector<std::vector<int>> m(n);
    for (int i = 0; i < n; i++)
        m[i].resize(n);

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            m[i][j] = Rand_LE9;
        }
    }
    return m;
}
// 随机生成 n x n数组, 2 =< n <= 10
std::vector<std::vector<int>> geneNArray()
{
    srand(time(NULL));

    int n = Rand_GE2_LE9;
    std::vector<std::vector<int>> m(n);
    for (int i = 0; i < n; i++)
        m[i].resize(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            m[i][j] = Rand_LE9;
        }
    }
    return m;
}

//给定尺寸m,n,随机生成 m x n数组
std::vector<std::vector<int>> geneArray(int m, int n)
{
    assert(m > 1);
    assert(n > 1);
    std::vector<std::vector<int>> M(m);
    for (int i = 0; i < m; i++)
        M[i].resize(n);

    srand(time(NULL));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            M[i][j] = Rand_LE9;
        }
    }
    return M;
}
//随机生成 m x n数组
std::vector<std::vector<int>> geneArray()
{
    srand(time(NULL));
    int m = Rand_GE2_LE9;
    int n = Rand_GE2_LE9;
    std::vector<std::vector<int>> M(m);
    for (int i = 0; i < m; i++)
        M[i].resize(n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            M[i][j] = Rand_LE9;
        }
    }
    return M;
}

//旋转数组类
class RoateArray
{
public:
    void rotateN(std::vector<std::vector<int>> &m, bool CW = true); //旋转n x n 二维数组
    void rotate(std::vector<std::vector<int>> &M, bool CW = true);  //旋转m x n 二维数组
    void print(std::vector<std::vector<int>> &m);
};

//旋转n x n数组
void RoateArray::rotateN(std::vector<std::vector<int>> &m, bool CW)
{
    int len = m.size();
    assert(len > 1);
    int last_step_value = m[0][0];
    for (int layer = 0; layer < len / 2; layer++)
    {
        for (int start = layer; start < len - layer - 1; start++)
        {
            int i = layer, j = start;
            for (int loop = 0; loop < 5; loop++)
            {
                if (CW)
                {
                    // 顺时针
                    int temp = m[j][len - i - 1];
                    m[j][len - i - 1] = last_step_value;
                    last_step_value = temp;
                    temp = i;
                    i = j;
                    j = len - temp - 1;
                }
                else
                {
                    // 逆时针
                    int temp = m[len - j - 1][i];
                    m[len - j - 1][i] = last_step_value;
                    last_step_value = temp;
                    temp = j;
                    i = len - temp - 1;
                    j = i;
                }
            }
        }
    }
}
//旋转m x n 二维数组
void RoateArray::rotate(std::vector<std::vector<int>> &M, bool CW)
{
    int m = M.size();
    assert(m > 1);
    int n = M[0].size();
    assert(n > 1);
    if (m == n)
    {
        rotateN(M, CW);
    }
    else
    {
        std::vector<std::vector<int>> new_M(n);
        for (int i = 0; i < n; i++)
            new_M[i].resize(m);
        if (CW)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    new_M[j][m - i - 1] = M[i][j];
                }
            }
        }
        else
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    new_M[n-j-1][i] = M[i][j];
                }
            }
        }
        M.resize(n);
        for (int i = 0; i < n; i++)
            M[i].resize(m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                M[i][j] = new_M[i][j];
        }
    }
}
//打印任意大小二维数组
void RoateArray::print(std::vector<std::vector<int>> &m)
{
    int m_len = m.size();
    assert(m_len > 1);
    int n_len = m[0].size();
    assert(n_len > 1);
    std::cout << "[";
    for (int i = 0; i < m_len; i++)
    {
        if (i == 0)
            std::cout << "[";
        else
            std::cout << " [";
        for (int j = 0; j < n_len; j++)
        {
            if (j == n_len - 1)
                std::cout << m[i][j];
            else
                std::cout << m[i][j] << " ";
        }
        if (i == m_len - 1)
            std::cout << "]";
        else
            std::cout << "]" << std::endl;
    }
    std::cout << "] " << m_len << " x " << n_len << std::endl;
}

#endif