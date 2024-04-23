#include <iostream>

#include <Windows.h>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accNum, double initBalance) : accountNumber(accNum), balance(initBalance), interestRate(0)
    {

    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        }
        else {
            cout << "Недостаточно средств!" << endl;
            return false;
        }
    }

    double getBalance() const {
        return balance;
    }

    double getInterest() const {
        return balance * interestRate * (1 / 12);
    }

    void setInterestRate(double newRate) {
        interestRate = newRate;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        return true;
    }
    else {
        cout << "Ошибка перевода: недостаточно средств счете!" << endl;
        return false;
    }
}

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Rus");
    int choose;

    BankAccount acc1(1111, 1000);
    BankAccount acc2(2222, 500);

    do {

    cout << "Введите действие которое хотите выполнить: \n1)Вывод баланса двух аккаунтов\n2)Рассчитать процентную ставку\n3)Поставить новую ставку\n4)Получить номер аккаунта\n5)Выйти\n";
    cin >> choose;
        switch (choose)
        {
            case 1:
                cout << "Баланс 1 аккаунта: " << acc1.getBalance() << endl;
                cout << "Баланс 2 аккаунта: " << acc2.getBalance() << endl;
                break;
            case 2:
                cout << "Расчет процентной ставки для первого аккаунта: " << acc1.getInterest() << endl;
                cout << "Расчет процентной ставки для второго аккаунта: " << acc2.getInterest() << endl;
                break;
            case 3:

        }

    } while (choose >= 5);
    acc1.deposit(100);
    acc2.withdraw(100);

    transfer(acc1, acc2, 0);

    

    return 0;
}
