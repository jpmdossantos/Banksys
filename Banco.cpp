#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>
#include "banksys.h"


Banco::Banco()
{
  nomeBanco_ = "JP&MA Chase";
}

Banco::Banco(std::string nome, std::vector<Cliente> clientes, std::vector<Conta> contas )
{
  clientes_ = clientes;
  contas_ = contas;
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
  bool tem_conta = false;
  for (size_t j = 0;  j<contas_.size(); j++)
  {
    if (contas_[j].get_cliente().getcpf_cnpj() == cpf_cnpj)
    {
      tem_conta = true;
    }
  }
  if (!tem_conta)
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
}

void Banco::excluirConta(int numConta)
{
  for (size_t i = 0; i<contas_.size(); i++)
  {
    if (contas_[i].get_num_conta() == numConta)
    {
      Conta aux = contas_[contas_.size() - 1];
      contas_[i] = aux;
      contas_.pop_back();
      break;
    }
  }
}

void Banco::deposito(int numConta, double valor)
{
  for(size_t i = 0; i<contas_.size(); i++)
  {
    if (contas_[i].get_num_conta() == numConta)
    {
      contas_[i].debitar(valor, "Deposito");
      break;
    }
  }
}

void Banco::saque(int numConta, double valor)
{
  for(size_t i = 0; i<contas_.size(); i++)
  {
    if (contas_[i].get_num_conta() == numConta)
    {
      contas_[i].debitar(valor, "Saque");
      break;
    }
  }

}

void Banco::transferencia(int numContaOrigem, int numContaDestino, double valor)
{
  std::ostringstream numeroStr;

  for(size_t i = 0; i<contas_.size(); i++)
  {
    if (contas_[i].get_num_conta() == numContaOrigem)
    {
      numeroStr << numContaDestino;
      std::string texto = "Transferencia para a conta "
      + numeroStr.str();


      contas_[i].debitar(valor, texto);
      break;
    }
  }




  for(size_t i = 0; i<contas_.size(); i++)
  {
    if (contas_[i].get_num_conta() == numContaDestino)
    {
      numeroStr << numContaOrigem;
      std::string texto = "Transferencia da conta "
      + numeroStr.str();
      contas_[i].debitar(valor, texto);
      break;
    }
  }
}

void Banco::cobrarTarifa()
{
  double tarifa = 15.0;
  for(size_t i = 0; i<contas_.size(); i++)
  {
    std::string texto = "Cobranca de tarifa";
    contas_[i].debitar(tarifa, texto);
  }
}

void Banco::cobrarCPMF()
{
  for(size_t i = 0; i<contas_.size(); i++)
  {
    double cpmf = contas_[i].get_saldo() * (0.38/100);
    std::string texto = "Cobranca de CPMF";
    contas_[i].debitar(cpmf, texto);
  }
}

double Banco::obterSaldo(int numConta)
{
  for(size_t i = 0; i<contas_.size(); i++)
  {
    if (contas_[i].get_num_conta() == numConta)
    {
      return contas_[i].get_saldo() ;
    }
    return -1;
    //indicador de que nao achou a conta
  }
}

std::string Banco::obterExtrato(int numConta)
{
  for (size_t i = 0; i < contas_.size(); i++)
  {
    if (contas_[i].get_num_conta() == numConta)
    {
      return contas_[i].get_extrato();
    }
  }
  return "Conta inexistente";
}

std::string Banco::obterExtrato(int numConta, Data dInicial)
{
  for (size_t i = 0; i < contas_.size(); i++)
  {
    if (contas_[i].get_num_conta() == numConta)
    {
      return contas_[i].get_extrato(dInicial);
    }
  }
  return "Conta inexistente";
}

std::string Banco::obterExtrato(int numConta, Data dInicial, Data dFinal)
{
  for (size_t i = 0; i < contas_.size(); i++)
  {
    if (contas_[i].get_num_conta() == numConta)
    {
      return contas_[i].get_extrato(dInicial, dFinal);
    }
  }
  return "Conta inexistente";
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
  std::ofstream clientes("clientes.txt");
  std::ofstream contas("contas.txt");

  if(clientes.is_open())
  {
    for(size_t i = 0; i < clientes_.size(); i++)
    {
      clientes << clientes_[i].get_ficha() + "\n";
    }
  }

  clientes.close();

  if (contas.is_open())
  {
    for(size_t i = 0; i < contas_.size(); i++)
    {
      contas << contas_[i].get_ficha_conta() + "\n";
    }
  }
  contas.close();


}

void Banco::lerDados()
{
  std::string nome;
  std::string cpf;
  std::string endereco;
  std::string fone;

  std::string numeroconta;
  std::string saldo;


  std::string data;
  std::string descricao;
  std::string valor;
  std::string dc;
  std::vector<Movimentacao> movs;

  std::string linha;
  std::ifstream clientes("clientes.txt");
  std::ifstream contas("contas.txt");

  if(clientes.is_open())
  {
    while(getline(clientes,linha))
    {
      std::istringstream slinha(linha);
      getline(slinha, nome, '|');
      getline(slinha, cpf, '|');
      getline(slinha, endereco, '|');
      getline(slinha, fone, '|');
      Cliente clienteCarregado(nome, cpf, endereco, fone);
      this->inserirCliente(clienteCarregado);
    }
  }

  if (contas.is_open())
  {
    while(getline(contas,linha))
    {
      std::istringstream slinha(linha);
      getline(slinha, numeroconta, '|');
      getline(slinha, saldo, '|');
      getline(slinha, cpf, '|');
      getline(slinha, fone, '|');
      while(slinha)
      {
        getline(slinha, data, '|');
        Data d(data);
        getline(slinha, descricao, '|');
        getline(slinha, valor, '|');
        double dvalor = stod(valor);
        getline(slinha, dc, '|');

        Movimentacao movCarregada(d,descricao,dc[0],dvalor);
        movs.push_back(movCarregada);
      }
      for (size_t i = 0; i < clientes_.size(); i++)
      {
        if (clientes_[i].getcpf_cnpj() == cpf)
        {
          Conta contaCarregada(clientes_[i]);
          contaCarregada.get_movimentacoes() = movs;
        }
      }
    }
  }
}





std::string Banco::get_dados_conta(int numConta)
{
  for (size_t i = 0; i < contas_.size(); i++)
  {
    if (contas_[i].get_num_conta() == numConta)
    {
      return contas_[i].get_ficha_conta();
    }
  }
  return "conta nao existe";
}

std::string Banco::get_dados_cliente(std::string cpf_cnpj)
{
  for (size_t i = 0; i < clientes_.size(); i++)
  {
    if (clientes_[i].getcpf_cnpj() == cpf_cnpj)
    {
      return clientes_[i].get_ficha();
    }
  }
  return "cliente nao existe";
}
