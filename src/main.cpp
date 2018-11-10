#include <iostream>
#include <memory>
#include <string>

#include <crow.h>

using namespace std;

unique_ptr<crow::App<>> app;

void init_server();
void join_server();

int main() {
  init_server();
  cout<<"Start..."<<endl;
  join_server();
  return 0;
}

void init_server() {
  app = unique_ptr<crow::App<>>(new crow::App<>());

  crow::App<> &handle = *app;

  auto pong = [](string name) -> string {
    return string("Hello, ") + name;
  };

  CROW_ROUTE(handle, "/hello/<string>").methods("GET"_method)(pong);
}

void join_server() {
  app->port(6473).run();
}
