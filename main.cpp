#include "phone_book.h"
#include <iostream>

using std::cout;
using std::cin;

constexpr auto str_ascending = "Ascending";
constexpr auto str_descending = "Descending";
constexpr auto str_name_crit = "Name";
constexpr auto str_surname_crit = "Surname";
constexpr auto str_phone_crit = "PhoneNumberCode";

int main()
{
    string file_path;
    string criteria; SORT_CRIT e_criteria;
    string order; SORT_ORDER e_order;

    cout << "File Path - "; cin >> file_path;
    PhoneBook pb(file_path);
    pb.read_credentials();
    cout << "Please choose an ordering to sort: \"Ascending\" or \"Descending\".\n";
    cin >> order;
    if (order == str_ascending) e_order = SORT_ORDER::ASC;
    else if (order == str_descending) e_order = SORT_ORDER::DESC;
    
    cout << "Please choose criteria : \"Name\", \"Surname\", \"PhoneNumberCode\".\n";
    cin >> criteria;

    if (criteria == str_name_crit) e_criteria = SORT_CRIT::Name;
    else if (criteria == str_surname_crit) e_criteria = SORT_CRIT::Surname;
    else if (criteria == str_phone_crit) e_criteria = SORT_CRIT::PhoneNumber;

    pb.sort(e_criteria, e_order);
    pb.dump_user_entries();
    pb.show_validation_messages();
    return 0;
}