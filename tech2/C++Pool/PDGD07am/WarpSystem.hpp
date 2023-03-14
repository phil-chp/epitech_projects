/*
** EPITECH PROJECT, 2022
** PDG-D7-AM (Workspace)
** File description:
** WarpSystem
*/

#pragma once

namespace WarpSystem {
    class QuantumReactor {
        public:
            QuantumReactor();
            ~QuantumReactor();
            bool isStable();
            void setStability(bool stability);

        private:
            bool _stability;
    };

    class Core {
        public:
            Core(QuantumReactor *coreReactor);
            ~Core();
            QuantumReactor *checkReactor();

        private:
            QuantumReactor *_coreReactor;
    };
};
