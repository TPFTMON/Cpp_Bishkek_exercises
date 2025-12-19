#include <iostream>
#include <string>

int str_calculator(std::string expr, int len){
    int pos = 0;

    // Parsing first number
    int a = 0;
    while (pos < len && expr[pos] >= '0' && expr[pos] <= '9'){
        a = a * 10 + (expr[pos] - '0');
        pos++;
    }
    char op1 = expr[pos++];

    // Parsing second number
    int b = 0;
    while (pos < len && expr[pos] >= '0' && expr[pos] <= '9'){
        b = b * 10 + (expr[pos] - '0');
        pos++;
    }
    char op2 = expr[pos++];

    // Parsing third number
    int c = 0;
    while (pos < len && expr[pos] >= '0' && expr[pos] <= '9'){
        c = c * 10 + (expr[pos] - '0');
        pos++;
    }

    // Now evaluating with priority
    int result;
    if ((op2 == '*' || op2 == '/') && (op1 != '*' && op1 != '/')){
        // Doing b op2 c first
        int temp;
        if (op2 == '*')
            temp = b * c;
        else if (op2 == '/')
            temp = b / c;
        else
            temp = 0; // shouldn't happen

        // Then a op1 temp
        if (op1 == '+')
            result = a + temp;
        else if (op1 == '-')
            result = a - temp;
        else
            result = 0;
    } else {
        // Doing a op1 b first
        int temp;
        if (op1 == '+')
            temp = a + b;
        else if (op1 == '-')
            temp = a - b;
        else if (op1 == '*')
            temp = a * b;
        else if (op1 == '/')
            temp = a / b;
        else
            temp = 0;

        // Then temp op2 c
        if (op2 == '+')
            result = temp + c;
        else if (op2 == '-')
            result = temp - c;
        else if (op2 == '*')
            result = temp * c;
        else if (op2 == '/')
            result = temp / c;
        else
            result = 0;
    }

    return (result);
}

int main(){
    std::string expr;
    std::cin >> expr;

    int len = expr.length();
    int result = str_calculator(expr, len);

    std::cout << result << std::endl;
    return (0);
}
