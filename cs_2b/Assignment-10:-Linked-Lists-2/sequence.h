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
        ~Sequence();

        Sequence(const Sequence &node);
        Sequence(int val);

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
            size_type data;
            node* next;
        };
        int num_items; // stores the number of items in the Sequence.
        node* head_ptr;
        node* tail_ptr;
        node* cursor;
        node* precursor;
        void copy();
        void clear();


   };   

}

#endif