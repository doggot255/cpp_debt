#ifndef __CLINIC_H__
#define __CLINIC_H__

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <iomanip>
#include <limits>

#include "Person.h"
#include "../generation/Generator.h"
#include "../interface/Draw.h"

#define UPDATE_RATE_MILLISECONDS 500

#define MAX_ROOMS_QUANTITY 10
#define MIN_ROOMS_QUANTITY 1
#define ROOM_NUMBER_MAX_GAP 20
#define ROOM_NUMBER_MIN_GAP 1
#define MINIMAL_ROOM_NUMBER 100
#define MINIMAL_USER_AMOUNT_OF_WORK 100
#define USER_AMOUNT_OF_WORK_PER_SYMBOL 10
#define NEW_PATIENT_ARRIVAL_BASE_CHANCE 10

#define PRINT_BOARD_LENGTH 50
#define INDEX_SUBSECTION_LENGTH 3

#define DEBUG_FILENAME "debug_rooms.txt"

class Room
{
    Doctor doctor;
    std::queue<Patient> patients;
    int room_number;
    float new_patient_arrival_chance;

public:
    Room();
    void print_as_table();
    void update();
    std::string to_string();
    std::string get_doctor_name();
    void add_patient_to_queue(Patient patient);
    int get_total_waiting_time();
};

class Clinic
{
    std::map<int, Room> rooms;

public:
    Clinic();
    void update(double);
    std::map<int, Room>::iterator find_room_by_number(int );
    std::map<int, Room>::iterator find_room_by_doctor(std::string &);
    bool check_if_room_exists(int);
    bool insert_patient_into_queue(int, Patient);
    bool iter_is_out_of_bounds(std::map<int, Room>::iterator );
    std::map<int, Room> & get_rooms_map();
    int get_room_waiting_time(int);

    static int calculate_amount_of_work(std::string &);
    bool debug_print_rooms_to_file();
};

#endif
