#include "FHvector.h"
#include "FHlist.h"
#include <iostream>
#include <vector>



using namespace std;

template <class Object>
class MatNode
{
    protected:
        int col;

    public:
        Object data;
        // we need a default constructor for lists
        MatNode(int cl = 0, Object dt = Object()) : col(cl), data(dt) {}
        int getCol() const { return col; }

        // not optimized yet for set() = defaultVal;  refer to forums
        const Object & operator=( const Object &x ) { return (data = x);}
};

template <class T = int>
class SparseMat 
{
    public:

        SparseMat(int rows, int columns, T def_value)
        {
            num_of_rows = rows;
            num_of_columns = columns;
            default_value = def_value;
            for(int z = 0; z < num_of_rows; z++)
            {
                FHlist<float> c;
                vector_rows.push_back(c);
            }            
        }

        ~SparseMat()
        {
            num_of_rows = 0;
            num_of_columns = 0;
            default_value = 0;  
            /*
            for(int z = 0; z < num_of_rows; z++)
            {
                delete vector_rows[z];
            } 
            */             
        }

        bool set(int row, int column, int val)
        {
            if(row > num_of_rows)
            {
                return false;
            } else {

            }
        }

        void clear()
        {

        }

        
        int get(int row, int column) const {

        }  

        void showSubSquare(int start, int size)
        {

        }

    protected:
        T default_value = 0;
        int num_of_rows = 0;
        int num_of_columns = 0;
        FHlist< MatNode<T> > MatRow;
        FHvector<MatRow> rows;
};
