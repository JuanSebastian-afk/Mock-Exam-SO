#pragma once

#include <vector>
#include "Queue.h"
#include "Process.h"

/**
 * @file Scheduler.h
 * @author Juan Sebastian Valencia Quinchua (juan.quinchua@correounivalle.edu.com)
 * @brief Planificador central que implementa la lógica de las colas multinivel (MLQ).
 * @details El algoritmo gestiona las colas despachando procesos según prioridades y diferentes políticas de planificación.
 * @version 0.1
 * @date 2026-07-03
 * @copyright Copyright (c) 2026
 */
class Scheduler {
private:
    Queue& queue;
    int globalTime;
    std::vector<Process*> historyProcesses;

public:
    /**
     * @brief Construye un nuevo planificador asociado a un manejador de colas.
     * @param mainQueue Referencia a la estructura Queue previamente inicializada con los procesos.
     */
    Scheduler(Queue& mainQueue);

    /**
     * @brief Inicia el ciclo principal del planificador (simulación de la CPU).
     * @details Se ejecuta continuamente comprobando llegadas, asignando CPU e interrumpiendo procesos según las políticas de MLQ.
     */
    void runAlgorithm();

    /**
     * @brief Realiza los cálculos finales de las métricas (WT, TAT, RT, CT) para todos los procesos almacenados en el historial.
     */
    void setMetrics();

    /**
    * @brief Get the History Processes object
    * 
    * @return std::vector<Process*>& 
    */
    std::vector<Process*>& getHistoryProcesses();
    
};