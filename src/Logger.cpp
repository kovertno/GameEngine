//
// Created by Konrad Kurzak on 07/10/2024.
//
#include <iostream>
#include <ctime>
#include "Logger.h"


std::vector<LogEntry> Logger::messages;

void Logger::Log(const std::string& message) {
    const time_t timestamp = time(nullptr);
    struct tm datetime = *localtime(&timestamp);

    char output[50];

    LogEntry logEntry;
    logEntry.type = LOG_INFO;

    strftime(output, 50, "LOG: [ %d/%b/%Y %H:%M:%S ]", &datetime);

    logEntry.message = output + message;
    std::cout << "\033[32m" << logEntry.message << "\033[0m" << std::endl;

    messages.push_back(logEntry);
}

void Logger::Err(const std::string& message) {
    const time_t timestamp = time(nullptr);
    struct tm datetime = *localtime(&timestamp);

    char output[50];

    LogEntry logEntry;
    logEntry.type = LOG_ERROR;

    strftime(output, 50, "ERR: [ %d/%b/%Y %H:%M:%S ]", &datetime);

    logEntry.message = output + message;
    std::cout << "\033[31m" << logEntry.message << "\033[0m" << std::endl;

    messages.push_back(logEntry);
}