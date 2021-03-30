#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool CheckCircle (string Figure)
{	
    if ((strstr(Figure.c_str(), "Circle "))
      || (strstr (Figure.c_str(), "Circle(")))
      {         
	            cmatch result;
                regex regular (                          
                      "([\\w\\s]+)"	
                      "(\\()"		
                      "(\\s*)"	
					//  "([0-9]+)"	
                      "([0-9]*[.]?[0-9]+)"	
                      "(\\s*)"	
                    //  "([0-9]+)"
					  "([0-9]*[.]?[0-9]+)"
                      "(\\s*)"	
					  "(\\,)"		
                      "(\\s*)"		
					  "([0-9]*[.]?[0-9]+)"	
                      "(\\s*)"
                      "(\\))" 
					   );
                 if (regex_match(Figure.c_str(), result, regular))
                    return true; 
					//cout<<"1";
				else
					return false;
                 	//cout<<"0";
                
      } 
      else
      	return false;
      	//cout<<"00";
      
}


int main ()
{   
    setlocale(LC_ALL,"Russian");
    string Figure;
    getline (cin, Figure);
    if (CheckCircle(Figure))
    	cout<<"5";
	else 
		cout<<"No";
}
