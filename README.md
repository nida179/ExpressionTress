# Expression Tree

A C++ implementation of an **Expression Tree** that converts infix expressions to postfix and prefix notations, evaluates them, and builds a binary expression tree with inorder traversal.

---

## Features

- **Infix → Postfix** conversion 
- **Infix → Prefix** conversion 
- **Postfix evaluation** using a stack
- **Prefix evaluation** using a stack
- **Binary Expression Tree** construction from a postfix expression
- **Inorder traversal** of the tree (reproduces the original infix expression with parentheses)
- **Recursive tree evaluation** (`Revaluate` and `RprefixEvaluate`)

---

## Supported Operators

| Operator | Meaning        | Precedence |
|----------|----------------|------------|
| `!`      | Logical NOT    | 4 (highest)|
| `%`      | Modulo         | 3          |
| `/`      | Division       | 3          |
| `*`      | Multiplication | 3          |
| `+`      | Addition       | 2          |
| `-`      | Subtraction    | 2          |
| `<`      | Less than      | 1          |
| `>`      | Greater than   | 1 (lowest) |

Parentheses `( )` are also supported for grouping.

---
