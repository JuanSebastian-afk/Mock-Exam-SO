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
    // Leer línea por línea
    while (std::getline(file, line)) {
        // Ignorar encabezados o líneas vacías
        if (line.empty() || line[0] == '#' || line.find("Tag") != std::string::npos) {
            continue;
        }

        std::stringstream ss(line);
        std::string tag, at_str, bt_str, q_str;
        
        // Asumiendo formato: Tag;ArrivalTime;BurstTime;Queue
        std::getline(ss, tag, ';');
        std::getline(ss, at_str, ';');
        std::getline(ss, bt_str, ';');
        std::getline(ss, q_str, ';');

        if (!tag.empty()) {
            float at = std::stof(at_str);
            float bt = std::stof(bt_str);
            int q = std::stoi(q_str);

            Process* newProcess = new Process(tag, at, bt, q);
            // El proceso ingresa por defecto a la cola que indica el archivo
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