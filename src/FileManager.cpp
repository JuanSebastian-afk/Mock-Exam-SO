#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool FileManager::loadProcesses(std::string filePath, Queue& mainQueue) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo: " << filePath << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#' || line.find("Tag") != std::string::npos) {
            continue;
        }

        std::stringstream ss(line);
        std::string tag, bt_str, at_str, q_str;
        
        // ¡CORRECCIÓN AQUÍ! El formato del profe es: Tag; BurstTime; ArrivalTime; Queue
        std::getline(ss, tag, ';');
        std::getline(ss, bt_str, ';'); // Primero se lee el Burst Time
        std::getline(ss, at_str, ';'); // Luego el Arrival Time
        std::getline(ss, q_str, ';');

        if (!tag.empty()) {
            float bt = std::stof(bt_str);
            float at = std::stof(at_str);
            int q = std::stoi(q_str);

            // Se respeta el orden del constructor: Process(tag, at, bt, q)
            Process* newProcess = new Process(tag, at, bt, q);
            mainQueue.addProcessToQueue(newProcess, q - 1); 
        }
    }
    file.close();
    return true;
}

bool FileManager::saveResults(std::string filePath, std::vector<Process*>& completedProcesses) {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error al crear el archivo de resultados: " << filePath << std::endl;
        return false;
    }

    file << "Tag;WT;CT;RT;TAT\n";
    float totalWT = 0, totalCT = 0, totalRT = 0, totalTAT = 0;
    int n = completedProcesses.size();

    for (Process* p : completedProcesses) {
        file << p->getTag() << ";"
             << p->getWaitingTime() << ";"
             << p->getCompleteTime() << ";"
             << p->getResponseTime() << ";"
             << p->getTurnaroundTime() << "\n";

        totalWT += p->getWaitingTime();
        totalCT += p->getCompleteTime();
        totalRT += p->getResponseTime();
        totalTAT += p->getTurnaroundTime();
    }

    if (n > 0) {
        file << "\nPROMEDIOS:\n";
        file << "WT: " << totalWT / n << "\n";
        file << "CT: " << totalCT / n << "\n";
        file << "RT: " << totalRT / n << "\n";
        file << "TAT: " << totalTAT / n << "\n";
    }

    file.close();
    return true;
}