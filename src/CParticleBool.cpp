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
#include<iostream>
#include "CParticleBool.h"
#include "CParticle.h"
#include "CPSOParameter.h"
#include "PSOdeclaration.h"
#include "../Util/log.hpp"
#include "../Util/CRandomgenerator.h"
using namespace util;
namespace PSOZJUT{

CParticleBool::CParticleBool(CPSOParameter* mbf,COMPARE_FIT fn)
:mParameter(mbf),mCompareFun(fn)
{
   assert(mbf);
   assert(fn);
}
void CParticleBool::init()
{
    util::Log::Debug<<"CParticleBool::init()"<<std::endl;
    for(size_t i=0;i<mParameter->particleNum();i++){
        this->particles.push_back(new CParticle(mParameter));
        this->particles[this->particles.size()-1]->init();

        this->currentBestParticle.push_back(new CParticle(*(particles[particles.size()-1])));
    }

    this->mostBestParticle=new CParticle(*(particles[0]));
}
void CParticleBool::update()
{
    //this->output();

    //util::Log::Debug<<"CParticleBool::update():"<<mParameter->currentGeneration()<<std::endl;

    for(size_t i=0;i<particles.size();i++)
      if(mParameter->currentGeneration()==0){
        *(currentBestParticle[i]) = *(particles[i]);
       // std::cout<<"he:"<<currentBestParticle.size()<<std::endl;
      }else{
        if((*mCompareFun)(particles[i]->rawscore(),currentBestParticle[i]->rawscore()))
           *(currentBestParticle[i]) = *(particles[i]);
      }

    double refs=currentBestParticle[0]->rawscore();
    //util::Log::Debug<<"CParticleBool::update()2:   "<<refs<<" "<<particles.size()<<std::endl;
    size_t index=0;
    for(size_t i=0;i<particles.size();i++){
      //util::Log::Debug<<i<<" "<<currentBestParticle[i]->rawscore()<<std::endl;
      if((*mCompareFun)(currentBestParticle[i]->rawscore(),refs)){
        refs=currentBestParticle[i]->rawscore();
        index=i;
      }
    }
    //util::Log::Debug<<"CParticleBool::update()3"<<std::endl;
    if(mParameter->currentGeneration()==0)
       *mostBestParticle=*(currentBestParticle[index]);
    else{
      if((*mCompareFun)(currentBestParticle[index]->rawscore(),mostBestParticle->rawscore()))
         *mostBestParticle = *(currentBestParticle[index]);
    }
   // util::Log::Debug<<"CParticleBool::update()4"<<std::endl;
    double vel,pos;
    double c1,c2,w;
    w =mParameter->IW();
    c1=mParameter->C1();
    c2=mParameter->C2();
    CRandomgenerator *rnd=new CRandomgenerator();
    for(size_t i=0;i<particles.size();i++){
        for(size_t j=0;j<particles[i]->position.size();j++){
            //update position;
            pos= particles[i]->position[j] + particles[i]->velocity[j];
            if (pos < mParameter->positionRng().min)
                pos = mParameter->positionRng().min;
            else if (pos > mParameter->positionRng().max)
                pos = mParameter->positionRng().max;

            //update velocity
            vel=particles[i]->velocity[j]*w + c1*rnd->uniformRandom01(i*j)*(currentBestParticle[i]->position[j] - particles[i]->position[j])  \
                                            + c2*rnd->uniformRandom01(i*j+1)*(mostBestParticle->position[j] - particles[i]->position[j]);
            if(vel < mParameter->velocityRng().min)
                vel=mParameter->velocityRng().min;
            else if (vel > mParameter->velocityRng().max)
                vel=mParameter->velocityRng().max;

            particles[i]->position[j] = pos;
            particles[i]->velocity[j] = vel;
        }
    }
    delete rnd;
}
void CParticleBool::output()
{
   util::Log::Info<<"Generation: "<<mParameter->currentGeneration()<<std::endl;

   for(size_t i=0;i<particles.size();i++){
       util::Log::Info<<"particle: "<<i<<": "<<particles[i]->rawscore()<<std::endl;
       util::Log::Info<<"  position:" ;
       for(size_t j=0;j<particles[i]->position.size();j++)
          util::Log::Info<<particles[i]->position[j]<<" ";
       util::Log::Info<<std::endl;

       util::Log::Info<<"  velocity:";
       for(size_t j=0;j<particles[i]->velocity.size();j++)
          util::Log::Info<<particles[i]->velocity[j]<<" ";
       util::Log::Info<<std::endl;
   }
   util::Log::Info<<"****Generation: "<<mParameter->currentGeneration()<<"****"<<std::endl;

   util::Log::Info<<"Until now,Best particle: "<<""<<mostBestParticle->rawscore()<<std::endl;
   util::Log::Info<<"  position:";
   for(size_t j=0;j<mostBestParticle->position.size();j++)
      util::Log::Info<<mostBestParticle->position[j]<<" ";
   util::Log::Info<<std::endl;

   util::Log::Info<<"  velocity:";
   for(size_t j=0;j<mostBestParticle->velocity.size();j++)
       util::Log::Info<<mostBestParticle->velocity[j]<<" ";
   util::Log::Info<<std::endl;
   util::Log::Info<<std::endl;
}
void CParticleBool::lastOutput()
{
   util::Log::Info<<"Best particle: "<<mostBestParticle->rawscore()<<std::endl;
   util::Log::Info<<"  position:";
   for(size_t j=0;j<mostBestParticle->position.size();j++)
      util::Log::Info<<mostBestParticle->position[j]<<" ";
   util::Log::Info<<std::endl;

   util::Log::Info<<"  velocity:";
   for(size_t j=0;j<mostBestParticle->velocity.size();j++)
       util::Log::Info<<mostBestParticle->velocity[j]<<" ";
   util::Log::Info<<std::endl;
   util::Log::Info<<std::endl;
}
CParticleBool::~CParticleBool()
{
   for(size_t i=0;i<particles.size();i++){
      delete particles[i];
      delete currentBestParticle[i];
   }
   particles.clear();
   currentBestParticle.clear();
}


}
