#include <iostream>
#include "WorkingWithUser/working_with_password.h"
#include "App/app.h"

int main() {
    DefaultLogger::ClearFile(kMainLogFile);
    App app;
    std::string username;
    std::string name;
    std::cout << std::endl<<"Please, enter your username:\t";
    std::cin>>username;
    std::cout << std::endl<<"Please, enter your name:\t";
    std::cin>>name;
    std::cout <<std::endl<<"Please, enter your password:\t";
    const std::string password = HidePassword::ReadPassword();
    try {
        app.RegistrateUser(username, password, name);
    }
    catch (const ExceptionUserName &e ) {
        DefaultLogger::LogFile(e.what(), kMainLogFile);
    }
    catch (const ExceptionName &e ) {
        DefaultLogger::LogFile(e.what(), kMainLogFile);
    }
    catch (const ExceptionPassword &e ) {
        DefaultLogger::LogFile(e.what(), kMainLogFile);
    }
    catch (const Exception &e ) {
        DefaultLogger::LogFile(e.what(), kMainLogFile);
    }

    return 0;
}
