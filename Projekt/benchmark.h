#pragma once
#include "dynamicArray.h"
#include "linkedList.h"
#include <chrono>
#include <fstream>
#include <vector>
#include <climits>
#include <ctime>
#include <random>
#include <iostream>

int generateRandomNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(INT_MIN, INT_MAX);
    return dist(gen);
}

void benchmarkDynamicArray() {
    

    std::string fileName = "C:/Users/andos/source/repos/Zienek12/Projekt1_StrukturyDantch/Projekt/Results/benchmarkDynamicArray";
    std::vector<std::string> names = {
        "AddFront.txt",
        "AddBack.txt",
        "AddIndex.txt",
        "RemoveFront.txt",
        "RemoveBack.txt",
        "RemoveIndex.txt",
        "Search.txt",
    };
    std::vector<int> iterations = { 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000 };

    for (size_t i = 0; i < names.size(); i++) {
        std::ofstream file(fileName + names[i]);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << fileName + names[i] << std::endl;
            continue;
        }

        file << "Iterations,AvgTime\n";

        for (size_t j = 0; j < iterations.size(); j++) {
            DynamicArray arr;

            switch (i) {
            case 0: { // AddFront
                auto start = std::chrono::high_resolution_clock::now();
                for (int k = 0; k < iterations[j]; k++) {
                    arr.addFront(generateRandomNumber());
                }
                auto end = std::chrono::high_resolution_clock::now();
                double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / iterations[j];
                file << iterations[j] << "," << avgtime << "\n";
                break;
            }
            case 1: { // AddBack
                auto start = std::chrono::high_resolution_clock::now();
                for (int k = 0; k < iterations[j]; k++) {
                    arr.addBack(generateRandomNumber());
                }
                auto end = std::chrono::high_resolution_clock::now();
                double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / iterations[j];
                file << iterations[j] << "," << avgtime << "\n";
                break;
            }
            case 2: { // AddIndex
                for (int k = 0; k < iterations[j]; k++) {
                    arr.addBack(generateRandomNumber());
                }

                auto start = std::chrono::high_resolution_clock::now();
                for (int k = 0; k < iterations[j]; k++) {
                    size_t index = k % (arr.getSize() + 1);
                    arr.addIndex(index, generateRandomNumber());
                }
                auto end = std::chrono::high_resolution_clock::now();
                double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / iterations[j];
                file << iterations[j] << "," << avgtime << "\n";
                break;
            }
            case 3: { // RemoveFront
                for (int k = 0; k < iterations[j]; k++) {
                    arr.addBack(generateRandomNumber());
                }

                auto start = std::chrono::high_resolution_clock::now();
                for (int k = 0; k < iterations[j]; k++) {
                    if (arr.getSize() > 0) {
                        arr.removeFront();
                    }
                }
                auto end = std::chrono::high_resolution_clock::now();
                double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / iterations[j];
                file << iterations[j] << "," << avgtime << "\n";
                break;
            }
            case 4: { // RemoveBack
                for (int k = 0; k < iterations[j]; k++) {
                    arr.addBack(generateRandomNumber());
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int k = 0; k < iterations[j]; k++) {
                    if (arr.getSize() > 0) {
                        arr.removeBack();
                    }
                }
                auto end = std::chrono::high_resolution_clock::now();
                double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / iterations[j];
                file << iterations[j] << "," << avgtime << "\n";
                break;
            }
            case 5: { // RemoveIndex
                for (int k = 0; k < iterations[j]; k++) {
                    arr.addBack(generateRandomNumber());
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int k = 0; k < iterations[j]; k++) {
                    if (arr.getSize() > 0) {
                        arr.removeIndex(k % arr.getSize());
                    }
                }
                auto end = std::chrono::high_resolution_clock::now();
                double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / iterations[j];
                file << iterations[j] << "," << avgtime << "\n";
                break;
            }
            case 6: { // Search
                for (int k = 0; k < iterations[j]; k++) {
                    arr.addBack(generateRandomNumber());
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int k = 0; k < iterations[j]; k++) {
                    arr.search(generateRandomNumber());
                }
                auto end = std::chrono::high_resolution_clock::now();
                double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / iterations[j];
                file << iterations[j] << "," << avgtime << "\n";
                break;
            }
            default:
                std::cerr << "Operation not implemented: " << names[i] << std::endl;
                break;
            }
            std::cout << names[i] << " " << iterations[j] << "\n";

        }
        file.close();
    }
}

