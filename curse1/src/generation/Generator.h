#ifndef __GENERATOR_H__
#define __GENERATOR_H__

#include <iostream>
#include <vector>
#include <fstream>
#include <random>

#include "../core/Person.h"

#define PRINT_DEBUG_INFO std::cout << __FILE__ << ", " << __LINE__ << std::endl;

#define FILENAME_NAMES_MALE "../src/generation/txt/names_male.txt"
#define FILENAME_NAMES_FEMALE "../src/generation/txt/names_female.txt"
#define FILENAME_SECOND_NAMES_MALE "../src/generation/txt/second_names_male.txt"
#define FILENAME_SECOND_NAMES_FEMALE "../src/generation/txt/second_names_female.txt"
#define FILENAME_SURNAMES_MALE "../src/generation/txt/surnames_male.txt"
#define FILENAME_SURNAMES_FEMALE "../src/generation/txt/surnames_female.txt"

#define MIN_PATIENT_AMOUNT_OF_WORK 200
#define MAX_PATIENT_AMOUNT_OF_WORK 1000
#define MAX_DOCTOR_THROUGHPUT 15
#define MIN_DOCTOR_THROUGHPUT 1

class Generator
{
    std::vector<std::string> names_male;
    std::vector<std::string> names_female;
    std::vector<std::string> second_names_male;
    std::vector<std::string> second_names_female;
    std::vector<std::string> surnames_male;
    std::vector<std::string> surnames_female;

    std::random_device rd;
    std::mt19937 mt;

public:
    Generator();
    int get_random_number(int, int);
    Doctor create_new_doctor();
    Doctor *create_new_doctor_dyn();
    Patient create_new_patient();
};

#endif
