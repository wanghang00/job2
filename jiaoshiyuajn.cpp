#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate_number(int max_num) {
    return rand() % max_num + 1;
}

void generate_math_questions(int num_questions, char operator, int max_num, int with_brackets, int with_decimal) {
    char operators[4] = {'+', '-', '*', '/'};
    
    for (int i = 0; i < num_questions; i++) {
        int a = generate_number(max_num);
        int b = generate_number(max_num);
        
        if (operator == '/') {
            while (a % b != 0 || a / b == 0) {
                a = generate_number(max_num);
                b = generate_number(max_num);
            }
        }
        
        char question[50];
        
        if (with_brackets) {
            sprintf(question, "(%d %c %d)", a, operator, b);
        } else {
            sprintf(question, "%d %c %d", a, operator, b);
        }
        
        if (with_decimal) {
            printf("%s = %.2f\n", question, (float)eval(question));
        } else {
            printf("%s = %d\n", question, eval(question));
        }
    }
}

int main() {
    srand(time(NULL));
    
    int num_questions, max_num, with_brackets, with_decimal;
    char operator;
    
    printf("请输入题目数量：");
    scanf("%d", &num_questions);
    
    printf("请输入运算符（+、-、*、/）：");
    scanf(" %c", &operator);
    
    printf("请输入最大数：");
    scanf("%d", &max_num);
    
    printf("是否要加括号？（1为是，0为否）：");
    scanf("%d", &with_brackets);
    
    printf("是否要有小数？（1为是，0为否）：");
    scanf("%d", &with_decimal);
    
    generate_math_questions(num_questions, operator, max_num, with_brackets, with_decimal);
    
    return 0;
}