#include <iostream>
#include <cmath>
#include "CPSOEngine.h"
using namespace std;
using namespace PSOZJUT;
double test_Function(const std::vector<double>& _data)
{
     double x1=_data[0];
     double x2=_data[1];
     return 0.5 + (sin(x1*x1-x2*x2)*sin(x1*x1-x2*x2) - 0.5)/((1+0.001*(x1*x1+x2*x2))*(1+0.001*(x1*x1+x2*x2)));
}
int main()
{
    CPSOEngine* pso=new CPSOEngine(&test_Function);
    cout << "Hello world!" << endl;
  //  pso->init();
    pso->evolve();
    cout << "Hello world!" << endl;
    delete pso;
    return 0;
}
