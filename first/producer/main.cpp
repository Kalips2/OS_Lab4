#include <unistd.h>
#include <iostream>

int main() {
    char data[] = "Some data we need to keep safety!!";

    std::cout << "Pid is " << getpid() << std::endl;
    std::cout << "Adress is " << (void *) data << std::endl;
    std::cout << "Size: " << sizeof(data) << std::endl;

    // infinity waiter in order to not close process.
    std::cin.get();

    return 0;
}