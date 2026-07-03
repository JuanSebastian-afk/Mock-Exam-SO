#pragma once

#include <string>
#include <vector>
#include "Queue.h"
#include "Process.h"

/**
 * @file FileManager.h
 * @author Juan Sebastian Valencia Quinchua (juan.quinchua@correounivalle.edu.com)
 * @brief Clase encargada de la persistencia de datos: lectura de entradas y generación de reportes.
 * @version 0.1
 * @date 2026-07-03
 * @copyright Copyright (c) 2026
 */
class FileManager {
public:
    /**
     * @brief Lee un archivo de texto con la lista de procesos y los carga en la cola principal.
     * @details Parsea líneas separadas por punto y coma (;) respetando el formato de entrada del simulador[cite: 19, 21].
     * @param filePath Ruta del archivo de entrada a leer (ej. "mlq001.txt").
     * @param mainQueue Referencia a la clase Queue donde se cargarán los procesos instanciados.
     * @return true Si el archivo se leyó y procesó correctamente.
     * @return false Si hubo un error al abrir o procesar el archivo.
     */
    bool loadProcesses(std::string filePath, Queue& mainQueue);

    /**
     * @brief Genera un archivo de salida con el orden de ejecución y las métricas de los procesos.
     * @details Muestra en el archivo de texto el WT, CT, RT, TAT y sus respectivos promedios[cite: 27, 29, 30].
     * @param filePath Ruta del archivo de salida a generar.
     * @param completedProcesses Referencia al vector histórico con los procesos ya finalizados.
     * @return true Si el archivo se generó y guardó correctamente.
     * @return false Si hubo un error de escritura.
     */
    bool saveResults(std::string filePath, std::vector<Process*>& completedProcesses);
};