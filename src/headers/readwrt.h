#ifndef READWRT_H
#define READWRT_H

#include <semaphore.h>

#define WR_CYCLES 640 // Nombre de cycles des writers
#define RD_CYCLES 2560 // Nombres de cycles des readers

mutex_t mutex_readcount; // protège readcount
mutex_t mutex_writecount; // protège writecount
mutex_t z; // un seul reader en attente
semaphore_t wsem;       // accès exclusif à la db
semaphore_t rsem;       // pour bloquer des readers
int readcount=0;
int writecount=0;

int read_total=0;
int write_total=0;

void * writer(void* args);

void * reader(void* args);


#endif // READWRT_h