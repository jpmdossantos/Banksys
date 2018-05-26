#include <iostream>
#include <string>
#include "banksys.h"
using namespace std;

int main()
{
  time_t now = time(NULL);
  Data chorume(now);
  Data lixo;


  Cliente mateus;
  mateus.putdata();
  mateus.setnomeCliente("jorge");
  mateus.putdata();
  Cliente jaco("hatsune miko", "08654","Rua do Flavio","+5531065156321");
  //jaco.setnomeCliente(mateus.getnomeCliente());
  jaco.putdata();

  cout << endl << lixo.get_data() << endl;
  cout << endl << chorume.get_data() << endl;

}
