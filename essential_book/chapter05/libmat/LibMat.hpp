#ifndef __LIBMAT__
#define __LIBMAT__

#include<iostream>
#include<string>


using namespace std;


class LibMat
{

public:
    LibMat() { cout << "LibMat::LibMat() default constructor!\n"; }

    virtual ~LibMat() { cout << "LibMat::~LibMat() destructor!\n"; }

    virtual void print() const
    {
        cout << "LibMat::print()  -- I am a LibMat object!\n";
    }


};

class Book : public LibMat
{
public:
    Book( const string &title, const string &author )
        :_title(title), _author( author )
    {
        cout << "Book::Book( " << _title << ", " <<_author 
            << " ) constructor\n";
    }

    virtual ~Book()
    {
        cout << "Book::~Book() destructor!\n";
    }

    virtual void print() const
    {
        cout << "Book::print() -- I am a Book object!\n"
            << "My title is: " << _title << '\n'
            << "My author is: " << _author <<endl;
    }

    const string& title() const { return _title; }
    const string& author() const { return _author; }

protected:
    string _title;
    string _author;
};

class AudioBook : public Book
{
public:
    AudioBook( const string &title, 
                const string &author, 
                const string &narrator )
        : Book( title, author ), _narrator(narrator)
        {
            cout << "AudioBook::AudioBook( " << title
                <<", "<<_author
                <<", "<<_narrator
                <<" ) constructor\n";
        }

    ~AudioBook()
    {
        cout << "AudioBook::~AudioBook() destructor!\n";
    }

    virtual void print() const{
        cout << "AudioBook::print() -- I am an AudioBook object!\n"
            <<"My title is: " << _title << '\n'
            <<"My author is: " << _author <<'\n'
            <<"My narrator is: " <<_narrator<<endl;
    }

    const string& narrator() const { return _narrator; }

    
protected:
    string _narrator;

};





#endif