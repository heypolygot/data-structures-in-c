#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

//Function to create a new node
DNode *dll_new_node(int data){
    DNode *temp = (DNode *)malloc(sizeof(DNode));
    temp->prev = NULL;
    temp->data=data;
    temp->next= NULL;
    return temp;
}


//Function for initialising a new list
Dlist *dll_new_list(){
    Dlist *n_list = (Dlist *)malloc(sizeof(Dlist));
    n_list->len=0;
    if(!n_list) return n_list;
}



//Function to add new node at the beginning.
Dlist *dll_add(Dlist *list, int data){
    if(!list){ 
        printf("List doesn't exist !");
        return NULL;
    }
    DNode *n_node = dll_new_node(data);
    
    if (!list->head){
        list->head = n_node;
        list->tail=n_node;
    }else{
        list->head->prev = n_node;
        n_node->next = list->head;
        list->head = n_node;
    }
    list->len++;
    return list;
}



//Function to push new node at the end of the list.
Dlist *dll_push(Dlist *list, int data){
    if(!list){ 
        printf("List doesn't exist !");
        return NULL;
    }
    DNode *n_node = dll_new_node(data);
    if(list->head==NULL){
        list->head = n_node;
        list->tail = n_node;
    }else{
        DNode *current = list->head;
        while(current->next!=NULL) current = current->next;
        current->next = n_node;
        n_node->prev = current;
        list->tail = n_node;
    }
    list->len++;
    return list;
}



//Function for removing the node at the beginning of the list.
int dll_pop(Dlist *list){
    if(!list){ 
        printf("List doesn't exist !");
        return 0;
    }
    if(!list->head){ 
        printf("List head doesn't exist !");
        return 0;
    }
    DNode *current = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    int pop_data = current->data;
    free(current);
    list->len--;
    return pop_data;
}



//Function to remove the last node from the list.
int dll_remove(Dlist *list){
    if(!list) { 
        printf("List doesn't exist !");
        return 0;
    };
    if(!list->head) { 
        printf("List head doesn't exist !");
        return 0;
    }
    
    DNode *current = list->head, *temp;

    while (current->next!=NULL) current = current->next;
    current->prev->next = NULL;
    list->tail = current->prev;
    int pop_data = current->data;
    free(current);
    list->len--;
    return pop_data;
}



//Function to find weather a given data is present in the list or not.
int dll_find(Dlist *list, int data){
    if(!list) { 
        printf("List doesn't exist !");
        return 0;
    }
    if(!list->head) { 
        printf("List head doesn't exist !");
        return 0;
    }

    DNode *current = list->head;

    int index = 0, count = 0;
    
    while(current!=NULL){
        index++;
        if (current->data == data) {
            count++;
            return index;
        } 
        current = current->next;
    }
    return -1;
}



//Function to print all the nodes 
void dll_display(Dlist *list){
    if(!list) { 
        printf("List doesn't exist !");
        return ;
    };
    if(!list->head) { 
        printf("List doesn't exist !");
        return ;
    }

    DNode *current = list->head;

    int count = 1;
    
    while(current!=NULL){
        printf("Node %d = %d\n", count, current->data );
        count++; 
        current = current->next;
    }
}


//Function for returning the last node value from the list.
int dll_peek(Dlist *list){
    if(!list) { 
        printf("List doesn't exist !");
        return 0;
    };
    if(list->head == NULL) { 
        printf("List doesn't exist !");
        return 0;
    }
    return list->tail->data;
}


//Function for returning the size of the ll.
int dll_size(Dlist *list){
    return list->len;
}


//function which takes input and returns the value given by the user.
int int_input(){
    int num;
    printf("Enter a value:");
    scanf("%d", &num);
    return num;
}