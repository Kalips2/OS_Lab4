#include <iostream>
#include <iomanip>
#include <fcntl.h>
#include <unistd.h>

// ./a.out pid address size
int main(int argc, char **argv) {
    std::string pid = "23853";
    std::string address = "0x7ffd104f2d60";
    std::string size_string = "35";

    auto start = std::stoull(address, nullptr, 16);
    auto size = std::stoull(size_string);
    auto filename = "/proc/" + pid + "/mem";

    std::cout << "Filename: " << filename << std::endl;
    std::cout << "Addr is: " << (void *) start << std::endl;
    std::cout << "Size: " << size << "\n";

    int fd = open(filename.c_str(), O_RDONLY);
    if(fd == -1) {
        return -2;
    }

    off_t res = lseek(fd, (off_t)start, SEEK_SET);
    if(res == (off_t)-1) {
        return -3;
    }

    std::string output(size, 0);
    auto read_res = read(fd, output.data(), output.size());
    std::cout << "Data is " << std::quoted(output) <<"\n";
    return 0;
}