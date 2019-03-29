//
//  SortedLinkList.c
//  lab-1.5-gharrison15
//
//  Created by Grace M. Harrison on 3/29/19.
//  Copyright © 2019 Grace M. Harrison. All rights reserved.
//

#include "SortedLinkList.h"
#include<stdlib.h>

/* List Structure */

typedef struct llnode
{
    int data;
    int key;
    struct llnode *head;
    struct llnode *nextNode;
}llnode;

typedef struct LinkedList{
    // Data is an int
    llnode *head;
}LinkedList;


//this node will be where head is and will keep track of it.
llnode *head = NULL;

/* Driver functions */
void insert(LinkedList list, int data, int key);
/* Function for Printing Linked List */
void print()
{
    llnode *temp = head;
    
    while(temp)
    {
        printf(" %d",temp->data);
        temp = temp->nextNode;
    }
    printf(" \n\n");
}



/* Main method */
int main()
{
    LinkedList listinorder;
    insert(listinorder,360,1);    // Insert 360 at 1st position
    insert(listinorder,222,3);    // Insert 222 at 3rd position
    insert(listinorder,42,2);    // Insert 42 at 2nd position
    insert(listinorder,11,5);    // insert 11 at 5th position
    insert(listinorder,0,4);    // Insert 0 at 4th position
    
    //This always crashed
//    insert(360,1);    // Insert 360 at 1st position
//    insert(222,3);    // Insert 222 at 3rd position
//    insert(42,2);    // Insert 42 at 2nd position
//    insert(11,5);    // insert 11 at 5th position
//    insert(0,4);    // Insert 0 at 4th position
    
    printf("\n Before sorting = ");
    print();
    return 0;
}

/* To sort the linked list */

/* Function for Inserting nodes at defined position */
void insert(LinkedList list, int data, int key){
    
    /* making the tempnode */
    llnode *tempnode = (llnode*)malloc(sizeof(llnode));
    tempnode->data = data;
    tempnode->nextNode = NULL;
    
    //if insert at head
    if(key==1){
        list.head=tempnode;
        tempnode->nextNode = head;
        head = tempnode;
        return ;
    }
    
    //inserting in other places
    llnode *traverse = head;
    for(int i=0; i<key-2; i++)
    {
        traverse = traverse->nextNode;
    }
    tempnode->nextNode = traverse->nextNode;
    traverse->nextNode = tempnode;
}

