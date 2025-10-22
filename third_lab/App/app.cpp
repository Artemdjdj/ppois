#include "app.h"


void App::RegistrateUser(const std::string &username, const std::string &password,
                                       const std::string &name) {
    const std::shared_ptr<User> new_user = this->user_manager_.CreateUser(username, password, name);
    this->user_ =new_user;
}

void App::Login(const std::string &username, const std::string &password) {
    const std::shared_ptr<User> new_user = this->user_manager_.AuthenticateUser(username, password);
    this->user_=new_user;
}

void App::Logout() {
    if (!this->user_) {
        throw std::logic_error("User is not authenticate, you can't logout");
    }
    this->user_ = nullptr;
}

void App::DeleteAccount() {
    this->user_manager_.DeleteUser(this->user_);
    this->user_ = nullptr;
}

std::unique_ptr<Profile> App::GetProfile() const {
    return this->user_->GetProfile();
}

void App::CreateNewChat(const std::shared_ptr<User> &second_user) {
    this->data_manager_.CreateNewChat(this->user_, second_user);
}

void App::SendMessageToChat(const std::shared_ptr<User> &second_user, const std::shared_ptr<Message> &message) {
    this->data_manager_.SendMessageToChat(this->user_, second_user, message);
}

void App::DeleteChat(const std::shared_ptr<User>& user) {
    this->data_manager_.DeleteChat(this->user_, user);
}

std::vector<std::shared_ptr<Chat>> App::GetAllChats() {
    return this->data_manager_.GetAllChats(this->user_);
}

std::string App::GetChatName(const std::shared_ptr<User>& user){
    const auto chat = this->data_manager_.GetChat(this->user_, user);
    if (!chat) {
        throw std::logic_error("Chat is not exist, you can't see name!");
    }
    return this->user_->GetUsername();
}

void App::DeleteMessageFromChat(const std::shared_ptr<User> &second_user, const int number_of_message) {
    auto chat  = this->data_manager_.GetChat(this->user_, second_user);
    if (!chat) {
        throw std::logic_error("Chat is not exist, you can't delete it");
    }
    chat->DeleteMessage(number_of_message, this->user_);
}

void App::RefactorMessageInChat(const std::shared_ptr<User> &second_user, const int number_of_message, const std::shared_ptr<Message> &new_message) {
    auto chat  = this->data_manager_.GetChat(this->user_, second_user);
    if (!chat) {
        throw std::logic_error("Chat is not exist, you can't refactor it");
    }
    auto messages = chat->GetAllMessages();
    DefaultWorkingWithVector::RefactorElement(messages, new_message, number_of_message);
}

std::vector<std::pair<int,std::pair<std::string, std::string>>> App::ViewAllHistoryOfChat(const std::shared_ptr<User> &second_user) {
    auto chat  = this->data_manager_.GetChat(this->user_, second_user);
    if (!chat) {
        throw std::logic_error("Chat is not exist, you can't view history");
    }
    auto messages = chat->GetAllMessages();
    int index = 0;
    std::vector<std::pair<int,std::pair<std::string, std::string>>> result;
    for (auto message : messages) {
        if (const auto author = message->GetAuthor()) {
            result.push_back(std::make_pair(++index, std::make_pair(message->GetMessageDefaultText(),author->GetUsername())));
        }
    }
    return result;
}

int App::GetCountOfUsers() const {
    return this->user_manager_.GetCountOfUsers();
}

std::string App::GetAuthor() const {
    if (!this->user_) {
        return "";
    }
    return this->user_->GetUsername();
}

std::shared_ptr<User> App::GetCurrentUser() {
    return this->user_;
}

std::shared_ptr<User> App::GetUser(const std::string& username){
    return this->user_manager_.GetUser(username);
}







