#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **logs;    
    size_t size;    
    size_t capacity;
} LogBook;

void initLogBook(LogBook *book, size_t capacity) {
    book->logs = (char **)malloc(capacity * sizeof(char *));
    book->size = 0;
    book->capacity = capacity;
}

void addLog(LogBook *book, const char *message) {
    if (book->size == book->capacity) {
        book->capacity *= 2;
        book->logs = (char **)realloc(book->logs, book->capacity * sizeof(char *));
    }
    book->logs[book->size] = (char *)malloc(strlen(message) + 1); // +1 for '\0'
    strcpy(book->logs[book->size], message);
    book->size++;
}

void printLogs(LogBook *book) {
    printf("Logs:\n");
    for (size_t i = 0; i < book->size; i++) {
        printf("%s\n", book->logs[i]);
    }
}

void freeLogBook(LogBook *book) {
    for (size_t i = 0; i < book->size; i++) {
        free(book->logs[i]);
    }
    free(book->logs);
    book->logs = NULL;
    book->size = 0;
    book->capacity = 0;
}

int main()
{
    LogBook logbook;
    initLogBook(&logbook, 2);
    int opt = 1;
    char buffer[256];

    while(opt != 3) {
        printf("Captain's Log Menu\n");
        printf("1 - Add log\n");
        printf("2 - Print logs\n");
        printf("3 - Exit\n");
        scanf("%d", &opt);
        getchar();

        if(opt < 1 || opt > 3) {
            printf("Option not available\n");
            continue;
        }

        if(opt == 1) {
            printf("Type the new log below:\n");
            scanf("%255[^\n]%*c", buffer);

            addLog(&logbook, buffer);
            printf("Log added, Captain!\n");
        }

        if(opt == 2) {
            printLogs(&logbook);
        }
    }

    printf("Arr Captain, see you in another trip!\n");
    freeLogBook(&logbook);

    return 0;
}