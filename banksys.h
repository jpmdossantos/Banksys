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
  Data(Data &d);
  Data(time_t &data);
  std::string get_data();
};


class Cliente
{
private:
std::string nomeCliente, cpf_cnpj_, endereco, fone;
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
  double valor_;

public:
  Movimentacao(Data dataMov, std::string descr, char dc, double valor);
  Movimentacao(const Movimentacao &M);
  Data get_data_obj();
  std::string get_descricao();
  double get_valor_mov();
  char get_dc();

};


class Conta
{
private:
  int numConta_;
  double saldo_;
  Cliente cliente_;
  std::vector <Movimentacao> movimentacoes_;
  static int proximoNumConta_;

public:
  Conta();
  Conta(const Cliente &cliente);
  int get_num_conta();
  double get_saldo();
  Cliente get_cliente();
  void debitar(double valor, std::string descr);
  void creditar(double valor, std::string descr);

};

class Banco
{
private:
  std::string nomeBanco_;
  std::vector <Cliente> clientes_;
  std::vector <Conta> contas_;

public:
  Banco();
  Banco(std::string nome);
  void inserirCliente(Cliente C);
  void criarConta(const Cliente &C);
  void excluirCliente(std::string cpf_cnpj);
  void excluirConta(int numConta);
  void deposito(int numConta, double valor);
  void saque(int numConta, double valor);
  void transferencia(int numContaOrigem, int numContaDestino, double valor);
  void cobrarTarifa();
  void cobrarCPMF();
  double obterSaldo(int numConta);
  std::string obterExtrato(int numConta);
  std::string obterExtrato(int numConta, Data dInicial);
  std::string obterExtrato(int numConta, Data dInicial, Data dFinal);
  std::vector<Cliente> obterListaClientes();
  std::vector<Conta> obterListaContas();
  void gravarDados();
  void gravarDados(std::string path);
  void lerDados();
  void lerDados(std::string path);


};



//class Interface
//{

//};




#endif
