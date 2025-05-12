#include <iostream>
#include <functional>

int add(int a, int b) {
    return a + b;
}

int main() {
    std::function<int(int, int)> func = add;
    std::cout << func(3, 4) << std::endl; // 输出 7
    return 0;
}
#include <iostream>
#include <functional>

int main() {
    std::function<int(int, int)> func = [](int a, int b) { return a * b; };
    std::cout << func(3, 4) << std::endl; // 输出 12
    return 0;
}
#include <iostream>
#include <functional>

int multiply(int a, int b, int c) {
    return a * b * c;
}

int main() {
    auto bound_multiply = std::bind(multiply, std::placeholders::_1, std::placeholders::_2, 2);
    std::function<int(int, int)> func = bound_multiply;
    std::cout << func(3, 4) << std::endl; // 输出 24
    return 0;
}
#include <iostream>
#include <future>

int compute(int a, int b) {
    return a + b;
}

int main() {
    // 启动一个异步任务
    std::future<int> result = std::async(std::launch::async, compute, 2, 3);

    // 阻塞等待结果
    std::cout << "Result: " << result.get() << std::endl; // 输出 Result: 5

    return 0;
}
#include <iostream>
#include <future>
#include <thread>

int compute(int a, int b) {
    return a + b;
}

int main() {
    // 创建一个 packaged_task
    std::packaged_task<int(int, int)> task(compute);

    // 获取与任务关联的 future
    std::future<int> result = task.get_future();

    // 在一个新线程中执行任务
    std::thread t(std::move(task), 2, 3);
    t.detach();

    // 阻塞等待结果
    std::cout << "Result: " << result.get() << std::endl; // 输出 Result: 5

    return 0;
}
#include <iostream>
#include <type_traits>

int add(int a, int b) {
    return a + b;
}

int main() {
    // 使用 std::invoke_result 推断 add 函数的返回类型（参数为 int 和 int）
    using ReturnType = std::invoke_result<decltype(add), int, int>::type;
    std::cout << "ReturnType is: " << typeid(ReturnType).name() << std::endl;
    // 输出可能为 "i"（表示 int）

    return 0;
}