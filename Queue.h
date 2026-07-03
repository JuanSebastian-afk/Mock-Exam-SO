#pragma once
/**

 * @file Queue.h
 * @author Juan Sebastian Valencia Quinchua (juan.quinchua@correounivalle.edu.com)
 * @brief 
 * @version 0.1
 * @date 2026-07-03
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <vector>
#include "Process.h"

class Queue{

    private:
        std::vector<Process*> queues[3];

    public:
        /**
         * @brief 
         * 
         * @param process 
         * @param queueIndex 
         */
        void addPorcessToQueue(Process* process, int queueIndex);

        /**
         * @brief 
         * 
         * @param tag 
         */
        void processComplete(std::string tag);

        /**
         * @brief Get the Queue object
         * 
         * @param queueIndex 
         * @return std::vector<Process*> 
         */
        std::vector<Process*> getQueue(int queueIndex);

        /**
         * @brief Get the Process object
         * 
         * @param processIndex 
         * @return Process* 
         */
        Process* getProcess(int processIndex);

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool emptyQueue();

    
};