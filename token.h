#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <string>
using namespace std;
 
class token
{

  private:
    string token_type;
    string token_value;
	//token(){ }
    	
    	
  public:
    //token(string token_type, char *token_value);
    void set_values(string , string );
    string get_type();
    string get_value();
	
    
};
 
#endif
