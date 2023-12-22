#include "Generator.h"

bool read_file(const char *file_name, std::vector<std::string> &vec)
{
    std::ifstream input_file(file_name, std::ifstream::in);

    if (!input_file.is_open())
    {
        PRINT_DEBUG_INFO;
        std::cerr << "Failed to open file <" << file_name << ">" << std::endl;
        return false;
    }

    std::string buffer;
    while (std::getline(input_file, buffer))
        vec.push_back(buffer);

    input_file.close();
    return true;
}

Generator::Generator(): mt(rd())
{
    std::cout << "Reading male names...";
    read_file(FILENAME_NAMES_MALE, names_male);
    names_male.pop_back();
    std::cout << "done." << std::endl;

    std::cout << "Reading female names...";
    read_file(FILENAME_NAMES_FEMALE, names_female);
    names_female.pop_back();
    std::cout << "done." << std::endl;

    std::cout << "Reading male second names...";
    read_file(FILENAME_SECOND_NAMES_MALE, second_names_male);
    second_names_male.pop_back();
    std::cout << "done." << std::endl;

    std::cout << "Reading female second names...";
    read_file(FILENAME_SECOND_NAMES_FEMALE, second_names_female);
    second_names_female.pop_back();
    std::cout << "done." << std::endl;

    std::cout << "Reading male surnames...";
    read_file(FILENAME_SURNAMES_MALE, surnames_male);
    surnames_male.pop_back();
    std::cout << "done." << std::endl;

    std::cout << "Reading female surnames...";
    read_file(FILENAME_SURNAMES_FEMALE, surnames_female);
    surnames_female.pop_back();
    std::cout << "done." << std::endl;
}

Generator & Generator::instance()
{
    static Generator instance;
    return instance;
}

int Generator::get_random_number(int lbound, int ubound)
{
    std::uniform_int_distribution<int> dist(lbound, ubound);
    return dist(mt);
}

Doctor Generator::create_new_doctor()
{
    return get_random_number(0, 1) ? // true: male, false: female
    Doctor(
        names_male[get_random_number(0, names_male.size())],
        second_names_male[get_random_number(0, second_names_male.size())],
        surnames_male[get_random_number(0, surnames_male.size())],
        get_random_number(MIN_DOCTOR_THROUGHPUT, MAX_DOCTOR_THROUGHPUT)
    )
    :
    Doctor(
        names_female[get_random_number(0, names_female.size())],
        second_names_female[get_random_number(0, second_names_female.size())],
        surnames_female[get_random_number(0, surnames_female.size())],
        get_random_number(MIN_DOCTOR_THROUGHPUT, MAX_DOCTOR_THROUGHPUT)
    );
}

Patient Generator::create_new_patient()
{
    return get_random_number(0, 1) ? // true: male, false: female
    Patient(
        names_male[get_random_number(0, names_male.size())],
        second_names_male[get_random_number(0, second_names_male.size())],
        surnames_male[get_random_number(0, surnames_male.size())],
        get_random_number(MIN_PATIENT_AMOUNT_OF_WORK, MAX_PATIENT_AMOUNT_OF_WORK)
    )
    :
    Patient(
        names_female[get_random_number(0, names_female.size())],
        second_names_female[get_random_number(0, second_names_female.size())],
        surnames_female[get_random_number(0, surnames_female.size())],
        get_random_number(MIN_PATIENT_AMOUNT_OF_WORK, MAX_PATIENT_AMOUNT_OF_WORK)
    );
}
