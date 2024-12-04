#include "crow.h"
#include "routes.h"

int main() {
    crow::Simple app;

    setup_routes(app);

    app.port(8080).multithreaded().run();
    return 0;
}