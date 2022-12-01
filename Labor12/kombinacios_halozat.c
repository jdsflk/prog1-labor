#include <stdlib.h>

typedef enum
{
	AND,
	OR,
	NAND,
	NOR,
	NOT,
	FALSE,
	TRUE
} type_t;

typedef struct g {
	type_t type;
	struct g *in1, *in2;
} gate_t, *gate_tree;

int eval(gate_tree root) {
    return checkParents(root);
}

int checkParents(gate_tree current) {
	if(current == NULL) {
		return 0;
	}
	switch (current->type)
	{
	case TRUE: {
		return 1;
		break;
	}
	case FALSE: {
		return 0;
	}
	case OR: {
		return checkParents(current->in1) || checkParents(current->in2);
		break;
	}
	case AND: {
		return checkParents(current->in1) && checkParents(current->in2);
		break;
	}
	case NAND: {
		return !(checkParents(current->in1) && checkParents(current->in2));
		break;
	}
	case NOR: {
		return !(checkParents(current->in1) || checkParents(current->in2));
		break;
	}
	case NOT: {
		return !checkParents(current->in1) || !checkParents(current->in2);
		break;
	}
	default:
		break;
	}
}