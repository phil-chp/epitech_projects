/*
** EPITECH PROJECT, 2022
** PDG-Rush3 (Workspace)
** File description:
** CPUModule
*/

#ifndef CPUMODULE_HPP_
#define CPUMODULE_HPP_

#include <iostream>
#include <cstdint>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <ctime>
#include <list>


namespace CPUModule {
    // The amount of elements to keep inside an array (1 value/s)
    // So MAX_KEEP_COUNT elements maximum.
    // For example in the CPUModule you will store
    // the percentages of CPU usage over the time of MAX_KEEP_COUNT.
    const size_t MAX_KEEP_COUNT = 60;

    class Core;

    typedef struct CPUModuleConfig {
        std::vector<CPUModule::Core> _cores;
    } CPUModuleConfig;

    typedef struct CoreData {
        int index;
        int total;
        int work;
    } CoreData;

    class Core {
        public:
            Core();
            Core(size_t index);
            ~Core();

            void setData(CoreData *coreData);
            CoreData *getData();

            size_t getIndex();
            size_t getPercent();

            void addPercent(int percent);
            void resizePercent();

        private:
            size_t _index;
            CoreData *_data;
            std::vector<int> _percent;
    };

    class Cores {
        public:
            Cores();
            ~Cores();

            std::vector<Core> getCores();
            Core *getCore(size_t index);
            CPUModuleConfig *getConfig();
            void setConfig();
            void refresh();
        private:
            void _buildNewCores(std::vector<CoreData> dataVector);
            void _populateCores(std::vector<CoreData> dataVector);
            void _getData(std::vector<CoreData> &cpuData);

            CPUModuleConfig *_config;
            std::vector<Core> _cores;
            size_t _current_index;
            std::time_t _timestamp;
    };
};

#endif /* CPUMODULE_HPP_ */
