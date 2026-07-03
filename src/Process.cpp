#include "../include/Process.h"

Process::getTag(){ return tag; }
Process::getArrivalTime(){ return arraibalTime; }
Process::getBurstTime(){ return arraibalTime; }
Process::getCompleteTime(){ return completeTime; }
Process::getTurnaroundTime(){ return turnaroundTime; }
Process::getResponseTime(){ return responseTime; }
Process::getWitingTime(){ return witingTime; }
Process::getRemainingBurstTime(){ return remainingBurstTime; }
Process::getQueue(){ return queue; }

Process::setCompleteTime(float newCT){ completeTime = newCT; }
Process