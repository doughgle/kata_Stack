/*
 * stack.h
 *
 *  Created on: Nov 17, 2012
 *      Author: dough
 */

#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>
#include <stdint.h>

#define MAX_SIZE 256

typedef enum
{
	STACK_NO_ERR = 0,
	STACK_ERR_UNDERFLOW = 0xA,
	STACK_ERR_OVERFLOW,
	STACK_ERR_MAX_SIZE_EXCEEDED
} Stack_errors;


int 	Stack_init(const uint32_t size);
bool 	Stack_isEmpty(void);
int		Stack_push(void *element);
void* 	Stack_pop(void);
void*	Stack_peek(void);

#endif /* STACK_H_ */
