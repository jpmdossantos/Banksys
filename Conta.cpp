#include <iostream>
#include <string>
#include <vector>
#include "banksys.h"
using namespace std;

int Conta::proximoNumConta_ = 0;


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
