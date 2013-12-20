/*
 * stack.c
 *
 *  Created on: Nov 17, 2012
 *      Author: dough
 */

#include "stack.h"

static int elements_in_stack;
static void* elements[MAX_SIZE];
static uint32_t _size;

int Stack_init(const uint32_t size)
{
	int result = STACK_NO_ERR;
	if(size > MAX_SIZE)
	{
		_size = MAX_SIZE;
		result = STACK_ERR_MAX_SIZE_EXCEEDED;
	}
	else
	{
		_size = size;
	}

	elements_in_stack = 0;
	return result;
}

bool Stack_isEmpty(void)
{
	if(elements_in_stack)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int Stack_push(void *element)
{
	int result;
	if(elements_in_stack == _size)
	{
		result = STACK_ERR_OVERFLOW;
	}
	else
	{
		elements[elements_in_stack++] = element;
		result = STACK_NO_ERR;
	}

	return result;
}

void* Stack_pop(void)
{
	if(Stack_isEmpty())
	{
		return STACK_ERR_UNDERFLOW;
	}
	else return elements[--elements_in_stack];
}

void*	Stack_peek(void)
{
	if(Stack_isEmpty())
	{
		return STACK_ERR_UNDERFLOW;
	}
	return elements[elements_in_stack];
}
