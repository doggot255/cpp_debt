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

Room::Room(): doctor(Generator::instance().create_new_doctor())
{
    for(int i = 0; i < Generator::instance().get_random_number(0, 10); i++)
    {
        patients.push(Generator::instance().create_new_patient());
    }
    update();
}

void Room::print_as_table()
{
    draw_header(doctor.to_string(), INDEX_SUBSECTION_LENGTH,  PRINT_BOARD_LENGTH);

    Patient *temp_patient;
    for (int i = 0; i < patients.size(); i++)
    {
        draw_section_with_subsection(std::to_string(i), INDEX_SUBSECTION_LENGTH,
                                    patients.front().to_string(),
                                    PRINT_BOARD_LENGTH - INDEX_SUBSECTION_LENGTH + 1);
        patients.push(patients.front());
        patients.pop();
    }
    draw_table_bottom(INDEX_SUBSECTION_LENGTH, PRINT_BOARD_LENGTH - INDEX_SUBSECTION_LENGTH + 3);
}

void Room::update()
{
    if (!patients.empty())
    {
        patients.front().reduce_remaining_work(doctor.get_throughput());
        if (patients.front().get_remaining_amount_of_work() <= 0)
        {
            patients.pop();
        }
    }
}

std::string Room::get_doctor_name()
{
    return doctor.get_surname();
}

std::string Room::to_string()
{
    return doctor.to_string();
}

Clinic::Clinic() // TBD: may need to switch from [] to .insert
{
    int last_created_room_number = MINIMAL_ROOM_NUMBER;
    int next_room_gap;
    for (int i = 0; i < Generator::instance().get_random_number(MIN_ROOMS_QUANTITY, MAX_ROOMS_QUANTITY); i++)
    {
        rooms[last_created_room_number] = Room();
        next_room_gap = Generator::instance().get_random_number(ROOM_NUMBER_MIN_GAP, ROOM_NUMBER_MAX_GAP);
        last_created_room_number = Generator::instance().get_random_number(
            last_created_room_number + 1,
            last_created_room_number + next_room_gap
        );
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
