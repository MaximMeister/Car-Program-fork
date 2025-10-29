#include <iostream>
#include <limits>
#include <string>
#include <vector>

class Car {
   private:
    std::string name;
    int age;
    float retail_price;
    float sales_price;

   public:
    Car(std::string n, int a, float rp, float sp) : name(n), age(a), retail_price(rp), sales_price(sp) {}

    void print() {
        std::cout << "\n==== Car ====\n"
                  << "Name: " << name << "\n"
                  << "Alter: " << age << " \n"
                  << "Retail price: " << retail_price << "\n"
                  << "Sales price: " << sales_price << "\n";
    }
};

Car create_car() {
    std::string name;
    int age;
    float retail_price;
    float sales_price;

    std::cout << "\nName of the car: ";
    std::getline(std::cin, name);

    std::cout << "Age of the car: ";
    std::cin >> age;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Retail price: ";
    std::cin >> retail_price;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Current sales price:";
    std::cin >> sales_price;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return Car(name, age, retail_price, sales_price);
}

int main() {
    std::vector<Car> cars;
    char choice;

    while (true) {
        std::cout << "\nChoose option:\n\n";
        std::cout << "(1) Create a car\n";
        std::cout << "(2) Print list\n";
        std::cout << "(3) Delete cars\n";
        std::cout << "(q) Quit\n\n";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case '1': {
                Car c = create_car();
                cars.push_back(c);
                break;
            }

            case '2': {
                if (cars.empty()) {
                    std::cout << "\nThere is no car yet.\n";
                } else {
                    for (Car& c : cars) {
                        c.print();
                    }
                }
                break;
            }

            case '3': {
                cars.clear();
                std::cout << "\nAll cars were deleted!\n";
                break;
            }

            case 'q': {
                std::cout << "\nClosing the program...\n";
                return 0;
            }

            default:
                std::cout << "\nWrong character!\n";
        }
    }

    return 0;
}
