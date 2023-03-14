/*
** EPITECH PROJECT, 2022
** Plazza (Workspace)
** File description:
** SafeQueue
*/

#ifndef SAFEQUEUE_HPP_
    #define SAFEQUEUE_HPP_

class ISafeQueue {
    public:
    virtual ~ISafeQueue() = default;
    virtual void push(int value) = 0;
    virtual bool tryPop(int & value) = 0;
};

class SafeQueue : public ISafeQueue {
    public:
        SafeQueue();
        ~SafeQueue();

    private:
};

#endif /* !SAFEQUEUE_HPP_ */
