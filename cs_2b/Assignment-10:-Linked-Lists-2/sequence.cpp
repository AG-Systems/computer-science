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
        copy(node, true);
    }




    Sequence& Sequence::operator=(Sequence &copied_linked_list)
    {
        copy(copied_linked_list, true);
        return *this;
    }




    Sequence::Sequence(int val)
    {

    }




    void Sequence::copy(Sequence &node, bool new_list) // Still needs to be completed
    {
        head_ptr = nullptr;
        cursor = nullptr;
        tail_ptr = nullptr;
        precursor = nullptr;
        num_items = 0;

        while(node.is_item())
        {
            attach(node.current());
            node.advance();
        }          
    }




    void Sequence::clear()
    {
        /* 
        if(cursor)
        {
            delete cursor;
        }
        if(head_ptr)
        {
            delete head_ptr;
        }
        
        if(tail_ptr)
        {
            delete tail_ptr;
        }
        if(precursor)
        {
            delete precursor;
        }
        */
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


    void Sequence::attach(const value_type& entry) {
        /*
        node* temp_cursor = new node;
        node* temp_precursor = new node;
        temp_cursor = cursor;
        temp_precursor = precursor;
        if(is_item())
        {
            temp_precursor = temp_cursor;
            temp_cursor = temp_cursor->next;        
        }

        if(temp_cursor != nullptr && temp_cursor != tail_ptr && num_items > 1 && temp_precursor != nullptr) 
        {
            precursor = cursor;
            cursor = cursor->next;
            insert(entry);
        } else {

            node* new_node = new node;
            new_node->data = entry;
            num_items++;
            if(cursor == tail_ptr && cursor != nullptr)
            {
                cursor = tail_ptr;
                cursor->next = new_node;
                cursor = cursor->next;
                tail_ptr = new_node;
                cursor = new_node;
            }
            else if (cursor != nullptr)
            {
                node* temp = cursor->next;
                new_node->next = temp;
                cursor->next = new_node;
                precursor = cursor;
                cursor = new_node;
            }

            if (num_items == 1) {
                new_node->next = nullptr;
                head_ptr = new_node;
                cursor = new_node;
            }
            
        }
        delete temp_cursor;
        delete temp_precursor;
        */

        node* new_node = new node;
        new_node->data = entry;
        num_items++;

        if(cursor == tail_ptr || cursor == nullptr)
        {

            if(cursor == tail_ptr && cursor != nullptr) /* tail exists  && cursor is at the end */
            {
                cursor->next = new_node;
                tail_ptr = new_node;
                precursor = cursor;
                cursor = cursor->next;
            }

            if(cursor != tail_ptr && cursor == nullptr) /* tail exists && cursor is off */
            {
                cursor = tail_ptr;

                cursor->next = new_node;
                tail_ptr = new_node;
                precursor = cursor;
                cursor = cursor->next;              
            }

            if(cursor == tail_ptr && cursor == nullptr) /* list is empty */
            {
                tail_ptr = new_node;
                head_ptr = new_node;
                precursor = nullptr;
                cursor = new_node;
            }

        } else {
            node* temp = new node;
            temp = cursor->next;
            cursor->next = new_node;
            new_node->next = temp;

            precursor = cursor;
            cursor = cursor->next;
            // delete temp;

        }

    }  


    void Sequence::remove_current() 
    {
        if(is_item())
        {
            num_items--;
            if(cursor->next == nullptr)
            {
                precursor->next = nullptr;
                delete cursor;
            } else {
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
        } else {
           //throw; 
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