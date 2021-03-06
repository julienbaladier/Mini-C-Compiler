#include "Instructions_stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int cmp_instructions(list_node * node, void * instruction){
	return ((Instruction *)node->data)->ui_address 
			== ((Instruction *)instruction)->ui_address;
}

void print_instruction(void * data){
	printf("Instruction number : %d | Position : %ld | ", 
		((Instruction *)data)->ui_address, ((Instruction *)data)->l_position);
	if (((Instruction *)data)->b_incomplete){
		printf("Written");
	}else{
		printf("Not written");
	}
	printf("\n");
}


/* Création d'une pile contenant des lignes contenant chacune une instruction */
llist* create_instructions_stack(){
	return list_create(&cmp_instructions, &print_instruction);
};

/* Méthode qui permet d'afficher cette pile */
void print_instructions_stack(llist instructions_stack){
	list_print(instructions_stack);
}

/* Méthode qui permet d'empiler un élément */
Instruction  *push_instruction(llist * instructions_stack, int ui_address, long l_position, bool b_incomplete){
	Instruction *instruction = (Instruction *) malloc(sizeof(Instruction));
	instruction->ui_address = ui_address;
	instruction->l_position = l_position;
	instruction->b_incomplete = b_incomplete;
	list_node *node = list_insert_beginning(instructions_stack, instruction);
	return (node ? (Instruction*)node->data : NULL);	 
}

/* Méthode qui permet dépiler un élément */
Instruction *pop_instruction(llist * instructions_stack){
	return list_isempty(*instructions_stack) ? NULL : (Instruction*)list_pop(instructions_stack);
}




