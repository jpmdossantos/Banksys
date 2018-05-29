#include <iostream>
#include <string>
#include <vector>
#include "banksys.h"
using namespace std;

//void interface::menu(){
//
//}
void Interface::novocliente(){

  string name,id,add,pho;
  cout<<endl<<"Digite o nome do cliente "<<endl;
  getline(cin,name);
  cout<<"Digite o cpf ou cnpj do cliente"<<endl;
  getline(cin,id);
  cout<<"Digite o endereço do cliente"<<endl;
  getline(cin,add);
  cout<<"Digite o telefone do cliente"<<endl;
  getline(cin,pho);
  Cliente novo(name,id,add,pho);
  this->inserirCliente (novo);
  this->criarConta (novo);
}

//void Interface::excluircliente(){

//}

//void Interface::excluirconta(){

//}

//void Interface::deposito(){

//}

//void Interface::saque(){

//}

//void Interface::transferencia(){

//}
//void Interface::tarifa(){

//}
//void Interface::cpmf(){

//}
//void Interface::saldo(){

//}

//void Interface::extrato(){

//}

//void Interface::listaclientes(){

//}

//void Interface::listacontas(){

//}

// void Interface::main(){

//}
