#include <iostream>

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(){
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data){
        this ->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Tree{
public:
    Node *root;

    Tree(){
        this->root = NULL;
    }

    Tree(int data){
        this->root = new Node(data);
    }

    int isFree(Node *node){
        return node == NULL;
    }
    int isFull(Node *node){
        return node->left != NULL && node->right == NULL;
    }
    void AddNode(int data){
        Node *node = this->root;
        if (node == NULL){
            this->root = new Node(data);
            return;
        }
        while (node != NULL){
            if (node->data > data){
                if (isFree(node->left)){
                    node->left = new Node(data);
                    return;
                }
                node = node->left;
            }
            else if (node->data <= data){
                if (isFree(node->right)){
                    node->right = new Node(data);
                    return;
                }
                node = node->right;
            }
        }
    }
    int hasChildren(Node *parent){
        return parent->left != NULL || parent->right != NULL;
    }
    void printNode(Node *parent){
        if (!hasChildren(parent)){
            std::cout<<"Parent: "<<parent->data<<" Children: NONE\n";
            return;
        }

        std::cout<<"Parent: "<<parent->data<<" Children: ";
        if (parent->left != NULL){
            std::cout<< parent->left->data << " ";
        }
        if (parent->right != NULL){
            std::cout<<parent->right->data;
        }
        std::cout<<"\n";
        if (parent->left != NULL){
            printNode(parent->left);
        }
        if (parent->right != NULL){
            printNode(parent->right);
        }
    }
    int searchDFS(Node *parent, int element){
        if (!hasChildren(parent)){
            if (parent->data == element){
                return 1;
            }
            return 0;
        }
        if (parent->left != NULL && searchDFS(parent->left, element)){
            return 1;
        }
        if (parent->right != NULL && searchDFS(parent->right, element)){
            return 1;
        }
        if (parent->data == element){
            return 1;
        }
        return 0;
    }
};

int sum(Node *tree){
    if (tree->left == NULL && tree->right == NULL){
        return tree->data;
    }
    return tree->data + sum(tree->left) + sum(tree->right);
}

int convertInt(char *num){
    int result = 0;
    for (int i = 0;num[i] != '\0'; ++i){
        result *= 10;
        result += num[i] - '0';
    }
    return result;
}

int main(int argc, char** argv){
    if (argc != 2){
        std::cout<<"run Command of type: ./a <number>";
        return 1;
    }
    int total;
    Tree *binary = new Tree();
    binary->AddNode(4);
    binary->AddNode(3);
    binary->AddNode(2);
    binary->AddNode(8);
    binary->AddNode(9);
    binary->AddNode(7);
    std::cout<<"Printing Node: \n";
    binary->printNode(binary->root);
    if (binary->searchDFS(binary->root, convertInt(argv[1]))){
        std::cout<<"Element found\n";
    }
    else{
        std::cout<<"Element not found\n";
    }

    return 0;
}