#ifndef INTF_TEST__STUB_H
#define INTF_TEST__STUB_H

#include <queue>
#include <functional>

namespace test {

template<typename T>
using function_fifo_t = std::queue<std::function<T>>;

// helper for stub functions
template<typename T>
std::function<T> get(std::queue<std::function<T>>& queue)
{
    std::function<T> f = queue.front();
    queue.pop();
    return f;
}

} // namespace test

#endif // INTF_TEST__STUB_H