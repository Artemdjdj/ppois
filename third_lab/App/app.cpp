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


Profile* App::GetProfile() const {
    return this->user_->GetProfile().get();
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

void App::SetLocation(const std::string& location) const {
    const auto profile = GetProfile();
    profile->SetLocation(location);
}

void App::SetBiography(const std::string& biography) const {
    const auto profile = GetProfile();
    profile->SetBiography(biography);
}

void App::SetGender(const bool is_man) const {
    const auto profile = GetProfile();
    profile->SetGender(is_man);
}

void App::SetAge(const int age) const {
    const auto profile = GetProfile();
    profile->SetAge(age);
}

std::string App::GetLocation() const {
    return GetProfile()->GetLocation();
}

std::string App::GetBiography() const {
    return GetProfile()->GetBiography();
}

bool App::GetGender() const {
    return GetProfile()->GetGender();
}

int App::GetAge() const {
    return GetProfile()->GetAge();
}

void App::AddUserToBlackList(const std::string &user){
    if (this->user_ and GetCurrentUser()->GetUsername()  == user) {
        throw std::logic_error("You can't add to black list yourself");
    }
    if (const auto bad_user = GetUser(user); !bad_user) {
        throw std::logic_error("You can't add this_person, because he is not exist!");
    }
    const auto profile = GetProfile();
    profile->AddUserToBlackList(user);
}

void App::DeleteUserFromBlackList(const std::string& user) const {
    const auto profile = GetProfile();
    profile->DeleteUserFromBlackList(user);
}

void App::DeleteAllFromBlackList() const {
    const auto profile = GetProfile();
    profile->DeleteAllFromBlackList();
}

std::vector<std::string> App::GetBlockedUsersNamesFromBlackList() {
    const auto profile = GetProfile();
    return profile->GetBlockedUsersNamesFromBlackList();
}











