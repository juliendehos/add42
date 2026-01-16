
#include <mymaths.hpp>

#include <hv/HttpServer.h>

int main() {

  using namespace hv;

  HttpService router;

  router.GET("/", [](HttpRequest* req, HttpResponse* resp) {
      std::cout << "/home" << std::endl;
      return resp->String("try: /api/add42/0");
    });

  router.GET("/api/add42/:x", [](HttpRequest* req, HttpResponse* resp) {
      const std::string str = req->GetParam("x");
      std::cout << "/api/add42/" << str << std::endl;
      const int x = std::stoi(str);
      const int result = mymaths::add42(x);
      resp->content_type = APPLICATION_JSON;
      resp->json["result"] = result;
      return 200;
    });

  const int port = 3000;
  HttpServer server(&router);
  server.setPort(port);
  std::cout << "running server, port " << port << "..." << std::endl;
  server.run();

  return 0;
}

