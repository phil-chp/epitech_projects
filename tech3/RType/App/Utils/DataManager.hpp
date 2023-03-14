/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** DataManager
*/

#ifndef DATAMANAGER_HPP_
    #define DATAMANAGER_HPP_

    #include <map>
    #include <iostream>
    #include <array>

template <typename T, typename K>
class DataManager {
    private:
        DataManager() {};

    public:
        static DataManager &getInstance() {
            static DataManager instance;
            return (instance);
        }

        ~DataManager() {};

        void unload() {};

        template <typename U>
        void insertData(U &data) {
            (void)data;
        };

        void insertData(T const &data, K const &name) {
            if (this->_datas.find(name) != this->_datas.end()) {
                throw(std::exception());
            }
            this->_datas.insert(std::make_pair(name, data));
        };

        T getData(K const &name) {
            if (this->_datas.find(name) == this->_datas.end()) {
                throw(std::exception());
            }
            return (this->_datas[name]);
        };

        DataManager(const DataManager &) = delete;
        DataManager &operator=(const DataManager &) = delete;

    private:
        std::map<K const, T> _datas;
};


#endif /* !DATAMANAGER_HPP_ */
