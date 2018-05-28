#include <iostream>
#include <string>
#include <vector>
#include "banksys.h"


Banco::Banco()
{
  nomeBanco_ = "JP&MA Chase";
}

Banco::Banco(std::string nome)
{
  nomeBanco_ = nome;
}

void Banco::inserirCliente(Cliente C)
{
  clientes_.push_back(C);
}

void Banco::criarConta( const Cliente &C)
{
  Conta nova(C);
  contas_.push_back(nova);
}

void Banco::excluirCliente(std::string cpf_cnpj)
{
  for (size_t i = 0; i<clientes_.size(); i++)
  {
    if (clientes_[i].getcpf_cnpj() == cpf_cnpj)
    {
      Cliente aux = clientes_[clientes_.size() - 1];
      clientes_[i] = aux;
      clientes_.pop_back();
    }
  }
}

void Banco::excluirConta(int numConta)
{

}

void Banco::deposito(int numConta, double valor)
{

}

void Banco::saque(int numConta, double valor)
{

}

void Banco::transferencia(int numContaOrigem, int numContaDestino, double valor)
{

}

void Banco::cobrarTarifa()
{

}

void Banco::cobrarCPMF()
{

}

double Banco::obterSaldo(int numConta)
{
  return 0;
}

std::string Banco::obterExtrato(int numConta)
{
  return "";
}

std::string Banco::obterExtrato(int numConta, Data dInicial)
{
  return "";
}

std::string Banco::obterExtrato(int numConta, Data dInicial, Data dFinal)
{
  return "";
}

std::vector<Cliente> Banco::obterListaClientes()
{
  return clientes_;
}

std::vector<Conta> Banco::obterListaContas()
{
  return contas_;
}

void Banco::gravarDados()
{

}

void Banco::gravarDados(std::string path)
{

}

void Banco::lerDados()
{

}

void Banco::lerDados(std::string path)
{

}
