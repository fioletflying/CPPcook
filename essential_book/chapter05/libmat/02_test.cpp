#include <iostream>
#include"LibMat.hpp"

void print(const LibMat &mat)
{
    cout << "in global print(): about to print mat.print()\n";

    mat.print();
}

int main()
{
    // LibMat libmat;
    // print(libmat);

    cout << "--------------------" << endl;

    Book b( "The Castle", "Franz Kafka");
    print(b);

    cout <<"\n --------------------\n " <<endl;

    AudioBook ab("Mason and Dixon", "Thomas Pynchon", "Edwin Leonard");
    print(ab);

    return 0;
}

