#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

/* Question 1: Convert binary number to unsigned int */
unsigned int binary_to_uint(const char *b);

/* Question 2: Print the binary representation of a number */
void print_binary(unsigned long int n);

/* Question 3: Get the value of a bit at a given index */
int get_bit(unsigned long int n, unsigned int index);

/* Question 4: Set the value of a bit to 1 at a given index */
int set_bit(unsigned long int *n, unsigned int index);

/* Question 5: Set the value of a bit to 0 at a given index */
int clear_bit(unsigned long int *n, unsigned int index);

/* Question 6: Count the number of bits to flip to get from one number to another */
unsigned int flip_bits(unsigned long int n, unsigned long int m);

/* Function to write a character to stdout */
int _putchar(char c);

#endif /* MAIN_H */
