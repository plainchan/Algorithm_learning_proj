#include "rotate.hpp"
#include <unistd.h>
// #include <Eigen/Dense>

using namespace std;

int main()
{
    RoateArray *r;

    vector<vector<int>> a;

    a = geneNArray(4);
    r->print(a);
    r->rotateN(a);
    r->print(a);

    return 0;
}