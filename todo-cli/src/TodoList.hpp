#pragma once
#include "Task.hpp"
#include <string>
#include <vector>
#include <optional>

class TodoList {
    public:
        explicit TodoList(std::string path);

        int add(std::string& title);
        bool remove(int id);
        bool toggle(int id);
        bool edit(int id, std::string& new_title);
        const std::vector<Task>& all() const { return tasks_; }
        std::optional<Task> get(int id) const;

        void load();
        void save() const;

    private:
        std::string path_;    
        std::vector<Task> tasks_;
        int next_id_ = 1;   
};