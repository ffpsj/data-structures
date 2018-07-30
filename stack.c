#include <stdio.h>
#include <stdlib.h>

#define MAX 10

//estrutura da pilha
typedef struct {
	int value[MAX]; //elementos da pilha
	int index; //referencia o index da pilha
} Stack;

//criar uma nova pilha
Stack* create() {
	//aloca um espaço na memória para a pilha
	Stack* stack = (Stack*) malloc(sizeof(Stack));
	//aponta o index para -1
	stack->index = -1;
	//retorna a pilha
	return stack;
}

//verificar se a pilha está vazia (OK)
int isEmpty(Stack* stack) {
	return stack->index == -1;
}

//verificar se a pilha está cheia (OK)
int isFull(Stack* stack) {
	return stack->index >= MAX;
}

//retornar o tamanho da pilha (OK)
int length(Stack* stack) {
	//se a pilha estiver vazia não retornamos nada
	if(isEmpty(stack)) {
		printf("Is Empty\n");
		return -1;
	}
	//caso contrário retornamos o último index acessado, logo o tamanho da pilha
	return stack->index + 1;
}

//inserir um elemento na pilha (OK)
void push(Stack* stack, int element) {
	//se a pilha estiver cheia, não inserimos nenhum elemento novo
	if(isFull(stack)) {
		printf("Is Full\n");
		return;
	}
	//caso contrário insiro o elemento
	stack->value[++stack->index] = element;
}

//retornar o elemento da base da pilha (OK)
int bottom(Stack* stack) {
	//se a pilha estiver vazia não retornamos nada
	if(isEmpty(stack)) {
		printf("Is Empty\n");
		return -1;
	}
	//caso contrário retornamos o primeiro elemento inserido
	return stack->value[0];
}

//retornar o elemento do topo da pilha (OK)
int top(Stack* stack) {
	//se a pilha estiver vazia não retornamos nada
	if(isEmpty(stack)) {
		printf("Is Empty\n");
		return -1;
	}
	//caso contrário retornamos o último elemento inserido
	return stack->value[stack->index];
}

//retornar e retirar o elemento superior da pilha (OK)
int pop(Stack* stack) {
	//se a pilha estiver vazia não retornamos nada
	if(isEmpty(stack)) {
		printf("Is Empty\n");
		return -1;
	}
	//caso contrário retornamos e retiramos o último elemento inserido
	int element = stack->value[stack->index];
	stack->index--;
	return element;
}

//trocar o elemento da base pelo do topo da pilha (OK)
void trade(Stack* stack) {
	//se a pilha estiver vazia não retornamos nada
	if(isEmpty(stack)) {
		printf("Is Empty\n");
		return;
	}
	//crio novas variáveis para receber os valores da base e do topo
	int down = bottom(stack);
	int up = top(stack);
	//meu novo valor da base será igual ao valor do topo
	stack->value[0] = up;
	//retiro o último elemento da pilha
	pop(stack);
	//insiro o elemento da base no topo
	push(stack, down);
}

//colocar todos os elementos pares na base e os ímpares no topo (OK)
void rearrange(Stack* stack) {
	//se a pilha estiver vazia não retornamos nada
	if(isEmpty(stack)) {
		printf("Is Empty\n");
		return;
	}
	//crio novas pilhas
	Stack* stackEven = create();
	Stack* stackOdd = create();
	//enquanto a minha pilha não estiver vazia coloco todos os elementos pares na pilha de pares
	//senão coloco na pilha de ímpares
	while(!isEmpty(stack)) {
		int element = pop(stack);
		if(element % 2 == 0) {
			push(stackEven, element);
		}
		else {
			push(stackOdd, element);
		}
	}
	//enquanto a pilha de pares não estiver vazia coloco todos os elementos dela na base da pilha antiga
	while(!isEmpty(stackEven)) {
		int element = pop(stackEven);
		push(stack, element);
	}
	//enquanto a pilha de ímpares não estiver vazia coloco todos os elementos dela no topo pilha antiga
	while(!isEmpty(stackOdd)) {
		int element = pop(stackOdd);
		push(stack, element);
	}
}

//inverter a pilha (OK)
void reverse(Stack* stack) {
	//se a pilha estiver vazia não retornamos nada
	if(isEmpty(stack)) {
		printf("Is Empty\n");
		return;
	}
	//crio uma nova pilha
	Stack* newStack = create();
	//enquanto a minha pilha não estiver vazia coloco o primeiro elemento na base da nova pilha, invertendo-a
	while(!isEmpty(stack)) {
		int element = pop(stack);
		push(newStack, element);
	}
	*stack = *newStack;
}

//imprimir a pilha (OK)
int print(Stack* stack) {
	//se a pilha estiver vazia não retornamos nada
	if(isEmpty(stack)) {
		printf("Is Empty\n");
		return -1;
	}
	//senão imprimo a pilha em ordem inversa à de inserção (ordem certa para pilha)
	for(int i = stack->index ; i >= 0 ; i--) {
		printf("%d\n", stack->value[i]);
	}
	printf("//////////\n");
}

int main() {
	Stack* stack = create();
	print(stack);
	push(stack, 3);
	push(stack, 7);
	push(stack, 9);
	push(stack, 2);
	push(stack, 4);
	print(stack);
	trade(stack);
	print(stack);
	printf("Length: %d\n", length(stack));
	printf("Top: %d\n", top(stack));
	printf("Bottom: %d\n", bottom(stack));
	printf("Pop: %d\n", pop(stack));
	printf("Top: %d\n", top(stack));
	print(stack);
	rearrange(stack);
	print(stack);
	reverse(stack);
	print(stack);

	return 0;
}