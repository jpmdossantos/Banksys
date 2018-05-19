#include <iostream>
#include <string>
#include "banksys.h"
using namespace std;

Cliente::Cliente(string name, string id, string add, string pho)
{
  this->nomeCliente = name;
  this->cpf_cnpj = id;
  this->endereco = add;
  this->fone = pho;
}
Cliente::Cliente()
{
  this->nomeCliente = "default";
  this->cpf_cnpj = "default";
  this->endereco = "default";
  this->fone = "default";
}

Cliente::Cliente(const Cliente &a)
{
  this->nomeCliente = a.nomeCliente;
  this->cpf_cnpj = a.cpf_cnpj;
  this->endereco = a.endereco;
  this->fone = a.fone;
}

void Cliente::get()
{
string name, id, add, pho;

cout<<endl<<"Digite o nome do cliente "<<endl;
getline(cin,name);
cout<<"Digite o cpf ou cnpj do cliente"<<endl;
getline(cin,id);
cout<<"Digite o endereço do cliente"<<endl;
getline(cin,add);
cout<<"Digite o telefone do cliente"<<endl;
getline(cin,pho);

this->set(name,id,add,pho);
}

void Cliente::set(string name,string id,string add,string pho)
{
  this->nomeCliente = name;
  this->cpf_cnpj = id;
  this->endereco = add;
  this->fone = pho;
}

void Cliente::putdata()
{
  cout<<endl<<"Nome = "<<this->nomeCliente<<endl;
  cout<<"CPF/CNPJ = "<<this->cpf_cnpj<<endl;
  cout<<"Endereço = "<<this->endereco<<endl;
  cout<<"Telefone = "<<this->fone<<endl;

}
