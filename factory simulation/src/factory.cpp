#include <iostream>
#include <string>
#include "../include/factory.hpp"
#include <cstdlib> // std::srand
using namespace std;

Factory::Factory(float capital):m_capital(capital),m_is_bankrupt(false){};

void Factory::passOneDay(){
   for(int i=0;i<m_workers.size();i++){
      m_capital += m_workers[i].getReturnPerDay();
      m_capital -= m_workers[i].getCostPerDay();
   }
   for(int i=0;i<m_head_workers.size();i++){
      m_capital += m_head_workers[i].getReturnPerDay();
      m_capital -= m_head_workers[i].getCostPerDay();
   }
   for(int i=0;i<m_machines.size();i++){
      m_capital += m_machines[i].getReturnPerDay();
      m_capital -= m_machines[i].getCostPerDay();
   }
   

   for(int i=0;i<m_workers.size();i++){
      if(m_workers[i].getExperience()==10){
         HeadWorker new_head_worker(m_workers[i]);
         m_head_workers.push_back(new_head_worker);
         m_workers.erase(m_workers.begin() + i);
      }
      ;
   }
   if(m_capital<0){
      m_is_bankrupt = true;
   }
};
    
void Factory::addUnit(const Worker &rhs_worker){
   m_workers.push_back(rhs_worker);
   
};
void Factory::addUnit(const Machine &rhs_machine){
   m_machines.push_back(rhs_machine);
   m_capital -= rhs_machine.getPrice();
}; 
    
bool Factory::isBankrupt() const{
   return m_is_bankrupt;
};
float Factory::getCapital() const{return m_capital;};
    
int Factory::getWorkerCount() const{return m_workers.size();};
int Factory::getMachineCount() const{return m_machines.size();};
int Factory::getHeadWorkerCount() const{return m_head_workers.size();};