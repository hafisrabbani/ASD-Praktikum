#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct tree *tree;
struct tree{
    char info;
    tree kiri;
    tree kanan;
};

tree baru(char hrf)
{
    tree br;
    br=(tree)malloc(sizeof(struct tree));
    br->info=hrf;
    br->kiri=NULL;
    br->kanan=NULL;
    return (br);
}

int presentase(char operator) {

    if(operator == '+' || operator == '-'){
        return 1;
    }else if(operator == '*' || operator == '/'){
        return 2;
    }else{
        return -1;
    }

}

tree treeProcess(char* infix) {
    tree operandStack[100];
    int topOperand = -1;
    tree operatorStack[100];
    int topOperator = -1;
    
    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            tree operandNode = baru(infix[i]);
            operandStack[++topOperand] = operandNode;
        }
        else if (infix[i] == '(') {
            tree operatorNode = baru(infix[i]);
            operatorStack[++topOperator] = operatorNode;
        }
        else if (infix[i] == ')') {
            while (topOperator != -1 && operatorStack[topOperator]->info != '(') {
                tree operatorNode = operatorStack[topOperator--];
                operatorNode->kanan = operandStack[topOperand--];
                operatorNode->kiri = operandStack[topOperand--];
                operandStack[++topOperand] = operatorNode;
            }
            if (topOperator != -1 && operatorStack[topOperator]->info == '(') {
                free(operatorStack[topOperator--]);
            }
        }
        else {
            tree operatorNode = baru(infix[i]);
            while (topOperator != -1 && presentase(operatorNode->info) <= presentase(operatorStack[topOperator]->info)) {
                tree topOperatorNode = operatorStack[topOperator--];
                topOperatorNode->kanan = operandStack[topOperand--];
                topOperatorNode->kiri = operandStack[topOperand--];
                operandStack[++topOperand] = topOperatorNode;
            }
            operatorStack[++topOperator] = operatorNode;
        }
    }

    while (topOperator != -1) {
        tree topOperatorNode = operatorStack[topOperator--];
        topOperatorNode->kanan = operandStack[topOperand--];
        topOperatorNode->kiri = operandStack[topOperand--];
        operandStack[++topOperand] = topOperatorNode;
    }

    return operandStack[topOperand];
}

void postOrder(tree ph) {
    if (ph != NULL) {
        postOrder(ph->kiri);
        postOrder(ph->kanan);
        printf("%c", ph->info);
    }
}

int simpul(tree ph) {
    if (ph == NULL) {
        return 0;
    } else {
        return 1 + simpul(ph->kanan) + simpul(ph->kanan);
    }
}

int level(tree ph) {
    if (ph == NULL) {
        return 0;
    } else {
        int levelKiri = level(ph->kiri);
        int levelKanan = level(ph->kanan);
        if (levelKiri > levelKanan) {
            return levelKiri + 1;
        } else {
            return levelKanan + 1;
        }
    }
}

int main() {
    char infix[100];
    printf("Masukkan data infix: ");
    scanf("%s", infix);
    tree treeMath = treeProcess(infix);
    printf("Traversal postorder: ");
    postOrder(treeMath);
    printf("\nSimpul = %d\nLevel = %d\n", simpul(treeMath), level(treeMath));
    return 0;
}
