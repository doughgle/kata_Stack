'''
Created on Nov 11, 2012

@author: Asus
'''

class StackEmptyError(Exception): pass

class Stack(object):
    '''
    My Stack
    '''

    def __init__(self):
        '''
        Constructor
        '''
        self._elements = []
    
    def is_empty(self):
        if len(self._elements) == 0:
            is_empty = True
        else:
            is_empty = False
        return is_empty
    
    def push(self, element):
        self._elements.append(element)
        
    def pop(self):
        if self.is_empty():
            raise StackEmptyError
        else:
            return self._elements.pop(-1)
        
    def peek(self):
        if self.is_empty():
            raise StackEmptyError
        return self._elements[-1]