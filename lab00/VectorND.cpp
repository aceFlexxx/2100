#include "VectorND.h"
#include <cmath>
#include <iostream>
#include <array>
using namespace std;

VectorND::VectorND(int n) {
	alloc = n;
	c = new float [alloc];
  for (int i=0; i < n; i++) {
    c[i] = 0.0;

  }
}

VectorND::~VectorND(){
	delete c;
}

float VectorND::getCoordinate(const int i)const {
  return c[i];
//	cout << "The siZe: "<< c.size();
}

void VectorND::setCoordinate(const int i, const float val){
  c[i] = val;
}

VectorND::VectorND(const VectorND& v) {
	for (int i=0; i < alloc; i++) {
    c[i] = v.c[i];
  }
}

/*

VectorND::VectorND(float x, float y, float z) {
  c[0] = x;
  c[1] = y;
  c[2] = z;
}
*/


float VectorND::magnitude() const {
  float ans = 0.0;
  for (int i=0; i < alloc; i++) {
    ans += c[i]*c[i]; 
  }
  return sqrt(ans);
}

void VectorND::normalize(){
  float m = magnitude();
  if (m != 0.0) {
    for (int i=0; i < alloc; i++) {
      c[i] /= m;
    }
  }
}

bool  VectorND::checkDim(const VectorND& other) const{
	bool logic=0;
	if( alloc==other.alloc){
		 logic=1;
	}
	return logic;
}

VectorND VectorND::operator+(const VectorND& other)const {
	if(checkDim(other)){
		VectorND holder(alloc);
  	for (int i=0; i < alloc; i++) {
			holder.setCoordinate(i,c[i]+other.c[i]);
		}	
		return holder;
	}	
	else{
		VectorND holder(1);
		cout << "Operation can not be performed; the vectors"
		<< " are not of equal size.";
		cout << "The first vector is size:" << alloc <<  endl;
		cout << "The secound vector is size:" << other.alloc <<
		endl;
		return holder;	
	}
}


float VectorND::operator*(const VectorND& other)const {
  float ans = 0.0;
  for (int i=0; i < alloc; i++) {
    ans += c[i]*other.c[i]; 
  }
  return ans;
}
void VectorND::absoluteValue(){
	for(int i=0;i<alloc;++i){
		if(c[i]<0){
			c[i]*=-1;
		}
	}
}
int VectorND::length() const{
	return alloc;
}


