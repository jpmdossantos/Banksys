#include <iostream>
#include <string>
#include <ctime>
#include "banksys.h"
using namespace std;

Data::Data()
{
  dia_ = "1";
  mes_ = "Jan";
  ano_ = "1970";
}

Data::Data(time_t &data)
{
  dia_ = "";
  mes_ = "";
  ano_ = "";


  //formato time_t para data em string:
  // www mmm dd hh:mm:ss yyyy
  std::string sd(ctime(&data));

  dia_ += sd[8]; dia_ += sd[9];
  mes_ += sd[4]; mes_ += sd[5]; mes_ += sd[6];
  ano_ += sd[20]; ano_ += sd[21]; ano_ += sd[22];
  ano_ += sd[23];
}

std::string Data::get_data()
{
  return dia_ + ' ' + mes_ + ' ' + ano_;
}
