#pragma once

/**
 * @file Scheduler.h
 * @author Juan Sebastian Valencia Quinchua (juan.quinchua@correounivalle.edu.com)
 * @brief 
 * @version 0.1
 * @date 2026-07-03
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include "Queue.h"
#include <vector>

class Scheduler{

    private:
        Queue& queue;
        int globalTime;
        std::vector<Process*> historyProcesses;

    public:
        /**
         * @brief Construct a new Scheduler object
         * 
         * @param mainQueue 
         */
        Scheduler(Queue& mainQueue);

        /**
         * @brief 
         * 
         * @return Process* 
         */
        Process* chooseProcessToRun();

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool verifyFirstQueue();

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool verifySecondQueue();

        /**
         * @brief 
         * 
         * @param targetQueue 
         */
        void runToRoundRobinAlgorithm(std::vector<Process*> targetQueue);

        /**
         * @brief 
         * 
         * @param targetQueue 
         */
        void runToShortJobFirstAlgorithm(std::vector<Process*> targetQueue);

        /**
         * @brief 
         * 
         */
        void executeFirstQueue();

        /**
         * @brief 
         * 
         */
        void executeSecondQueue();

        /**
         * @brief 
         * 
         */
        void executeThirdtQueue();

        /**
         * @brief 
         * 
         */
        void runAlgorithm();

        /**
         * @brief Set the Metrics object
         * 
         */
        void setMetrics();
        
};