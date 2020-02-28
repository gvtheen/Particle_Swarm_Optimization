#ifndef CPSOENGINE_H
#define CPSOENGINE_H
#include "../IACS.h"
#include "PSOdeclaration.h"
#include "CPSOFitnessScaling.h"
namespace PSOZJUT{

class CParticleBool;
class CEvaluator;
class CPSOFitnessScaling;
class CPSOEngine
{
    public:
        CPSOEngine(EVALUATOR_FUN mf, std::string _filename="");
        virtual ~CPSOEngine();

        void evolve();

    protected:

    private:
        CParticleBool   *m_ParticleBool;
        CPSOParameter   *m_Parameter;
        EVALUATOR_FUN    m_evaluator_fun;
        COMPARE_FIT      m_compare_fun;
        CEvaluator      *m_evaluator;
        CPSOFitnessScaling*  m_FitnessScaling;


};


}
#endif // CPSOENGINE_H
