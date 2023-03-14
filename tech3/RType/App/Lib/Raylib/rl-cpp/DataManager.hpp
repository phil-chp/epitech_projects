/*
** EPITECH PROJECT, 2022
** RType
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
    public:
        static DataManager &getInstance()
        {
            static DataManager instance;
            return (instance);
        }

        ~DataManager() {};

        template <typename U>
        void insertData(U &data) {
            (void)data;
            // std::cout << "should not have reached there" << std::endl;
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
        DataManager & operator=(const DataManager &) = delete;

    protected:
        DataManager() {};

        std::map<K const, T> _datas;
};


#endif /* !DATAMANAGER_HPP_ */
