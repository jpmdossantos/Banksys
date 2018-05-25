#include <iostream>
#include <string>
#include <vector>
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

string Cliente::getnomeCliente ()const
{
return nomeCliente;
}
string Cliente::getcpf_cnpj ()const
{
return cpf_cnpj;
}
string Cliente::getendereco ()const
{
return endereco;
}
string Cliente::getfone ()const
{
  return fone;
}

void Cliente::setnomeCliente(string name)
{
this->nomeCliente=name;
}
void Cliente::setcpf_cnpj(string id)
{
this->cpf_cnpj=id;
}
void Cliente::setendereco(string add)
{
this->endereco =add;
}
void Cliente::setfone(string pho)
{
  this->fone = pho;
}

void Cliente::putdata()
{
  cout<<endl<<"Nome: "<< this->nomeCliente <<endl;
  cout<<"CPF/CNPJ: "<< this->cpf_cnpj <<endl;
  cout<<"Endereço: "<< this->endereco <<endl;
  cout<<"Telefone: "<< this->fone <<endl;

}
