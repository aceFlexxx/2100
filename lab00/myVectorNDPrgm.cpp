#include <iostream>
#include "VectorND.h"

using namespace std;

int main(){
	
	int size=1;//initializes for at least d1 for user
	float val=0.0;//initializes value to zero.	
	char resp;


	cout << "What dimension size would you like for" 
	<< " your vector:";
	cin >> size;
	VectorND myVector(size);
		
	for (int i=0;i<size;++i){		
		cout <<"Coordinate-" << i+1 << ':';
		cin >> val;
		myVector.setCoordinate(i,val);
		}
	
	cout << "Your vector normalized with absolute value:"<<
	endl; 
	myVector.normalize();
	myVector.absoluteValue();

	for (int i=0;i<size;++i){	
		cout <<"Coordinate-" << i+1 << ':' <<
		myVector.getCoordinate(i) << endl ;
		}
	
	
	cout << "Would you like to make a new vector?(y,n):";
	cin >> resp;
	if (resp=='y'){
	
		cout << "What dimension size would you like for" 
		<< " your vector:";
		cin >> size;
		VectorND myVector1(size);
	
		for (int i=0;i<size;++i){		
			cout <<"Coordinate-" << i+1 << ':';
			cin >> val;
			myVector1.setCoordinate(i,val);
		}	
	//	VectorND newVector(myVector1);	
		VectorND sumVector(myVector1+myVector);	
		cout << "Your summed vectors resultant:\n ";
	
		for (int i=0;i<size;++i){	
			cout <<"Coordinate-" << i+1 << ':' <<
			sumVector.getCoordinate(i) << endl ;
		}
		
		
		cout << "Your scaler resultant of the dotting of" 
		<< "your vectors: " << myVector1*myVector << endl;
		cout << "The length of your two vectors, respectively:" 
		<< myVector1.length() << " and  " << myVector.length() <<
		endl; 
	}
}
