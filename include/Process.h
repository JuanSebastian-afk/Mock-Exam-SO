#pragma once

#include <string>

/**
 * @file Process.h
 * @author Juan Sebastian Valencia Quinchua (juan.quinchua@correounivalle.edu.com)
 * @brief Definición de la clase Process para el simulador MLQ.
 * @version 0.1
 * @date 2026-07-03
 * @copyright Copyright (c) 2026
 */

/

class Process {
private:
    std::string tag;
    float arrivalTime;
    float burstTime;
    float waitingTime;
    float turnaroundTime;
    float completeTime;
    float responseTime;
    int queue;
    float remainingBurstTime;

public:
    /**
     * @brief Construye un nuevo objeto de tipo Process.
     * @param tag Identificación del proceso (ej. A, p1).
     * @param AT Arrival Time: Momento en el que el proceso llega al sistema.
     * @param BT Burst Time: Tiempo total que el proceso necesita para ejecutarse.
     * @param Q Queue: Cola a la que pertenece el proceso inicialmente.
     */
    Process(std::string tag, float AT, float BT, int Q);

    /**
     * @brief Obtiene la etiqueta identificadora del proceso.
     * @return std::string Etiqueta del proceso.
     */
    std::string getTag();

    /**
     * @brief Obtiene el tiempo de llegada (Arrival Time).
     * @return float Tiempo de llegada.
     */
    float getArrivalTime();

    /**
     * @brief Obtiene el tiempo total de ráfaga (Burst Time).
     * @return float Tiempo de ráfaga.
     */
    float getBurstTime();

    /**
     * @brief Obtiene el tiempo de espera (Waiting Time).
     * @return float Tiempo de espera acumulado.
     */
    float getWaitingTime();

    /**
     * @brief Establece el tiempo de espera (Waiting Time).
     * @param newWT Nuevo valor del tiempo de espera.
     */
    void setWaitingTime(float newWT);

    /**
     * @brief Obtiene el tiempo de retorno (Turnaround Time).
     * @return float Tiempo de retorno.
     */
    float getTurnaroundTime();

    /**
     * @brief Establece el tiempo de retorno (Turnaround Time).
     * @param newTRT Nuevo valor del tiempo de retorno.
     */
    void setTurnaroundTime(float newTRT);

    /**
     * @brief Obtiene el tiempo de respuesta (Response Time).
     * @return float Tiempo de respuesta.
     */
    float getResponseTime();

    /**
     * @brief Establece el tiempo de respuesta (Response Time).
     * @param RT Nuevo valor del tiempo de respuesta.
     */
    void setResponseTime(float RT);

    /**
     * @brief Obtiene el tiempo de completado (Complete Time).
     * @return float Tiempo en el que el proceso finaliza su ejecución.
     */
    float getCompleteTime();

    /**
     * @brief Establece el tiempo de completado (Complete Time).
     * @param CT Nuevo valor del tiempo de completado.
     */
    void setCompleteTime(float CT);

    /**
     * @brief Obtiene el tiempo restante de ráfaga (útil para algoritmos expropiativos).
     * @return float Tiempo restante de CPU que necesita el proceso.
     */
    float getRemainingBurstTime();

    /**
     * @brief Establece el tiempo restante de ráfaga.
     * @param RBT Nuevo tiempo restante.
     */
    void setRemainingBurstTime(float RBT);

    /**
     * @brief Obtiene el identificador de la cola asignada.
     * @return int Índice de la cola.
     */
    int getQueue();
};