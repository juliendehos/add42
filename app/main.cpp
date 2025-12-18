
#include <mymaths.hpp>

#include <drogon/HttpAppFramework.h>
#include <drogon/HttpSimpleController.h>
#include <drogon/HttpController.h>

#include <iostream>

using namespace drogon;

class Api : public drogon::HttpController<Api> {
  public:

    METHOD_LIST_BEGIN
    METHOD_ADD(Api::handleAdd42, "/add42/{1}", Get);
    METHOD_LIST_END

    void handleAdd42(
        const HttpRequestPtr &req,
        std::function<void (const HttpResponsePtr &)> &&callback,
        std::string str) const {

      const int x = std::stoi(str);
      const int result = mymaths::add42(x);

      LOG_DEBUG << "add42("<< x <<") = " << result;

      auto resp = HttpResponse::newHttpJsonResponse(result);
      callback(resp);
    }
};

class Home : public drogon::HttpSimpleController<Home> {
  public:

    PATH_LIST_BEGIN
    PATH_ADD("/", Get);
    PATH_LIST_END

    void asyncHandleHttpRequest(
        const HttpRequestPtr& req,
        std::function<void (const HttpResponsePtr &)> &&callback) override {

      LOG_DEBUG << "home";

      auto resp=HttpResponse::newHttpResponse();
      resp->setStatusCode(k200OK);
      resp->setContentTypeCode(CT_TEXT_HTML);
      resp->setBody("try: /api/add42/0");
      callback(resp);
    }
};

int main() {
  const int port = 3000;
  std::cout << "running server, port " << port << "..." << std::endl;
  drogon::app().addListener("0.0.0.0", port);
  drogon::app().run();
  return 0;
}

