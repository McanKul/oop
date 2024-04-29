#include <iostream>
#include <string>
#include "../include/headworker.hpp"
using namespace std;

HeadWorker::HeadWorker(Worker &worker):Worker(worker){
   Worker::increaseHeadWorkerCount();
};
    
float HeadWorker::getReturnPerDay(){
   int daily_return = (Unit::getReturnPerDay()) + (Worker::getExperience()) * 5;
   return daily_return;
};