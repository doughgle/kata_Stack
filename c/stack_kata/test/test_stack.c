#include "unity.h"
#include "stack.h"

void setUp(void)
{
	TEST_ASSERT_EQUAL(STACK_NO_ERR, Stack_init(5));
}

void tearDown(void) {} // every test file requires this function;
                       // tearDown() is called by the generated runner before each test case function

void test_afterCreationStackIsEmpty(void)
{
	TEST_ASSERT_TRUE(Stack_isEmpty());
}

void test_afterOneSuccessfulPushStackIsNotEmpty(void)
{
	TEST_ASSERT_EQUAL(STACK_NO_ERR, Stack_push(1));
	TEST_ASSERT_FALSE(Stack_isEmpty());
}

void test_afterOnePushAndOnePop_stackIsEmpty(void)
{
	Stack_push(1);
	void *element = Stack_pop();
	TEST_ASSERT_TRUE(Stack_isEmpty());
}

void test_pushedElementsArePoppedInReverseOrder(void)
{
	Stack_push(0);
	Stack_push(1);
	Stack_push(2);
	Stack_push(3);
	TEST_ASSERT_EQUAL(3, Stack_pop());
	TEST_ASSERT_EQUAL(2, Stack_pop());
	TEST_ASSERT_EQUAL(1, Stack_pop());
	TEST_ASSERT_EQUAL(0, Stack_pop());
}

void test_popWhenEmptyIsUnderflowError(void)
{
	TEST_ASSERT_TRUE(Stack_isEmpty());
	TEST_ASSERT_EQUAL(STACK_ERR_UNDERFLOW, Stack_pop());
}

void test_pushWhenFullIsOverflowError(void)
{
	Stack_init(MAX_SIZE);
	int i;
	for(i=0; i<MAX_SIZE; i++)
	{
		TEST_ASSERT_EQUAL(STACK_NO_ERR, Stack_push(i));
	}
	TEST_ASSERT_EQUAL(STACK_ERR_OVERFLOW, Stack_push(1));
}

void test_requestedStackSizeExceedsMaxIsMaxSizeExceededError(void)
{
	TEST_ASSERT_EQUAL(STACK_ERR_MAX_SIZE_EXCEEDED, Stack_init(MAX_SIZE+1));
}

void test_peekWhenEmpty_IsUnderflowError(void)
{
	TEST_ASSERT_TRUE(Stack_isEmpty());
	TEST_ASSERT_EQUAL(STACK_ERR_UNDERFLOW, Stack_peek());
}

void test_peekReturnsTopElementWithoutRemoving(void)
{
	Stack_push(1);
	TEST_ASSERT_EQUAL(1, Stack_peek());
	TEST_ASSERT_EQUAL(1, Stack_peek());
}
