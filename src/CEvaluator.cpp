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
#include "CEvaluator.h"
#include "CParticleBool.h"
#include "CParticle.h"
#include "../Util/log.hpp"
namespace PSOZJUT{

CEvaluator::CEvaluator(EVALUATOR_FUN mbf)
:m_evaluator(mbf)
{
    assert(mbf);
}

CEvaluator::~CEvaluator()
{
    //dtor
}
void CEvaluator::run(CParticleBool* particlebool)
{
    util::Log::Debug<<" CEvaluator::run"<<std::endl;
    for(size_t i=0;i<particlebool->particles.size();i++)
        particlebool->particles[i]->setOrigValue((*m_evaluator)(particlebool->particles[i]->position));

}

}
