#include <iostream>
#include <string>
#include <vector>
#include "banksys.h"

Movimentacao::Movimentacao(Data dataMov, std::string descr, char dc, double valor)
{
  dataMov_ = dataMov;
  descricao_ = descr;
  debito_credito = dc;
  valor_ = valor;

}

Movimentacao::Movimentacao(const Movimentacao &M)
{
  dataMov_ = M.dataMov_;
  descricao_ = M.descricao_;
  debito_credito = M.debito_credito;
  valor_ = M.valor_;
}

Data Movimentacao::get_data_obj()
{
  return dataMov_;
}

std::string Movimentacao::get_descricao()
{
  return descricao_;
}

double Movimentacao::get_valor_mov()
{
  return valor_;
}

char Movimentacao::get_dc()
{
  return debito_credito;
}
