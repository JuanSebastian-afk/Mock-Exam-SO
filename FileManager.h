#pragma once

/**
 * @file FileManager.h
 * @author Juan Sebastian Valencia Quinchua (juan.quinchua@correounivalle.edu.com)
 * @brief 
 * @version 0.1
 * @date 2026-07-03
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include "Queue.h"

class FileManager{

    public:
    /**
     * @brief 
     * 
     * @param filePath 
     * @param mainQueue 
     * @return true 
     * @return false 
     */
    bool loadProcesses(std::string filePath, Queue& mainQueue);

    /**
     * @brief 
     * 
     * @param filePath 
     * @param completedProcesses 
     * @return true 
     * @return false 
     */
    bool saveResults(std::string filePath, std::vector<Process*>& completedProcesses);

};