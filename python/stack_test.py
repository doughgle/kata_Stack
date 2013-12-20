'''
Created on Nov 11, 2012

@author: Asus
'''
import unittest
from stack import Stack, StackEmptyError


class TestStack(unittest.TestCase):

    def setUp(self):
        self.s=Stack()

    def test_afterCreationStackIsEmpty(self):
        self.assertTrue(self.s.is_empty())
        
    def test_afterOnePush_stackIsNotEmpty(self):
        self.s.push(1)
        self.assertFalse(self.s.is_empty())
        
    def test_afterOnePushAndOnePop_stackIsEmpty(self):
        self.s.push(1)
        element = self.s.pop()
        self.assertTrue(self.s.is_empty())
        
    def test_pushedElementsArePoppedInReverseOrder(self):
        self.s.push(1)
        self.s.push(2)
        self.s.push(3)
        self.assertEquals(3, self.s.pop())
        self.assertEquals(2, self.s.pop())
        self.assertEquals(1, self.s.pop())
        
    def test_popWhenEmptyShouldRaiseException(self):
        self.assertRaises(StackEmptyError, self.s.pop)
        
    def test_peekReturnsTopElementWithoutPopping(self):
        self.s.push(0xAA)
        self.assertEquals(0xAA, self.s.peek())
        self.assertEquals(0xAA, self.s.peek())
        
    def test_peekWhenEmptyShouldRaiseException(self):
        self.assertRaises(StackEmptyError, self.s.peek)

              
        


if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()