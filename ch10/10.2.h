//
// Created by makodo on 2020/12/15.
//

#ifndef CH10_2_h
#define CH10_2_h

#include "/Users/jiangrenjie/Documents/clrs/print/print.h"
#include "List.h"

namespace CLRS{ namespace CH10{
    template <typename T>
    ListNode<T>* list_search(List<T>& L, T k){
        ListNode<T>* x = L.head;
        while(x != nullptr && x -> key != k){
            x = x -> next;
        }
        return x;
    }

    template <typename T>
    void list_insert(List<T>& L, ListNode<T>* x) {
        x->next = L.head;
        if (L.head != nullptr)
            L.head->prev = x;
        L.head = x;
        x -> prev = nullptr;
    }

    template <typename T>
    void list_delete(List<T>& L, ListNode<T>* x){
        if(x -> prev != nullptr)
            x -> prev -> next = x -> next;
        else
            L.head = x -> next;
        if(x -> next != nullptr)
            x -> next -> prev = x -> prev;
    }

    template <typename T>
    void list_delete_(List<T>& L, ListNode<T>* x){
        x -> prev -> next = x -> next;
        x -> next -> prev = x -> prev;
    }

    template <typename T>
    ListNode<T>* list_search_(List<T>& L, T k){
        ListNode<T>* x = L.nil -> next;
        while(x != L.nul && x -> key != k){
            x = x -> next;
        }
        return x;
    }

    template <typename T>
    void list_insert_(List<T>& L, ListNode<T>& x){
        x -> next = L.nil -> next;
        L.nil -> next -> prev = x;
        L.nil -> next = x;
        x -> prev = L.nil;
    }

    template <typename T>
    void list_insert_single(List<T>& L, ListNode<T>& x){
        x -> next = L.head;
        L.head = x;
    }

    template <typename T>
    void list_delete_single(List<T>& L, ListNode<T>* x){
         ListNode<T>* head = L.head;
         ListNode<T>* hair = head -> prev;
         while(head != x){
             hair = head;
             head = head -> next;
         }
         hair -> next = head -> next;
    }

    template <typename T>
    void list_push(List<T>& L, ListNode<T>& x){
        x -> next = L.head;
        L.head -> prev = x;
        L.head = x;
    }

    template <typename T>
    ListNode<T>* list_pop(List<T>& L){
        ListNode<T>& temp = L.head;
        L.head = L.head -> next;
        L.head -> prev = nullptr;
        return temp;
    }

    template <typename T>
    void list_enqueue(List<T>& L, ListNode<T>& x, T t){
        ListNode<T> input;
        input -> prev = x;
        x -> next = input;
        input.key = t;
    }

    template <typename T>
    void single_insert(List<T>& L, ListNode<T>& x){
        ListNode<T> head = L.head;
        ListNode<T> hair;
        while(head != x){
            hair = head;
            head = head -> next;
        }
        hair -> next = x;
        x -> next = head -> next;

    }

    template <typename T>
    ListNode<T>* single_delete(List<T>& L, ListNode<T>& x){
        ListNode<T> head = L.head;
        ListNode<T> hair;
        while(head != x){
            hair = head;
            head = head -> next;
        }
        hair -> next = head -> next;
    }

    template <typename T>
    ListNode<T>* single_search(List<T>& L, ListNode<T>& x){
        ListNode<T> head = L.head;
        while(head != x){
            head = head -> next;
        }
        return head;
    }

    template <typename T>
    void reverse(List<T>& L){
        ListNode<T> a = L -> head -> next;
        ListNode<T> b = L -> head;
        while(a != nullptr){
            ListNode<T> temp = a.next;
            a -> next = b;
            b = a;
            a = temp;
        }
        L.head = b;
    }

} } // namespace

#endif