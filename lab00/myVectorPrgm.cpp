#include <iostream>
#include "Vector3D.h"
using namespace std;

	int main(){
	char vecArray[3]={'x','y','z'};
	float tempCoord;
	Vector3D myVector;//create Vector3D instance 

	for (int i=0;i<3;i++ ){ 
		cout << "Enter in coordinate " << vecArray[i] << ":";
		float value=0; //initializes value for user to input
		cin >> value;
		cout <<endl; 
		myVector.setCoordinate(i,value);
		//runs through this loop to have user enter vector vals	
	}
	/*
	for (int i=0;i<3;i++){
		if(myVector.getCoordinate(i)<0){
			myVector.setCoordinate(i,
			myVector.getCoordinate(i)*-1);	
		}//if statement checks for neg coords
	}
	*/
	myVector.absoluteValue();
	for (int i=0;i<3;i++ ){	
		cout  << vecArray[i] << "-coordinate:" <<
		myVector.getCoordinate(i) << endl;		
	}
  myVector.normalize();
	cout << "Normalized Vector:" << endl;
	for (int i=0;i<3;i++ ){	
		cout  << vecArray[i] << "-coordinate:" <<
		myVector.getCoordinate(i) << endl;		
	}
	
}
