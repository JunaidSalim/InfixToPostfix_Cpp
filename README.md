# InfixToPostfix_Cpp

**Approach:**
The code implements a basic calculator/converter that reads an infix expression, converts it to postfix notation, and evaluates the result. It utilizes two custom stack classes, `Stack` for string elements and `IntStack` for double elements.

**Algorithm Used:**
1. The `Stack` class performs infix to postfix conversion using the Shunting Yard algorithm.
2. The `IntStack` class handles the evaluation of postfix expressions.
3. The code uses two stacks to convert infix to postfix and then evaluate the postfix expression.

**Intuition:**
1. Infix to Postfix Conversion:
   - The `checkOperator` function categorizes operators and parentheses.
   - The `InfixToPostFix` method uses two stacks to convert the infix expression to postfix.
   - It considers operator precedence and handles parentheses.

2. Evaluation of Postfix Expression:
   - The `Evaluate` method uses a stack to evaluate the postfix expression.
   - It iterates through the postfix expression, performing operations on operands.

3. Reverse Functionality:
   - The `reverse` method reverses the order of elements in the stack.

4. User Interaction:
   - The main function reads an infix expression, displays the infix, converts to postfix, displays postfix, and finally evaluates and displays the result.

The overall code structure facilitates the step-by-step processing of infix expressions, making it easy to understand and extend.
