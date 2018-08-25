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
        T get(int position);
        void concat(List<T> &other);
        bool empty();
        int size();
        void print(){
            Node<T> *temp = head;
            while(temp != tail){
                cout<< temp->data<<" ";
                temp = temp->next;
            }
            cout<<temp->data<<" ";
        };
        void print_reverse();
        void clear();
        Iterator<T> begin();
        Iterator<T> end();

        ~List();
};
#endif
