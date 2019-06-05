#ifndef SEQUENCE_H
#define SEQUENCE_H


#include <iostream>



namespace cs_sequence {

   class Sequence
   { 
        typedef size_t size_type;
        typedef int value_type;
        
      public:
        Sequence();
        void start();
        void advance();
        void insert(const value_type& entry); 
        void attach(const value_type& entry); // NOT REQUIRED
        void remove_current(); // NOT REQUIRED
        size_type size() const;
        bool is_item() const;
        value_type current() const;

       private:
        struct node {
            value_type data;
            node* next;
        };
        int num_items;
        node* head_ptr;
        node* tail_ptr;
        node* cursor;
        node* precursor;


   };   

}

#endif