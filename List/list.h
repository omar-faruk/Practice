//
// Created by munna on 7/15/18.
//

#ifndef LIST_H
#define LIST_H

#include <string.h>
#include <stdlib.h>
#include <cstdio>


template <class T,int max_size>

class List{
private:
    int head_index,tail_index;
    int max_allowed_size;

    T data[max_size];

public:
    List(){
        head_index = tail_index = 0;
        max_allowed_size = max_size;
    }

    T first(){
        return data[head_index];
    }

    T last(){
        return data[tail_index-1];
    }

    int size(){
        return tail_index;
    }

    //insert item into the list in sorted (ascending) order
    int insert(T element){

        int element_index;
       // printf("inserting element: %f \n",element);

        if(tail_index==max_allowed_size){
            puts("List Overflow!!");
            return -1;
        }

        else{
            T tmp;
            int flag = 0;

            if(tail_index==head_index){
                data[head_index] = element;
                element_index = head_index;
                tail_index++;
                return element_index;
            }
            else{

                int i,idx,flag = 0;

                for(i = 0; i < tail_index; i++){
                    if(data[i] >= element){
                        idx = i;
                        flag = 1;
                        break;
                    }
                }

                if(flag){
                    for(i = tail_index; i > idx; i--){
                        data[i] = data[i-1];
                    }
                }

                else{
                    idx = tail_index;
                }

                data[idx] = element;
                element_index = idx;
                tail_index++;
            }
        }

        return element_index;
    }

    int exist(T element){
        int start = head_index;
        int end = tail_index-1;
        int mid;

        int element_index = -1;

        //use binary search to find the element
        while(start<=end){
            mid = ((start + end) / 2);

            if(data[mid] == element){
                return mid;
            }

            if(element>data[mid]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return element_index;
    }

    void printList(){
        int i;
        for(i = 0; i < tail_index; i++){
            data[i].print();
        }
    }


};

#endif //LIST_LIST_H
