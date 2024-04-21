// Copyright 2021 NNTU-CS
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
    TStack<char, 100> stack1;
    std::map<char, int>  priority  = {{'(', 0}, { ')', 1}, { '+', 2},
                                      { '-', 2}, { '*', 3}, { '/', 3} };
    std::string res_str = "";
    for (int i = 0; i < inf.length(); i++) {
        if ('0' <= inf[i] && inf[i] <= '9') {
            res_str += inf[i];
            res_str += " ";
        } else if (inf[i] == '(') {
            stack1.push(inf[i]);
        } else if (inf[i] == ')') {
            while (!stack1.isEmpty() && stack1.top() != '(') {
                res_str += stack1.pop();
                res_str += " ";
            }
            stack1.pop();
        } else if (inf[i] == '+' || inf[i] == '-'
                   || inf[i] == '*' || inf[i] == '/') {
            while ( !stack1.isEmpty()
                   && priority[inf[i]] <= priority[stack1.top()]) {
                res_str += stack1.pop();
                res_str += " ";
            }
            stack1.push(inf[i]);
        }
    }
    while (!stack1.isEmpty()) {
        res_str += stack1.pop();
        res_str += " ";
    }
    res_str.erase(res_str.length() - 1);
    return res_str;
}

int eval(std::string pref) {
    TStack<int, 100> stack2;
    for (int i = 0; i < pref.length(); i++) {
        if ('0' <= pref[i] && pref[i] <= '9') {
            stack2.push(pref[i] - '0');
        } else if (pref[i] == '+') {
            stack2.push(stack2.pop() + stack2.pop());
        } else if (pref[i] == '-') {
            int num2 = stack2.pop();
            int num1 = stack2.pop();
            stack2.push(num1 - num2);
        } else if (pref[i] == '*') {
            stack2.push(stack2.pop() * stack2.pop());
        } else if (pref[i] == '/') {
            int num2 = stack2.pop();
            int num1 = stack2.pop();
            stack2.push(num1 / num2);
        }
    }
    return stack2.top();
}
