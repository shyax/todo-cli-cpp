#pragma once
#include <string>
#include <chrono>

struct Task {
    int id;
    std::string title;
    bool done = false;
    std::chrono::system_clock::time_point created_at = std::chrono::system_clock::now();
};