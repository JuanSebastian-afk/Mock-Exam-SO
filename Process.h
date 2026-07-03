#pragma once

/**
 * @file Process.h
 * @author Juan Sebastian Valencia Quinchua (juan.quinchua@correounivalle.edu.com)
 * @brief Esta clase representa un proceso
 * @version 0.1
 * @date 2026-07-03
 * 
 * @copyright Copyright (c) 2026
 * 
 */



 class Process{

    private:
        std::string tag;
        float arraibalTime
        float burstTime;
        float waytingTime;
        float turnaroundTime;
        float completeTime;
        int queue;
        float remainingBurstTime;

    public:
        /**
         * @brief Construct a new Process object
         * 
         * @param tag 
         * @param AT (Arraibal time)
         * @param BT (Burst time)
         * @param Q (Queue)
         */
        Process(std::string tag, float AT, float BT, int Q);

        /**
         * @brief Get the Tag object
         * 
         * @return float
         */
        float getTag();

        /**
         * @brief Get the Arrival Time object
         * 
         * @return float 
         */
        float getArrivalTime();

        /**
         * @brief Get the Burst Time object
         * 
         * @return float 
         */
        float getBurstTime();

        /**
         * @brief Get the Witing Time object
         * 
         * @return float 
         */
        float getWitingTime();

        /**
         * @brief Set the Witing Time object
         * 
         */
        void setWitingTime();

        /**
         * @brief Get the Turnaround Time object
         * 
         * @return float 
         */
        float getTurnaroundTime();

        /**
         * @brief Set the Turnaround Time object
         * 
         * @return float 
         */
        float setTurnaroundTime();

        /**
         * @brief Get the Response Time object
         * 
         * @return float 
         */
        float getResponseTime();

        /**
         * @brief Set the Response Time object
         * 
         */
        void setResponseTime();

        /**
         * @brief Get the Complete Time object
         * 
         * @return float 
         */
        float getCompleteTime();

        /**
         * @brief Set the Complete Time object
         * 
         */
        void setCompleteTime();

        /**
         * @brief Get the Remaining Burst Time object
         * 
         * @return float 
         */
        float getRemainingBurstTime();

        /**
         * @brief Set the Remaining Burst Time object
         * 
         */
        void setRemainingBurstTime();

        /**
         * @brief Get the Queue object
         * 
         * @return int 
         */
        int getQueue();

 };