#include "reader.h"

Reader::Reader (const string& _file_path) :
    m_file_input(_file_path)
{
    if (!m_file_input.is_open())
    {
        /* If file stream could not be opened */
        cout << "Error in reading file\n";
        throw;
    } 
}

void Reader::fill_credentials(vector<UserEntry>& _users)
{
    uint32_t line_number = 1;
    for( std::string line; getline( m_file_input, line ); )
    {
    /* Some stuf for reading each line into string */
    /* call parse_line and push created user into user list*/
        _users.push_back(parse_line(line, line_number));
        line_number++;
    }    
}

void Reader::dump_messages(void) const
{
    m_validation_messages.dump_message();
}

UserEntry Reader::parse_line (const string& _cred_line, uint32_t _line)
{
    string credentials[4]; /* {name}_{surname}_{separator}_{phone_number} */
    int index = 0;
    bool valid_entry = true;
    /* Parse line of this kind */
    /* {name}_{surname}_{separator}_{phone_number} */
    /* Also checking needs to be done here in order
        to find out validity of current user entry */
        /* If invalid set invalid flag  _cred_line->inv_flag*/

    stringstream ss(_cred_line);  
    while (ss >> credentials[index++])
    {
        /* Break if credential count is exceeded */
        if (index >= 4) break;
        ;/* get credentials from grabbed line while there is one */
    }
    
/* Check if surname got valid ':' or '-' then it's obviously separator, not surname" 
    just swap them 
    
    separator->phone number (which would be empty by this moment)
    surname -> separator
    (surname remains empty )
    */
   if ((credentials[1] == ":" || credentials[1] == "-" )&& 
        credentials[3].empty())
    {
        /* Then swap up */
        credentials[3] = std::move(credentials[2]);
        credentials[2] = std::move(credentials[1]);
   }

   if (!(credentials[2].empty()) &&  credentials[3].empty())
   {
        std::swap(credentials[2], credentials[3]);
    }

    UserEntry user(credentials[0],credentials[1],credentials[2], credentials[3]);
    /* Check name validity */
    user.set_valid(check_entry(user, _line));


    return user;
}

bool Reader::check_entry(const UserEntry& user, uint32_t line)
{
    /* Check all credentials and return false if at least one is invalid */
    bool is_valid = true;
    bool ret_val = false;
    is_valid = check_name(user.get_name());
    ret_val &= is_valid;
    if (!is_valid)
    {
        m_validation_messages.push_message(line, INVALID_MESSAGE_TYPES::FIRST_NAME);
    }

    is_valid = check_surname(user.get_name());
    ret_val &= is_valid;
    if (!is_valid)
    {
        m_validation_messages.push_message(line, INVALID_MESSAGE_TYPES::SURNAME);
    }

    is_valid = check_separator(user.get_separator());
    ret_val &= is_valid;
    if (!is_valid)
    {
        m_validation_messages.push_message(line, INVALID_MESSAGE_TYPES::SEP_CHAR);
    }

    is_valid = check_phone(user.get_phone());
    ret_val &= is_valid;
    if (!is_valid)
    {
        m_validation_messages.push_message(line, INVALID_MESSAGE_TYPES::PHONE);
    }

    return ret_val;
}

bool Reader::check_name(const string& name)
{
    if (name.length() != 0) return true;
    return false;
}

bool Reader::check_surname(const string& surname)
{
    /* Criteria non-specified for this field */
    return true;
}

bool Reader::check_separator(const string& separator)
{   
    
    if (separator == ":" || separator == "-") return true;
    return false;
}

bool Reader::check_phone(const string& phone)
{
    if (phone.length() != 9) return false;
    return true;
}



Reader::~Reader ()
{
    /* Ifstream closes stream in its desctructor, so no need to 
        explicitly close it in here */
}