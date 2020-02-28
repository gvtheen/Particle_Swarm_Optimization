#ifndef IACS_H_INCLUDED
#define IACS_H_INCLUDED


#include <stdexcept>
#include <boost/throw_exception.hpp>
#define DEBUG
#include "assert.h"
#include <iostream>

#define SIGN_DIGIT_NUMBER 16
#define SIGN_DIGIT_LENGTH 21

#define PLANE_DIFF_CONVERGENCE 2


namespace IACSZJUT{

struct VarRangeStruct{
	double min;
	double max;
	double accuracy;
	VarRangeStruct(double a,double b,double c=0.01){
	    min=a;
	    max=b;
	    accuracy=c;
	}
	VarRangeStruct(){
	    min=0;
	    max=0;
	    accuracy=0;
	}
};

}

#endif
