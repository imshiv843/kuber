#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

struct BankAccount {
    string accountNumber;

    double balance;


    void depositMoney(double amount) {
        balance += amount;
    }

    void displayBalance() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

struct User {
    string username;
    string password;
    string name; // New field for user's name
    string phoneNumber; // New field for user's phone number
    string dob; // New field for user's date of birth
    BankAccount bankAccount;

    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            file << username << " " << password << " " << name << " " << phoneNumber << " " << dob << " " << bankAccount.accountNumber << " " << " " << bankAccount.balance << endl;
            file.close();
        }
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            file >> username >> password >> name >> phoneNumber >> dob >> bankAccount.accountNumber >> bankAccount.balance;
            file.close();
        }
    }
};

static const int n=4;


class Stock {
     string  st="\n\nTHE COMAPNIES AND THEIR RESPECTIVE SHARES\n\n";
   friend  ostream &operator <<(ostream &show,Stock &ss);
public:

    string symbol;
    double price;
    Stock() {}
    Stock(string sym, double pr) : symbol(sym), price(pr) {}
} availableStocks[] = {
        Stock("Apple", 150.25),
        Stock("Google", 2750.65),
        Stock("Tata", 800.10),
        Stock("Microsoft", 340.50),
      };
ostream &operator <<(ostream &show,Stock &ss)
{
    show<<ss.st;
    return show;
}
class Portfolio {
public:
    double bankBalance;

    static const int MAX_STOCKS = 100000;
    Stock stocks[n]={};
    int quantities[MAX_STOCKS]={};
string str="\nEnter 'B' to buy a stock, 'S' to sell a stock, 'D' to display portfolio, or 'Q' to quit: ";
 string filename = "portfolio.txt";
    Portfolio() {
    LoadPortfolio();
    }
   // Load portfolio data from file
   void LoadPortfolio() {
    ifstream file(filename);
    if (file.is_open()) {
        int i = 0;
        while (i < n && file >> stocks[i].symbol >> quantities[i]) {
            i++;
        }
        file.close();
    }
}


    // Save portfolio data to file
    void SavePortfolio() {
        ofstream file(filename);
        if (file.is_open()) {
            for (int i = 0; i < n; ++i) {
                file << stocks[i].symbol << " " << quantities[i] << endl;
            }
            file.close();
        }
    }
    void BuyStock(Stock stock, int quantity) {



        int index=FindStockb(stock.symbol);
        if (index!=-1) {
            stocks[index].symbol=stock.symbol;
            quantities[index] += quantity;

            }

            if(quantity>=MAX_STOCKS) {
                cout << "Portfolio is full, cannot add more stocks." << endl;
            }
        }


    void SellStock(Stock stock, int quantity) {
        int index = FindStocks(stock.symbol);
        if(quantities[index]-quantity<0) throw 0.0;
        if (index != -1) {
            quantities[index] -= quantity;
        } else {
            throw "Stock not found in portfolio.";

        }
    }

    void DisplayPortfolio() {
        cout << "Portfolio:" << endl;
        for (int i = 0; i < n; ++i) {
            if(quantities[i]!=0)
            cout << stocks[i].symbol << " - Quantity: " << quantities[i] << endl;
        }
        cout << endl;
    }
    template<typename T>
    int FindStockb(T& symbol) {
        for (int i = 0; i < n; ++i) {
            if (availableStocks[i].symbol == symbol) {
                return i;
            }
        }
        return -1;
    }
    template<typename T>
     int FindStocks(T& symbol) {
        for (int i = 0; i < n; ++i) {
            if (stocks[i].symbol == symbol && quantities[i]!=0) {
                return i;
            }
        }

        return -1;
    }
friend ostream &operator <<(ostream &display,Portfolio&c);
~Portfolio() {
        SavePortfolio(); // Save portfolio data to file when object is destroyed
    }
};
bool validateLogin(const string& username, const string& password, User& user) {
    ifstream file("credentials.txt");
    if (file.is_open()) {
        string storedUsername, storedPassword, accountNumber, name;
        double balance;
        while (file >> storedUsername >> storedPassword >> accountNumber >> name >> balance) {
            if (storedUsername == username && storedPassword == password) {
                // Login successful, populate the User object with bank account details
                user.username = storedUsername;
                user.password = storedPassword;
                user.bankAccount.accountNumber = accountNumber;
                user.name = name;
                user.bankAccount.balance = balance;
                file.close();
                return true;
            }
        }
        file.close();
    }
    return false; // Login failed
}

