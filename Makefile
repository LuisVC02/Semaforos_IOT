
CC ?= gcc

APP_NAME_PIPE_SND   = semaphore_rcv
OBJ_FILES_PIPE_SND  = semaphore_rcv.o

APP_NAME_PIPE_RCV  = semaphore_send
OBJ_FILES_PIPE_RCV = semaphore_send.o

LIBS = .
LIB = pthread

all: $(APP_NAME_PIPE_SND) $(APP_NAME_PIPE_RCV)

$(APP_NAME_PIPE_SND): $(OBJ_FILES_PIPE_SND)
	$(CC) $^ -o $@ -L$(LIBS) -l$(LIB)


$(APP_NAME_PIPE_RCV): $(OBJ_FILES_PIPE_RCV)
	$(CC) $^ -o $@ -L$(LIBS) -l$(LIB)

%.o: %.c
	$(CC) -o $@ -c $^ -g


clean:
	rm *.o $(APP_NAME_PIPE_SND) $(APP_NAME_PIPE_RCV)

fresh:
	make clean
	make all
