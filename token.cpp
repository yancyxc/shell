// pointer to classes example
#include "token.h"


 
void token::set_values(string a,string  b) {
  token_type = a;
  token_value = b;
}
string token::get_type () {
  return token_type;
}
string token::get_value () {
  return token_value;
}




