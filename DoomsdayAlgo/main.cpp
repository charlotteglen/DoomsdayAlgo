#include <iostream>
#include <string>
#include <random>
#include "Player.h"

int calculateDay(int m, int d, std::string y);
int generateYear();
int generateDay(int year, int month);
int generateMonth();
std::string wordMonth(int m);
std::string wordDay(int d);

int main() {
    bool newGame = true;
    int Round = 1;
    int Games = 0;
    std::cout << "Welcome to the doomsday algorithm game.";
    std::cout << "\nPlease enter your name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Rules of the game: A random date will be given to you, "
        "ranging from 1900 to 2030.\nYou must tell me what day of the week it is.\n";
    std::cout << "Please enter the day of the week in the following numerical format:";
    std::cout << "\nSunday=0\nMonday=1\nTuesday=2\nWednesday=3\nThursday=4\nFriday=5\nSaturday=6\n"
        << "You will have 3 lives. Have fun playing the game, " << name << "!\n";
    Player player1(name);
    while (newGame) {
        player1.setLives(3);
        player1.setPoints(0);
        while (player1.getLives() != 0) {
            std::cout << "\nRound " << Round << std::endl;
            int year = generateYear();
            std::string y = std::to_string(generateYear());
            int m = generateMonth();
            int d = generateDay(year, m);
            std::cout << "The date is: ";
            std::cout << wordMonth(m) << " " << d << ", " << y << std::endl;
            int dayOfWeek = calculateDay(m, d, y);
            int answer;
            std::cout << "Enter what day of the week it is: \n";
            std::cin >> answer;
            int snark = 0;
            while (answer > 7 || answer < 0) {
                if (snark >= 2) std::cout << "Try again: ";
                else std::cout << "Invalid answer, try again: ";
                std::cin >> answer;
                if (answer > 7 || answer < 0) snark++;
                if (snark == 3) std::cout << "\nPlease enter a valid answer\n";
                if (snark > 3) {
                    std::cout << "\nYou took too many tries. Your game is terminated. Please follow the rules next time\n";
                    newGame = false;
                    break;
                }
            }
            if (!newGame) break;
            if (answer != dayOfWeek) {
                //add something here that says day was/will be

                std::cout << "WRONG! The day is " << wordDay(dayOfWeek) << std::endl;

                player1.decreaseLives();
                std::cout << "You now have " << player1.getLives();
                if ((player1.getLives() > 1) || (player1.getLives() == 0))

                    std::cout << " lives.\n";

                else if (player1.getLives() == 1) std::cout << " life.\n";
            }
            else if (answer == dayOfWeek) {
                std::cout << "CORRECT!\n";
                player1.increasePoints();
            }
            Round++;
        }
        std::cout << "You have run out of lives! Total Points: " <<

            player1.getPoints();
        Games++;
        player1.setPrevPoints(player1.getPoints());
        if (Round == 1) player1.setHighScore(player1.getPoints());
        else if (player1.getPoints() > player1.getHighScore())

            player1.setHighScore(player1.getPoints());

        std::cout << "\nYou got " << player1.getPoints() << "Points. Would you like to play another game? "
            "Enter Y for yes, N for no:\n";
        char yn;
        std::cin >> yn;
        if (yn == 'y' || yn == 'Y') newGame = true;
        else if (yn == 'n' || yn == 'N') newGame = false;
        Round = 1;
    }
    std::cout << "\nThank you for playing the game, " << player1.getName() << " Stats:\nGames Played: "
        << Games << "\nHigh Score: " << player1.getHighScore() << "\n";
    return 0;
}

int calculateDay(int m, int d, std::string y) {
    std::string XX, YY;
    XX = y.substr(0, 2);
    YY = y.substr(2, 2);
    int Year = stoi(y);
    int xx, yy;
    xx = stoi(XX);
    yy = stoi(YY);
    if (xx == 20) xx = 2;
    else if (xx == 19) xx = 3;
    else if (xx == 18) xx = 5;
    else if (xx == 17) xx = 0;
    int n, r, s;
    n = yy / 12;
    r = yy % 12;
    s = r / 4;
    int numDay = xx + n + r + s;
    if (numDay < 7) numDay = numDay + 7;
    int MonthAnchor;
    if (m == 1) {
        if (Year % 4 == 0) MonthAnchor = 4;
        else MonthAnchor = 3;
    }
    if (m == 2) {
        if (Year % 4 == 0)MonthAnchor = 1;
        else MonthAnchor = 0;
    }
    if (m == 3) MonthAnchor = 0;
    if (m == 4) MonthAnchor = 4;
    if (m == 5) MonthAnchor = 2;
    if (m == 6) MonthAnchor = 6;
    if (m == 7) MonthAnchor = 4;
    if (m == 8) MonthAnchor = 1;
    if (m == 9) MonthAnchor = 5;
    if (m == 10) MonthAnchor = 3;
    if (m == 11) MonthAnchor = 0;
    if (m == 12) MonthAnchor = 5;
    numDay = d - MonthAnchor + numDay;
    while (numDay >= 7) {
        numDay = numDay - 7;
    }
    return numDay;
}
int generateYear() {
    std::random_device randomDevice;
    //std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<> disYear(1900, 2030);
    return disYear(randomDevice);
}
int generateMonth() {
    std::random_device randomDevice;
    //std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<> disMonth(1, 12);
    return disMonth(randomDevice);
}
int generateDay(int year, int month) {
    std::random_device randomDevice;
    //std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<>dis30Day(1, 30);
    std::uniform_int_distribution<>dis31Day(1, 31);
    if (year % 4 != 0 && month == 2) {
        std::uniform_int_distribution<>FebLeapYear(1, 29);
        return FebLeapYear(randomDevice);
    }
    else if (year == 2 && (month % 4 != 0)) {
        std::uniform_int_distribution<>FebRegYear(1, 28);
        return FebRegYear(randomDevice);
    }
    else if (month == 4) return dis30Day(randomDevice);
    else if (month == 6) return dis30Day(randomDevice);
    else if (month == 9) return dis30Day(randomDevice);
    else if (month == 11) return dis30Day(randomDevice);
    else return dis31Day(randomDevice);
}
std::string wordMonth(int m) {
    if (m == 1) return "January";
    if (m == 2) return "February";
    if (m == 3) return "March";
    if (m == 4) return "April";
    if (m == 5) return "May";
    if (m == 6) return "June";
    if (m == 7) return "July";
    if (m == 8) return "August";
    if (m == 9) return "September";
    if (m == 10) return "October";
    if (m == 11) return "November";
    if (m == 12) return "December";
    else return "ERROR";
}
std::string wordDay(int d) {
    if (d == 0) return "Sunday";
    if (d == 1) return "Monday";
    if (d == 2) return "Tuesday";
    if (d == 3) return "Wednesday";
    if (d == 4) return "Thursday";
    if (d == 5) return "Friday";
    if (d == 6) return "Saturday";
    else return "ERROR";
}