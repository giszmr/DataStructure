SUBDIRS = $(shell ls -F | grep "\/" | sed 's/\///g')
CUR_SOURCES = $(wildcard *.c)
CUR_OBJS    = $(patsubst %.c, %.o, $(CUR_SOURCES))

.PHONY : all

all : $(SUBDIRS) $(CUR_OBJS)

$(SUBDIRS) : ECHO
	make -C $@

ECHO:
	@echo $(SUBDIRS)

$(CUR_OBJS) : %.o : %.c
	$(CC) -c $^ -o $(ROOT_DIR)/$(OBJ_DIR)/$@
