CC=gcc

ROOT_DIR = $(shell pwd)
SUBDIRS  = $(shell ls -F | grep "\/" | sed 's/\///g' | sed 's/target//g')
OBJ_DIR  = target/obj
BIN_DIR  = target/bin

BIN      = list_test

CUR_SOURCES = $(wildcard *.c)
CUR_OBJS    = $(patsubst %.c, %.o, $(CUR_SOURCES))

export CC BIN ROOT_DIR OBJ_DIR BIN_DIR


.PHONY:all
all:$(SUBDIRS) TARGET

$(SUBDIRS) : ECHO
	make -C $@

TARGET : ECHO
	make -C target 

ECHO:
	@echo $(SUBDIRS)

$(CUR_OBJS) : %.o : %.c
	$(CC) -c $^ -o $(ROOT_DIR)/$(OBJ_DIR)/$@


.PHONY : clean
clean:
	-rm -rf $(ROOT_DIR)/$(OBJ_DIR)/*.o
	-rm -rf $(ROOT_DIR)/$(BIN_DIR)/$(BIN)
