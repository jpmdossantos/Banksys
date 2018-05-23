#include <iostream>
#include <string>
#include "banksys.h"
using namespace std;

int main()
{
Cliente mateus;
mateus.putdata();
mateus.setnomeCliente("jorge");
mateus.putdata();
Cliente jaco("jaco", "08654","Rua da sacanagem","+5531065156321");
jaco.setnomeCliente(mateus.getnomeCliente());
jaco.putdata();

}
