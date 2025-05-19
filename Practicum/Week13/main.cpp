#include <iostream>
#include "Company.h"
#include "Worker.h"
#include "Trainee.h"
#include "PaidTrainee.h"

int main() {
    Company c;

    Worker w1("Alice", 28, 2000, 10);
    Worker w2("Bob", 40, 2500, 24);

    Trainee t1("Charlie", 23, 1000, 2);
    Trainee t2("Dana", 23, 1100, 2);

    PaidTrainee pt1("Eve", 24,1800, 5, 31, 70.05);

    c.addWorker(w1);
    c.addWorker(w2);
    c.addTrainee(t1);
    c.addTrainee(t2);
    c.addPaidTrainee(pt1);

    std::cout << "Average salary: " << c.getAverageSalary() << std::endl;

    double target = 3100;
    std::cout << "Two-sum for " << target << ": "
        << (c.twoSum(target) ? "Exists" : "Does NOT exist") << std::endl;

    return 0;
}
