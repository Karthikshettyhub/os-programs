#include <stdio.h>

int main() {
    int buffer[10], bufsize = 10;
    int in = 0, out = 0;
    int produce, consume;
    int choice = 0;

    while(choice != 3) {
        printf("\n1. Produce\t2. Consume\t3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                if((in + 1) % bufsize == out)
                    printf("Buffer is Full\n");
                else {
                    printf("Enter value to produce: ");
                    scanf("%d", &produce);
                    buffer[in] = produce;
                    in = (in + 1) % bufsize; 
                }
                break;

            case 2: 
                if(in == out)
                    printf("Buffer is Empty\n");
                else {
                    consume = buffer[out];
                    printf("Consumed value: %d\n", consume);
                    out = (out + 1) % bufsize; 
                }
                break;
        }
    }

    return 0;
}
