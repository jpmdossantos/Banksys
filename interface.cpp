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

void Interface::excluirclientei(){
  string cpf_cnpj;
cout <<endl<< "Insira o CPF ou o CNPJ do cliente a ser excluido"<<endl;
getline(cin,cpf_cnpj);
this->excluirCliente(cpf_cnpj);
}

void Interface::excluircontai(){
  int numConta;
cout <<endl<< "Insira o numero da conta a ser excluida"<<endl;
cin>>numConta;
this->excluirConta(numConta);
}

void Interface::depositoi(){
  int numConta;
  double valor;
cout <<endl<< "Insira o numero da conta a receber o deposito"<<endl;
cin>>numConta;
cout << "Insira o valor a ser depositado"<<endl;
cin>>valor;
this->deposito(numConta, valor);
}

void Interface::saquei(){
  int numConta;
  double valor;
cout << "Insira o numero da conta da qual o saque sera realizado"<<endl;
cin>>numConta;
cout << "Insira o valor a ser sacado"<<endl;
cin>>valor;
this->saque(numConta, valor);
}

void Interface::transferenciai(){
  int oriconta,destconta;
  double valor;
cout <<endl<< "Insira o numero da conta de origem da transferencia"<<endl;
cin>>oriconta;
cout <<"Insira o numero da conta de destino"<<endl;
cin>>destconta;
cout <<"Insira o valor a ser transferido"<<endl;
cin>>valor;

this->transferencia(oriconta,destconta, valor);

}

void Interface::cobrartarifai(){

this->cobrarTarifa();
cout<<endl<<"Tarifa Cobrada"<<endl;


}
void Interface::cobrarcpmfi(){

  this->cobrarCPMF();
  cout<<endl<<"CPMF Cobrada"<<endl;

}

void Interface::saldoi(){

  int numConta;
  double valor;

cout <<endl<< "Insira o numero da conta a se avaliar o saldo"<<endl;
cin>>numConta;
valor = this->obterSaldo(numConta);

if(valor = -1)
cout<< "O numero de conta inserido nao foi encontrado";
else
cout<<"O saldo da conta e de: R$"<<valor<<",00"<<endl;
}

void Interface::extratoi(){
  int numConta;
  string extrato;
  time_t dinicial,dfinal;

cout <<endl<< "Insira o numero da conta a se avaliar o saldo"<<endl;
cin>>numConta;
cout <<endl<< "Insira a data inicial da consulta"<<endl;
cin>>dinicial;
Data dini(dinicial);
cout <<endl<< "Insira a data final da consulta"<<endl;
Data dfim(dfinal);

extrato = this->obterExtrato(numConta,dini,dfim);
cout<<extrato<<endl;
}

void Interface::listaclientes(){
std::vector<Cliente> temp;
Cliente clientetemp;
temp = this->obterListaClientes();

for(std::vector<Cliente>::const_iterator i = temp.begin(); i != temp.end(); ++i){
clientetemp =*i;
this->printacliente(clientetemp);
}
}

void Interface::listacontas(){
  std::vector<Conta> temp;
  Conta contatemp;
  Cliente clientetemp;
  temp = this->obterListaContas();

  for(std::vector<Conta>::const_iterator i = temp.begin(); i != temp.end(); ++i){
  contatemp =*i;
  clientetemp = contatemp.get_cliente();
  this->printaconta(contatemp);
  this->printacliente(clientetemp);

  }
}

void Interface::printacliente(Cliente clientet){
  cout<<endl<<endl<<"Nome: "<< clientet.getnomeCliente() <<endl;
  cout<<"CPF/CNPJ: "<< clientet.getcpf_cnpj() <<endl;
  cout<<"Endereço: "<< clientet.getendereco() <<endl;
  cout<<"Telefone: "<< clientet.getfone() <<endl;
}

void Interface::printaconta(Conta contat){
  cout<<endl<<endl<<"Nome: "<< contat.get_num_conta() <<endl;
  cout<<"CPF/CNPJ: "<< contat.get_saldo() <<endl;

}

// void Interface::main(){

//}
