#include <thread>
#include <chrono>
#include <mutex>

std::mutex pencil;
unsigned int garlic_count = 0;
void shopper() {
    for (int i = 0; i < 10; i++) {
        printf("Shopper %lu is thinking...\n", std::this_thread::get_id());
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        pencil.lock();
        garlic_count++;
        pencil.unlock();
    }
}

int main() {
    std::thread barron(shopper);
    std::thread olivia(shopper);
    barron.join();
    olivia.join();
    printf("We should buy %u garlic.\n", garlic_count);
    return 0;
}
