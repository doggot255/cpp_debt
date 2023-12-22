#include "Clinic.h"

bool Clinic::debug_print_rooms_to_file()
{
    std::ofstream output_file(DEBUG_FILENAME, std::ofstream::out);

    if (!output_file.is_open())
    {
        PRINT_DEBUG_INFO;
        std::cerr << "Failed to open file <" << DEBUG_FILENAME << ">" << std::endl;
        return false;
    }

    for(auto &room: rooms)
    {
        output_file << room.first << " | " << room.second.to_string() << std::endl;
    }

    output_file.close();
    return true;
}

Room::Room() {};

Room::Room(Generator &generator)
{
    current_patient = nullptr;
    doctor = generator.create_new_doctor_dyn();

    for(int i = 0; i < generator.get_random_number(0, 10); i++)
    {
        patients.push(generator.create_new_patient());
    }
    update();
}

void Room::print_as_table()
{
    draw_header(doctor->to_string(), INDEX_SUBSECTION_LENGTH,  PRINT_BOARD_LENGTH);

    Patient *temp_patient;
    for (int i = 0; i < patients.size(); i++)
    {
        temp_patient = &patients.front();
        draw_section_with_subsection(std::to_string(i), INDEX_SUBSECTION_LENGTH,
                                    temp_patient->to_string() + std::to_string(current_patient->amount_of_work),
                                    PRINT_BOARD_LENGTH - INDEX_SUBSECTION_LENGTH + 1);
        patients.push(*temp_patient);
        patients.pop();
    }
    draw_table_bottom(INDEX_SUBSECTION_LENGTH, PRINT_BOARD_LENGTH - INDEX_SUBSECTION_LENGTH + 3);
}

void Room::update()
{
    if (current_patient)
    {
        current_patient->reduce_remaining_work(doctor->get_throughput());

        if (current_patient->get_remaining_amount_of_work() <= 0)
        {
            patients.pop();
            current_patient = nullptr;
        }
    }
    else
    {
        if (!patients.empty())
        {
            current_patient = &patients.front();
        }
    }
}

std::string Room::get_doctor_name()
{
    return doctor->get_surname();
}

std::string Room::to_string()
{
    return doctor->to_string();
}

Clinic::Clinic(Generator &generator) // TBD: may need to switch from [] to .insert
{
    int last_created_room_number = 100;
    int next_room_gap;
    for (int i = 0; i < generator.get_random_number(MIN_ROOMS_QUANTITY, MAX_ROOMS_QUANTITY); i++)
    {
        rooms[last_created_room_number] = Room(generator);
        std::cout << last_created_room_number << " " << std::endl;
        next_room_gap = generator.get_random_number(ROOM_NUMBER_MIN_GAP, ROOM_NUMBER_MAX_GAP);
        last_created_room_number = generator.get_random_number(last_created_room_number + 1, last_created_room_number + next_room_gap);
    }

    debug_print_rooms_to_file();
}

void Clinic::update(double time_elapsed)
{
    for (auto &room: rooms)
    {
        for (int i = 0; i < time_elapsed / UPDATE_RATE_MILLISECONDS; i++)
        {
            room.second.update();
        }
    }
}

std::map<int, Room>::iterator Clinic::find_room_by_number(int number)
{
    return rooms.find(number);
}

bool Clinic::iter_is_out_of_bounds(std::map<int, Room>::iterator iter)
{
    return iter == rooms.end();
}

std::map<int, Room> & Clinic::get_rooms_map()
{
    return rooms;
}

void Clinic::insert_person_into_queue(int room_number, Patient person)
{
}
