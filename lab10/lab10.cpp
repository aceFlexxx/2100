#include<iostream>
#include<fstream>
#include<string>
#include"grmat.h"
using namespace std;



int main()

{

            string fileName;
            cout << "Enter in .csv file:";
            cin >> fileName;
            ifstream stream1(fileName);

            char a[80];
            int nvert;
	    if(!stream1)

            {

                        cout << "While opening a file an error is encountered" << endl;

            }

            else

            {

                        cout << "File is successfully opened" << endl;

            }

            while(!stream1.eof())
            {
                        stream1 >> a;
			if(!stream1.eof())
			{	
				if(a ==';') ++nvert;
				cout << a << endl;	           
			}      
	    }
	    	    
            return(0);

}
