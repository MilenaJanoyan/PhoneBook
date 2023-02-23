#include "message.h"

void MessageVector::push_message(uint32_t _line_number, INVALID_MESSAGE_TYPES _message_type)
{
    m_message_map[_line_number].push_back(_message_type);
}

void MessageVector::dump_message(ostream& _outp_stream) const
{
    if (m_message_map.size() == 0) return;

    map<uint32_t, vector<INVALID_MESSAGE_TYPES> >::const_iterator map_it;
    for(map_it = m_message_map.begin(); map_it != m_message_map.end(); ++map_it)
    {
        _outp_stream << "line " << map_it->first << ": ";
        vector<INVALID_MESSAGE_TYPES>::const_iterator vec_it;
        
        for (vec_it = map_it->second.cbegin(); vec_it != map_it->second.cend(); vec_it++)
        {
            switch (*vec_it)
            {
            case INVALID_MESSAGE_TYPES::FIRST_NAME:
                _outp_stream << FIRST_NAME_FAIL;
                break;
            case INVALID_MESSAGE_TYPES::SURNAME:
                _outp_stream << SURNAME_FAIL;
                break;
            case INVALID_MESSAGE_TYPES::SEP_CHAR:
                _outp_stream << SEPAR_FAIL;
                break;
            case INVALID_MESSAGE_TYPES::PHONE:
                _outp_stream << PHONE_FAIL;
                break;
            default:
                _outp_stream << UNKNOWN_FAIL;
                break;
            }
        }
        _outp_stream << '\n';
    }
}