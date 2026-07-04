# 1. Versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.10)

# 2. Nombre del proyecto y lenguaje
project(SimuladorMLQ CXX)

# 3. Especificar el estándar de C++ (C++11 o C++17 son ideales)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 4. Configurar la salida del ejecutable a la carpeta "bin/"
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# 5. Indicar dónde están los archivos de cabecera (.h)
include_directories(${CMAKE_SOURCE_DIR}/include)

# 6. Recopilar todos los archivos fuente (.cpp) de la carpeta src/
file(GLOB SOURCES "src/*.cpp")

# 7. Crear el ejecutable llamado "simulador" usando los archivos fuente
add_executable(simulador ${SOURCES})