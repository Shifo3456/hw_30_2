#include "cpr/cpr.h"
#include <iostream>
#include <string>

int main() {
  cpr::Response r = cpr::Get(cpr::Url{"http://httpbin.org/html"},
                             cpr::Header{{"accept", "text/html"}});
  int a = r.text.find("<h1>");
  int b = r.text.find("</h1>");
  std::string header = r.text.substr(a + 4, b - a - 4);
  std::cout << header << std::endl;
}