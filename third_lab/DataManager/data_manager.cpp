#include "data_manager.h"

void DataManager::CreateNewChat(const std::string &user1, const std::string &user2) {
    if (IsChatExist(user1, user2)) {
        throw std::logic_error("Such chat is exist");
    }
    const auto new_chat = std::make_shared<Chat>(user1, user2);
    this->chats_[user1].push_back(new_chat);
    this->chats_[user2].push_back(new_chat);
}

bool DataManager::IsChatExist(const std::string &user1, const std::string &user2) {
    for (const auto &chat: this->chats_[user1]) {
        if (chat->GetFirstMember() == user1 and chat->GetSecondMember() == user2 or chat->GetFirstMember() == user2 and
            chat->GetSecondMember() == user1) {
            return true;
        }
    }
    return false;
}

std::shared_ptr<Chat> DataManager::GetChat(const std::string &user1, const std::string &user2) {
    for (auto &chat: this->chats_[user1]) {
        if (chat->GetFirstMember() == user1 and chat->GetSecondMember() == user2 or chat->GetFirstMember() == user2 and
            chat->GetSecondMember() == user1) {
            return chat;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Chat> > DataManager::GetAllChats(const std::string &user) {
    if (!this->chats_.contains(user)) {
        throw std::logic_error("User do not have any chats!");
    }
    return this->chats_[user];
}

void DataManager::DeleteChat(const std::string &user1, const std::string &user2) {
    int index = 0;
    for (const auto &chat: this->chats_[user1]) {
        if ((chat->GetFirstMember() == user1 and chat->GetSecondMember() == user2) or (
                chat->GetFirstMember() == user2 and chat->GetSecondMember() == user1)) {
            DefaultWorkingWithVector::DeleteElementFromVectorByPos(this->chats_[user1], index);
        }
        index += 1;
    }
    index = 0;
    for (const auto &chat: this->chats_[user2]) {
        if ((chat->GetFirstMember() == user1 and chat->GetSecondMember() == user2) or (
                chat->GetFirstMember() == user2 and chat->GetSecondMember() == user1)) {
            DefaultWorkingWithVector::DeleteElementFromVectorByPos(this->chats_[user2], index);
            return;
        }
    }
    throw std::logic_error("Such chat is not exist");
}

void DataManager::CreateNewStory(const std::string &name, const std::string &info, const StorySettings &settings,
                                 const std::string &user) {
    std::string id;
    this->stories_generator_id_.GenerateNewId(id);
    const auto new_story = std::make_shared<Story>(name, info, settings, user, id);
    this->stories_[user].push_back(new_story);
}

std::vector<std::shared_ptr<Story> > DataManager::GetAllStories(const std::string &user) {
    if (!this->stories_.contains(user)) {
        throw std::logic_error("Such user doesn't have any stories ");
    }
    return this->stories_[user];
}

int DataManager::GetNumberOfStory(const std::string &user, const std::string &id) {
    if (!this->stories_.contains(user)) {
        throw std::logic_error("Such user doesn't have any stories ");
    }
    int index = 0;
    for (const auto &story: this->stories_[user]) {
        if (story->GetId() == id) {
            return index;
        }
        index++;
    }
    return -1;
}

std::shared_ptr<Story> DataManager::GetStory(const std::string &user, const std::string &id) {
    const int pos_of_user_story = GetNumberOfStory(user, id);
    if (pos_of_user_story == -1) {
        throw std::logic_error("This story is not exist");
    }
    return this->stories_[user][pos_of_user_story];
}

void DataManager::DeleteStory(const std::string &user, const std::string &id) {
    const int pos_of_user_story = GetNumberOfStory(user, id);
    DefaultWorkingWithVector::DeleteElementFromVectorByPos(this->stories_[user], pos_of_user_story);
}

void DataManager::SendMessageToChat(const std::string &user1, const std::string &user2,
                                    const std::shared_ptr<Message> &message) {
    auto chat = GetChat(user1, user2);
    if (!chat) {
        throw std::logic_error("Such chat is not exist!");
    }
    chat->WriteMessage(message);
}
