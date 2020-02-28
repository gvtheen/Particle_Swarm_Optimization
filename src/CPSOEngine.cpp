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
#include "CPSOEngine.h"
#include "CParticleBool.h"
#include "CEvaluator.h"
#include "CPSOFitnessScaling.h"
#include "CPSOParameter.h"
#include "../Util/log.hpp"
namespace PSOZJUT{

CPSOEngine:: CPSOEngine(EVALUATOR_FUN mf,std::string _filename)
:m_evaluator_fun(mf)
{
    if(_filename!=""){
      this->m_Parameter=new CPSOParameter(_filename);
      this->m_Parameter->input();
    }else
      this->m_Parameter=new CPSOParameter();

    m_compare_fun=&minFunction;

    this->m_ParticleBool=new CParticleBool(m_Parameter,m_compare_fun);
    this->m_evaluator=new CEvaluator(mf);
    this->m_FitnessScaling=new CPSOFitnessScaling();
    //initialization
    this->m_ParticleBool->init();

}

CPSOEngine::~CPSOEngine()
{
    delete m_ParticleBool;
    delete m_evaluator;
    delete m_FitnessScaling;
    delete m_Parameter;
}
void CPSOEngine::evolve()
{
  util::Log::Debug<<"CPSOEngine::evolve()"<<std::endl;
   while( m_Parameter->IsStop()){
       this->m_evaluator->run(this->m_ParticleBool);
       this->m_FitnessScaling->run(this->m_ParticleBool);
       this->m_ParticleBool->update();
       this->m_Parameter->addGeneration();
       this->m_ParticleBool->output();
   }
   this->m_ParticleBool->lastOutput();
}


}
