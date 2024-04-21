#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

int main() {
    // get the name from  sudo cat /proc/bus/input/devices
    int fd;
    fd = open("/dev/input/event4", O_RDONLY);
    if (fd == -1) {
        perror("Unable to open input device");
        exit(EXIT_FAILURE);
    }

    struct input_event ev;
    while (1) {
        if (read(fd, &ev, sizeof(struct input_event)) < sizeof(struct input_event)) {
            perror("Error reading input event");
            exit(EXIT_FAILURE);
        }

        if (ev.type == EV_KEY) {
            printf("Key code is %d\n", ev.code);
        }
    }

    close(fd);
    return 0;
}