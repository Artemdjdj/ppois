#include "data_manager.h"

void DataManager::CreateNewChat(const std::shared_ptr<User> &user1, const std::shared_ptr<User> &user2) {
    if (!user1 or !user2) {
        throw std::invalid_argument("One of the users is empty");
    }
    if (IsChatExist(user1, user2)) {
        throw std::logic_error("Such chat is exist");
    }
    const auto new_chat = std::make_shared<Chat>(user1, user2);
    this->chats_[user1->GetUserName()].push_back(new_chat);
    this->chats_[user2->GetUserName()].push_back(new_chat);
}

bool DataManager::IsChatExist(const std::shared_ptr<User> &user1, const std::shared_ptr<User> &user2) {
    for (const auto& chat : this->chats_[user1->GetUserName()]) {
        if (chat->GetFirstUser() == user1  and chat->GetSecondMember() == user2 or chat->GetFirstUser() == user2 and chat->GetSecondMember() == user1) {
            return true;
        }
    }
    return false;
}

std::shared_ptr<Chat> DataManager::GetChat(const std::shared_ptr<User> &user1, const std::shared_ptr<User> &user2) {
    if (!user1 or !user2) {
        return nullptr;
    }
    for (auto& chat : this->chats_[user1->GetUserName()]) {
        if (chat->GetFirstUser() == user1  and chat->GetSecondMember() == user2 or chat->GetFirstUser() == user2 and chat->GetSecondMember() == user1) {
            return chat;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Chat>> DataManager::GetAllChats(const std::shared_ptr<User> &user) {
    if (!user) {
        throw std::invalid_argument("The user is empty");
    }
    if (!this->chats_.contains(user->GetUserName())) {
        throw std::logic_error("User do not have any chats!");
    }
    return this->chats_[user->GetUserName()];
}

void DataManager::DeleteChat(const std::shared_ptr<User> &user1, const std::shared_ptr<User> &user2) {
    if (!user1 or !user2) {
        throw std::invalid_argument("The authors can't be empty");
    }
    int index = 0;
    for (auto& chat : this->chats_[user1->GetUserName()]) {
        if (chat->GetFirstUser() == user1  and chat->GetSecondMember() == user2 or chat->GetFirstUser() == user2 and chat->GetSecondMember() == user1) {
            DefaultWorkingWithVector::DeleteElementFromVectorByPos(this->chats_[user1->GetUserName()], index);
        }
        index+=1;
    }
    index = 0;
    for (auto& chat : this->chats_[user2->GetUserName()]) {
        if (chat->GetFirstUser() == user1  and chat->GetSecondMember() == user2 or chat->GetFirstUser() == user2 and chat->GetSecondMember() == user1) {
            DefaultWorkingWithVector::DeleteElementFromVectorByPos(this->chats_[user2->GetUserName()], index);
            return;
        }
    }
    throw std::logic_error("Such chat is not exist");
}

void DataManager::CreateNewStory(const std::string &name, const std::string &info, const StorySettings &settings, const std::shared_ptr<User> &user) {
    if (!user) {
        throw std::invalid_argument("author can't be empty");
    }
    std::string id;
    this->stories_generator_id.GenerateNewId(id);
    const auto new_story = std::make_shared<Story>(name, info,settings, user, id);
    this->stories_[user->GetUserName()].push_back(new_story);
}
std::vector<std::shared_ptr<Story>> DataManager::GetAllStories(std::shared_ptr<User> user) {
    if (!user) {
        throw std::invalid_argument("author can't be empty");
    }
    if (!this->stories_.contains(user->GetUserName())) {
        throw std::logic_error("Such user doesn't have any stories ");
    }
    return this->stories_[user->GetUserName()];
}

int DataManager::GetNumberOfStory(const std::shared_ptr<User> &user, const std::string& id) {
    if (!user) {
        throw std::invalid_argument("author can't be empty");
    }
    if (!this->stories_.contains(user->GetUserName())) {
        throw std::logic_error("Such user doesn't have any stories ");
    }
    int index = 0;
    for (const auto &story : this->stories_[user->GetUserName()]) {
        if (story->GetId() == id) {
            return index;
        }
        index++;
    }
    return -1;
}

std::shared_ptr<Story> DataManager::GetStory(const std::shared_ptr<User> &user, const std::string& id) {
    const int pos_of_user_story = GetNumberOfStory(user, id);
    if (pos_of_user_story==-1) {
        throw std::logic_error("This story is not exist");
    }
    return this->stories_[user->GetUserName()][pos_of_user_story];
}

void DataManager::DeleteStory(const std::shared_ptr<User> &user, const std::string& id) {
    const int pos_of_user_story = GetNumberOfStory(user, id);
    DefaultWorkingWithVector::DeleteElementFromVectorByPos(this->stories_[user->GetUserName()], pos_of_user_story);
}

void DataManager::CreateNewPost(const std::string &name, const std::string &info, const std::shared_ptr<User> &user) {
    if (!user) {
        throw std::invalid_argument("author can't be empty");
    }
    std::string id;
    this->posts_generator_id.GenerateNewId(id);
    const auto new_story = std::make_shared<Post>(name, info, user, id);
    this->posts_[user->GetUserName()].push_back(new_story);
}
std::vector<std::shared_ptr<Post>> DataManager::GetAllPosts(const std::shared_ptr<User> &user){
    if (!user) {
        throw std::invalid_argument("author can't be empty");
    }
    if (!this->posts_.contains(user->GetUserName())) {
        throw std::logic_error("Such user doesn't have any stories ");
    }
    return this->posts_[user->GetUserName()];
}

int DataManager::GetNumberOfPost(const std::shared_ptr<User> &user, const std::string& id) {
    if (!user) {
        throw std::invalid_argument("author can't be empty");
    }
    if (!this->posts_.contains(user->GetUserName())) {
        throw std::logic_error("Such user doesn't have any stories ");
    }
    int index = 0;
    for (const auto &post : this->posts_[user->GetUserName()]) {
        if (post->GetId() == id) {
            return index;
        }
        index++;
    }
    return -1;
}

std::shared_ptr<Post> DataManager::GetPost(const std::shared_ptr<User> &user, const std::string& id) {
    const int pos_of_user_post = GetNumberOfPost(user, id);
    if (pos_of_user_post==-1) {
        throw std::logic_error("This story is not exist");
    }
    return this->posts_[user->GetUserName()][pos_of_user_post];
}

void DataManager::DeletePost(const std::shared_ptr<User> &user, const std::string& id) {
    const int pos_of_user_post = GetNumberOfPost(user, id);
    DefaultWorkingWithVector::DeleteElementFromVectorByPos(this->posts_[user->GetUserName()], pos_of_user_post);
}
