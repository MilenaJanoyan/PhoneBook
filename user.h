#pragma once
#include "message.h"
#include <string>
#include <iostream>
using std::string;
using std::cout;

class UserEntry
{
    public:
        UserEntry (const string& _name, const string& _surname, 
                            const string& _separator,  const string& _phone);
        string get_name(void) const;
        string get_surname(void) const;
        string get_separator(void) const;
        string get_phone(void) const;
        bool   is_valid(void) const;
        void set_valid(bool valid);
        string dump_entry(void) const;
    private:
        string m_name;
        string m_surname;
        string m_separator;
        string m_phone;
        bool m_is_valid_entry;
};