#include <iostream>
#include <string>
#include <ctime>

#include "banksys.h"


Data::Data()
{
  agora_ = time(NULL);

  // objeto data carrega consigo o momento em que
  // o construtor foi chamado
}

time_t Data::get_data_unix()
{
  return agora_;
}

std::string Data::get_data_formatado()
{

  time_t unix_ = agora_;
  //faco uma copia pq essas funcoes malucas
  // de tempo alteram a variavel de entrada,
  //repare que a entrada eh passada por referencia

  //formato time_t para data em string C:
  // www mmm dd hh:mm:ss yyyy
  std::string sd(ctime(&unix_));
  //cout << sd;
  std::string ret = "";

  ret += sd[8]; ret += sd[9]; ret += " ";
  ret += sd[4]; ret += sd[5]; ret += sd[6]; ret += " ";
  ret += sd[20]; ret += sd[21]; ret += sd[22]; ret += sd[23];

  return ret;

}
