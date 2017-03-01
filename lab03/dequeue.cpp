#include "book.h"
#include "ldeque.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

	string message="()((";
     int holder=message.length();
	bool balance;
	int placeHolder=-10;
	LDeque<int> placeStack;	

