#include "book.h"
#include "astack.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

	string message="()((";
     int holder=message.length();
	AStack<char> myStack;
	bool balance;
	int i = 0;
	AStack<int> placeStack;
	myStack.push('E');	
	int placeHolder=0;	

	while(i<holder){
		char c = message[i];
		char s = myStack.topValue();
		if((c == '(') && (s = '(')){		          
			myStack.pop();
			i++;			
			//cout << "I pushed a lefty!" << endl;
		}//Don't really know what this does outside of popping if 

		else if((c == ')') && (s = ')')){
			myStack.pop();
			i++;
			//cout << "I pushed a righty!" << endl;
			//cout << myStack.topValue() << "at " << i << endl;
		}//if there are no open lefties then a rightie get's pushed in				
		else if((c == '*') || )){
			myStack.pop();
			placeStack.pop();
			//cout << "I popped!" << endl << myStack.length() << endl;
		}//if there are any open lefties and current element is a rightie, then time to pop a leftie
		//cout << "current length: " << myStack.length() << endl; 
	}

	if(myStack.length()==0){
		balance=true; 
		cout << "-1 aka True"  << endl;
	}//no problem		
	else{
		if(myStack.topValue()==')'){
			cout << "False" << endl;
  			cout << "Open right parenthesis at position " << placeHolder << endl;
		}//if the problem was a rightie left open
		
		else{
			//placeStack.moveToStart();
			for(int i=0; i<placeStack.length()-1;++i){
				placeStack.pop();
			}
			cout << "False" << endl;
  			cout << "Open left parenthesis at position " << placeStack.topValue() << endl;
			cout << "Original phrase:" << message << endl;		
		}//if the problem was a leftie(s), it pops until the first leftie position is on top
		//I don't really like this, but it seems like the only way to keep track and return the 
		//first rightie unmatched. :/
	}
}
