#include <iostream>
#include <string>
#include <vector>
#include "banksys.h"
using namespace std;

Cliente::Cliente(string name, string id, string add, string pho)
{
  this->nomeCliente = name;
  this->cpf_cnpj_ = id;
  this->endereco = add;
  this->fone = pho;
}
Cliente::Cliente()
{
  this->nomeCliente = "default";
  this->cpf_cnpj_ = "default";
  this->endereco = "default";
  this->fone = "default";
}

Cliente::Cliente(const Cliente &a)
{
  this->nomeCliente = a.nomeCliente;
  this->cpf_cnpj_ = a.cpf_cnpj_;
  this->endereco = a.endereco;
  this->fone = a.fone;
}

string Cliente::getnomeCliente ()const
{
return nomeCliente;
}
string Cliente::getcpf_cnpj ()const
{
return cpf_cnpj_;
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
this->cpf_cnpj_=id;
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
  cout<<"CPF/CNPJ: "<< this->cpf_cnpj_ <<endl;
  cout<<"Endereço: "<< this->endereco <<endl;
  cout<<"Telefone: "<< this->fone <<endl;

}