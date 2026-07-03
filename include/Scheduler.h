#pragma once

#include <vector>
#include "Queue.h"
#include "Process.h"

/**
 * @file Scheduler.h
 * @author Juan Sebastian Valencia Quinchua (juan.quinchua@correounivalle.edu.com)
 * @brief Planificador central que implementa la lógica de las colas multinivel (MLQ).
 * @details El algoritmo gestiona las colas despachando procesos según prioridades y diferentes políticas de planificación[cite: 13].
 * @version 0.1
 * @date 2026-07-03
 * * @copyright Copyright (c) 2026
 */
class Scheduler {
private:
    Queue& queue;
    int globalTime;
    std::vector<Process*> historyProcesses;

public:
    /**
     * @brief Construye un nuevo planificador asociado a un manejador de colas.
     * * @param mainQueue Referencia a la estructura Queue previamente inicializada con los procesos.
     */
    Scheduler(Queue& mainQueue);

    /**
     * @brief Selecciona el próximo proceso a ejecutar evaluando la prioridad estricta de las colas.
     * * @return Process* Puntero al proceso seleccionado para tomar control de la CPU.
     */
    Process* chooseProcessToRun();

    /**
     * @brief Verifica si la primera cola (RR1) tiene procesos listos para ejecutar.
     * * @return true Si existen procesos en la primera cola.
     * @return false Si la primera cola está vacía.
     */
    bool verifyFirstQueue();

    /**
     * @brief Verifica si la segunda cola (RR3) tiene procesos listos para ejecutar.
     * * @return true Si existen procesos en la segunda cola.
     * @return false Si la segunda cola está vacía.
     */
    bool verifySecondQueue();

    /**
     * @brief Ejecuta los procesos de una cola utilizando la política Round Robin.
     * * @param targetQueue Referencia a la cola sobre la que se aplicará el algoritmo.
     */
    void runToRoundRobinAlgorithm(std::vector<Process*>& targetQueue);

    /**
     * @brief Ejecuta los procesos de una cola utilizando la política Shortest Job First (SJF).
     * * @param targetQueue Referencia a la cola sobre la que se aplicará el algoritmo.
     */
    void runToShortJobFirstAlgorithm(std::vector<Process*>& targetQueue);

    /**
     * @brief Despacha la primera cola utilizando su respectivo Quantum (Round Robin q=1).
     */
    void executeFirstQueue();

    /**
     * @brief Despacha la segunda cola utilizando su respectivo Quantum (Round Robin q=3).
     */
    void executeSecondQueue();

    /**
     * @brief Despacha la tercera cola utilizando Shortest Job First (SJF).
     */
    void executeThirdQueue();

    /**
     * @brief Inicia el ciclo principal del planificador (simulación de la CPU).
     * @details Se ejecuta continuamente comprobando llegadas, asignando CPU e interrumpiendo procesos según las políticas de MLQ.
     */
    void runAlgorithm();

    /**
     * @brief Realiza los cálculos finales de las métricas (WT, TAT, RT, CT) para todos los procesos almacenados en el historial.
     */
    void setMetrics();
};