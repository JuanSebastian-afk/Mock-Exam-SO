#include "Queue.h"
#include <stdexcept> // Necesario para std::out_of_range en el método getQueue()

void Queue::addProcessToQueue(Process* process, int queueIndex) {
    if (queueIndex >= 0 && queueIndex < 3) {
        queues[queueIndex].push_back(process);
    }
}

void Queue::processCompleted(std::string tag) {
    // Busca y elimina el proceso de cualquiera de las colas donde esté
    for (int i = 0; i < 3; i++) {
        for (auto it = queues[i].begin(); it != queues[i].end(); ++it) {
            if ((*it)->getTag() == tag) {
                queues[i].erase(it);
                return; // Asumimos que solo hay un proceso con ese tag
            }
        }
    }
}

std::vector<Process*>& Queue::getQueue(int queueIndex) {
    if (queueIndex >= 0 && queueIndex < 3) {
        return queues[queueIndex];
    }
    // Lanza un error si se pide una cola que no existe
    throw std::out_of_range("Error: Indice de cola fuera de los limites (debe ser 0, 1 o 2)");
}

Process* Queue::getProcess(int processIndex) {
    // Retorna un proceso de la primera cola por defecto según índice (ejemplo básico)
    if (processIndex >= 0 && processIndex < queues[0].size()) {
        return queues[0][processIndex];
    }
    return nullptr;
}

bool Queue::emptyQueue() {
    return queues[0].empty() && queues[1].empty() && queues[2].empty();
}