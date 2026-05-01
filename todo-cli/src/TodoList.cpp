#include "TodoList.hpp"
#include <fstream>
#include <algorithm>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

TodoList::TodoList(std::string path) : path_(std::move(path)) { load(); }

int TodoList::add(const std::string& title) {
    Task t{ next_id_++, title };
    tasks_.push_back(t);
    save();
    return t.id;
}

bool TodoList::remove(int id) {
    auto it = std::remove_if(tasks_.begin(), tasks_.end(), [&](const Task& t){ return  t.id == id; });
    if (it == tasks_.end()) return false;
    tasks_.erase(it, tasks_.end());
    save();
    return true;
}

bool TodoList::toggle(int id) {
    for (auto& t: tasks_) {
        if(t.id == id) { 
            t.done = !t.done; 
            save();
            return true;
        }
    }

    return false;
}

bool TodoList::edit(int id, const std::string& new_title) {
    for (auto &t : tasks_) {
        if (t.id == id)
        {
            t.title = new_title;
            save();
            return true;
        }
    }

    return false;
}

std::optional<Task> TodoList::get(int id) const {
    for (const auto &t: tasks_) if (t.id == id) return t;
    return std::nullopt;
}

void TodoList::load() {
    std::ifstream f(path_);
    if(!f) return;
    json j; f >> j;
    for (const auto& item: j.at("tasks")) {
        Task t;
        t.id = item.at("id").get<int>();
        t.title = item.at("title").get<std::string>();
        t.done = item.at("done").get<bool>();
        tasks_.push_back(t);
        next_id_ = std::max(next_id_, t.id+1);
    }
}

void TodoList::save() const {
    json j;
    j["tasks"] = json::array();
    for (const auto& t: tasks_ ) {
        j["tasks"].push_back({
            {"id", t.id},
            {"title", t.title},
            {"done", t.done}
        });
    }
    std::ofstream f(path_);
    f << j.dump(2);
}