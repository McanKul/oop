#include <iostream>
#include <string>
#include "../include/simulation.hpp"
#include <cstdlib> // std::srand
#include <fstream>
#include <sstream>
using namespace std;

void Simulation::printWelcomeMessage() const
{
    cout << "Welcome to the Car Factory!" << endl;
    cout << "You have " << m_total_days << " days to make as much money as possible" << endl;
    cout << "You can add workers, machines, and fast forward days" << endl;

    cout << "Available commands:" << endl;
    cout << "    wX: adds X workers" << endl;
    cout << "    mX: adds X machines" << endl;
    cout << "    pX: passes X days" << endl;
    cout << "    q: exit the game properly" << endl;
}

Machine Simulation::buyRandomMachine()
{
    int random_int = rand()%100;
    return m_machines_market[random_int];
};
Worker Simulation::hireRandomWorker()
{
    int random_int = rand()%100;
    (*m_factory).addUnit(m_labor_market[random_int]);
    return m_labor_market[random_int];
};

Simulation::Simulation(Factory &factory, int total_days, std::string workers_list_path, std::string machines_list_path)
{

    fstream worker_list;
    worker_list.open(workers_list_path, ios::in);
    if (!worker_list.is_open())
    {
        std::cerr << "Dosya açılamadı!" << std::endl;
    }
    string line;
    getline(worker_list, line);

    while (getline(worker_list, line))
    {
        istringstream nec(line);
        string name;
        float cost, retu;
        nec >> name >> cost >> retu;
        this->m_labor_market.push_back(Worker(name, cost, retu));
    }

    fstream machine_l(machines_list_path);
    if (!machine_l.is_open())
    {
        std::cerr << "Dosya açılamadı!" << std::endl;
    }
    getline(machine_l, line);

    while (getline(machine_l, line))
    {
        istringstream nec(line);
        string m_name;
        float daily_cost, daily_return, fail_prob, repair_cost, price;
        int repair_time;
        nec >> m_name >> price >> daily_cost >> daily_return >> fail_prob >> repair_cost >> repair_time;
        m_machines_market.push_back(Machine(m_name, price, daily_cost, daily_return, fail_prob, repair_time, repair_cost));
    }
    (m_factory) = (&factory);

    m_total_days = total_days;
};

void Simulation::run()
{
    int a = 0;
    while (!m_factory->isBankrupt() && a < m_total_days)
    {
        char an;
        int y;
        cin >> an >> y;
    
        if (an == 'w')
        {
            for (int i = 0; i < y; i++)
            {
                Worker my_w = hireRandomWorker();
                (*m_factory).addUnit(my_w);
            }
            m_factory->passOneDay();
            a++;
            cout << m_factory->getCapital() << endl;
        }
        else if (an == 'm')
        {
            for (int i = 0; i < y; i++)
            {
                Machine my_m = buyRandomMachine();
                (*m_factory).addUnit(my_m);
            }
            m_factory->passOneDay();
            a++;
            cout << m_factory->getCapital() << endl;
        }
        else if (an == 'p')
        {
            for (int i = 0; i < y; i++)
            {
                m_factory->passOneDay();
                a++;
            }
            cout << m_factory->getCapital() << endl;
        }
        else if (an == 'q')
        {
            break;
        }
    }
};
