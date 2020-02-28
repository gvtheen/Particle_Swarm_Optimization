#ifndef CPARTICLEBOOL_H
#define CPARTICLEBOOL_H
#include <vector>
#include "PSOdeclaration.h"

namespace PSOZJUT{
class CParticle;
class CPSOParameter;

class CParticleBool
{
    public:
        CParticleBool(CPSOParameter*,COMPARE_FIT);
        virtual ~CParticleBool();

        void init();
        void update();

        void output();

        void lastOutput();

    public:
        std::vector<CParticle*> particles;

        std::vector<CParticle*> currentBestParticle;
        CParticle   *mostBestParticle;
        CPSOParameter* mParameter;
        COMPARE_FIT mCompareFun;   // bool fun( const double test, const double reference )

    private:
};


}
#endif // CPARTICLEBOOL_H
