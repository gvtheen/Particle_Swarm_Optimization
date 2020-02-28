#ifndef CPARTICLE_H
#define CPARTICLE_H
#include <vector>
#include <string>
namespace PSOZJUT{

class CPSOParameter;
class CParticle
{
    public:
        CParticle(CPSOParameter*);
        CParticle(const CParticle&);
        virtual ~CParticle();

        void init();
        double origValue()const;
        void setOrigValue(const double&);
        double rawscore()const;
        void setRawscore(const double&);

        CParticle& operator=(const CParticle&);

        double operator[](std::string);

    public:

        std::vector<double>  velocity;
        std::vector<double>  position;
        double  m_rfitness;       // relative fitness ratio
        double  m_origValue;      // it is obtained from energy of DFT
                // Importantly, only this value can be compared with those from parents, grandparents
        double  m_rawscore;       // it is obtained from conversion of m_origValue by using some formula.  Usually
		                                         // this conversion formula differed among the generations.
        double  m_fitness;        // m_fitness= the value after scalling treatment of m_rawscore

        CPSOParameter* mParameter;
};


}
#endif // CPARTICLE_H
