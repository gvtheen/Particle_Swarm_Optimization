#ifndef CPSOPARAMETER_H
#define CPSOPARAMETER_H
#include <iostream>
#include <string>
#include <map>
#include "../IACS.h"

using namespace IACSZJUT;

namespace PSOZJUT{

class CPSOParameter
{
    public:
        CPSOParameter(const std::string& );
        CPSOParameter(size_t _partnum=20,
                      size_t _gennum=50,
                      double _IW=0.5,
                      double _AC1=2.0,
                      double _AC2=2.0);
        virtual ~CPSOParameter();

        bool IsStop()const;

        double C1()const;
        double C2()const;  //Accelerationconstant
        double IW()const;  //inertanceWeight
        size_t particleNum()const;
        size_t generationNum()const;
        double CF()const;
        void addGeneration();
        size_t currentGeneration()const;

        void input();
        void defaultint();

        void setPositionRng(double,double);
        void setVelocityRng(double,double);
        VarRangeStruct positionRng()const;
        VarRangeStruct velocityRng()const;
    private:
        size_t particle_num;
        size_t generation;
        size_t current_Generation;
        double inertanceWeight;
        double AC1, AC2; //Accelerationconstant
        double ConstFactors; //constriction factor
        std::string filename;

        VarRangeStruct positionRange;
        VarRangeStruct velocityRange;
    private:
        std::multimap<std::string, std::string>      *m_mapCmdString;
};


}
#endif // CPSOPARAMETER_H
