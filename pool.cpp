#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <atomic>
#include<future>

class ThreadPool {
public:
//构造函数
    ThreadPool(size_t num_threads) : stop(false)//初始化 stop 为 false
    {
        for(size_t i = 0; i < num_threads; ++i) 
        {
            workers.emplace_back([this] 
            {
                for(;;) 
                {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(this->queue_mutex);
                        this->condition.wait(lock,
                            [this]{ return this->stop || !this->tasks.empty(); });
                        if(this->stop && this->tasks.empty())
                            return;
                        task = std::move(this->tasks.front());
                        this->tasks.pop();
                    }
                    task();
                }
            });
        }
    }
// 添加任务
    template<class F, class... Args>
    void enqueue(F&& f, Args&&... args) {
        auto task = std::make_shared<std::packaged_task<void()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            tasks.emplace([task](){ (*task)(); });
        }
        condition.notify_one();
    }
// 关闭线程池
    void shutdown() {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            stop = true;
        }
        condition.notify_all();//通知所有等待线程
        for(std::thread &worker: workers)
            worker.join();
    }

private:
    std::vector<std::thread> workers;// 工作线程容器
    std::queue<std::function<void()>> tasks;// 任务队列
    std::mutex queue_mutex;// 队列互斥锁
    std::condition_variable condition;// 条件变量
    bool stop;// 停止标志
};

// 示例任务：矩阵相乘（简化版）
void matrix_multiply(const std::vector<std::vector<int>>& a,
                    const std::vector<std::vector<int>>& b,
                    std::vector<std::vector<int>>& result,
                    std::function<void(const std::vector<std::vector<int>>&)> callback) {
    // 简单实现矩阵相乘（实际应添加边界检查）
    size_t n = a.size();
    result.resize(n, std::vector<int>(n, 0));
    
    for(size_t i = 0; i < n; ++i) {
        for(size_t j = 0; j < n; ++j) {
            for(size_t k = 0; k < n; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    callback(result);
}
int main() {
    const size_t MATRIX_SIZE = 3;
    const size_t NUM_TASKS = 10;
    const size_t POOL_SIZE = 4;
    
    ThreadPool pool(POOL_SIZE);
    
    // 生成测试矩阵
    auto generate_matrix = []() {
        std::vector<std::vector<int>> mat(MATRIX_SIZE, std::vector<int>(MATRIX_SIZE, 1));
        return mat;
    };
    
    // 任务完成回调
    auto task_callback = [](const std::vector<std::vector<int>>& result) {
        std::cout << "计算结果：" << std::endl;
        for(const auto& row : result) {
            for(int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "----------------------" << std::endl;
    };
    
    // 提交任务
    for(size_t i = 0; i < NUM_TASKS; ++i) {
        auto a = generate_matrix();
        auto b = generate_matrix();
        std::vector<std::vector<int>> result;
        
        pool.enqueue([a, b, &result, task_callback]() {
            matrix_multiply(a, b, result, task_callback);
        });
    }
    
    // 等待所有任务完成
    pool.shutdown();
    return 0;
}