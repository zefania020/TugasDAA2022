/* 	Nama	: Zefania Agustina Lumbangaol
	NIM	: 201401020
	LAB	: DAA1 */
	
#include <iostream>
using namespace std;

struct BST{
	int data;
	BST* kiri;
	BST* kanan;
};

BST* InsertNode(int data, BST* tree){
	if(tree==NULL){
		BST* NewNode = new BST;
		NewNode->data = data;
		NewNode->kiri = NULL;
		NewNode->kanan = NULL;
		tree = NewNode;
		cout<<NewNode->data;
	}
	
	else if(tree->data > data){
		if(tree->kiri == NULL || tree->kiri->data < data || tree->kiri->data > data){
			cout<<endl;
			tree->kiri = InsertNode(data, tree->kiri);
		}		
	}
	
	else{
		if(tree->kanan == NULL||  tree->kanan->data > data){
			cout<<" ";
			tree->kanan = InsertNode(data, tree->kanan);
		}
	}
	return tree;
}

bool SearchNode(int data, BST* tree){
	if(tree==NULL) return false;
	else if(tree->data == data) return true;
	else if(tree->data < data) return SearchNode(data, tree->kanan);
	else return SearchNode(data, tree->kiri);
}

void PrintLeftNodes(BST* tree){
	if(tree!=NULL){
		cout<<tree->data;
		PrintLeftNodes(tree->kiri);
	}
}

int main(){
	int a[10] = {4,1,9,6,2,5,3,8,7,0};
	BST* Pohon = NULL;
	for(int i=0;i<10;i++){
		Pohon = InsertNode(a[i], Pohon);
	}
	/* if(!SearchNode(7, Pohon)) cout<<"Tidak ";
	cout<<"Ada 7"<<endl;
	if(!SearchNode(11, Pohon)) cout<<"Tidak ";
	cout<<"Ada 11"<<endl; */
}    
