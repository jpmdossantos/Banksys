#include <iostream>
#include <string>
#include <cstring>
#include "banksys.h"
using namespace std;


int main()
{
//  Data lixo;
//  Data chorume;
//  Cliente mateus;
//  Conta x(mateus);
//  mateus.putdata();
//  mateus.setnomeCliente("jorge");
//  mateus.putdata();
//  Cliente jaco("hatsune miko", "08654","Rua do Flavio","+5531065156321");
  //jaco.setnomeCliente(mateus.getnomeCliente());
//  jaco.putdata();
vector<Cliente> clientes;
vector<Conta> contas;
Interface Itau("Itau",clientes,contas);
Itau.main();



}
