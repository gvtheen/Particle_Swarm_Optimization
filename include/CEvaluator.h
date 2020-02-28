#ifndef CEVALUATOR_H
#define CEVALUATOR_H
#include "PSOdeclaration.h"
namespace PSOZJUT{

class CParticleBool;

class CEvaluator
{
    public:
        CEvaluator(EVALUATOR_FUN);
        virtual ~CEvaluator();

        void run(CParticleBool*);

    protected:

    private:
        EVALUATOR_FUN m_evaluator;
};


}
#endif // CEVALUATOR_H
