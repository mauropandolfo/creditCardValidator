#include<iostream>
#include <string>
#include <regex>

class CreditCard{
    long number;
    std::string name;
    std::string expirationDate;
    int securityCode;

    public:
        CreditCard(long number, char* name, char* expirationDate, int securityCode){
            this ->number = number;
            this ->name = std::string(name);
            this ->expirationDate = std::string(expirationDate);
            this ->securityCode = securityCode;
        }

        bool validate(CreditCard creditCard){
            if(!validateNumber(creditCard.number) || !validateName(creditCard.name) || !validateSecurityCode(creditCard.securityCode)) return false;
            return true;
        }
    
    private:
        bool validateNumber(int number){
            long invertedNumber = 0;
            long tempNumber = number ;
            while(tempNumber > 0){
                invertedNumber = invertedNumber * 10 + tempNumber % 10;
                tempNumber /= 10;
            }
            int add = 0;
            bool secondDigit = false ;
            while(invertedNumber > 0){
                int digit = invertedNumber % 10;
                if(secondDigit){
                    digit*=2;
                    if(digit > 9){
                        digit -= 9;
                    }
                    
                }
                add += digit;
                secondDigit = !secondDigit;
                invertedNumber /= 10;
            }
            return (add % 10 == 0);
        }

        bool validateName(std::string name){
            std::regex letterCheck("^[a-zA-Z ]+$");
            if(!std::regex_match(name, letterCheck)) return false;
            if(name.length() == 0) return false;
            return true;
        }

        bool validateSecurityCode(int securityCode){
            if(securityCode < 100 || securityCode > 999) return false;
            return true;
        }
};