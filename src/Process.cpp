#include "Process.h"

// Constructor
Process::Process(std::string tag, float AT, float BT, int Q) {
    this->tag = tag;
    this->arrivalTime = AT;
    this->burstTime = BT;
    this->queue = Q;
    
    // Inicialización de métricas
    this->remainingBurstTime = BT;
    this->waitingTime = 0;
    this->turnaroundTime = 0;
    this->completeTime = 0;
    this->responseTime = -1; // -1 indica que no ha sido atendido aún
}

std::string Process::getTag() { return tag; }
float Process::getArrivalTime() { return arrivalTime; }
float Process::getBurstTime() { return burstTime; }

float Process::getWaitingTime() { return waitingTime; }
void Process::setWaitingTime(float newWT) { waitingTime = newWT; }

float Process::getTurnaroundTime() { return turnaroundTime; }
void Process::setTurnaroundTime(float newTRT) { turnaroundTime = newTRT; }

float Process::getResponseTime() { return responseTime; }
void Process::setResponseTime(float RT) { responseTime = RT; }

float Process::getCompleteTime() { return completeTime; }
void Process::setCompleteTime(float CT) { completeTime = CT; }

float Process::getRemainingBurstTime() { return remainingBurstTime; }
void Process::setRemainingBurstTime(float RBT) { remainingBurstTime = RBT; }

int Process::getQueue() { return queue; }