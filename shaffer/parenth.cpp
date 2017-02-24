#include "book.h"
#include "astack.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

	string message="()()(())(";
     int holder=message.length();
	AStack<int> myStack;
	bool balance;	
	
	for(int i=0;i<holder;++i){	
		if(message[i]=='('){		          
			myStack.push(message[i]);
		}
		if(message[i]==')'){
			myStack.pop();
		}
		
	}
	if(myStack.length()==0){
		balance=true; 
		cout << "True"  << endl;
	}		
	else{
		cout << "False" << endl;
	}
}

