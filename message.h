#pragma once
#include <string>
#include <map>
#include <vector>
#include <iostream>


using std::string;
using std::map;
using std::vector;
using std::ostream;
using std::cout;

constexpr auto FIRST_NAME_FAIL = "first name should be non-zero value. ";
constexpr auto SURNAME_FAIL = ""; /* Not specified in problem requirements*/
constexpr auto PHONE_FAIL = "phone number should be with 9 digits. ";
constexpr auto SEPAR_FAIL = "separator should be ':' or '-'. ";
constexpr auto UNKNOWN_FAIL = "unknown syntax error. ";

enum class INVALID_MESSAGE_TYPES
{
    FIRST_NAME,
    SURNAME,
    PHONE,
    SEP_CHAR
};

struct MessageVector
{
        MessageVector() = default;
        void push_message(uint32_t _line_number, INVALID_MESSAGE_TYPES _message_type);
        void dump_message(ostream& _outp_stream = cout) const;
    private:
        map<uint32_t, vector<INVALID_MESSAGE_TYPES>> m_message_map;
};