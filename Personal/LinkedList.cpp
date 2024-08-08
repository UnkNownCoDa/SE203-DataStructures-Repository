#include <iostream>

class Node{
public:
    int data;
    Node *next;
    Node(int add){
        data = add;
        next = NULL;
    }
};

class LinkedList{
public:
    Node *head;
    void print(){
        Node *ptr;
        if (head == NULL){
            std::cout<<"Empty List\n";
            return;
        }
        ptr = head;
        std::cout<<"List: ";
        while (ptr->next != NULL){
            std::cout<<ptr->data<<"->";
            ptr = ptr->next;
        }
        std::cout<<ptr->data<<"->END\n";
    }
//Insert functions
    void insertEnd(int data){
        Node *ptr;
        if (head == NULL){
            head = new Node(data);
            return;
        }
        for (ptr = head; ptr->next != NULL; ptr = ptr->next);
        ptr->next = new Node(data);
        return;
    }

    void insertBegining(int data){
        Node *ptr;
        ptr = new Node(data);
        if (head == NULL){
            head = ptr;
            return;
        }
        ptr->next = head;
        head = ptr;

    }
//Delete functions
    void deleteEnd(void){
        Node *ptr;
        if (head == NULL){
            std::cout<<"List is already empty!\n";
            return;
        }
        for (ptr = head; ptr->next->next != NULL; ptr = ptr->next);
        free(ptr->next->next);
        ptr->next = NULL;
    }

    void deleteBeginning(void){
        Node *ptr;
        ptr = head->next;
        free(head);
        head = ptr;
    }

    void deleteElement(int data){
        Node *ptr;
        if (head == NULL){
            std::cout<<"List is already empty!\n";
            return;
        }
        if (head->data == data){
            deleteBeginning();
            return;
        }
        for (ptr = head; ptr->next->next != NULL; ptr = ptr->next){
            if (ptr->next->data == data){
                ptr->next = ptr->next->next;
                free(ptr->next);
                return;
            }
        }
        if (ptr->next->data == data){
            deleteEnd();
            return;
        }
        std::cout<<"Element not found!\n";
        return;
    }
//search function
    void searchElement(int data){
        Node *ptr;
        if (head == NULL){
            std::cout<<"List is empty!\n";
            return;
        }
        for (ptr = head; ptr->next != NULL; ptr = ptr->next){
            if (ptr->data == data){
                std::cout<<"Element is in the list";
                return;
            }
        }
        if (ptr->data == data){
            std::cout<<"Element is in the list\n";
            return;
        }
        std::cout<<"Element not found!\n";
        return;
    }
};

int main(void){
    LinkedList list;
    int data;
    list.head = NULL;
    list.print();
    for (int i = 0; i < 10; ++i){
        list.insertBegining(i);
    }
    list.print();
    list.deleteEnd();
    list.print();
    list.insertBegining(100);
    list.print();
    list.deleteBeginning();
    list.print();
    std::cout<<"Enter data to delete: ";
    std::cin>>data;
    list.deleteElement(data);
    list.print();
    std::cout<<"Enter data to serch: ";
    std::cin>>data;
    list.searchElement(data);
    list.print();
    return 0;
}
