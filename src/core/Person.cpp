#include "Person.h"

Person::Person()
{
    name = "";
    second_name = "";
    surname = "";
}

Person::Person(std::string &name, std::string &second_name, std::string &surname)
{
    this->name = name;
    this->second_name = second_name;
    this->surname = surname;
}

void Person::print()
{
    std::cout << surname << " " << name << " " << second_name << std::endl;
}

std::string Person::get_surname()
{
    return surname;
}

std::string Person::to_string()
{
    return name + " " + second_name + " " + surname;
}

Patient::Patient(std::string &name, std::string &second_name, std::string &surname, int work): Person(name, second_name, surname)
{
    amount_of_work = work;
}

bool Patient::reduce_remaining_work(int throughput)
{
    amount_of_work -= throughput;
    return amount_of_work <= 0;
}

Doctor::Doctor(std::string &name, std::string &second_name, std::string &surname, int throughput): Person(name, second_name, surname)
{
    this->throughput = throughput;
}

int Doctor::get_throughput()
{
    return throughput;
}
