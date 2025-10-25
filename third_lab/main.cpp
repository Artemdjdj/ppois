#include <iostream>
#include "WorkingWithUser/working_with_password.h"
#include "App/app.h"

int main() {
    DefaultLogger::ClearFile(kMainLogFile);
    App app;
    std::string username;
    std::string name;
    std::cout <<std::endl<< "==============Registration=============="<<std::endl;
    std::cout << std::endl<<"Please, enter your username:\t";
    std::cin>>username;
    std::cout << std::endl<<"Please, enter your name:\t";
    std::cin>>name;
    std::cout <<std::endl<<"Please, enter your password:\t";
    const std::string password = HidePassword::ReadPassword();
    try {
        app.RegistrateUser(username, password, name);
        std::cout<<std::endl<<GREEN<<"Successful registration"<<RESET<<std::endl;
    }
    catch (const ExceptionUserName &e ) {
        DefaultLogger::LogFile(e.what(), kMainLogFile);
        std::cout<<std::endl<<RED<<e.what()<<RESET<<std::endl;
    }
    catch (const ExceptionName &e ) {
        DefaultLogger::LogFile(e.what(), kMainLogFile);
        std::cout<<std::endl<<RED<<e.what()<<RESET<<std::endl;
    }
    catch (const ExceptionPassword &e ) {
        DefaultLogger::LogFile(e.what(), kMainLogFile);
        std::cout<<std::endl<<RED<<e.what()<<RESET<<std::endl;
    }
    catch (const Exception &e ) {
        DefaultLogger::LogFile(e.what(), kMainLogFile);
        std::cout<<std::endl<<RED<<e.what()<<RESET<<std::endl;
    }
    app.Logout();
    std::cout <<std::endl<< "==============Authorization=============="<<std::endl;
    std::cout << std::endl<<"Please, enter your username:\t";
    std::cin>>username;
    std::cout <<std::endl<<"Please, enter your password:\t";
    std::string check_password;
    std::cin>>check_password;
    try {
        app.Login(username, check_password);
        std::cout<<std::endl<<GREEN<<"Successful authorization"<<RESET<<std::endl;
    }
    catch (const std::invalid_argument& e){
        DefaultLogger::LogFile(e.what(), kMainLogFile);
        std::cout<<std::endl<<RED<<e.what()<<RESET<<std::endl;
    }
    catch (const std::logic_error& e){
        DefaultLogger::LogFile(e.what(), kMainLogFile);
        std::cout<<std::endl<<RED<<e.what()<<RESET<<std::endl;
    }
    system("pause");
    return 0;
}
