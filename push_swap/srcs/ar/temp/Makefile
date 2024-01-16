TARGET = srcs/c.c \
        srcs/dir1/a.c \
        srcs/dir1/dir2/b.c

OBJS = $(patsubst srcs/%.c,objs/%.o,$(TARGET))

temp: $(OBJS)

objs/%.o: srcs/%.c
	@echo $< "=>" $@
