// portfolio-smart-pointers-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <memory>
#include <vector>
#include "Test.h"

//function prototypes
//std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<std::shared_ptr<Test>>& vec, int num);
void display(const std::vector <std::shared_ptr<Test>>&vec);

//std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
auto make() {
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

int main()
{
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter:";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
}

void fill(std::vector<std::shared_ptr<Test>>& vec, int num) {
    int temp;
    for (int i = 1; i <= num; ++i) {
        std::cout << "Enter data point [" << i << "] :";
        std::cin >> temp;
        //        std::shared_ptr<Temp> ptr = std::make_shared<Test>(temp);
        //       vec.push_back(ptr);
        vec.push_back(std::make_shared<Test>(temp));
    }
}

void display(const std::vector <std::shared_ptr<Test>>& vec) {
    std::cout << "\Display Vector Data" << std::endl;
    std::cout << "===================" << std::endl;
    for (const auto& ptr : vec)
        std::cout << ptr->get_data() << std::endl;
    std::cout << "===================" << std::endl;
}