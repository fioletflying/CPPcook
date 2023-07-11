#include<iostream>
#include<vector>

using namespace std;

class num_sequence
{
public:
    typedef void (num_sequence::*PtrType)( int );
    enum ns_type
    {
        ns_unset, 
        ns_fibonacci, 
        ns_pell, 
        ns_lucas,
        ns_triangular,
        ns_square,
        ns_pentagonal
    };

    static ns_type nstype( int num )
    {
        return num <= 0 || num >= num_seq ? ns_unset
                            : static_cast< ns_type > (num);
    }

private:
    vector<int> *_elem;
    PtrType _pmf;
    ns_type _isa;
    

    

};