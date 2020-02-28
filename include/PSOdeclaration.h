#ifndef PSODECLARATION_H
#define PSODECLARATION_H
#include <vector>

typedef double (*EVALUATOR_FUN)(const std::vector<double>&);

typedef bool   (*COMPARE_FIT)(const double& test,const double& refs);

bool minFunction(const double& test,const double& refs);
bool maxFunction(const double& test,const double& refs);

#endif // PSODECLARATION_H
