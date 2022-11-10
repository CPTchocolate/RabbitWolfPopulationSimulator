
//*****************************************************
//* Programmer: Holden Madriaga                       *
//* Date      : 9 September 2022                      * 
//*                                                   *                                                   
//* Function  : Create a program to simulate          *
//* the rabbit and wolf population growth.            *
//*                                                   *
//* Pseudocode:                                       *
//* Get the current Wolf and rabbit populations       *
//* for the area we are simulating.                   *
//* set up a program to simulate 1000 days            *
//* passing in a loop.                                *
//* Compute the next days rabbit population.          *
//* Compute the next days wolf population.            *
//* Display the population every 25 days for          *
//* both specices.                                    *
//*****************************************************

#include <iostream>
using namespace std;

int main()
{
    double  nextRabbitPopulation;
    double currentWolfPopulation;
    double currentRabbitPopulation;
    double nextWolfPopulation;
    int finalDay = 1000, currentDay;

    const double A = .01;//Fractional increase in Rabbit population without competition from wolves.
    const double B = .005;//Fractional decrease in wolf population without rabbits to eat.
    const double C = 0.00001;//Likelihood that a wolf will encounter and eat a rabbit.
    const double D = 0.01;//Fractional increase in wolf population attributed to a devoured rabbit.

    cout << "Rabbits .... ";
    cin >> currentRabbitPopulation;
    cout << "Wolves ..... ";
    cin >> currentWolfPopulation;
    cout << endl;
    cout << "DAY            R            W\n";
    cout << "---            -            -\n";

    for (currentDay = 0; currentDay <= finalDay; currentDay++)
    {
        nextRabbitPopulation = ((1 + A) * currentRabbitPopulation - C * currentRabbitPopulation * currentWolfPopulation);
        
        nextWolfPopulation = ((1 - B) * currentWolfPopulation + C * D * currentRabbitPopulation * currentWolfPopulation);
        
        if (currentDay % 25 == 0 && currentDay > 1)
            
            cout << currentDay << "           " << static_cast<int>(currentRabbitPopulation) << "         " << static_cast<int>(currentWolfPopulation) << endl;
        
        currentRabbitPopulation = nextRabbitPopulation;
        currentWolfPopulation = nextWolfPopulation;
    }  
    return (0);
}

