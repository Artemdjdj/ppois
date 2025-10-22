//
// Created by Redmi on 19.10.2025.
//

#ifndef THIRD_LAB_DATA_MANAGER_H
#define THIRD_LAB_DATA_MANAGER_H
#include <vector>
#include <memory>
#include <unordered_map>
#include <stdexcept>
#include "../Communication/chat.h"
#include "../Generator/generator.h"
#include "../SocialMedia/story.h"
#include "../SocialMedia/post.h"

class DataManager {
public:
    void CreateNewChat(const std::shared_ptr<User> &user1, const std::shared_ptr<User> &user2);

    std::vector<std::shared_ptr<Chat> > GetAllChats(const std::shared_ptr<User> &user);

    std::shared_ptr<Chat> GetChat(const std::shared_ptr<User> &user1, const std::shared_ptr<User> &user2);

    bool IsChatExist(const std::shared_ptr<User> &user1, const std::shared_ptr<User> &user2);

    void SendMessageToChat(const std::shared_ptr<User> &user1, const std::shared_ptr<User> &user2, const std::shared_ptr<Message> &message);

    void DeleteChat(const std::shared_ptr<User> &user1, const std::shared_ptr<User> &user2);

    void CreateNewStory(const std::string &name, const std::string &info, const StorySettings &settings,
                        const std::shared_ptr<User> &user);

    std::vector<std::shared_ptr<Story> > GetAllStories(const std::shared_ptr<User> &user);



    std::shared_ptr<Story> GetStory(const std::shared_ptr<User> &user, const std::string &id);

    void DeleteStory(const std::shared_ptr<User> &user, const std::string &id);

private:
    GeneratorId stories_generator_id_;
    std::unordered_map<std::string, std::vector<std::shared_ptr<Chat> > > chats_;
    std::unordered_map<std::string, std::vector<std::shared_ptr<Story> > > stories_;
    std::unordered_map<std::string, std::vector<std::shared_ptr<Post> > > posts_;

    int GetNumberOfStory(const std::shared_ptr<User> &user, const std::string &id);

    int GetNumberOfPost(const std::shared_ptr<User> &user, const std::string &id);
};

#endif //THIRD_LAB_DATA_MANAGER_H
