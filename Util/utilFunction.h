#ifndef UTILFUNCTION_H
#define UTILFUNCTION_H

#include <cstddef>
#include <string>
#include "Point-Vector.h"
//#include "../CataZJUT/Geometry.h"
#include "GaDeclaration.h"
#include "Bitset.h"
#include "../IACS.h"

using IACSZJUT::VarRangeStruct;

namespace util{
//
Vector4 SphereEquationFromPoints(const std::vector<Point3>& coordinate);
double binaryDecode(const Bitset & myCode,VarRangeStruct myGenVar);
int calcBitNum(VarRangeStruct myVarRangeStruct);
void grayTobit(Bitset& data);
void bitTogray(Bitset& data);
bool strcasecmp(const std::string& s1, const std::string& s2);




}



#endif
