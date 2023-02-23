#pragma once
#include "user.h"
#include "message.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using std::ifstream;
using std::string;
using std::cout;
using std::vector;
using std::stringstream;

class Reader
{
    public:
        Reader (const string& _file_path);
        void fill_credentials(vector<UserEntry>& _users);
        void dump_messages(void) const;
        ~Reader ();
    private:
        UserEntry parse_line(const string& _cred_line, uint32_t _line);
        bool check_entry(const UserEntry& user, uint32_t line);
        bool check_name(const string& name);
        bool check_surname(const string& surname);
        bool check_separator(const string& separator);
        bool check_phone(const string& phone);
        ifstream m_file_input;
        MessageVector m_validation_messages;
};