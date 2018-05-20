#ifndef BANKSYS_H
#define BANKSYS_H
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
//class Movimentacao
//{

//};
class Conta
{
private:
int numConta;
double saldo;
Cliente cliente;
std::vector <int> movimentacoes;
static int proximoNumConta;
};
//class Banco
//{

//};
//class Interface
//{

//};
#endif
