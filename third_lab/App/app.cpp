#include "app.h"


void App::RegistrateUser(const std::string &username, const std::string &password,
                                       const std::string &name) {
    const std::shared_ptr<User> new_user = this->user_manager_.CreateUser(username, password, name);
    this->user_ =new_user;
}

void App::Login(const std::string &username, const std::string &password) {
    if (this->user_) {
        throw std::logic_error("Now user is authenticate, logout before login");
    }
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

void App::CreateNewChat(const std::string &second_user) {
    this->data_manager_.CreateNewChat(this->user_->GetUsername(), second_user);
}

void App::SendMessageToChat(const std::string &second_user, const std::shared_ptr<Message> &message) {
    this->data_manager_.SendMessageToChat(this->user_->GetUsername(), second_user, message);
}

void App::DeleteChat(const std::string& user) {
    this->data_manager_.DeleteChat(this->user_->GetUsername(), user);
}

std::vector<std::shared_ptr<Chat>> App::GetAllChats() {
    return this->data_manager_.GetAllChats(this->user_->GetUsername());
}

std::string App::GetChatName(const std::string& user){
    const auto chat = this->data_manager_.GetChat(this->user_->GetUsername(), user);
    if (!chat) {
        throw std::logic_error("Chat is not exist, you can't see name!");
    }
    const auto user1 = chat->GetFirstMember();
    const auto user2  = chat->GetSecondMember();
    return (user1 == this->user_->GetUsername())?user2:user1;
}

void App::DeleteMessageFromChat(const std::string &second_user, const int number_of_message) {
    auto chat  = this->data_manager_.GetChat(this->user_->GetUsername(), second_user);
    if (!chat) {
        throw std::logic_error("Chat is not exist, you can't delete it");
    }
    chat->DeleteMessage(number_of_message, this->user_->GetUsername());
}

void App::RefactorMessageInChat(const std::string &second_user, const int number_of_message, const std::shared_ptr<Message> &new_message) {
    auto chat  = this->data_manager_.GetChat(this->user_->GetUsername(), second_user);
    if (!chat) {
        throw std::logic_error("Chat is not exist, you can't refactor it");
    }
    chat->RefactorMessage(new_message->GetMessageDefaultText(), number_of_message, this->user_->GetUsername());
}

std::vector<std::pair<int,std::pair<std::string, std::string>>> App::ViewAllHistoryOfChat(const std::string &second_user) {
    const auto chat  = this->data_manager_.GetChat(this->user_->GetUsername(), second_user);
    if (!chat) {
        throw std::logic_error("Chat is not exist, you can't view history");
    }
    const auto messages = chat->GetAllMessages();
    int index = 0;
    std::vector<std::pair<int,std::pair<std::string, std::string>>> result;
    for (const auto& message : messages) {
        result.emplace_back(++index, std::make_pair(message->GetMessageDefaultText(),message->GetAuthor()));
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

std::shared_ptr<Chat> App::GetChat(const std::string& user) {
    return this->data_manager_.GetChat(this->user_->GetUsername(), user);
}

std::shared_ptr<User> App::GetCurrentUser() {
    return this->user_;
}

std::shared_ptr<User> App::GetUser(const std::string& username){
    return this->user_manager_.GetUser(username);
}







