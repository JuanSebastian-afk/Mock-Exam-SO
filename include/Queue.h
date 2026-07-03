#pragma once

#include <vector>
#include <string>
#include "Process.h"

/**
 * @file Queue.h
 * @author Juan Sebastian Valencia Quinchua (juan.quinchua@correounivalle.edu.com)
 * @brief Clase gestora de las colas multinivel para los procesos.
 * @version 0.1
 * @date 2026-07-03
 * @copyright Copyright (c) 2026
 */
class Queue {
private:
    std::vector<Process*> queues[3];

public:
    /**
     * @brief Añade un proceso a una cola específica.
     * @param process Puntero al proceso a encolar.
     * @param queueIndex Índice de la cola (0 a 2 para MLQ de 3 niveles).
     */
    void addProcessToQueue(Process* process, int queueIndex);

    /**
     * @brief Marca un proceso como completado y lo remueve de su cola actual.
     * * @param tag Etiqueta identificadora del proceso a completar.
     */
    void processCompleted(std::string tag);

    /**
     * @brief Obtiene todos los procesos almacenados en una cola específica.
     * * @param queueIndex Índice de la cola a consultar.
     * @return std::vector<Process*> Vector con los punteros a los procesos de esa cola.
     */
    std::vector<Process*> getQueue(int queueIndex);

    /**
     * @brief Obtiene un proceso específico dentro de la estructura general mediante su índice.
     * @param processIndex Índice global o identificador posicional del proceso.
     * @return Process* Puntero al proceso encontrado.
     */
    Process* getProcess(int processIndex);

    /**
     * @brief Verifica si todas las colas del sistema están vacías.
     * @return true Si no hay procesos pendientes en ninguna de las 3 colas.
     * @return false Si existe al menos un proceso en alguna cola.
     */
    bool emptyQueue();
};