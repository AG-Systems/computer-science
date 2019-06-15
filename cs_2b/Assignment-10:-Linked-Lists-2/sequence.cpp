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
            insert(node.current());
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



    /* 
    void Sequence::attach(const value_type& entry) 
    {
        // Postcondition: A new copy of entry has been inserted in the Sequence after the current 
        // item. If there was no current item, then the new entry has been attached to the end of 
        // the Sequence. In either case, the new item is now the current item of the Sequence.
        if(is_item() && cursor->next != nullptr)
        {
            node* new_node = new node;
            node* temp = cursor->next;
            new_node->data = entry;
            cursor->next = new_node;
            temp->next = new_node;
            cursor = temp;
            num_items++;
            
        } else {
            
            if(is_item())
            {
                node* new_node = new node;
                new_node->data = entry;
                cursor->next = new_node;
                cursor = cursor->next;
                num_items++;
            } else {

            }
            
        }
    }
    */
    void Sequence::attach(const value_type& entry) {
        
        node* new_node = new node;
        new_node->data = entry;
        num_items++;
        
        if (cursor == tail_ptr || cursor == nullptr) { 
            if(num_items == 1)
            {
                head_ptr = new_node;
            } else {
                tail_ptr->next = new_node;
                
            }
            tail_ptr = new_node;
        } else {  
            node* temp = cursor->next;
            precursor = cursor;

            cursor->next = new_node;
            new_node->next = temp;
        }
        
        cursor = new_node;
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
        } else {
           throw; 
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