#include "atm.hpp"
#include <iostream>
#include <string.h>

using namespace std;

int main () 
{
    int account, pass;
    banesco atm1(1234,300.23,"francesco",12345,"0414855759", "pregunta","123");

    //login
    atm1.login();
    return 0;
}
