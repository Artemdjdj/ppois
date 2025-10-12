#include "post.h"
#include "exceptions.h"
#include "../Utils/project_utils.h"


Post::Post(const std::string &name, const std::string &info, User *author): name_(name), info_(info),
                                                                            author_(author) {
};

void Post::SetName(const std::string &name, const User *author) {
    if (author_ != author) {
        throw ExceptionAccess("You don't have access to changing this post");
    }
    this->name_ = name;
}

void Post::SetInfo(const std::string &info, const User *author) {
    if (author_ != author) {
        throw ExceptionAccess("You don't have access to changing this post");
    }
    this->info_ = info;
}

std::string Post::GetName() const {
    return this->name_;
}

std::string Post::GetInfo() const {
    return this->info_;
}

void Post::AddReaction(Reaction *reaction) {
    this->reactions_[reaction->SeeAuthor()] = reaction;

}

void Post::RemoveReaction(const std::string &username) {
    auto it = this->reactions_.find(username);
    if (it == this->reactions_.end()) {
        throw std::logic_error("You don't have access to remove this post");
    }
    this->reactions_.erase(it);
}

Reaction *Post::SeeReactionByAuthor(const std::string &username) const {
    return this->reactions_.at(username);
}

int Post::CheckHashTagUsed(const std::string &check_hash_tag) const {
    int it= 0;
    for (const auto &hash_tag: this->hash_tags_) {
        if (hash_tag->GetHashTag() == check_hash_tag) {
            return it;
        }
        it++;
    }
    return -1;
}

void Post::AddHashTag(HashTag* hash_tag) {
    std::string check_hash_tag_str = hash_tag->GetHashTag();
    DefaultProjectSettings::ToLower(check_hash_tag_str);
    if (this->author_->GetUserName()!= hash_tag->SeeAuthor()) {
        throw ExceptionAccess("You don't have access to changing this post");
    }
    if (CheckHashTagUsed(check_hash_tag_str)!=-1) {
        throw std::invalid_argument("Such hash tag is used in this post!");
    }
    this->hash_tags_.push_back(hash_tag);
}

void Post::RemoveHashTag(const std::string& hash_tag, const User * author) {
    if (this->author_!= author) {
        throw ExceptionAccess("You don't have access to changing this post");
    }
    const auto it  = CheckHashTagUsed(hash_tag);
    if (it == -1) {
        throw std::logic_error("Nothing to delete");
    }
    this->hash_tags_.erase(hash_tags_.begin() + it);
}

int Post::CheckPollUsed(const std::string &check_question) const {
    int it = 0;
    for (const auto & poll : polls_) {
        if (poll->GetQuestion() == check_question) {
            return it;
        }
        it++;
    }
    return -1;
}

bool Post::CheckPollUsedInList(const Poll *check_poll) const {
    for (const auto & poll : polls_) {
        if (poll == check_poll) {
            return true;
        }
    }
    return false;
}


void Post::AddPoll(Poll* poll, const User *author) {
    if (this->author_!= author) {
        throw ExceptionAccess("You don't have access to changing this post");
    }
    if (CheckPollUsedInList(poll)) {
        throw std::invalid_argument("Poll already exists");
    }
    this->polls_.push_back(poll);
}

void Post::RemovePoll(const std::string& question, const User * author) {
    if (this->author_!= author) {
        throw ExceptionAccess("You don't have access to changing this post");
    }
    const auto it  = CheckPollUsed(question);
    if (it == -1) {
        throw std::logic_error("Nothing to delete");
    }
    this->polls_.erase(polls_.begin() + it);
}