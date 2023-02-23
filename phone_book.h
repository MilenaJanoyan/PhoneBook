#pragma once
#include "user.h"
#include "reader.h"
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

enum class SORT_CRIT 
{
    Name,
    Surname,
    PhoneNumber
};

enum class SORT_ORDER
{
    ASC,
    DESC
};

class PhoneBook 
{
    public:
        PhoneBook (const string& file_path);
        void read_credentials();
        void sort(SORT_CRIT s_c, SORT_ORDER s_t);
        void dump_user_entries(void) const;
        void show_validation_messages(void) const;
    private:
        vector<UserEntry> m_users;
        Reader m_reader;
};