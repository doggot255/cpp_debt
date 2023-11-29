#include "Scene.h"

inline void Scene::pause()
{
    std::cin.get();
    std::cin.get();
}

Scene::Scene(): clinic(generator)
{}

void Scene::start_main_menu()
{
    char user_input;
    do
    {
        print_main_menu();
        std::cout << "Ввод: ";
        std::cin >> user_input;
        switch(user_input)
        {
            case '0':
                return;

            case '1':
                menu_find_room_by_number();
                break;

            case '2':
                menu_find_doctor_by_surname();
                break;

            default:
                std::cout << "Некорректный ввод. Попробуйте снова." << std::endl;
                std::cin.get();
                std::cin.get();
        }
    } while(user_input != '0');
}
void Scene::menu_find_room_by_number()
{
    system("clear");

    int room_number;
    std::cout << "Номер кабинета: ";
    std::cin >> room_number;

    auto room_iter = clinic.find_room_by_number(room_number);

    // iter is out of bounds => element does not exist
    if (!clinic.iter_is_out_of_bounds(room_iter))
        room_iter->second.print_as_table();
    else
        std::cout << "Кабинет с таким номером не найден" << std::endl;

    pause();
}

void Scene::menu_find_doctor_by_surname()
{
    system("clear");

    std::string surname;
    std::cout << "Фамилия врача: ";
    std::cin >> surname;

    bool doctor_exists = false;
    for (auto &room: clinic.get_rooms_map())
    {
        if (room.get_doctor_name() == surname)
        {
            room.print_as_table();
            doctor_exists = true;
            break;
        }
    }

    if (!doctor_exists)
        std::cout << "Врача с фамилией " << surname << " не найдено." << std::endl;

    pause();
}
