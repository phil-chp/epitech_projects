/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** SafeQueue
*/

#ifndef SAFEQUEUE_HPP_
    #define SAFEQUEUE_HPP_

    #include <queue>
    #include <mutex>
    #include <condition_variable>

template <typename T>
class SafeQueue {
    public:
        SafeQueue(unsigned int maxLen = 0)
            : _queue(), _mutex(), _cond()
            , _maxLen(maxLen)
        {}
        ~SafeQueue() = default;

        void enqueue(T t) {
            if (this->_maxLen > 0 && this->_queue.size() >= this->_maxLen) return;
            std::unique_lock<std::mutex> lock(this->_mutex);
            this->_queue.push(t);
            this->_cond.notify_one();
        }

        T dequeue() {
            std::unique_lock<std::mutex> lock(this->_mutex);
            this->_cond.wait(lock, [this] { return !this->_queue.empty(); });
            T t = this->_queue.front();
            this->_queue.pop();
            return (t);
        }

        bool try_dequeue(T &t) {
            std::unique_lock<std::mutex> lock(this->_mutex);
            if (this->_queue.empty()) return (false);
            t = this->_queue.front();
            // this->_queue.pop();
            return (true);
        }

        // void pop() {
        //     std::unique_lock<std::mutex> lock(this->_mutex);
        //     this->_queue.pop();
        // }

        void empty() {
            std::unique_lock<std::mutex> lock(this->_mutex);
            while (!this->_queue.empty()) this->_queue.pop();
        }

        bool isEmpty() {
            std::unique_lock<std::mutex> lock(this->_mutex);
            return (this->_queue.empty());
        }

        unsigned int size() {
            std::unique_lock<std::mutex> lock(this->_mutex);
            return (this->_queue.size());
        }

        void pop() {
            std::unique_lock<std::mutex> lock(this->_mutex);
            this->_queue.pop();
        }

    private:
        std::queue<T> _queue;
        std::mutex _mutex;
        std::condition_variable _cond;

        unsigned int _maxLen;
};

#endif /* !SAFEQUEUE_HPP_ */
