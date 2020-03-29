CC = g++
CFLAGS = -g -Wall -Wl,--no-undefined
TARGET = main
SRC = ./src
FILES = $(foreach dir, $(SRC), $(wildcard $(dir)/*.c))
OBJS = $(patsubst %.c, %.o,$(FILES))
BUILD_DIR := ./build
INC = ./src/include

$(TARGET): CHECKDIR $(OBJS)
	$(CC)  -o $(BUILD_DIR)/$(TARGET) $(addprefix $(BUILD_DIR)/, $(notdir $(OBJS)))
	cp $(BUILD_DIR)/$(notdir $@) ./

CHECKDIR:
	mkdir -p ${BUILD_DIR}
	# mkdir -p ${BUILD_DIR}/src

$(OBJS): %.o:%.c
	$(CC) -MD -MF $(BUILD_DIR)/$(notdir $*.d) -MP -I $(INC) -c $< -o $(BUILD_DIR)/$(notdir $@) $(CFLAGS)

clean:
	rm -rf $(BUILD_DIR)
	rm -rf  ./$(TARGET).exe