#include "qh_string.h"

#include <string.h>

namespace qh
{
    // TODO 将在这里写实现代码

    string::string()
        : data_(NULL), len_(0)
    {
        data_ = new char[1];
        data_[0] = '\0';
    }

    string::string( const char* s )
    {
        len_ = strlen(s);
        data_ = new char(len_ + 1);
        memcpy(data_, s, len_ + 1);
    }

    string::string( const char* s, size_t len )
    {
        len_ = len;
        data_ = new char(len_ + 1);
        memcpy(data_, s, len_ + 1);
    }

    string::string( const string& rhs )
    {
        len_ = rhs.size();
        data_ = new char[len_ + 1];
        memcpy(data_, rhs.data(), len_ + 1);
    }

    string& string::operator=( const string& rhs )
    {
        if(data_) delete[] data_;
        data_ = NULL;
        len_ = rhs.size();
        data_ = new char[len_ + 1];
        memcpy(data_, rhs.data(), len_ + 1);
        return *this;
    }

    string::~string()
    {
        if(data_) delete[] data_;
        data_ = NULL;
    }

    size_t string::size() const
    {
        return len_;
    }

    const char* string::data() const
    {
        return data_;
    }

    const char* string::c_str() const
    {
        return data_;
    }

    char* string::operator[]( size_t index )
    {
        return NULL;
    }

    bool string::operator==(const string &rhs)
    {
        return strcmp(data_, rhs.data_) == 0;
    }
}
