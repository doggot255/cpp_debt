#include "Draw.h"

void draw_header_top(int section_length)
{
    std::cout << "┌";
    for (int i = 0; i < section_length; i++)
        std::cout << "─";
    std::cout << "┐" << std::endl;
}

void draw_header_bottom_continued(int section_length1, int section_length2)
{
    std::cout << "├";

    for (int i = 0; i < section_length1; i++)
        std::cout << "─";
    std::cout << "┬";   

    for (int i = 0; i < section_length2; i++)
        std::cout << "─";

    std::cout << "┤" << std::endl;
}

void draw_section_with_message(std::string message, int section_length)
{
    std::cout << "│";
    std::cout << message;
    for (int i = 0; i < section_length - message.size() / 2; i++)
        std::cout << " ";
    std::cout << "│";
}

void draw_header(std::string message, int section_length1, int section_length2)
{
    draw_header_top(section_length1 + section_length2 + 1);
    draw_section_with_message(message, section_length1 + section_length2);
    std::cout << std::endl;
    draw_header_bottom_continued(section_length1, section_length2);
}

void draw_section_with_subsection(std::string message1, int section_length1, std::string message2, int section_length2)
{
    draw_section_with_message(message1, section_length1);
    std::cout << "\b" << "\b";
    draw_section_with_message(message2, section_length2 + 1);
    std::cout << std::endl;
}

void draw_table_bottom(int section_length1, int section_length2)
{
    std::cout << "└";

    for (int i = 0; i < section_length1; i++)
        std::cout << "─";
    std::cout << "┴";

    for (int i = 0; i < section_length2; i++)
        std::cout << "─";

    std::cout << "┘" << std::endl;
}
