#include<stdio.h>
#include<stdlib.h>
int base = 0;
int one = 0;
int two = 0;
typedef struct Tree {
	int data;
	struct Tree* left;
	struct Tree* right;
}Tree,*Tr;
void CreateTree(Tree **T) {
	int ch;
	scanf_s("%d", &ch);
	if (ch == -1) {
		*T = NULL;
		return;
	}
	*T = (Tree*)malloc(sizeof(Tree));
	(*T)->data=ch;
	CreateTree(&((*T)->left));
	CreateTree(&((*T)->right));
}
void countTree(Tr T) {
	if (T == NULL)return;
	int left=(T->left != NULL)? 1:0;
	int right = (T->right != NULL) ? 1 : 0;
	if (left == 0 && right == 0) {
		base++;
	}
	if (left + right == 1) {
		one++;
	}
	if (left+right==2){
		two++;
	}
	countTree(T->left);
	countTree(T->right);
}
int main() {
	Tr T=NULL;
	CreateTree(&T);
	countTree(T);
	printf("%d %d %d", base, one, two);
	return 0;
}