#ifndef BANKSYS_H
#define BANKSYS_H

#include <vector>



class Data
{
private:
  std::string dia_;
  std::string mes_;
  std::string ano_;

public:
  Data();
  Data(time_t &data);
  std::string get_data();
};


class Cliente
{
private:
std::string nomeCliente, cpf_cnpj, endereco, fone;
public:
  Cliente(std::string name, std::string id, std::string add, std::string pho);
  Cliente(const Cliente &a);
  Cliente();
  std::string getnomeCliente()const;
  std::string getcpf_cnpj()const;
  std::string getendereco()const;
  std::string getfone()const;
  void setnomeCliente(std::string name);
  void setcpf_cnpj(std::string id);
  void setendereco(std::string add);
  void setfone(std::string pho);
  void putdata();

};


class Movimentacao
{
private:
  Data dataMov_;
  std::string descricao_;
  char debito_credito;
  double valor;

public:
  Movimentacao();
  Movimentacao(Data dataMov, std::string descricao, double valor);
  Movimentacao(const Movimentacao &M);
  Data get_data();
  std::string get_descricao();
  double get_valor();

};


class Conta
{
private:
  int numConta_;
  double saldo_;
  Cliente cliente_;
  std::vector <int> movimentacoes_;
  static int proximoNumConta_;

public:
  Conta(const Cliente &cliente);
  int get_num_conta();
  double get_saldo();
  Cliente get_cliente();

};

//class Banco
//{

//};
//class Interface
//{

//};




#endif
