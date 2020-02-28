#ifndef CPSOFITNESSSCALING_H
#define CPSOFITNESSSCALING_H

namespace PSOZJUT{

class CPSOParameter;
class CParticleBool;
class CPSOFitnessScaling
{
    public:
        CPSOFitnessScaling();
        virtual ~CPSOFitnessScaling();

        void run(CParticleBool*);
    private:
        double scaling(const double&);
    private:
};


}
#endif // CPSOFITNESSSCALING_H
