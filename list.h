#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;


    void print_reverse(Node<T>* head);

public:
    int nodes;
    List(){
        head = NULL;
        tail = NULL;
    };

    T front(){
        if(!head){
            throw "322";
        }
        return head->data;
    };
    T back(){
        if(!head){
            throw "322";
        }
        return tail->data;
    };
    void push_front(T value){
        Node<T> *temp=new Node<T>;
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else{
            temp->next=head;
            head=temp;}
        nodes++;
    };
    void push_back(T value){
        Node<T> *temp=new Node<T>;
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
        nodes++;
    };
    void pop_front(){
        Node<T> *temp = head;
        if(!head){
            throw "Lista Vacia";
        }
        else if(nodes == 1){
            delete head;
        }
        else{
            head = temp->next;

        }
        delete temp;
        nodes--;
    };
    void pop_back(){
        auto *temp = head;
        if(!head){
            throw "Lista Vacia";
        }
        if(nodes == 1){
            delete head;
        }
        else
        {
            while(temp->next != tail){
                temp = temp->next;
            }

            tail = temp;
            temp = temp->next;
        }
        nodes--;
        delete temp;
    };
    T get(int position){
        try{
            if(position <= nodes-1){
                if(position==0) {
                    return head->data;
                }
              else if(position == nodes-1){
                return tail->data;}
                else{ auto temp = head;
                while (position--){temp=temp->next;}
                return temp->data;}}
            else{throw position;}
        }catch(int position){
            cout<<"\nNo existe indice "<<position<<"\n";
        }
    };
    void concat(List<T> &other);
    bool empty(){
        if(nodes > 0)return false;
        else return true;
    };
    int size(){
        return nodes;
    };
    void print(){
        Node<T> *temp = head;
        while(temp != tail){
            cout<< temp->data<<" ";
            temp = temp->next;
        }
        cout<<temp->data<<" ";
    };
    void print_reverse(){Node<T> *temp = tail;
        while(temp != head){
            cout<< temp->data<<" ";
            temp = temp->next;
        }
        cout<<temp->data<<" ";}
    void clear(){
        Node<T> *temp = head;
        while(temp != tail){
            temp->data = NULL;
            temp = temp->next;
        }
        temp->data=NULL;
    };
    Iterator<T> begin();
    Iterator<T> end();

    ~List();
};
#endif