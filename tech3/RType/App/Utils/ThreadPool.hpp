/*
** EPITECH PROJECT, 2022
** ThreadPool
** File description:
** ThreadPool
*/


#ifndef THREADPOOL_HPP_
    #define THREADPOOL_HPP_

    #include <condition_variable>
    #include <functional>
    #include <iostream>
    #include <vector>
    #include <thread>
    #include <queue>
    #include <mutex>

class ThreadPool {
    public:
        ThreadPool(unsigned int maxThreads = 18) // std::thread::hardware_concurrency()
            : _maxThreads(maxThreads), _shouldTerminate(false)
        {
            this->_threads.resize(maxThreads);
        }
        ~ThreadPool() = default;

        void start() {
            // std::cout << "Creating " << this->_threads.size() << " threads" << std::endl;
            for (unsigned int i = 0; i < this->_maxThreads; ++i) {
                this->_threads[i] = std::thread(std::bind(&ThreadPool::_threadLoop, this));
            }
        }

        void queueJob(const std::function<void()> &job) {
            {
                std::unique_lock<std::mutex> lock(this->_queueMutex);
                this->_jobs.push(job);
            }
            this->_cond.notify_one();
        }

        void stop() {
            {
                std::unique_lock<std::mutex> lock(this->_queueMutex);
                this->_shouldTerminate = true;
            }
            this->_cond.notify_all();
            for (std::thread& active_thread : this->_threads) {
                active_thread.join();
            }
            this->_threads.clear();
        }

        bool busy() {
            bool poolbusy;
            {
                std::unique_lock<std::mutex> lock(this->_queueMutex);
                poolbusy = !this->_jobs.empty();
            }
            return poolbusy;
        }

        void operator=(const ThreadPool &tp) {
            this->_maxThreads      = tp._maxThreads;
            this->_threads.resize(tp._maxThreads);
            this->_shouldTerminate = false;
        }


    private:
        void _threadLoop() {
            while (true) {
                std::function<void()> job;
                {
                    std::unique_lock<std::mutex> lock(this->_queueMutex);
                    this->_cond.wait(lock, [this] {
                        return !this->_jobs.empty() || this->_shouldTerminate;
                    });
                    if (this->_shouldTerminate) return;
                    job = this->_jobs.front();
                    this->_jobs.pop();
                }
                job();
            }
        }

        unsigned int _maxThreads;
        bool _shouldTerminate;

        std::queue<std::function<void()>> _jobs;

        std::mutex _queueMutex;
        std::condition_variable _cond;
        std::vector<std::thread> _threads;
};

#endif /* !THREADPOOL_HPP_ */
