#include <iostream>
#include <string>
#include "banksys.h"
using namespace std;

int main()
{
Cliente mateus;
mateus.putdata();
mateus.get();
mateus.putdata();
Cliente jaco("jaco", "08654","Rua da sacanagem","+5531065156321");
jaco.putdata();

}
