#include <iostream>

class Node{
public:
    int data;
    Node *next;
    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int add){
        this->data = add;
        this->next = NULL;
    }
};

class LinkedList{
public:
    Node *head;
    LinkedList(){
        this->head = NULL;
    }
    LinkedList(int data){
        this->head = new Node(data);
    }
    int isEmpty(void){
        return this->head == NULL;
    }
//Print function
    void print(){
        Node *ptr;
        if (this->isEmpty()){
            std::cout<<"\n\nList: Empty\n\n";
            return;
        }
        ptr = this->head;
        std::cout<<"\n\nList: ";
        while (ptr->next != NULL){
            std::cout<<ptr->data<<"->";
            ptr = ptr->next;
        }
        std::cout<<ptr->data<<"->END\n\n";
    }

//Delete functions
    void deleteEnd(void){
        Node *ptr;
        if (this->isEmpty()){
            std::cout<<"List is already empty!\n";
            return;
        }
        for (ptr = this->head; ptr->next != NULL; ptr = ptr->next);
        delete ptr;
        ptr->next = NULL;
    }

    void deleteBeginning(void){
        Node *ptr;
        if (this->isEmpty()){
            std::cout<<"List is already empty!\n";
            return;
        }
        ptr = this->head;
        this->head = ptr->next;
        delete ptr;
    }

    void deleteElement(int data){
        Node *ptr, *nextPtr;
        ptr = this->head;
        if (ptr == NULL){
            std::cout<<"List is already empty!\n";
            return;
        }
        if (ptr->data == data){
            deleteBeginning();
            return;
        }
        for (nextPtr = ptr->next; nextPtr != NULL; nextPtr = ptr->next ){
            
            if (nextPtr->data == data){
                ptr->next = nextPtr->next;
                delete nextPtr;
                return;
            }
            ptr = nextPtr;
        }
        std::cout<<"Element not found!\n";
        return;
    }
//Insert functions
    void insertEnd(int data){
        Node *ptr;
        if (this->isEmpty()){
            this->head = new Node(data);
            return;
        }
        for (ptr = this->head; ptr->next != NULL; ptr = ptr->next);
        ptr->next = new Node(data);
        return;
    }

    void insertBegining(int data){
        Node *ptr;
        ptr = new Node(data);
        if (this->isEmpty()){
            this->head = ptr;
            return;
        }
        ptr->next = this->head;
        this->head = ptr;
    }
};
int main(){
    LinkedList list;
    int size, data;

    std::cout<<"Enter size of list: ";
    std::cin>>size;

    for (int i = 0; i < size; i++){
        std::cin>>data;
        list.insertEnd(data);
    }
    list.print();
    return 0;
}