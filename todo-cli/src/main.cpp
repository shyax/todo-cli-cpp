#include "TodoList.hpp"
#include <iostream>
#include <string>
#include <string_view>

void print_usage() {
    std::cout<<
        "todo <command> [args]\n"
        <<"  add <title>      Add a new task\n"
        <<"  ls               List tasks\n"
        <<"  done <id>        Toggle complete\n"
        <<"  rm <id>          Remove task\n"
        <<"  edit <id> <txt>  Edit task title\n";
}

int main(int argc, char* argv[]) {
    TodoList list("tasks.json");
    
    if(argc < 2) { print_usage(); return 0; }
    std::string_view cmd = argv[1];

    if (cmd == "add" && argc >= 3) {
        std::string title = argv[2];
        for (int i = 3; i < argc; ++i)
            title += std::string(" ") + argv[i];
        std::cout << "Added #" << list.add(title) << "\n";
    } 
    else if (cmd == "ls") {
        for (const auto &t : list.all())
        {
            std::cout << (t.done ? "[x] " : "[ ] ")
                      << "#" << t.id << "  " << t.title << "\n";
        }
    }
    else if (cmd == "done" && argc == 3)
    {
        int id = std::stoi(argv[2]);
        std::cout << (list.toggle(id) ? "Toggled\n" : "Not found\n");
    }
    else if (cmd == "rm" && argc == 3)
    {
        int id = std::stoi(argv[2]);
        std::cout << (list.remove(id) ? "Removed\n" : "Not found\n");
    }
    else if (cmd == "edit" && argc >= 4)
    {
        int id = std::stoi(argv[2]);
        std::string title = argv[3];
        for (int i = 4; i < argc; ++i)
            title += std::string(" ") + argv[i];
        std::cout << (list.edit(id, title) ? "Edited\n" : "Not found\n");
    }
    else
    {
        print_usage();
    }
} 