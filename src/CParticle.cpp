/******************************************************************************
**
** Copyright (C) 2019-2031 Dr.Gui-lin Zhuang <glzhuang@zjut.edu.cn>
** All rights reserved.
**
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
******************************************************************************/
#include<vector>
#include "CParticle.h"
#include "CPSOParameter.h"
#include "../Util/CRandomgenerator.h"
#include "../Util/log.hpp"
#include "../IACS.h"
using namespace util;
namespace PSOZJUT{

CParticle::CParticle(CPSOParameter*mbf)
:mParameter(mbf)
{
    assert(mbf);
}
CParticle::CParticle(const CParticle& mpa)
{
    this->m_fitness=mpa.m_fitness;
    this->m_origValue=mpa.m_origValue;
    this->m_rawscore=mpa.m_rawscore;
    this->m_rfitness=mpa.m_rfitness;
    this->position.assign(mpa.position.begin(),mpa.position.end());
    this->velocity.assign(mpa.velocity.begin(),mpa.velocity.end());

    this->mParameter=mpa.mParameter;
}
CParticle::~CParticle()
{
    //dtor
}
double CParticle::origValue()const
{
    return this->m_origValue;
}
void CParticle::setOrigValue(const double& bf)
{
    this->m_origValue=bf;
}
double CParticle::rawscore()const
{
    return this->m_rawscore;
}
void CParticle::setRawscore(const double& mf)
{
    this->m_rawscore=mf;
}
CParticle& CParticle::operator=(const CParticle&  mpa)
{
    if(this == &mpa)
        return *this;
    this->m_fitness=mpa.m_fitness;
    this->m_origValue=mpa.m_origValue;
    this->m_rawscore=mpa.m_rawscore;
    this->m_rfitness=mpa.m_rfitness;
    this->position.assign(mpa.position.begin(),mpa.position.end());
    this->velocity.assign(mpa.velocity.begin(),mpa.velocity.end());
    this->mParameter=mpa.mParameter;
    return *this;
}
double CParticle::operator[](std::string index_name)
{
    if(index_name=="rawscore")
	   return this->m_rawscore;
	else if(index_name=="fitness")
	   return this->m_fitness;
	else if(index_name=="origvalue")
	   return this->m_origValue;
	else{
	   Log::Error<<" indexname of [] can not match! CParticle::operator[]!\n";
	   boost::throw_exception(std::runtime_error("indexname of [] can not match! CParticle::operator[]!\n"));
	}
}
void CParticle::init()
{
    CRandomgenerator *rnd=new CRandomgenerator();
    for(size_t i=0;i < mParameter->particleNum();i++){
        position.push_back( mParameter->positionRng().min + \
                                 rnd->uniformRandom01(2*i)*(mParameter->positionRng().max-mParameter->positionRng().min) );
        velocity.push_back( mParameter->velocityRng().min + \
                                 rnd->uniformRandom01(111*i)*(mParameter->velocityRng().max-mParameter->velocityRng().min) );
    }
}

}
