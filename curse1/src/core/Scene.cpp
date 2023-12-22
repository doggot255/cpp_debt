#include "Scene.h"

inline void Scene::pause()
{
    std::cin.get();
    std::cin.get();
}

Scene::Scene(): clinic()
{
    clinic.debug_print_rooms_to_file();
}

void Scene::start_main_menu()
{
    char user_input;
    Timer timer;
    do
    {
        timer.start();
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

            case '3':
                menu_insert_patient_into_queue();
                break;

            default:
                std::cout << "Некорректный ввод. Попробуйте снова." << std::endl;
                pause();
        }

        clinic.update(timer.elapsed_miliseconds());
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
        if (room.second.get_doctor_name() == surname)
        {
            room.second.print_as_table();
            doctor_exists = true;
            break;
        }
    }

    if (!doctor_exists)
        std::cout << "Врача с фамилией " << surname << " не найдено." << std::endl;

    pause();
}

void Scene::menu_insert_patient_into_queue()
{
    system("clear");

    int room_number;

    std::cout << "Номер кабинета: ";
    std::cin >> room_number;

    if (!clinic.check_if_room_exists(room_number))
    {
        std::cout << "Данного кабинета не найдено" << std::endl;
        std::cout << "Нажмите Enter для выхода..." << std::endl;
        pause();
        return;
    }

    std::string name;
    std::string second_name;
    std::string surname;

    std::cout << "Ваше имя: ";
    std::cin >> name;
    std::cout << "Ваше отчетство: ";
    std::cin >> second_name;
    std::cout << "Ваша фамилия: ";
    std::cin >> surname;

    std::string procedure_name;
    std::cout << "Полное название процедуры: " << std::endl;
    std::cin >> procedure_name;

    clinic.insert_patient_into_queue(room_number, Patient(name, second_name, surname, Clinic::calculate_amount_of_work(procedure_name)));
    std::cout << "Примерное время ожидания: " << clinic.get_room_waiting_time(room_number) * 1000 / UPDATE_RATE_MILLISECONDS << " секунд";
    pause();
}
