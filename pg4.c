#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

    int fd;
    char *myfifo = "/tmp/myfifo";

    /* Create FIFO (named pipe) */
    mkfifo(myfifo, 0666);

    printf("Writer: Waiting for reader...\n");

    /* Open FIFO for writing */
    fd = open(myfifo, O_WRONLY);

    /* Write message to FIFO */
    write(fd, "Hi", sizeof("Hi"));

    printf("Writer: Message sent\n");

    /* Close FIFO */
    close(fd);

    /* Remove FIFO */
    unlink(myfifo);

    return 0;
}


#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUF 1024

int main() {

    int fd;
    char buf[MAX_BUF];
    char *myfifo = "/tmp/myfifo";

    /* Open FIFO for reading */
    fd = open(myfifo, O_RDONLY);

    /* Read message from FIFO */
    read(fd, buf, MAX_BUF);

    /* Display message */
    printf("Writer: %s\n", buf);

    /* Close FIFO */
    close(fd);

    return 0;
}