void benchmarkLinkedList() {
    std::string fileName = "C:/Users/andos/source/repos/Zienek12/Projekt1_StrukturyDantch/Projekt/Results/benchmarkLinkedList";
    std::vector<std::string> names = {
        "AddFront.txt",
        "AddBack.txt",
        "AddIndex.txt",
        "RemoveFront.txt",
        "RemoveBack.txt",
        "RemoveIndex.txt",
        "Search.txt",
    };
    std::vector<int> iterations = { 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000 };

    for (size_t i = 0; i < 3; i++) {
        std::ofstream file(fileName + names[i]);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << fileName + names[i] << std::endl;
            continue;
        }

        file << "Iterations,AvgTime\n";

        for (size_t j = 0; j < iterations.size(); j++) {
            LinkedList list;

            switch (i) {
            case 0: { // AddFront
                auto start = std::chrono::high_resolution_clock::now();
                for (int k = 0; k < iterations[j]; k++) {
                    list.addFront(generateRandomNumber());
                }
                auto end = std::chrono::high_resolution_clock::now();
                double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / iterations[j];
                file << iterations[j] << "," << avgtime << "\n";
                break;
            }
            case 1: { // AddBack
                auto start = std::chrono::high_resolution_clock::now();
                for (int k = 0; k < iterations[j]; k++) {
                    list.addBack(generateRandomNumber());
                }
                auto end = std::chrono::high_resolution_clock::now();
                double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / iterations[j];
                file << iterations[j] << "," << avgtime << "\n";
                break;
            }
            case 2: { // AddIndex
                for (int k = 0; k < iterations[j]; k++) {
                    list.addBack(generateRandomNumber());
                }

                auto start = std::chrono::high_resolution_clock::now();
                for (int k = 0; k < iterations[j]; k++) {
                    list.addIndex(generateRandomNumber(), k % (list.getSize() + 1));
                }
                auto end = std::chrono::high_resolution_clock::now();
                double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / iterations[j];
                file << iterations[j] << "," << avgtime << "\n";
                break;
            }
            case 3: { // RemoveFront
                for (int k = 0; k < iterations[j]; k++) {
                    list.addBack(generateRandomNumber());
                }

                auto start = std::chrono::high_resolution_clock::now();
                for (int k = 0; k < iterations[j]; k++) {
                    if (list.getSize() > 0) {
                        list.removeFront();
                    }
                }
                auto end = std::chrono::high_resolution_clock::now();
                double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / iterations[j];
                file << iterations[j] << "," << avgtime << "\n";
                break;
            }
            case 4: { // RemoveBack
                for (int k = 0; k < iterations[j]; k++) {
                    list.addBack(generateRandomNumber());
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int k = 0; k < iterations[j]; k++) {
                    if (list.getSize() > 0) {
                        list.removeBack();
                    }
                }
                auto end = std::chrono::high_resolution_clock::now();
                double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / iterations[j];
                file << iterations[j] << "," << avgtime << "\n";
                break;
            }
            case 5: { // RemoveIndex
                for (int k = 0; k < iterations[j]; k++) {
                    list.addBack(generateRandomNumber());
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int k = 0; k < iterations[j]; k++) {
                    if (list.getSize() > 0) {
                        list.removeIndex(k % list.getSize());
                    }
                }
                auto end = std::chrono::high_resolution_clock::now();
                double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / iterations[j];
                file << iterations[j] << "," << avgtime << "\n";
                break;
            }
            case 6: { // Search
                for (int k = 0; k < iterations[j]; k++) {
                    list.addBack(generateRandomNumber());
                }
                auto start = std::chrono::high_resolution_clock::now();
                for (int k = 0; k < iterations[j]; k++) {
                    list.search(generateRandomNumber());
                }
                auto end = std::chrono::high_resolution_clock::now();
                double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / iterations[j];
                file << iterations[j] << "," << avgtime << "\n";
                break;
            }
            default:
                std::cerr << "Operation not implemented: " << names[i] << std::endl;
                break;
            }
            std::cout << names[i] << " " << iterations[j] << "\n";

        }
        file.close();
    }
}