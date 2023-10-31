#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	char data;
	struct Node* next;
} Node;

void Push(char x,Node** pTH) {
	Node* var = (Node*)malloc(sizeof(Node));
	var->data = x;
	var->next = *pTH;
	*pTH = var;
}

void Pop(Node** pTH) {
	if (*pTH == NULL) return;
	Node* temp = *pTH;
	*pTH = temp->next;
	free(temp);
}

int isBalanced(char string[]) {
	Node* balance = NULL;
	for(int i=0; string[i] != '\0'; i++) {
		if (string[i] == '{' || string[i] == '[' || string[i] == '(') {
			Push(string[i],&balance);
		} else if (balance == NULL && (string[i] == ')' || string[i] == ']' || string[i] == '}')) {
			return 0; // string está vazia e primeiro elemento fecha - desbalanceada.
		} else if ((string[i] == ')' && balance->data == '(') || (string[i] == ']' && balance->data == '[') || (string[i] == '}' && balance->data == '{')) {
			Pop(&balance);
		} else if ((string[i] != '(') && (string[i] != ')') && (string[i] != '[') && (string[i] != ']') && (string[i] != '{') && (string[i] != '}')) {
		} else return 0;
	}
	if (balance == NULL) return 1;
	return 0;
}

int main() {
		
	printf("Esse programa checa se uma string está balanceada quanto aos {, [ e (. Digite algo: ");
	char nome[20]; fgets(nome,sizeof(nome),stdin);
	
	if (isBalanced(nome)) {
		printf("A string está balanceada.\n");
	} else {
		printf("A string não está balanceada.\n");
	}
	return 0;
}

