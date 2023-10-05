#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    // Check if a command is provided
    if (argc < 2) {
        printf(2, "Usage: time1 <command> [args]\n");
        exit();
    }

    // Record the start time
    uint start_time = uptime();

    // Create a child process to execute the specified command
    int pid = fork();

    if (pid < 0) {
        printf(2, "fork failed\n");
    } else if (pid == 0) {
        // This is the child process
        exec(argv[1], argv + 1);
        printf(2, "exec failed\n");
        exit();
    } else {
        // This is the parent process
        int status;
        wait(&status);

        // Record the end time
        uint end_time = uptime();

        // Calculate and print elapsed time
        printf(1, "Time: %d ticks\n", end_time - start_time);
    }

    exit();
}