ostream &operator <<(ostream &display,Portfolio&c)
{
    display<<c.str<<endl;
    return display;
}
bool storeUserCredentials(const User& user) {
    ofstream file("credentials.txt", ios::app); // Separate file for credentials
    if (file.is_open()) {
        file << user.username << " " << user.password << " " << user.bankAccount.accountNumber << " " << user.name << " " << user.bankAccount.balance << endl; // Write username, password, account number, name, and balance
        file.close();
        cout << "Login credentials stored successfully!\n"; getchar();getchar();system("cls");
        return true;
    } else {
        cout << "Unable to open file!\n";
        getchar();
        system("cls");
        return false;
    }
}
double CalculateAveragePrice(const vector<Stock>& stocks) {
    double totalValue = 0.0;

    for (const Stock& stock : stocks) {
        totalValue += stock.price;
    }

    double averagePrice = totalValue / stocks.size();

    return averagePrice;
}
int main() {
    User* user = nullptr;
    Portfolio* portfolio = nullptr;
    // Add this at the beginning of your main function

 vector<Stock> stocks = {
        Stock("Apple", 150.25),
        Stock("Google", 2750.65),
        Stock("Tata", 800.10),
        Stock("Microsoft", 340.50)
    };





    char choice;
l:
    cout << "\t\tWelcome Niveshak to Kuber - Your Ultimate Stock Market Platform\n";
    cout << "----------------------------------------------------------------------------------------------------------\n";
 double averagePrice = CalculateAveragePrice(stocks);
    cout << "\tThe Kuber4 rate for today is: " << "\t"<<averagePrice << endl << "\tThe Market is Bullish\n\tLet it never be bearish investors!\n"<<endl;
    cout << "** Nivesh Vikalp **\n";
    cout << "1. Login\n";
    cout << "2. Store User Credentials\n";
    cout << "3. Deposit Money\n";
    cout << "4. View Bank Account Balance\n";
    cout << "5. Exit\n6. Go to Nivesh Bazaar\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case '1': {
            // Login
             user = new User();
     user->loadFromFile("user_details.txt");

            string username, password;
            cout << "Enter username and password:\n";
            cin >> username >> password;


            if (validateLogin(username, password, *user)) {
                cout << "Login successful!\n"; getchar();getchar();system("cls");goto l;
            } else {
                cout << "Invalid login credentials.\n";
                delete user;
                user = nullptr;
                getchar();getchar(); system("cls");
                goto l;
            }
            break;
        }
       case '2': {
    // Store User Details
    user = new User();
     user->loadFromFile("user_details.txt");

    cout << "Enter username and password:\n";
    cin >> user->username >> user->password;
    cout << "Enter your name:\n";
    cin.ignore();
    getline(cin, user->name);
    cout << "Enter your phone number:\n";
    getline(cin, user->phoneNumber);
    cout << "Enter your date of birth (DOB):\n";
    getline(cin, user->dob);
    cout << "Enter Account Number:\n";
    cin >> user->bankAccount.accountNumber;

    storeUserCredentials(*user);

    delete user;
    user = nullptr;
    getchar();
    goto l;
    break;
}
        case '3': {
            // Deposit Money
            if (user == nullptr) {
                cout << "Please login first.\n";
                getchar();getchar();system("cls");
                goto l;
            }

            double depositAmount;
            cout << "Enter deposit amount: ";
            cin >> depositAmount;
            user->bankAccount.depositMoney(depositAmount);
            cout << "Deposit successful.\n";
            getchar();getchar();system("cls");
            goto l;
            break;
        }
        case '4': {
            // View Bank Account Balance
            if (user == nullptr) {
                cout << "Please login first.\n";
                getchar();
                goto l;
            }

            user->bankAccount.displayBalance();
            getchar();getchar();system("cls");
            goto l;
            break;
        }
        case '5': {
            // Exit Program
            cout << "Exiting Program...\n";
            if (user != nullptr) {
                delete user;
            }

                delete portfolio;

            return 0;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
            getchar();
            goto l;
            break;

case '6':
     if (user == nullptr) {
                cout << "Please login first.\n";
                getchar();
                goto l;
            }
    try {
        portfolio = new Portfolio();
        Stock sh;
        p:
        cout << sh << endl;

        for (int i = 0; i < 4; ++i) {
            cout << availableStocks[i].symbol << " - Price: " << availableStocks[i].price << endl;
        }
        cout << endl;

        char choice;
        do {
            cout << *portfolio;
            cin >> choice;

            switch (choice) {
                case 'B': {
                    string symbol;
                    int quantity;
                    cout << "Enter stock symbol to buy: ";
                    cin >> symbol;
                    cout << "Enter quantity to buy: ";
                    cin >> quantity;
                    if (quantity <= 0) {
                        throw 's';
                    }

                    int index = portfolio->FindStockb(symbol);
                       if(quantity*availableStocks[index].price>user->bankAccount.balance){
                    cout<<"INSUFFICIENT BALANCE TO PURCHASE THE STOCKS "<<endl;goto p;}
                     else{
                            cout<<"REMAINING AMOUNT AFTER BUYING STOCKS IS "<<(user->bankAccount.balance-=(quantity*availableStocks[index].price))<<endl;}
                    if (index >= 0 && index <= 4) {
                        portfolio->BuyStock(availableStocks[index], quantity);
                        cout << "Bought " << quantity << " shares of " << symbol << endl;
                        goto p;
                    } else {
                        throw 0;
                    }
                    break;
                }
                case 'S': {
                    string symbol;
                    int quantity;
                    cout << "Enter stock symbol to sell: ";
                    cin >> symbol;
                    cout << "Enter quantity to sell: ";
                    cin >> quantity;
                    if (quantity <= 0) {
                        throw 's';
                    }

                    int index = portfolio->FindStocks(symbol);
                       cout<<"REMAINING AMOUNT AFTER SELLING STOCKS IS "<<(user->bankAccount.balance+=(quantity*availableStocks[index].price))<<endl;
                    if (index != -1 ) {
                        portfolio->SellStock(availableStocks[index], quantity);
                        cout << "Sold " << quantity << " shares of " << symbol << endl;
                       goto p;
                    } else {
                        throw 0;
                    }
                    break;
                }
                case 'D':
                    portfolio->DisplayPortfolio();
                    getchar();
                    getchar();
                    system("cls");
                    break;
                case 'Q': {
                    cout << "Saving Portfolio and Exiting...\n";
                    delete user; // Delete the user object
                    delete portfolio; // Delete the portfolio object
                    goto s;
                }

                default:
                    cout << "Invalid choice" << endl;
                    getchar();
                    getchar();
                    system("cls");
            }
        } while (true);
s:
        goto l;
        // Add this to the end of your main function


    } catch (const char* str) {
        cout << str << endl;
        getchar();
        getchar();
        system("cls");
    } catch (int n) {
        cout << "STOCK NOT FOUND or insufficient balance" << endl;
        getchar();
        getchar();
        system("cls"); goto l;
    } catch (double d) {
        cout << "Please note that you cannot sell shares more than you have." << endl;
        getchar();
        getchar();
        system("cls");
    } catch (char x) {
        cout << "Please note that the entered quantity cannot be zero or negative." << endl;
        getchar();
        getchar();
        system("cls");
    }
    user->saveToFile("user_details.txt"); // Save user details to file
    delete user; // Delete the User object

    return 0;
}
}
