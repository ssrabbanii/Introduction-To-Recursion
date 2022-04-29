#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

class Node
{
///////Data and member functions for Constructing the Binary Tree:
    public:
	int Data;   //Data of the nodes
	Node *left;  //pointer to left child
	Node *right;  //pointer to right child


///////Data and member functions for applying the MergeSort to a linked list:

    void Print(Node *);       //For printing the linked list
    void setNode(Node *);     //For setting the data of each node of the linked listg
    Node* merge(Node *, Node *);  //Recursive function for merging the two sorted sub-arrays
    void mergeSort(Node *&, int);  //Function for sorting two sub-arrays recursively
    Node *next;

    private:
    int data;     //as data is private
};



//////////////////// Coding part for FIBONACCI SEQUENCE ///////////////////////
int Fib(int N){

    if(N == 1 || N == 0){
        return (N);
    }
    return Fib(N - 1) + Fib(N - 2);   //Adding the previous two terms for finding the next term in the series
}
////////////////////////////////////////////////////////////////////////////////




/////////////////////////////// Coding part for USING MERGE_SORT ON LINKED LIST /////////////////////////////////////////////////////////////////////

void Node::setNode(Node *p){
    p -> data = rand() % 100;      //Setting the data of each node, data will be between 0 and 99
}

void Node::Print(Node *head){      //Argument of this member function is the head of the linked list
    while(head != NULL){
        cout<<head -> data<<" ";
        head = head -> next;
    }
}

Node* Node::merge(Node *head1, Node *head2){
	Node *newHead = new Node();
	//Base case: returning the other half if  one of them is NULL
	if(head1==NULL){
    return head2;}
	else if(head2 ==NULL){
    return head1;}


	if(head1->data < head2->data){    //Comparing the two values
		newHead = head1;							//assign the newHead to the Node which has the smaller value
		newHead->next = merge(head1->next,head2);	//call the function again to find the next smallest Node
	}
	else{
		newHead = head2;
		newHead->next = merge(head1,head2->next);
	}

	return newHead;
}

