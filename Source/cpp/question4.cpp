//
// Created by FWDarling on 12/21/2019.
//

#include"../../Lab/stack.h"
#include<cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;

const char operators[10] = "!+-X/%^()";
const int32_t oper_order[9] = {0, 2, 2, 3, 3, 3, 4, 1, 1};

bool is_digit(char c){
    return c >= '0' && c <= '9';
}

int32_t get_ope_index(char ope){
    for(int32_t i = 0; i < 9; i++){
        if(ope == operators[i]) return i;
    }
    cout << "error: the operator is illegal!" << endl;
    return -1;
}

bool operatoe_cmp(char opt1, char opt2){
    int32_t ind1 = get_ope_index(opt1);
    int32_t ind2 = get_ope_index(opt2);
    return oper_order[ind1] < oper_order[ind2];
}

bool calculate(Stack<int32_t> &number_stack, Stack<char> &operator_stack){
    if(operator_stack.size() < 2 || number_stack.size() < 2) return false;
    char ope = operator_stack.top(); operator_stack.pop();
    int32_t num2 = number_stack.top(); number_stack.pop();
    int32_t num1 = number_stack.top(); number_stack.pop();
    switch (ope)
    {
        case '+':
            number_stack.push(num1 + num2);
            break;
        case '-':
            number_stack.push(num1 - num2);
            break;
        case 'X':
            number_stack.push(num1 * num2);
            break;
        case '/':
            number_stack.push(num1 / num2);
            break;
        case '^':
            number_stack.push(pow(num1, num2));
            break;
        case '%':
            number_stack.push(num1 % num2);
            break;
        default:
            cout << "the operator is illegal!" << endl;
            return false;
            break;
    }
    return true;
}


bool preprocesse(Stack<int32_t> &number_stack, Stack<char> &operator_stack, string expression){
    char current_char, previous_char = 0;
    int32_t current_number = 0;
    int32_t string_index = 0;
    while((current_char = expression[string_index++]) != '='){
        if(is_digit(current_char)){
            current_number = current_number * 10 + current_char - '0';
            if(previous_char == '@') current_number = -current_number;
        }else{
            if(current_char == '+' || current_char =='-'){
                if(is_digit(previous_char)){
                    number_stack.push(current_number);
                    current_number = 0;
                    while(operatoe_cmp(current_char, operator_stack.top())){
                        if(!calculate(number_stack, operator_stack)) return false;
                    }
                    operator_stack.push(current_char);
                }else if(previous_char == 0 || previous_char == '('){
                    if(current_char == '-')  previous_char = '@';
                    continue;
                }else if(previous_char == ')'){
                    while(operatoe_cmp(current_char, operator_stack.top())){
                        if(!calculate(number_stack, operator_stack)) return false;
                    }
                    operator_stack.push(current_char);
                }
            }else if(current_char == ')'){
                number_stack.push(current_number);
                current_number = 0;
                while(operator_stack.top() != '('){
                    if(operator_stack.size() < 2) return false;
                    if(!calculate(number_stack, operator_stack)) return false;
                }
                operator_stack.pop();
            }else if(current_char == '(') {
                operator_stack.push(current_char);
            }else{
                if(previous_char != ')') {
                    number_stack.push (current_number);
                    current_number = 0;
                }
                while(operatoe_cmp(current_char, operator_stack.top())){
                    if(!calculate(number_stack, operator_stack)) return false;
                }
                operator_stack.push(current_char);
            }
        }
        previous_char = current_char;
    }
    number_stack.push(current_number);
    while(operator_stack.size() >= 2){
        if(!calculate(number_stack, operator_stack)) return false;
    }
    return number_stack.size() == 1;
}

int main(){
    Stack<int32_t> number_stack;
    Stack<char> operator_stack;
    operator_stack.push ('!');
    string expression;
    cout << "Please enter your expression:" << endl;
    cin >> expression;
    if(preprocesse(number_stack, operator_stack, expression)){
        cout << "The result is: " << number_stack.top() << endl;
    }else{
        cout << "error: Incorrect input expression!" << endl;
    }
    return 0;
}