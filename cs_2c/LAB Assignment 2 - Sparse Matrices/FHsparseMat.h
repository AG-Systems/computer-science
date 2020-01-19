#include "FHvector.h"
#include "FHlist.h"
#include <iostream>
#include <vector>
#include <iterator>


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
    protected:


        T default_value;
        int num_of_rows = 0;
        int num_of_columns = 0;
        

        typedef FHlist< MatNode<T> > list_columns;
        typedef FHvector<list_columns> Vector;
        
        Vector vector_rows;

    public:

        SparseMat(int rows, int columns, T def_value)
        {
            if(rows >= 1)
            {
                num_of_rows = rows;
            } else {
                num_of_rows = 1;
            }

            if(columns >= 1)
            {
                num_of_columns = columns;
            } else {
                num_of_columns = 1;
            }
            vector_rows.resize(num_of_rows);
            default_value = def_value;        
        }

        ~SparseMat()
        {
            num_of_rows = 0;
            num_of_columns = 0;
            clear();       
        }
        bool set(int row, int column, const T &target_value)
        {
            
            if(row >= num_of_rows || row < 0 || column < 0 || column >= num_of_columns)
            {
                return false;
            } else {
                list_columns& selected_row = vector_rows[row];
                typename list_columns::iterator cur = selected_row.begin();
                while(cur != selected_row.end())
                {
                    
                    int obj_col = (*cur).getCol();
                    if(obj_col == column)
                    {
                        break;
                    }
                    cur++;
                }
                if(target_value == default_value)
                {
                    if(selected_row.end() != cur)
                    {
                        selected_row.erase(cur);
                        return true;
                    }
                    return false;
                } else {
                    if(selected_row.end() == cur)
                    {
                        MatNode<T> Node(column, target_value);
                        selected_row.insert(cur, Node);
                    } else
                    {
                        *cur = target_value;
                    }
                    return true;
                }
                   
            }
            
        }


        void clear()
        {
            
            for(int z = 0; z < num_of_rows; z++)
            {
                vector_rows[z].clear(); // automatically cleans out each list
            }
            // vector_rows.resize(num_of_rows);
            
        }

        const T& get(int row, int column) const {
            if(row >= num_of_rows || row < 0 || column < 0 || column >= num_of_columns)
            {
                throw row;
            }

            typename list_columns::const_iterator cur = vector_rows[row].begin();
            while(cur != vector_rows[row].end())
            {
                
                int obj_col = (*cur).getCol();
                if(obj_col == column)
                {
                    return (*cur).data;
                }
                    
                cur++;
            }

            // throw row; 
            
        }  

        void showSubSquare(int start, int size)
        {
            int length = start + size - 1;
            for(int i = start; i <= length; i++)
            {
                for(int j = start; j <= length; j++)
                {
                    cout << get(i, j) << "  ";
                }
                cout << "\n";
            }
        }


        
};
