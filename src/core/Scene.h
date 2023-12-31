#ifndef __SCENE_H__
#define __SCENE_H__

#include "../generation/Generator.h"
#include "Clinic.h"
#include "../interface/Menu.h"

class Scene
{
    Generator generator;
    Clinic clinic;

    void pause();
public:
    Scene();
    void start_main_menu();
    void menu_find_room_by_number();
    void menu_find_doctor_by_surname();
};

#endif
