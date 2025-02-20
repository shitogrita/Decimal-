CC := gcc
CFLAGS := -Wall -Werror -Wextra -std=c11

FILES = main.c arithmetic.c s21_decimal.c s21_wideDecimal.c other.c s21_round.c

all:
	$(CC) $(CFLAGS) $(FILES)

add:
	$(CC) $(CFLAGS) $(FILES) -D ADD

mul:
	$(CC) $(CFLAGS) $(FILES) -D MUL

sub:
	$(CC) $(CFLAGS) $(FILES) -D SUB


round:
	$(CC) $(CFLAGS) $(FILES) -D ROUND


test: # delete
	$(CC) $(CFLAGS) test.c s21_decimal.c s21_wideDecimal.c other.c aritmetic.c