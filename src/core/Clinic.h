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

#define MAX_ROOMS_QUANTITY 10
#define MIN_ROOMS_QUANTITY 1
#define ROOM_NUMBER_MAX_GAP 20
#define ROOM_NUMBER_MIN_GAP 1

#define PRINT_BOARD_LENGTH 50
#define INDEX_SUBSECTION_LENGTH 3

#define DEBUG_FILENAME "debug_rooms.txt"
class Room
{
    Doctor *doctor;
    std::queue<Patient> patients;
    Patient *current_patient;

public:
    Room();
    Room(Generator &);
    void print_as_table();
    void update();

    std::string get_doctor_name();
};

class Clinic
{
    std::map<int, Room> rooms;

public:
    Clinic(Generator &);
    void update();
    std::map<int, Room>::iterator find_room_by_number(int );
    std::map<int, Room>::iterator find_room_by_doctor(std::string &);
    bool iter_is_out_of_bounds(std::map<int, Room>::iterator );
    std::map<int, Room> & get_rooms_map();
};

#endif
