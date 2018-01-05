typedef struct Node {
	int	kind, value;
	struct	Node *first, *second, *third, *next;
	char *name;
	double rvalue;
} node;
typedef node	*tree;

extern char TokName[][15];

tree buildTree (int kind, tree first, tree second, tree third);
tree buildIntTree (int kind, int val);
tree buildStrTree (int kind, char *name);
tree buildDoubleTree(int kind, double rval);
void printTree (tree p);


/*
void check (tree);

void gen_program (tree);
*/
