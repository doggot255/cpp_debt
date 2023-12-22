#ifndef __CLINIC_H__
#define __CLINIC_H__

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <iomanip>

#include "Person.h"
#include "../generation/Generator.h"
#include "../interface/Draw.h"

#define UPDATE_RATE_MILLISECONDS 500

#define MAX_ROOMS_QUANTITY 10
#define MIN_ROOMS_QUANTITY 1
#define ROOM_NUMBER_MAX_GAP 20
#define ROOM_NUMBER_MIN_GAP 1
#define MINIMAL_ROOM_NUMBER 100

#define PRINT_BOARD_LENGTH 50
#define INDEX_SUBSECTION_LENGTH 3

#define DEBUG_FILENAME "debug_rooms.txt"

class Room
{
    Doctor doctor;
    std::queue<Patient> patients;
    int room_number;

public:
    Room();
    void print_as_table();
    void update();
    std::string to_string();

    std::string get_doctor_name();
};

class Clinic
{
    std::map<int, Room> rooms;

public:
    Clinic();
    void update(double);
    std::map<int, Room>::iterator find_room_by_number(int );
    std::map<int, Room>::iterator find_room_by_doctor(std::string &);
    void insert_person_into_queue(int, Person);
    bool iter_is_out_of_bounds(std::map<int, Room>::iterator );
    std::map<int, Room> & get_rooms_map();

    bool debug_print_rooms_to_file();
};

#endif
