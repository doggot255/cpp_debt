#ifndef __PERSON_H__
#define __PERSON_H__

#include <iostream>
#include <string>

class Person
{
    std::string name;
    std::string second_name;
    std::string surname;

public:
    Person();
    Person(std::string &, std::string &, std::string &);
    void print();
    std::string get_surname();

    std::string to_string();
};

class Patient: public Person
{
    int amount_of_work;

public:
    Patient(std::string &, std::string &, std::string &, int);
    bool reduce_remaining_work(int);
};

class Doctor: public Person
{
    int throughput;

public:
    Doctor(std::string &, std::string &, std::string &, int);
    int get_throughput();
};

#endif
