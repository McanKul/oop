#include <iostream>
#include <string>
#include "../include/worker.hpp"
using namespace std;

Worker::Worker(std::string name, float cost_per_day, float base_return_per_day) : Unit(name,cost_per_day,base_return_per_day),m_experience(0){};

float Worker::getReturnPerDay(){
   int daily_return = (Unit::getReturnPerDay()) + (m_experience) * 2 + (m_num_head_workers) * 3;
   m_experience++;
   return daily_return;
};
int Worker::getExperience() const{return m_experience;};

void Worker::increaseHeadWorkerCount(){
   m_num_head_workers++;
};

