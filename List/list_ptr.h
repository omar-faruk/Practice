#ifndef LISTPTR_H
#define LISTPTR_H

#include <string.h>
#include <stdlib.h>

template <class T,int allowed_size>
class List{

    struct node{
        T data;
        node *next;
    };

private:
    node *head,*tail;
    int list_size;
    int max_size;

public:
    List()
    {
        head = NULL;
        tail = NULL;
        max_size = allowed_size;
        list_size = 0;
    }

    int size() {
        return list_size;
    }

    void insert(T element) {
        if(list_size == 0){
            head = new node;
            tail = head;
        }
        node *itr = tail;
        itr->data = element;
        itr->next = new node;
        tail = itr->next;
        list_size++;
    }

    T first() {
        return head->data;
    }

    T last() {
        node *itr = head;
        int count = 1;
        while(true){
            if(count==list_size){
                return itr->data;
            }
            itr = itr->next;
            count++;
        }
    }

    bool exist(T element){
        node *itr = head;
        int count=0;
        while(count<list_size){
            if(element == itr->data){
                return true;
            }
            itr = itr->next;
            count++;
        }
        return false;
    }
};


#endif
