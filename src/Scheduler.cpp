#include "Scheduler.h"
#include <iostream>
#include <algorithm>

Scheduler::Scheduler(Queue& mainQueue) : queue(mainQueue), globalTime(0) {}


// =====================================================================
// LÓGICA DEL PLANIFICADOR
// =====================================================================
void Scheduler::runAlgorithm() {
    // 1. EXTRAE PROCESOS Y LOS ORDENA POR SU ARRIVAL TIME
    // El FileManager los carga en la Queue, pero los sacamos a una lista 
    // de "No Llegados" para respetar la línea de tiempo.
    std::vector<Process*> unarrived;
    for (int i = 0; i < 3; i++) {
        std::vector<Process*>& q = queue.getQueue(i);
        for (Process* p : q) {
            unarrived.push_back(p);
        }
        q.clear(); // Vaciamos las colas listas
    }
    
    // Ordenar procesos pendientes por Arrival Time
    std::sort(unarrived.begin(), unarrived.end(), [](Process* a, Process* b) {
        return a->getArrivalTime() < b->getArrivalTime();
    });

    globalTime = 0;
    Process* activeProcess = nullptr;
    int currentQuantum = 0;

    // 2. BUCLE DE TIEMPO
    // Se ejecuta mientras haya procesos por llegar, colas con procesos o un proceso en CPU
    while (!unarrived.empty() || !queue.emptyQueue() || activeProcess != nullptr) {
        
        // A. VERIFICAR LLEGADAS EN EL TIEMPO ACTUAL
        auto it = unarrived.begin();
        while (it != unarrived.end()) {
            if ((*it)->getArrivalTime() <= globalTime) {
                // Ingresa a su respectiva cola (1, 2 o 3)
                int qIndex = (*it)->getQueue() - 1; 
                queue.addProcessToQueue(*it, qIndex);
                it = unarrived.erase(it);
            } else {
                break; // Como están ordenados, si este no ha llegado, el resto tampoco
            }
        }

        // B. ORDENAR COLA 3 (SJF)
        // Cada vez que llega un proceso a la cola 3, se reordena para garantizar SJF
        std::vector<Process*>& q3 = queue.getQueue(2);
        if (!q3.empty()) {
            std::sort(q3.begin(), q3.end(), [](Process* a, Process* b) {
                return a->getRemainingBurstTime() < b->getRemainingBurstTime();
            });
        }

        // C. INTERRUPCIÓN ENTRE COLAS
        if (activeProcess != nullptr) {
            int activeQ = activeProcess->getQueue() - 1;
            int highestPriorityReady = -1;
            
            if (!queue.getQueue(0).empty()) highestPriorityReady = 0;
            else if (!queue.getQueue(1).empty()) highestPriorityReady = 1;

            // Si hay un proceso listo en una cola superior a la del proceso activo
            if (highestPriorityReady != -1 && highestPriorityReady < activeQ) {
                // Se interrumpe. El proceso activo se pone AL FRENTE de su propia cola para reanudar luego
                queue.getQueue(activeQ).insert(queue.getQueue(activeQ).begin(), activeProcess);
                activeProcess = nullptr;
                currentQuantum = 0;
            }
        }

        // D. ELEGIR NUEVO PROCESO SI LA CPU ESTÁ LIBRE
        if (activeProcess == nullptr) {
            if (!queue.getQueue(0).empty()) {
                activeProcess = queue.getQueue(0).front();
                queue.getQueue(0).erase(queue.getQueue(0).begin());
            } else if (!queue.getQueue(1).empty()) {
                activeProcess = queue.getQueue(1).front();
                queue.getQueue(1).erase(queue.getQueue(1).begin());
            } else if (!queue.getQueue(2).empty()) {
                activeProcess = queue.getQueue(2).front();
                queue.getQueue(2).erase(queue.getQueue(2).begin());
            }
            currentQuantum = 0; // Reiniciamos el quantum para el nuevo proceso
        }

        // E. EJECUTAR EL PROCESO 1 unidad de Tiempo)
        if (activeProcess != nullptr) {
            // Guardar Response Time si es su primera vez en CPU
            if (activeProcess->getResponseTime() == -1) {
                activeProcess->setResponseTime(globalTime - activeProcess->getArrivalTime());
            }

            // Ejecutamos 1 unidad
            activeProcess->setRemainingBurstTime(activeProcess->getRemainingBurstTime() - 1);
            globalTime++;
            currentQuantum++;

            // F. VERIFICAR FINALIZACIÓN DEL PROCESO
            if (activeProcess->getRemainingBurstTime() <= 0) {
                activeProcess->setCompleteTime(globalTime);
                historyProcesses.push_back(activeProcess);
                activeProcess = nullptr;
                currentQuantum = 0;
            } 
            // G. VERIFICAR EXPIRACIÓN DE QUANTUM PARA EL PROCESO ACTIVO (RR1 y RR3)
            else {
                int qIndex = activeProcess->getQueue() - 1;
                // Asignamos el Quantum según la cola: Q0(RR1)=1, Q1(RR3)=3, Q2(SJF)=999999
                int maxQuantum = (qIndex == 0) ? 1 : (qIndex == 1 ? 3 : 999999); 

                if (currentQuantum >= maxQuantum) {
                    // Si el Quantum expira se añade AL FINAL de su misma cola 
                    queue.addProcessToQueue(activeProcess, qIndex);
                    activeProcess = nullptr;
                    currentQuantum = 0;
                }
            }
        } else {
            // Si hay procesos listos avanzamos el tiempo 1 unidad
            globalTime++;
        }
    }

    // Al finalizar todos los procesos, calculamos promedios
    setMetrics();
}

void Scheduler::setMetrics() {
    for (Process* p : historyProcesses) {
        // TAT = Completado - Llegada
        p->setTurnaroundTime(p->getCompleteTime() - p->getArrivalTime());
        // WT = TAT - BurstTime Original
        p->setWaitingTime(p->getTurnaroundTime() - p->getBurstTime());
    }
}

std::vector<Process*>& Scheduler::getHistoryProcesses() { return historyProcesses; }
