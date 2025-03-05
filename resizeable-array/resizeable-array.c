#include <stdio.h>
#include <string.h>

struct log {
    char move[50];
    char desc[150];
};

int main() {

    struct log logs[10];

    struct log log1;
    strcpy(log1.move, "WIT");
    strcpy(log1.desc, "Widthdrawl of $ 100");
    
    struct log log2;
    strcpy(log2.move, "WIT");
    strcpy(log2.desc, "Widthdrawl of $ 200");
    
    struct log log3;
    strcpy(log3.move, "WIT");
    strcpy(log3.desc, "Widthdrawl of $ 300");
    
    struct log log4;
    strcpy(log4.move, "WIT");
    strcpy(log4.desc, "Widthdrawl of $ 400");

    logs[0] = log1;
    logs[1] = log2;
    logs[2] = log3;
    logs[3] = log4;


    for (int i = 0; i < 4; i++)
    {
        printf("%s - ", logs[i].move);
        printf("%s\n", logs[i].desc);
    }
    

    return 0;
}

void addToArray(struct log logs[], struct log newLog) {
    int i = 0;
    
}