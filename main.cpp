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
#include <iostream>
#include <cmath>
#include "CPSOEngine.h"
using namespace std;
using namespace PSOZJUT;
double test_Function(const std::vector<double>& _data)
{
     double x1=_data[0];
     double x2=_data[1];
     return 0.5 + (sin(x1*x1-x2*x2)*sin(x1*x1-x2*x2) - 0.5)/((1+0.001*(x1*x1+x2*x2))*(1+0.001*(x1*x1+x2*x2)));
}
int main()
{
    CPSOEngine* pso=new CPSOEngine(&test_Function);
    cout << "Hello world!" << endl;
  //  pso->init();
    pso->evolve();
    cout << "Hello world!" << endl;
    delete pso;
    return 0;
}
