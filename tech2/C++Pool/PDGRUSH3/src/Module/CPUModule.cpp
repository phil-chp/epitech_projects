

/*
** EPITECH PROJECT, 2022
** PDG-Rush3 (Workspace)
** File description:
** MonitorCoreModule
*/

#include "CPUModule.hpp"

// -------------------------------------------------------------------------- //
// ---------------------------------- Core ---------------------------------- //
// -------------------------------------------------------------------------- //

// ------------------------------ Subroutines ------------------------------- //

CPUModule::Core::Core() : _index(0), _data(nullptr) {}

CPUModule::Core::Core(size_t index) : _index(index) {}

CPUModule::Core::~Core() {}

// --------------------------- Getters & Setters ---------------------------- //

size_t CPUModule::Core::getIndex()
{
    return (_index);
}

size_t CPUModule::Core::getPercent()
{
    return (_percent.size() != 0 ? _percent.front() : -1);
}

void CPUModule::Core::addPercent(int percent)
{
    _percent.push_back(percent);
    resizePercent();
}

void CPUModule::Core::setData(CoreData *coreData)
{
    _data = coreData;
}

CPUModule::CoreData *CPUModule::Core::getData()
{
    return (_data != nullptr ? _data : nullptr);
}


// -------------------------------- Methods --------------------------------- //

void CPUModule::Core::resizePercent()
{
    int difference;

    difference = _percent.size() - MAX_KEEP_COUNT;
    for (; difference > 0; --difference) {
        _percent.erase(_percent.begin());
    }
}

// -------------------------------------------------------------------------- //
// --------------------------------- Cores ---------------------------------- //
// -------------------------------------------------------------------------- //

// ------------------------------ Subroutines ------------------------------- //

CPUModule::Cores::Cores() : _current_index(0)
{
    this->refresh();
}

CPUModule::Cores::~Cores() {}

// --------------------------- Getters & Setters ---------------------------- //

std::vector<CPUModule::Core> CPUModule::Cores::getCores()
{
    return (_cores);
}

CPUModule::Core *CPUModule::Cores::getCore(size_t index)
{
    if (_cores.size() <= index) {
        return (&_cores[index]);
    }
    return (NULL);
}

// -------------------------------- Methods --------------------------------- //

void _getCpuIndex(int &index, std::istringstream &iss)
{
    std::string line = "";

    iss >> line;
    index = line[3] - 47;
    if (index < 0) {
        index = 0;
    }
}

void _getCpuTime(int &total, int &work, std::istringstream &iss)
{
    int token;

    for (size_t tokenCount = 0; tokenCount < 10; ++tokenCount) {
        iss >> token;
        if (tokenCount < 3) {
            work += token;
        }
        total += token;
    }
}

bool _getProcessorStats(std::fstream &fs)
{
    fs.open("/proc/stat", std::ios::in);
    if (!fs.is_open()) {
        std::cerr << "[ERROR] Couldn't fetch CPU stats." << std::endl;
        return (false);
    }
    return (true);
}

void CPUModule::Cores::_getData(std::vector<CPUModule::CoreData> &cpuData)
{
    std::fstream fs;

    _getProcessorStats(fs);
    for (std::string line; std::getline(fs, line); ) {
        if (line.compare(0, 3, "cpu") == 0) {
            std::istringstream iss(line);
            CoreData data;
            data.total = 0;
            data.work = 0;

            _getCpuIndex(data.index, iss);
            _getCpuTime(data.total, data.work, iss);
            cpuData.push_back(data);
        }
    }
    fs.close();
}

void CPUModule::Cores::_buildNewCores(std::vector<CPUModule::CoreData> dataVector)
{
    for (size_t i = 0; i < dataVector.size(); i++) {
        CPUModule::CoreData data = dataVector[i];
        Core core(i);
        core.setData(&data);
        _cores.push_back(core);
    }
}

void CPUModule::Cores::_populateCores(std::vector<CPUModule::CoreData> dataVector)
{
    for (size_t i = 0; i < _cores.size(); i++) {
        CPUModule::CoreData &data = dataVector[i];
        CoreData *oldData = _cores[i].getData();

        int active = data.total - oldData->total;
        int idle   = data.work  - oldData->work;
        int result = (active + idle != 0
            ? 100 * idle / (active + idle)
            : 0);
        _cores[i].addPercent(result);
        _cores[i].setData(&data);
    }
}

void CPUModule::Cores::refresh()
{
    std::vector<CPUModule::CoreData> dataVector;

    _getData(dataVector);
    if (_cores.size() == 0) {
        _buildNewCores(dataVector);
    } else {
        auto now = std::chrono::system_clock::now();
        std::time_t time_old = std::chrono::system_clock::to_time_t(now);
        if (time_old - _timestamp <= 1) {
            return;
        }
        _populateCores(dataVector);
    }
}

CPUModule::CPUModuleConfig *CPUModule::Cores::getConfig() {
    return (this->_config);
}

void CPUModule::Cores::setConfig() {
    CPUModuleConfig *config = new CPUModuleConfig;
    config->_cores = _cores;
}
