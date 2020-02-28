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

#include <cmath>
#include "CPSOParameter.h"
#include "../IACS.h"
namespace PSOZJUT{

CPSOParameter::CPSOParameter(const std::string& _filename)
:filename(_filename)
{
    this->input();
    current_Generation=0;
}
CPSOParameter::CPSOParameter(size_t _partnum, size_t _gennum,double _IW, double _AC1, double _AC2)
:particle_num(_partnum),generation(_gennum),inertanceWeight(_IW),AC1(_AC1),AC2(_AC2)
{
    current_Generation=0;
    this->positionRange=VarRangeStruct(-10,10);
    this->velocityRange=VarRangeStruct(0.0,0.05);
}
CPSOParameter::~CPSOParameter()
{
    //dtor
}
double CPSOParameter::C1()const
{
    return this->AC1;
}
double CPSOParameter::C2()const
{
    return this->AC2;
}
double CPSOParameter::IW()const  //inertanceWeight
{
    return this->inertanceWeight;
}
double CPSOParameter::CF()const
{
    return 1;
}
size_t CPSOParameter::particleNum()const
{
    return this->particle_num;
}
size_t CPSOParameter::generationNum()const
{
    return this->generation;
}
void CPSOParameter::addGeneration()
{
    this->current_Generation++;
}
size_t CPSOParameter::currentGeneration()const
{
    return this->current_Generation;
}
void CPSOParameter::setPositionRng(double mimV,double maxV)
{
    this->positionRange.min=mimV;
    this->positionRange.max=maxV;
}
void CPSOParameter::setVelocityRng(double minV,double maxV)
{
    this->velocityRange.min=minV;
    this->velocityRange.max=maxV;
}
VarRangeStruct CPSOParameter::positionRng()const
{
    return this->positionRange;
}
VarRangeStruct CPSOParameter::velocityRng()const
{
    return this->velocityRange;
}
bool CPSOParameter::IsStop()const
{
    return this->generation >= this->current_Generation;
}
void CPSOParameter::defaultint()
{
    m_mapCmdString = new (std::multimap <std::string, std::string>);

    m_mapCmdString->insert(std::pair<std::string,std::string>("[PSO_Generation_Number]",    "200"));
    m_mapCmdString->insert(std::pair<std::string,std::string>("[PSO_Particle_Size]",      "20"));
    m_mapCmdString->insert(std::pair<std::string,std::string>("[PSO_C1]",    "2.0"));
    m_mapCmdString->insert(std::pair<std::string,std::string>("[PSO_C2]",    "2.0"));
    m_mapCmdString->insert(std::pair<std::string,std::string>("[PSO_IW]",    "0.5"));

}
void CPSOParameter::input()
{
/*    input.txt format


*/
}

}
