class Stack:
    def __init__(self):
        self.stack = []

    def push(self, el):
        self.stack.append(el)

    def pop(self):
        if not self.is_empty():
            return self.stack.pop()

    def peek(self):
        if not self.is_empty():
            return self.stack[-1]

    def is_empty(self):
        return len(self.stack) == 0


# Create an empty stack
my_stack = Stack()

# Check if the stack is empty
print(my_stack.is_empty())

# Push some elements on the stack
my_stack.push(0)
my_stack.push(1)
my_stack.push(2)
my_stack.push(3)
my_stack.push(4)

# Check again if the stack is empty
print(my_stack.is_empty())

# Remove some elements from the stack
print(my_stack.pop())
print(my_stack.pop())

# Get the last element from the stack
print(my_stack.peek())

# Remove one more element from the stack
print(my_stack.pop())

# Check again if the stack is empty
print(my_stack.is_empty())
