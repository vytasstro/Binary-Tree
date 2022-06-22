#include <iostream>
#include <stack>
using namespace std;


struct node
{
	int data;
	node *left;
	node *right;	
};

class BinarySearchTree
{
	private:
		node *root;
	public:
		BinarySearchTree()  
		{
			root = NULL; 
		}
		
		~BinarySearchTree()  
		{
			//
		}
		
		void displayKVD(node * temp) // Left-Top-Right
		{
			if (temp != nullptr)
			{
				displayKVD(temp->left);
				cout << temp->data << " ";
				displayKVD(temp->right);
			}
		}
		

		void displayKDV(node * temp)  //Left-Right-Top
		{
			if (temp != nullptr)
			{
				displayKDV(temp->left); 
				displayKDV(temp->right);
				cout << temp->data << " ";
			}
		}
		
		void displayVKD(node * temp) // Top-Left-Right
		{
			if (temp != nullptr)
			{
				cout << temp->data << " ";
				displayVKD(temp->left);
				displayVKD(temp->right);
			}
		}
		
		void insertNode(int value)
		{
			node *newNode = new node;
			newNode->data = value;    
			newNode->left = nullptr;
			newNode->right = nullptr;
			
			if (isEmpty(root))
			{
				root = newNode;
				return;
			}
			
			node *pos = root;    // Find a place where to insert node
			node *prev = nullptr;   // Remembering the top, to connect it later
			
			while (!isEmpty(pos))
			{
				prev = pos;
				if (value < pos->data)
					pos = pos->left;
				else
					pos = pos->right;
			}
			
			if (value < prev->data) // connect the unit to the tree
				prev->left = newNode;
			else
				prev->right = newNode;
		}
		node* getRoot()
		{
			return root;
		}
		bool isEmpty(node * temp)
		{
			if (temp == nullptr)
				return true;
			else
				return false;
		}
		void search(node * &temp, int value)//void search();
		{
			while (!isEmpty(temp))
			{
				if (temp->data == value)
					return;
				else if (temp->data > value)
				{
					temp = temp->left;
					continue;
				}
				else if (temp->data < value)
				{
					temp = temp->right;
					continue;
				}
			}
		}
		void clearTree(node * &temp)
		{
			if (isEmpty(temp))
				return;

			clearTree(temp->left);
			clearTree(temp->right);
			
			temp = nullptr;
			delete temp;
			root = temp;
			
				
		}
		void deleteNode(node* &temp, int value)
		{
			if (isEmpty(temp)) 
			{
				return;
			}
			//Going left from the temp node
			if (value < temp->data) 
			{
				deleteNode(temp->left, value);
			}

			//Going Right from the temp node
			else if (value > temp->data) 
			{
				deleteNode(temp->right, value);
			}
			//If Found the node
			else if(value == temp->data)
			{
				//If Doesn't have children
				if (temp->left == nullptr && temp->right == nullptr)
				{
					if (root->data == value)
					{
						clearTree(root);
					}
					else
					{
						delete temp;
						temp = nullptr;
					}
				}

				//Both children
				else if (temp->left && temp->right)
				{
					node* a = temp->left;
					//Looking for substitution of the node
					getMaximumNode(a);
					temp->data = a->data;

					deleteNode(temp->left, a->data);
				}

				//If One child
				else 
				{
					node* child;

					if (temp->left == nullptr)
					{
						child = temp->right;
					}
					else
					{
						child = temp->left;
					}
					cout << child << endl;
					node* curr = temp;
					temp = child;
					cout << temp << endl;
					delete curr;
					curr = nullptr;
				}
				cout << "Node " << value << " is deleted" << endl;
			}
			else
			{
				cout << " Node " << value << " is not in the tree" << endl;
			}
		}
		void getMaximumNode(node *&temp)
		{
			while (temp->right != nullptr)
			{
				temp = temp->right;
			}
		}

};
void menu()
{
	cout << "Search Binary Tree" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "[1] Search Node" << endl;
	cout << "[2] Insert Node" << endl;
	cout << "[3] Delete Node" << endl;
	cout << "[4] Is Tree Empty?" << endl;
	cout << "[5] Display Tree" << endl;
	cout << "[6] Clear Tree" << endl;
	cout << "[0] Exit Program" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "To make a selection, please enter a number: ";
}
int main()
{
	BinarySearchTree BST;
	node* temproot = new node;
	int n;
	int value;
	while (true)
	{
		temproot = BST.getRoot();
		system("CLS");
		menu();
		cin >> n;
		switch (n)
		{
		default:
			break;

		case 0:
			return 0;
			
		case 1:
			system("CLS");
			cout << "Node search" << endl;
			cout << "Please enter the node number:";
			cin >> value;
			BST.search(temproot, value);
			if (temproot != nullptr)
				cout << "Node " << value << " is in the tree" << endl;
			else
				cout << "Node " << value << " is not in the tree" << endl;
			system("pause");
			break;

		case 2:
			system("CLS");
			cout << "Node insertion" << endl;
			cout << "Please enter the node number:";
			cin >> value;
			BST.insertNode(value);
			cout << "Node " << value << " added!" << endl;
			system("pause");
			break;

		case 3:
			system("CLS");
			cout << "Node deletion" << endl;
			cout << "Please enter the node number:";
			cin >> value;
			BST.deleteNode(temproot, value);
			system("pause");
			break;
			
		case 4:
			system("CLS");
			if (BST.isEmpty(temproot))
				cout << "Tree is empty" << endl;
			else
				cout << "Tree is not empty" << endl;
			system("pause");
			break;
		case 5:
			system("CLS");
			cout << "Tree display" << endl;
			cout << "[1]KVD" << endl;
			cout << "[2]KDV" << endl;
			cout << "[3]VKD" << endl;
			cout << "Enter your choice:";
			cin >> n;
			switch (n)
			{
			default:
				break;
				
			case 1:
				system("CLS");
				BST.displayKVD(temproot);
				cout << endl;
				system("pause");
				break;

			case 2:
				system("CLS");
				BST.displayKDV(temproot);
				cout << endl;
				system("pause");
				break;

			case 3:
				system("CLS");
				BST.displayVKD(temproot);
				cout << endl;
				system("pause");
				break;
			}
			break;
		case 6:
			system("CLS");
			BST.clearTree(temproot);
			cout << "Tree is cleared" << endl;
			system("pause");
			break;
		}
	}
}
