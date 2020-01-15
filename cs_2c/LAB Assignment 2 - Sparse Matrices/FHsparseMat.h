#ifndef SparseMat
#define SparseMat

using namespace std;

namespace cs_sparse {
    template <typename T = int>
    class SpMat {
        public:
            SpMat(int rows, int columns, T def_value)
            {
                num_of_rows = rows;
                num_of_columns = columns;
                // default_value = def_value;
            }

            ~SpMat()
            {
                num_of_rows = 0;
                num_of_columns = 0;
                default_value = 0;                
            }

            bool set(int row, int column, int val)
            {
                
            }
            void clear()
            {

            }

            /*
            const SpMat & get(int row, int column) const {

            }
            */
            
            int get(int row, int column) const {

            }  

            void showSubSquare(int start, int size)
            {

            }

        protected:
            int default_value = 0;
            int num_of_rows = 0;
            int num_of_columns = 0;
    };
    /*
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
    */
}

#endif
