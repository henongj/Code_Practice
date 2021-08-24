#include<iostream>
/*

implement binary tree and binary search
https://www.youtube.com/watch?v=z_tzHoPfllA&list=PLRx0vPvlEmdDHxCvAQS1_6XV4deOwfVrz&index=20

*/
using namespace std;

// 구조체로 구현, 하나의 노드 정보를 선언
typedef struct node *treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;

//전위순회
void preOrder(treePointer ptr)
{
	if(ptr != nullptr) // ptr 이 NULL 이면 false, 아니면 true
	{
		cout << ptr->data << ' ';
		preOrder(ptr->leftChild);
		preOrder(ptr->rightChild);
	}
}
void inOrder(treePointer ptr)
{
	if(ptr != nullptr) // it is same /* if(ptr) */
	{
		inOrder(ptr->leftChild);
		cout << ptr->data << ' ';
		inOrder(ptr->rightChild);
	}
}
void postOrder(treePointer ptr)
{
	if(ptr != nullptr) // ptr 이 NULL 이면 false, 아니면 true
	{
		postOrder(ptr->leftChild);
		postOrder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}
inline bool isOdd(size_t num)
{
	return num & 1 ? true : false; 
}
int main(void)
{
	int treeNumber = 16;
	node nodes[treeNumber + 1];
	for(int i = 1 ;  i <= treeNumber ; i++)
	{
		nodes[i].data = i;
		nodes[i].leftChild = nullptr;
		nodes[i].rightChild = nullptr;
	}
	
	
	for(int i = 1 ; i <= treeNumber; i++)
	{
		if( !isOdd(i) ) // if it is even // i % 2 == 0 // i가 짝수면 i&0 의 답은 0
			nodes[i/2].leftChild = &nodes[i];
		else // if it is odd
			nodes[i/2].rightChild = &nodes[i];
	}
	cout << "--- preOrder --- \n";
	preOrder(&nodes[1]);
	cout << "\n--- inOrder --- \n";
	inOrder(&nodes[1]);
	cout << "\n--- postOrder --- \n";
	postOrder(&nodes[1]);
	return 0;
}






