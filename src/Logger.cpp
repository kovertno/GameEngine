//
// Created by Konrad Kurzak on 07/10/2024.
//
#include <iostream>
#include <ctime>
#include "Logger.h"


void Logger::Log(const std::string& message) {
    const time_t timestamp = time(nullptr);
    struct tm datetime = *localtime(&timestamp);

    char output[50];

    strftime(output, 50, "LOG: [ %d/%b/%Y %H:%M:%S ]", &datetime);
    std::cout << "\033[32m" << output << " " << message << "\033[0m" << std::endl;
}

void Logger::Err(const std::string& message) {
    const time_t timestamp = time(nullptr);
    struct tm datetime = *localtime(&timestamp);

    char output[50];

    strftime(output, 50, "ERR: [ %d/%b/%Y %H:%M:%S ]", &datetime);
    std::cout << "\033[31m" << output << " " << message << "\033[0m" << std::endl;
}