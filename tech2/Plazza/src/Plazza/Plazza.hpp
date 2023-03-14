/*
** EPITECH PROJECT, 2022
** Plazza (Workspace)
** File description:
** Plazza
*/

#ifndef PLAZZA_HPP_
    #define PLAZZA_HPP_

    #include "Reception/Reception.hpp"
    #include "Com/ComManager.hpp"
    #include "Kitchen/KitchenManager.hpp"

class Plazza {
    public:
        Plazza(int multiplier, int cooks, int ingredientDelay);
        ~Plazza() = default;

        void run();

    private:
        int _multiplier;
        int _cooks;
        int _ingredientDelay;

        std::unique_ptr<Reception> _reception;
        std::shared_ptr<ComManager> _cManager;
        std::unique_ptr<KitchenManager> _kManager;
};

#endif /* !PLAZZA_HPP_ */
