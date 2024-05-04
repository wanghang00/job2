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
    
    printf("��������Ŀ������");
    scanf("%d", &num_questions);
    
    printf("�������������+��-��*��/����");
    scanf(" %c", &operator);
    
    printf("�������������");
    scanf("%d", &max_num);
    
    printf("�Ƿ�Ҫ�����ţ���1Ϊ�ǣ�0Ϊ�񣩣�");
    scanf("%d", &with_brackets);
    
    printf("�Ƿ�Ҫ��С������1Ϊ�ǣ�0Ϊ�񣩣�");
    scanf("%d", &with_decimal);
    
    generate_math_questions(num_questions, operator, max_num, with_brackets, with_decimal);
    
    return 0;
}