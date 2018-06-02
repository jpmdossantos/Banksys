#include <iostream>
#include <string>
#include "banksys.h"
using namespace std;

int main()
{
  Data lixo;
  Data chorume;


  Cliente mateus;
  mateus.putdata();
  mateus.setnomeCliente("jorge");
  mateus.putdata();
  Cliente jaco("hatsune miko", "08654","Rua do Flavio","+5531065156321");
  //jaco.setnomeCliente(mateus.getnomeCliente());
  jaco.putdata();

  cout << endl << lixo.get_data_unix() << endl;
  cout << endl << chorume.get_data_unix() << endl;
  cout << endl << lixo.get_data_formatado() << endl;
  cout << endl << chorume.get_data_formatado() << endl;


}
