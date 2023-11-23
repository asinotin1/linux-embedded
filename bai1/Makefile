.PHONY: all clean
LIB_NAME := luan
CUR_DIR 	:= .
BIN_DIR 	:= $(CUR_DIR)/bin
INC_DIR 	:= $(CUR_DIR)/inc
OBJ_DIR 	:= $(CUR_DIR)/obj
SRC_DIR 	:= $(CUR_DIR)/src

LIB_DIR 	:= $(CUR_DIR)/lib
LIB_STATIC_DIR 	:= $(LIB_DIR)/static
LIB_SHARED_DIR 	:= $(LIB_DIR)/shared

INC_FLAGS	:= -I $(INC_DIR)
CC			:= gcc

mk_objs_static:
	$(cc) -c $(CUR_DIR)/main.c -o $(OBJ_DIR)/main.o $(INC_FLAGS)
	$(cc) -c -$(SRC_DIR)/hello.c -o $(OBJ_DIR)/hello.o $(INC_FLAGS)
	$(cc) -c -$(SRC_DIR)/hi.c -o $(OBJ_DIR)/hi.o $(INC_FLAGS)
mk_static:
	ar rcs $(LIB_STATIC_DIR)libluan.a $(OBJ_DIR)/hello.o $(OBJ_DIR)/hi.o

mk_objs_shared:
	$(cc) -c $(CUR_DIR)/main.c -o $(OBJ_DIR)/main.o $(INC_FLAGS)
	$(cc) -c -fPIC $(SRC_DIR)/hello.c -o $(OBJ_DIR)/hello.o $(INC_FLAGS)
	$(cc) -c -fPIC $(SRC_DIR)/hi.c -o $(OBJ_DIR)/hi.o $(INC_FLAGS)

mk_shared:
	$(CC) -shared $(OBJ_DIR)/hello.o $(OBJ_DIR)/hi.o -o $(LIB_SHARED_DIR)/lib$(LIB_NAME).so
install_shared:
	cp -f $(LIB_SHARED_DIR)/lib$(LIB_NAME).so /usr/lib
all: mk_objs_shared mk_shared install_shared
	$(CC)  $(OBJ_DIR)/main.o -L$(LIB_SHARED_DIR) -l$(LIB_NAME) -o $(BIN_DIR)/use-shared-library
	$(CC)  $(OBJ_DIR)/main.o -L$(LIB_STATIC_DIR) -l$(LIB_NAME) -o $(BIN_DIR)/use-static-library
clean:
	rm -rf $(OBJ_DIR)/*
	rm -rf $(LIB_SHARED_DIR)/lib$(LIB_NAME).so
	rm -rf $(BIN_DIR)/use-shared-library
	rm -rf $(BIN_DIR)/use-static-library
