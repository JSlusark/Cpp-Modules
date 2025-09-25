#include "../headers/utils.hpp"
#include "../headers/Array.hpp"

int main() {
    // 0) default
    Array<int> a0;
    std::cout << "a0.size=" << a0.size() << "\n";

    // 1) sized, value-initialized
    Array<int> ai(5);
    for (unsigned int i = 0; i < ai.size(); ++i) std::cout << ai[i] << " ";
    std::cout << "\n";

    // 2) write + read
    for (unsigned int i = 0; i < ai.size(); ++i) ai[i] = i * 10;
    for (unsigned int i = 0; i < ai.size(); ++i) std::cout << ai[i] << " ";
    std::cout << "\n";

    // 3) copy ctor deep copy
    Array<int> bi(ai);
    bi[0] = 999;
    std::cout << "ai[0]=" << ai[0] << " bi[0]=" << bi[0] << "\n";

    // 4) assignment deep copy
    Array<std::string> as(3);
    as[0] = "hi"; as[1] = "there"; as[2] = "!";
    Array<std::string> bs;
    bs = as;
    bs[1] = "world";
    std::cout << as[0] << " " << as[1] << " " << as[2] << "\n";
    std::cout << bs[0] << " " << bs[1] << " " << bs[2] << "\n";

    // 5) bounds check
    try {
        std::cout << ai[ai.size()] << "\n"; // out of bounds
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << "\n";
    }
}
