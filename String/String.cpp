#include <iostream>
#include <string.h>
#include <math.h>
#include "String.h"
using namespace std;

// resize function
void String::resize(int new_capacity)
{
    // 1. Create a block of new_capacity
    // 2. Copy elements from old char array
    // 3. Delete the old char array
    char *new_string = new char[new_capacity];

    // copy
    for (int i = 0; i < m_size; i++)
    {
        new_string[i] = m_data[i];
    }

    // delete old m_data
    // deleting array... problem caused
    delete[] m_data;

    // pass reference of new_string to m_data
    m_data = new_string;

    // m_capacity
    m_capacity = new_capacity;
}

/*

@ All the constructors will go here

*/
String::String()
{
    // initialize with a size of 2
    // default resize to 2
    resize(2);
}

String::String(const char *initializer_string)
{
    // do this thing at any cost
    // m_data is empty
    // strlen(initializer_string) --> size
    // capacity ()
    m_data = (char *)initializer_string;

    m_size = strlen(initializer_string);

    // fix capacity
    m_capacity = pow(2, ((m_size / 2) + 1));
}

// lets create this function
void String::operator=(const char *char_string)
{
    char *temp = (char *)char_string;
    while (temp != nullptr)
    {
        this->push_back(*temp);
        temp++;
    }
    // m_data = const char *
    // size
    // capacity
}

// overload [] operator
char &String::operator[](int index)
{

    if (index >= m_size || index < 0)
    {
        char error_message = '#';
        cerr << "Invalid index value" << endl;
        return error_message;
    }
    return m_data[index];
}

ostream &operator<<(ostream &os, const String &str)
{
    os << str.m_data;
    return os;
}
/////////////////////////////////////////

void String::push_back(char ch)
{
    // if no capacity
    if (m_size >= m_capacity)
    {
        resize(m_capacity * 2);
    }

    m_data[m_size++] = ch;
}

int String::size()
{
    return m_size;
}

// overload + operator
String String::operator+(String string_2)
{
    // adding two strings
    String result;
    for (int i = 0; i < size(); i++)
    {
        result.push_back(m_data[i]);
    }

    for (int i = 0; i < string_2.size(); i++)
    {
        result.push_back(string_2[i]);
    }

    return result;
}

void String::operator+=(const String &str)
{
    // change the value of this->m_data
    (*this) = (*this) + str;
}

String String::substr(int starting_idx, int num_elements)
{
    String result;

    // assertions
    if ((starting_idx + num_elements) >= m_size)
    {
        cerr << "Error.. Invalid parameters" << endl;
        return "";
    }

    for (int i = starting_idx; i < (starting_idx + num_elements); i++)
    {
        result.push_back(m_data[i]);
    }

    return result;
}