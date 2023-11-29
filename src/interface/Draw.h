#ifndef __DRAW_H__
#define __DRAW_H__

#include <iostream>
#include <iomanip>

void draw_header_top(int);
void draw_header_bottom_continued(int, int);
void draw_header(std::string, int, int);
void draw_section_with_message(std::string, int);
void draw_section_with_subsection(std::string, int, std::string, int);
void draw_table_bottom(int, int);

#endif
