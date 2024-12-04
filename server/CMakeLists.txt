cmake_minimum_required(VERSION 3.10)
project(ServiceApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adicionar diretórios de include e source
include_directories(include)
file(GLOB SOURCES "src/*.cpp" "src/models/*.cpp")

# Adicionar bibliotecas externas
find_package(SQLite3 REQUIRED)
find_package(nlohmann_json REQUIRED)

# Executável final
add_executable(ServiceApp ${SOURCES})

# Linkar bibliotecas
target_link_libraries(ServiceApp SQLite::SQLite3 nlohmann_json::nlohmann_json)