void Node::mergeSort(Node *&head, int x){
	if(head->next == NULL){   //check if this is the last node, then do nothing
        return;
    }
    Node* head1;
    Node* head2 = head;				//assign head2 to head

    for(int i=0; i<(x/2); i++)		//use for loop to divide the linked list into two halves
    {
        head1 = head2;				// assign head1 to any node head2 points to
        head2 = head2->next;
    }
    //After the FOR loop completes iteration, Head 2 will point to second half of the linked list

    head1->next = NULL;				//null terminate the first half of the linked list
    head1 = head;					//this will be the head for the first node of the first half

    //sorting the two sub-arrays recursively
    mergeSort(head1, x/2);
    mergeSort(head2, x-(x/2));
    head = merge(head1,head2);    //merge the two sorted sub-arrays
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////// Coding part for CONSTRUCTING BINARY TREE /////////////////////////////////////////////////////////////////////////////////////

// This function is used to test the constructed binary tree, by printing out the Inorder Traversal
void InorderTraversal(Node *root)
{
	if (root == NULL)
		return;

	InorderTraversal(root->left);    //recursively calling on the left child

	cout<<root->Data<<" ";    //printing the Data of the node

	InorderTraversal(root->right);     //recursively calling on the right child
}

// This funtcion is used to test the constructed binary tree, by printing out the Preorder Traversal
void PreorderTraversal(Node *root)
{
    if (root == NULL) {
        return;
    }

    cout << root->Data << ' ';      //printing the Data of the node
    PreorderTraversal(root->left);     //recursively calling on the left child
    PreorderTraversal(root->right);    //recursively calling on the right child
}


// Function to find index of value in the Inorder Traversal
int search(int d[], int start, int end, int value)
{
	for (int i = start; i <= end; i++)
	{
		if (d[i] == value)
			return i;
	}
    return 0;
}


Node *newNode(int Data)
{
	Node *node = new Node();
    //Setting the Data of the node and the left and right child node to NULL
	node->Data = Data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

Node *constructTree(int in[], int pre[], int Inorder_Start, int Inorder_End)
{
	static int preIndex = 0;

	if (Inorder_Start > Inorder_End)
		return NULL;

	Node *tree_node = newNode(pre[preIndex++]);  //Choosing the current node from Preorder traversal and then incrementing the preIndex for the next node

	// If the node has no children then return
	if (Inorder_Start == Inorder_End)
		return tree_node;

	int inIndex = search(in, Inorder_Start, Inorder_End, tree_node->Data);    //Search for the index of this node in Inorder traversal

	// Using the index in Inorder traversal to construct the left and right subtress by recursive calls
	tree_node -> left = constructTree(in, pre, Inorder_Start, inIndex - 1);
	tree_node -> right = constructTree(in, pre, inIndex + 1, Inorder_End);

	return tree_node;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int main()
{
    char choice;

    cout<<"\nHello! Welcome to this tutorial which will help you to learn about the concept of recursion in details.\nHopefully by the end, you will have a better understanding of how the entire process works both theoretically and in practise."<<endl;
    cout<<"\n\nFirst, let's start by defining what exactly is recursion:"<<endl;
    cout<<"\nWe can define Recursion as the process in which a function calls in on itself, in order to solve a complex iterative task by dividing it into smaller sub tasks.\nAny function which calls itself recursively is called recursive function, and the process of calling a function by itself is called recursion.\nThe iterative process in the recursive functions will continue until we encounter a base case, which will terminate the recursion procedure."<<endl;
    cout<<"\nIt is an efficient approach to solve a complex computation task by dividing it into easier, more manageable sub-tasks and to solve them individually to reach final solution.\nWe can call this approach of solving a problem as Divide and Conquer. "<<endl;
    cout<<"\n\nNow let us look at some examples to really understand on how the entire recursion process works in practise"<<endl;

    while(true){
        do{
            cout<<"\n\nPlease choose on what difficulty levels do you want to know about the recursion concepts and test out the examples\nEnter 'b' for Beginner, 'i' for Intermediate or 'a' for the Advanced level: ";
            cin>>choice;
        }while(choice != 'b' && choice != 'i' && choice != 'a');    //data validation


        /////FIBONACCI SEQUENCE
        if(choice == 'b'){
            cout<<"\n\n----------------------------"<<endl;
            cout<<"|      BEGINNER LEVEL      |"<<endl;
            cout<<"----------------------------"<<endl;
            cout<<"\nIn this beginner's level, we are going to be learning on how to create a Fibonacci sequence using recursion."<<endl;
            cout<<"\nThe Fibonacci sequence is a series where the next term is the sum of pervious two terms. The first two terms of the Fibonacci sequence are 0 followed by 1. Then, the next terms will be 1, 2, 3, 5 and so on."<<endl;
            cout<<"\nIn creating the program, we will first take input from the user about the number of terms that they want in the Fibonacci series.\nFor the first one or two terms, only 0 or (0,1) will be outputted to the screen."<<endl;
            cout<<"\nStarting from the 3rd term onwards, for each of the term, we need to add the previous two terms in the sequence. This is done by calling in a function, which will in turn recursively call in the same function for the previous two terms. This will carry on until we reach the base cases for the function which are 0 or 1 (the 1st or the 2nd term)."<<endl;
            cout<<"\nThe entire process continues until the number of terms printed out is equal to the input from the user."<<endl;
            cout<<"\nYou can kindly try out the following process below\n\n"<<endl;


            int x, y=0;
            cout<<"Please enter the number of terms of the series: ";
            cin>>x;
            cout << "\nFibonnaci Series : ";

            while(y < x){
                cout<<Fib(y)<<" ";
                y++;
            }
            cout<<"\n"<<endl;
        }


        ////// Using MergeSort on a linked list
        else if(choice == 'i'){
            cout<<"\n\n--------------------------------"<<endl;
            cout<<"|      INTERMEDIATE LEVEL      |"<<endl;
            cout<<"--------------------------------"<<endl;
            cout<<"\nIn this Intermediate level, we will create a linked list and sort it by applying the Merge Sort algorithm."<<endl;
            cout<<"\nA linked list is a sequence of data structures, in which each element contains a link to the next element in the list."<<endl;
            cout<<"\nThe list will be created according to the length that is inputted by the user.\nBy using a recursive function, we will then divide the linked list into two separate sub-lists (each of which are linked lists as well)."<<endl;
            cout<<"\nThis recursive process will continue until the entire linked list is broken down into single nodes, where each node points to NULL.\nAfterwards, with the help of another function, we will sort each of these single nodes and merge them together into a sorted linked list"<<endl;
            cout<<"\nYou can kindly try out the following process below\n\n"<<endl;


            Node *prevNode, *head, exp;    //The obj 'exp' is just used to access the member functions of the class Node
            int len;

            cout<<"Please enter the length of the singly linked list: ";
            cin>>len;

            srand(time(0));

            for(int i=0; i<len; i++){
                Node *newNode = new Node();     //Creating new node
                exp.setNode(newNode);      //Setting the data of each node

                if(i == 0){    //For the first node of the linked list
                    head = newNode;     //Setting the head of the linked list
                    prevNode = newNode;    //Here 'prevNode' is used to keep record of the current node and to set links for the next node

                    if(len == 1){     //If length of linked list is inputted as 1
                        newNode -> next = NULL;
                    }
                    continue;
                }
                prevNode -> next = newNode;
                prevNode = newNode;    //Here 'prevNode' is used to keep record of the current node and to set links for the next node
                if(i == len - 1){
                    newNode -> next = NULL;     //For the very last node of the linked list
                }

            }

            cout<<"\nThe singly linked list is created!"<<endl;

            cout<<"\nThe linked list from beginning to end: "<<endl;
            exp.Print(head);    //Printing the linked list using the member function

            char x;
            do{
                cout<<"\n\nDo you want to sort your linked list?\nPress 'y' for YES and 'n' for NO: ";
                cin>>x;
            }while(x != 'y' && x != 'n');

            if(x == 'y'){
                exp.mergeSort(head, len);    //Sorting the linking list using the merge-sort algorithm

                cout<<"\nAfter applying the merge sort algorithm, we get the sorted linked link as follow: "<<"\n";
                exp.Print(head);     //Printing the sorted linked list
            }
            cout<<"\n"<<endl;

        }


        ////// CONSTRUCTING A BINARY TREE
        else if(choice == 'a'){
            cout<<"\n\n----------------------------"<<endl;
            cout<<"|      ADVANCED LEVEL      |"<<endl;
            cout<<"----------------------------"<<endl;
            cout<<"\nIn this Advanced level, we will be using recursion to construct a binary tree from Inorder and Preorder Traversals."<<endl;
            cout<<"\nA binary tree is a hierarchical data structure whose behavior is similar to a tree. It contains a root and each node of the tree can have atmost two child nodes."<<endl;
            cout<<"\nIn this process, we will at first take input of the Inorder and Preorder traversals from the user.\nStarting with the root node, which will be the first item in the Preorder sequence, we will find the boundary of its left and right sub-tree from the Inorder sequence."<<endl;
            cout<<"\nThis is done by searching for the index of the root node in the Inorder sequence.\nOnce that is found, all of the nodes before the root node in the Inorder sequence becomes part of the left subtree and all nodes after the root node becomes part of the right subtree."<<endl;
            cout<<"\nThis task is repeated recursively for all the nodes in the tree by using a recursive function and we are able to construct the binary tree in the process."<<endl;
            cout<<"\nLastly, we will check whether the built binary tree have the same traversals as those that have been inputted to construct the tree in the first place."<<endl;
            cout<<"\nYou can kindly try out the following process below"<<endl;
            cout<<"(Some sample inputs can be found in the main() function for your convenience)\n\n"<<endl;


            /* Some sample Inorder and Preorder traversals that can be tested with the program:

            i) Inorder Traversal =   7 8 0 3 1 2 4 5 6 9
                Preorder Traversal =  1 3 8 7 0 6 4 2 5 9

            ii) Inorder Traversal =   10   15   20   23   25   30   35   39   42
                Preorder Traversal =  30   20   10   15   25   23   39   35   42

            iii) Inorder Traversal =   4    10   12   15   18   22   24   25   31   35   44   50   66   70   90
                Preorder Traversal =  25   15   10    4   12   22   18   24   50   35   31   44   70   66   90
            */

            int in, pre, num;
            cout<<"Please enter the length of your Inorder/Preorder traversal sequence: ";
            cin>>num;
            int inorder[num], preorder[num];

            cout<<"\nPlease enter the Inorder traversal (provide spaces between the elements): ";
            for(int i=0; i<num; i++){
                cin>>in;
                inorder[i] = in;
            }

            cout<<"\nPlease enter the Preorder traversal (provide spaces between the elements): ";
            for(int i=0; i<num; i++){
                cin>>pre;
                preorder[i] = pre;
            }

            int len = sizeof(inorder) / sizeof(inorder[0]);

            Node *root = constructTree(inorder, preorder, 0, len - 1);      //Building the binary tree and setting the root node

            cout<<"\nThe binary tree is constructed successfully from the given Inorder and Preorder Traversals!"<<endl;

            //Testing the built tree by printing the Preorder and the Inorder traversal
            cout << "\nInorder traversal of the constructed tree is: \n";
            InorderTraversal(root);

            cout<<"\n\nPreorder traversal of the constructed tree is: \n";
            PreorderTraversal(root);

            cout<<"\n"<<endl;
        }


        cout<<"Do you want to continue testing out other recursion levels or do you want to quit the program?"<<endl;

        char m;
        do{
            cout<<"Enter 'y' to continue and 'n' to exit: ";
            cin>>m;
        }while(m != 'y' && m != 'n');     //data validation

        if(m == 'n'){
            cout<<"\nThank you so much for using our program. Have a nice day!"<<endl;
            break;
        }

    }
    return 0;
}
