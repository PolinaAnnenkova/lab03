#pragma once
#include <random>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1 - 2;
const auto IMAGE_WIDTH = 400;
const auto IMAGE_HEIGHT = 300;
const auto TEXT_LEFT = 20;
const auto TEXT_BASELINE = 20;
const auto TEXT_WIDTH = 50;
const auto BIN_HEIGHT = 30;
const auto BLOCK_WIDTH = 10;
const auto EDGE_WIDTH = 40;
const auto EDGE_HEIGHT = 23;
//size_t number_count, bin_count, zv, zv_max = 0;
void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black");
string get_random_color();
void svg_begin(double width, double height);
void svg_end();
void svg_text(double left, double baseline, string text);
void svg_ramka(double x1, double y1, double x2, double y2, string stroke);
