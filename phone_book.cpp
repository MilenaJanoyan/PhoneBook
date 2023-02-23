#include "phone_book.h"

PhoneBook::PhoneBook(const string& file_path) :
        m_reader(file_path)
{
    m_reader.dump_messages();
}


void PhoneBook::read_credentials()
{
    m_reader.fill_credentials(m_users);
}

void PhoneBook::sort(SORT_CRIT crit, SORT_ORDER type)
{
    /* There are 4(6) outcomes in here */


        switch (crit)
        {
        case SORT_CRIT::Name:
            if (type == SORT_ORDER::ASC){
                /* Sort by name in ascending */
                ::sort(m_users.begin(), m_users.end(), [this](const UserEntry& u1, const UserEntry& u2){
                    return (u1.get_name().compare(u2.get_name()) <= 0 ? true : false);
                });
            } else {
                /* Sort by name in descending */
                ::sort(m_users.begin(), m_users.end(), [this](const UserEntry& u1, const UserEntry& u2){
                    return (u2.get_name().compare(u1.get_name()) <= 0 ? true : false);
                });
            }
            /* code */
            break;
        case SORT_CRIT::PhoneNumber:
            /* code */
            if (type == SORT_ORDER::ASC){
                /* Sort by phone in ascending */
                ::sort(m_users.begin(), m_users.end(), [this](const UserEntry& u1, const UserEntry& u2){
                    return (u1.get_phone().compare(u2.get_phone()) <= 0 ? true : false);
                });
            } else {
                /* Sort by phone in descending */
                ::sort(m_users.begin(), m_users.end(), [this](const UserEntry& u1, const UserEntry& u2){
                    return (u2.get_phone().compare(u1.get_phone()) <= 0 ? true : false);
                });
            }
            break;
      
        case SORT_CRIT::Surname:
            /* code */
            if (type == SORT_ORDER::ASC){
                /* Sort by name in ascending */
                ::sort(m_users.begin(), m_users.end(), [this](const UserEntry& u1, const UserEntry& u2){
                    char c = 0;
                    return (u1.get_surname().compare(u2.get_surname()) <= 0 ? true : false);
                });
            } else {
                /* Sort by name in descending */
                ::sort(m_users.begin(), m_users.end(), [this](const UserEntry& u1, const UserEntry& u2){
                    return (u2.get_surname().compare(u1.get_surname()) <= 0 ? true : false);
                });
            }
            
            auto it = std::partition (m_users.begin(), m_users.end(), [](const UserEntry& u){return u.get_surname().length();});
            if (type == SORT_ORDER::ASC) std::reverse(m_users.begin(), it);
            std::stable_partition(it, m_users.end(), [](const UserEntry& u){return u.get_surname().length() == 0 ;});
            
            break;
        }
}

void PhoneBook::dump_user_entries(void) const
{
    for (const auto& it : m_users)
    {
        cout << it.dump_entry() << '\n';
    }
}

void PhoneBook::show_validation_messages(void) const
{
   m_reader.dump_messages();
}
