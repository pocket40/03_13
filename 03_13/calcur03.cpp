#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

void postfix(void);

typedef enum {
    lparen, rparen, plus, minus, times, divide, eos, operand, negative
}precedence;

char expr[100];
int length;
std::string s;
int isp[] = { 0,19,12,12,13,13,0,0,19 };
int icp[] = { 20,19,12,12,13,13,0,0,19 };

template <typename T > class Stack {
private:
    T* arr;
    int top;
    int size;
public:
    Stack() : arr(0), top(0), size(100) {
        arr = new T[size];
        size = size;
        top = 0;
    }
    ~Stack() {
        delete[] arr;
    }
    bool isFull() {
        return(top == size);
    }
    bool isEmpty() {
        return(top == 0);
    }
    void push(const T& data) {
        arr[top++] = data;
    }
    T& top_f() {
        return arr[top - 1];
    }
    T& pop() {
        return arr[--top];
    }
};
Stack<precedence> t;
Stack<double> calc;

precedence getToken(char* symbol, int* n) {
    *symbol = s[(*n)++];

    switch (*symbol) {
    case '(':
        return lparen;
    case ')':
        return rparen;
    case '+':
        return plus;
    case '-':
        if (*n == 1) {
            return negative;
        }
        else if ((s[(*n) - 2] >= '0' && s[(*n) - 2] <= '9') || (s[(*n) - 2] == ')')) {
            return minus;
        }
        else {
            return negative;
        }
    case '/':
        return divide;
    case '*':
        return times;
    case '\0':
        return eos;
    default:
        return operand;
    }
}

void postfix(void) {
    char symbol;
    precedence token;
    int n = 0;
    int i = 0;

    t.push(eos);

    for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n)) {
        if (token == operand) {
            expr[i++] = symbol;
        }
        else if (token == rparen) {
            while (t.top_f() != lparen) {
                expr[i++] = t.pop();
            }
            t.pop();
        }
        else {
            if (i != 0) {
                if (expr[i - 1] >= '0' && expr[i - 1] <= '9') {
                    expr[i++] = '\0';
                }
            }
            if (t.top_f() == minus && token == negative) {
                t.pop();
                t.push(plus);
                continue;
            }
            while (isp[t.top_f()] >= icp[token]) {
                expr[i++] = t.pop();
            }
            t.push(token);
        }
    }
    while ((t.top_f()) != eos) {
        expr[i++] = t.pop();
    }
    expr[i] = '\0';
    length = i;
}

void eval() {
    precedence token;
    char symbol;
    double op1, op2, op3;
    int n = 0;
    char temp[100];
    char* arr = temp;
    int temp1 = 0;
    double num;
    token = getToken(&symbol, &n);

    for (int i = 0; i < length; i++) {
        if (expr[i] == '\0') {
            temp[temp1] = '\0';
            num = atof(arr);
            calc.push(num);
            for (int j = temp1 - 1; j >= 0; j--) {
                temp[j] = '\0';
            }
            temp1 = 0;
            continue;
        }
        if ((expr[i] >= '0' && expr[i] <= '9') || expr[i] == '.') {
            temp[temp1++] = expr[i];
        }
        else {
            if (temp1 != 0) {
                temp[temp1] = '\0';
                num = atof(arr);
                calc.push(num);
                for (int j = temp1 - 1; j >= 0; j--) {
                    temp[j] = '\0';
                }
                temp1 = 0;
            }
            switch (expr[i]) {
            case plus:
                op2 = calc.pop();
                op1 = calc.pop();
                op3 = op1 + op2;
                calc.push(op3);
                break;
            case minus:
                op2 = calc.pop();
                op1 = calc.pop();
                op3 = op1 - op2;
                calc.push(op3);
                break;
            case times:
                op2 = calc.pop();
                op1 = calc.pop();
                op3 = op1 * op2;
                calc.push(op3);
                break;
            case divide:
                op2 = calc.pop();
                op1 = calc.pop();
                op3 = op1 / op2;
                calc.push(op3);
                break;
            }
        }
    }
    printf("%.3lf\n", calc.pop());
}

int main() {

    std::cin >> s;
    postfix();
    eval();

    return 0;
}