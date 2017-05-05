#include<iostream>
#include<fstream>
#include<string>
#include"book.h"
#include"grmat.h"
using namespace std;



int main()

{

            string fileName;
            cout << "Enter in .csv file:";
            cin >> fileName;
            ifstream stream1(fileName);

            char a[80];
            int nvert = 0;
	    int nedge = 0;
	    char b[80];
	    
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
			if(!stream1.eof()){		
				for (int i=0; i < string(a).length(); ++i){
					if(a[i] == ','){
						++nedge;
					} 
					else {
						for(int f = 0; f < string(b).length(); ++f){
							if(b[f] != a[i]){
								b[f]=a[i];
								++nvert;
							}
					        }
								
					}
				}
				cout << a << endl;	           
			}
	    }		
	    cout <<"nvert: " << nvert << endl;
	    cout <<"nedge: " << nedge << endl;
	    cout <<"size of a: " << string(a).length() << endl;
            return(0);

	    
}
