#include <iostream>
#include <string>
#include <vector>
#include "banksys.h"
using namespace std;

int Conta::proximoNumConta_ = 0;
/*
Conta::Conta()
{
  Cliente gen;

  numConta_ = -1;
  cliente_ = gen;
  saldo_ = 0;
} //apenas usado para incializar,
  //nao precisa de incrementar proximoNumConta_
 na real acho q nem precisa dessa merda aqui*/
  
Conta::Conta(const Cliente &cliente)
{
  numConta_ = proximoNumConta_;
  proximoNumConta_++;
  cliente_ = cliente;
  saldo_ = 0;
}

int Conta::get_num_conta()
{
  return numConta_;
}

double Conta::get_saldo()
{
  return saldo_;
}

Cliente Conta::get_cliente()
{
  return cliente_;
}
