#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Node{
    char data;
    Node *left;
    Node *right;

};
Node *root = NULL;

int precedence(char oper){
   switch(oper){
    case '!': return 4;
    break;
    case '%': return 3;
    break;
    case '/': return 3;
    break;
    case '*': return 3;
    break;
    case '+': return 2;
    break;
    case '-': return 2;
    break;
    case '<': return 1;
    break;
    case '>': return 1;
    break;
    default : return 0;
   }
}

bool isOperator(char c){
    return c=='!'|| c== '%' || c =='+' || c =='-' || c =='*' || c=='/' || c=='<' || c=='>';
}
bool isOperand(char ch){
    if((ch>= 'A' && ch <='Z') || 
     (ch>= 'a' && ch <='z') ||
     (ch>= '0' && ch <='9'))
     return true;
     else return false;
}
string infixToPostFix(string express){
    stack<char> s;
    string output = "";
    for(int i=0;i<express.length();i++){
        // if operand then append to output

        if(isOperand(express[i])){
        output += express[i];
        output += ' ';
        }
        else if(express[i]=='('){
            s.push(express[i]);
        } 
        else if(express[i]==')'){
            while(!s.empty() && s.top()!='('){
                output +=  s.top(); // append to function
                output += ' ';
                s.pop();
            }
            s.pop(); // remove the ( from stack 
        }
        else if (isOperator(express[i])){
            while (!s.empty() && s.top()!='(' && isOperator(s.top())&& precedence(s.top())>=precedence(express[i])){
                output += s.top();
                 output += ' ';
                 s.pop();
            }
            s.push(express[i]);
        }
    }
    while(!s.empty()){
        output +=s.top();
        //output += s.top();
         output += ' ';
         s.pop();
    }
    return output;
}

// for infix to prefix 
string reverseString(string result) {
    string prefix = "";
    for (int i = result.length() - 1; i >= 0; i--) {
        prefix += result[i];
    }
    return prefix;
}
string infixToPrefix(string express){
    stack<char> s;
    string output = "";
    string r = reverseString(express);

    for (int i = 0; i < r.length(); i++) {
        if (r[i] == '(') r[i] = ')';
        else if (r[i] == ')') r[i] = '(';
        }
    for(int i=0;i<r.length();i++){
        if(isOperand(r[i])){
        output += r[i];
        output += ' ';
        }
        else if(r[i]=='('){
            s.push(r[i]);
        } 
        else if(r[i]==')'){
        while(!s.empty() && s.top()!='('){
            output += s.top();
            output += ' ';
            s.pop();
        }
        s.pop();
        }
        else if (isOperator(r[i])){
            while (!s.empty() && s.top()!='(' && isOperator(s.top())&& precedence(s.top())>precedence(r[i])){
                output += s.top();
                 output += ' ';
                 s.pop();
            }
            s.push(r[i]);
        }
        
    }
    while(!s.empty()){
        output +=s.top();
        //output += s.top();
         output += ' ';
         s.pop();
    }
    return reverseString(output);
}
void prefixEvalution(string prefix){
    stack<int> s;
    for(int i = prefix.length()-1;i>=0;i--){
        if(isOperand(prefix[i])){
            s.push(prefix[i] - 48); // now integers; when passing the digits direct
        }
        else if(prefix[i] == '+'){
                int right  = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                s.push(right+left);
        }
        else if(prefix[i] == '-'){
                int right  = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                s.push(right-left);
        }
        else if(prefix[i] == '*'){
                int right  = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                s.push(left*right);
        }
        else if(prefix[i] == '/'){
                int right  = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                s.push(right/left);
        }
        else if(prefix[i] == '!'){
            int val = s.top();
            s.pop();
            s.push(!val); 
        }
    }
    cout << "Result: " << s.top() << endl;
}
int RprefixEvaluate(Node* node){
    // base case: operand, return its value
    if(isOperand(node->data)){
        return node->data - '0';
    }
    
    // recursively evaluate left and right
    int left  = RprefixEvaluate(node->left);
    int right = RprefixEvaluate(node->right);
    
    // apply operator
    if(node->data == '+') return left + right;
    if(node->data == '-') return left - right;
    if(node->data == '*') return left * right;
    if(node->data == '/') return left / right;
}

void evaluation(string postfix){

    stack<int> s;
    for(int i = 0;i<postfix.length();i++){
        if(isOperand(postfix[i])){
            s.push(postfix[i] - 48); // now integers; when passing the digits direct
        }
        else if(postfix[i] == '+'){
                int right  = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                s.push(right+left);
        }
        else if(postfix[i] == '-'){
                int right  = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                s.push(left-right);
        }
        else if(postfix[i] == '*'){
                int right  = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                s.push(left*right);
        }
        else if(postfix[i] == '/'){
                int right  = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                s.push(left/right);
        }
        else if(postfix[i] == '!'){
            int val = s.top();
            s.pop();
            s.push(!val); 
        }
    }
    cout << "Result: " << s.top() << endl;
}

int Revaluate(Node* node){
    // base case: operand, return its value
    if(isOperand(node->data)){
        return node->data - '0';
    }
    
    // recursively evaluate left and right subtrees
    int left  = Revaluate(node->left);
    int right = Revaluate(node->right);
    
    // apply operator
    if(node->data == '+') return left + right;
    if(node->data == '-') return left - right;
    if(node->data == '*') return left * right;
    if(node->data == '/') return left / right;
}

void insert(string expression){

    stack<Node*> s;
    for(int i=0;i<expression.length();i++){
        if(expression[i] == ' ') continue;
        if(isOperand(expression[i])){
            Node *temp = (Node *)malloc(sizeof(Node));
            temp->data = expression[i];
            temp->left = NULL;
            temp->right = NULL;
            s.push(temp);
        }
        else {
            Node *temp = (Node *)malloc(sizeof(Node));
            temp->data = expression[i];
            if(expression[i] == '!'){
            temp->right = s.top();
            s.pop();
            temp->left = NULL; // only one child needed
            }
            else{
            temp->right = s.top();
            s.pop();
            temp->left = s.top();
            s.pop();
            }
            s.push(temp);
        }
    }
    root = s.top();
}

void inorder(Node* node){
    if(node == NULL) return;
    if(isOperator(node->data)) cout << "( ";
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
    if(isOperator(node->data)) cout << ") ";
}

int main(){

    string eq;
    std::cout << "ENTER THE EXPRESSION: " ;
    std::cin >> eq;

    std::cout << "EQUATION(INFIX): " << eq << "\n";
    string output = infixToPostFix(eq);
    std::cout << "EQUATION(POSTFIX): " << output << "\n";

    evaluation(output);
    cout << "";

    string out = infixToPrefix(eq);
    std::cout << "EQUATION(PREFIX): " << out << "\n";
    prefixEvalution(out);
    cout << "\n";

    insert(output);
    inorder(root);

    return 0;
}
