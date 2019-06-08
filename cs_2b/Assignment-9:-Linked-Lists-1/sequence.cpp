#include <iostream>
#include "sequence.h"


namespace cs_sequence {

    Sequence::Sequence()
    {
        head_ptr = nullptr;
        cursor = nullptr;
        tail_ptr = nullptr;
        precursor = nullptr;
        num_items = 0;
    }


    void Sequence::insert(const value_type& entry) {
        
        node* new_node = new node;
        new_node->data = entry;
        num_items++;
        
        if (cursor == head_ptr || cursor == nullptr) { // insert at front (or into empty list).
            new_node->next = head_ptr;                 // precursor remains nullptr.
            head_ptr = new_node;
            if (num_items == 1) {
                tail_ptr = new_node;
            }
        } else {                                       // inserting anywhere else
            new_node->next = cursor;                   // tailPtr, headPtr and precursor don't change.
            precursor->next = new_node;
        }
        
        cursor = new_node;
    } 

    void Sequence::attach(const value_type& entry) /* NOT REQUIRED */
    {
        /* NOT REQUIRED */
    } 


    void Sequence::remove_current() /* NOT REQUIRED */
    {
        /* NOT REQUIRED */
    } 

    size_t Sequence::size() const {
        return num_items;
    }

    bool Sequence::is_item() const {
        return cursor != nullptr;            
    }

    int Sequence::current() const {
        if(is_item())
        {
            return cursor->data;
        }
    }

    void Sequence::start() 
    {
        if(head_ptr != nullptr)
        {
            cursor = head_ptr;
            precursor = nullptr;
        }
    } 

    void Sequence::advance() 
    {
        if(is_item())
        {
            precursor = cursor;
            cursor = cursor->next;        
        }

    } 

}