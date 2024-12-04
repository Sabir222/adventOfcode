# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Directories
SRC_DIR = .
DAY1_DIR = day1
DAY2_DIR = day2
DAY3_DIR = day3

# Source files
SRC = $(SRC_DIR)/main.c $(DAY1_DIR)/c-day1-p1.c $(DAY1_DIR)/c-day1-p2.c $(DAY2_DIR)/c-day2-p1.c  $(DAY2_DIR)/c-day2-p2.c  $(DAY3_DIR)/c-day3-p1.c 
# Output executable
OUT = c-adventOfcode

# Default target to build the executable
all: $(OUT)

# Rule to build the executable
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Clean rule to remove compiled files
clean:
	rm -f $(OUT)
