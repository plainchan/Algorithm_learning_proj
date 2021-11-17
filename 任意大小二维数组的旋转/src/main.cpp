#include "rotate.hpp"
#include <unistd.h>
// #include <Eigen/Dense>

using namespace std;

int main()
{
    RoateArray *r = new RoateArray;

    vector<vector<int>> a;

    a = geneArray();
    r->print(a);
    r->rotate(a,false);
    r->print(a);

    return 0;
}