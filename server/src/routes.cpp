#include "routes.h"
#include "database.h"
#include <crow.h>

void setupRoutes(crow::SimpleApp& app) {

    CROW_ROUTE(app, "/").methods("GET"_method)([]() {
        return crow::response(200, "Ok");
    });

    CROW_ROUTE(app, "/register").methods("POST"_method)([](const crow::request& req) {
        auto body = crow::json::load(req.body);
        if (!body) return crow::response(400, "Dados inválidos.");

        std::string nome = body["nome"].s();
        std::string email = body["email"].s();
        std::string senha = body["senha"].s();

        bool sucesso = Database::addUser(nome, email, senha);
        return sucesso ? crow::response(201, "Usuário criado.")
                       : crow::response(500, "Erro ao salvar no banco.");
    });
}
