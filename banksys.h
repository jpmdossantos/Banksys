#ifndef BANKSYS_H
#define BANKSYS_H

#include <vector>



class Data
{
private:

int dia_;
int mes_;
int ano_;

public:
  Data();
  Data(int dia, int mes, int ano);
  Data(Data const &d);
  std::string get_data_formatada();
  int get_dia();
  int get_mes();
  int get_ano();
  bool operator==(Data d);
  bool operator<(Data d);
  bool operator>(Data d);
  bool operator>=(Data d);
  bool operator<=(Data d);

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
  std::string get_ficha()const;
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
  std::string get_extrato();
  std::string get_extrato(Data data);
  std::string get_extrato(Data datain, Data datasup);
  std::string get_ficha_conta();

};

class Banco
{
protected:
  std::string nomeBanco_;
  std::vector <Cliente> clientes_;
  std::vector <Conta> contas_;


public:
  Banco();
  Banco(std::string nome,std::vector<Cliente> clientes,std::vector<Conta> contas);
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
  void lerDados();
  std::string get_dados_conta(int numConta);
  std::string get_dados_cliente(std::string cpf_cnpj);


};



class Interface : public Banco
{
public:
Interface();
Interface(std::string nome,std::vector<Cliente> clientes,std::vector<Conta> contas);
int menu();
void novocliente();
void excluirclientei();
void excluircontai();
void depositoi();
void saquei();
void transferenciai();
void cobrartarifai();
void cobrarcpmfi();
void saldoi();
void extratoi();
void listaclientes();
void printacliente(Cliente clientet);
void listacontas();
void printaconta(Conta contat);
void main();
};




#endif
