#include <iostream>
#include <chrono>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>

std::string get_elapsed_time()
{
    std::cout << "Press Enter to stop the timer..." << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    std::cin.get();
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

    int hours = duration / 3600;
    int minutes = (duration % 3600) / 60;
    int seconds = duration % 60;

    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << hours << ":"
       << std::setfill('0') << std::setw(2) << minutes << ":"
       << std::setfill('0') << std::setw(2) << seconds;

    return ss.str();
}

void save_to_file(std::string elapsed_time, std::string task_name)
{
    std::ofstream outfile;
    outfile.open("timelog.txt", std::ios::app);

    if (outfile.is_open())
    {
        std::time_t now = std::time(nullptr);
        std::tm *local_time = std::localtime(&now);

        outfile << "[" << std::put_time(local_time, "%Y-%m-%d %H:%M:%S") << "] "
                << "Task: " << task_name << " - "
                << "Duration: " << elapsed_time << std::endl;

        outfile.close();
    }
    else
    {
        std::cerr << "Error: Could not open file." << std::endl;
    }
}

void start_timer()
{
    std::string task_name;
    std::cout << "Task Name: ";
    std::getline(std::cin, task_name);
    std::string time_result = get_elapsed_time();
    std::cout << time_result << std::endl;
    save_to_file(time_result, task_name);
}

int main(int argc, char *argv[])
{
    if ((argc > 1 && std::string(argv[1]) == "--help") || argc == 1)
    {
        std::cout << "timelog - Records time spent on tasks.\n\n"
                  << "start -  Starts the timer.\n"
                  << "clear - Clears the log." << std::endl;
        return 0;
    }

    if (argc > 1 && std::string(argv[1]) == "clear")
    {
        std::ofstream outfile("timelog.txt", std::ios::trunc);
        outfile.close();
        std::cout << "Log cleared." << std::endl;
        return 0;
    }

    if (argc > 1 && std::string(argv[1]) == "start")
    {
        start_timer();
        return 0;
    }
}