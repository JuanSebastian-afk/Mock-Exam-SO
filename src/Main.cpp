#include <iostream>
#include <string>
#include "Queue.h"
#include "FileManager.h"
#include "Scheduler.h"

int main(int argc, char* argv[]) {
    std::cout << "=========================================" << std::endl;
    std::cout << "      Simulador de Planificador MLQ      " << std::endl;
    std::cout << "=========================================" << std::endl;

    // Nombres de archivos por defecto
    std::string inputFile = "input.txt";
    std::string outputFile = "output.txt";

    // Manejo de argumentos por línea de comandos
    if (argc >= 3) {
        inputFile = argv[1];
        outputFile = argv[2];
    } else {
        std::cout << "Nota: Puedes usar argumentos personalizados.\n";
        std::cout << "Uso: ./simulador <archivo_entrada.txt> <archivo_salida.txt>\n";
        std::cout << "Usando archivos por defecto: " << inputFile << " y " << outputFile << "\n\n";
    }

    // 1. Instanciar los componentes principales
    Queue mainQueue;
    FileManager fileManager;
    Scheduler scheduler(mainQueue);

    // 2. Cargar procesos desde el archivo de entrada
    std::cout << "[1/3] Cargando procesos desde: " << inputFile << "..." << std::endl;
    if (!fileManager.loadProcesses(inputFile, mainQueue)) {
        std::cerr << "ERROR: No se pudo cargar el archivo de entrada. Verifica que exista la ruta." << std::endl;
        return 1; // Salida con código de error
    }
    std::cout << "      -> Procesos cargados exitosamente.\n" << std::endl;

    // 3. Ejecutar el planificador
    std::cout << "[2/3] Ejecutando algoritmo de planificacion MLQ..." << std::endl;
    scheduler.runAlgorithm();
    std::cout << "      -> Simulacion finalizada con exito.\n" << std::endl;

    // 4. Guardar los resultados en el archivo de salida
    std::cout << "[3/3] Guardando reporte de resultados en: " << outputFile << "..." << std::endl;
    
    // Obtenemos el historial de procesos desde el scheduler y lo pasamos al fileManager
    if (!fileManager.saveResults(outputFile, scheduler.getHistoryProcesses())) {
        std::cerr << "ERROR: No se pudieron guardar los resultados." << std::endl;
        return 1;
    }
    std::cout << "      -> Resultados guardados exitosamente.\n" << std::endl;

    std::cout << "=========================================" << std::endl;
    std::cout << "      Ejecucion completada con exito     " << std::endl;
    std::cout << "=========================================" << std::endl;

    return 0;
}