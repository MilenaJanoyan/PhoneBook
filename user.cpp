#include "user.h"

UserEntry::UserEntry (const string& _name, const string& _surname, const string& _separator, const string& _phone):
            m_name{_name},
                m_surname{_surname},
                    m_separator{_separator},
                        m_phone{_phone},
                            m_is_valid_entry{false}
{

}

string UserEntry::get_name(void) const
{
    return this->m_name;
}

string UserEntry::get_surname(void) const
{
    return this->m_surname;
}

string UserEntry::get_separator(void) const
{
    return this->m_separator;
}

string UserEntry::get_phone(void) const
{
    return this->m_phone;
}

bool UserEntry::is_valid(void) const
{
    return this->m_is_valid_entry;
}

void UserEntry::set_valid(bool valid)
{
    m_is_valid_entry = valid;
}

string UserEntry::dump_entry(void) const
{
    string result_string; 
    result_string.append(m_name);
    result_string.append(" ");
    result_string.append(m_surname);
    result_string.append(" ");
    result_string.append(m_separator);
    result_string.append(" ");
    result_string.append(m_phone);
    return result_string;
}