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

    Sequence::~Sequence()
    {
        clear();
    }

    Sequence::Sequence(Sequence &node)
    {
        copy(node);
    }

    Sequence& Sequence::operator=(Sequence &copied_linked_list)
    {
        copy(copied_linked_list);
    }

    Sequence::Sequence(int val)
    {

    }

    void Sequence::copy(Sequence &node) // Still needs to be completed
    {
        head_ptr = nullptr;
        cursor = nullptr;
        tail_ptr = nullptr;
        precursor = nullptr;
        num_items = 0;

        while(node.advance() != nullptr)
        {
            insert(node);
            node.advance();
        }
                    
    }

    void Sequence::clear()
    {
        delete cursor;
        delete head_ptr;
        delete tail_ptr;
        delete precursor;
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

    void Sequence::attach(const value_type& entry) 
    {
        // Postcondition: A new copy of entry has been inserted in the Sequence after the current 
        // item. If there was no current item, then the new entry has been attached to the end of 
        // the Sequence. In either case, the new item is now the current item of the Sequence.
        if(is_item())
        {
            num_items++;
            node* temp = cursor->next;

            node* new_node = new node;
            new_node->data = entry;

            cursor->next = new_node;
            new_node->next = temp;
            
        } else {
            insert(entry);
        }
    } 


    void Sequence::remove_current() 
    {
        if(is_item())
        {
            num_items--;
            if(cursor->next == nullptr)
            {
                delete cursor;
            } else {
                /* 
                node* temp_node = new node;
                temp_node = cursor->next;

                cursor = precursor;
                cursor->next = temp_node;
                */
                node* temp = cursor->next;  
                cursor->data = temp->data;  
                cursor->next = temp->next;  
                delete temp;
            }


        }
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