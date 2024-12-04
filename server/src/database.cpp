#include "database.h"
#include <iostream>
#include <sqlite3.h>

bool Database::initialize() {
    sqlite3* db;
    int rc = sqlite3_open("app.db", &db);
    if (rc) {
        std::cerr << "Erro ao abri banco de dados" << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    const char* sql = R"
    CREATE TABLE IF NOT EXIST users (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        nome TEXT NOT NULL,
        email TEXT UNIQUE NOT NULL,
        senha TEXT NOT NULL
        );
    )";

    char* errMsg = nullptr;
    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao criar tabelas." << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    sqlite3_close(db);
    return rc == SQLITE_OK;

}