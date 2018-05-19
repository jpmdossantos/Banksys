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
  void get();
  void set(std::string name, std::string id, std::string add, std::string pho);
  void putdata();

};
//class Movimentacao
//{

//};
//class Conta
//{

//};
//class Banco
//{

//};
//class Interface
//{

//};
#endif
