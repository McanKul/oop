#include <iostream>
#include <string>
#include "../include/machine.hpp"
#include <cstdlib> // std::srand
using namespace std;


Machine::Machine(
   string name,
   float price,
   float cost_per_day,
   float base_return_per_day,
   float failure_probability,
   int repair_time,
   float repair_cost
   ):
   Unit(name, cost_per_day, base_return_per_day),
   m_price(price),
   m_failure_probability(failure_probability),
   m_repair_time(repair_time),
   m_days_until_repair(repair_cost)
   {};

float Machine::getPrice() const{return m_price;};

float Machine::getReturnPerDay(){
   if(m_days_until_repair > 0) {
      m_days_until_repair--;
      return 0;
   }
   else{
      if(rand()<m_failure_probability){
         m_days_until_repair = m_repair_time;
         return (-1) * m_repair_cost;
      }
      else {
         return Unit::getReturnPerDay();
         };
   }
};