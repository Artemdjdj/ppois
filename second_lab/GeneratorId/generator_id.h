
#ifndef GENERATOR_ID_H
#define GENERATOR_ID_H
#include <vector>
#include "string"

class GeneratorId {
private:
    GeneratorId()=default;

public:
    GeneratorId(const GeneratorId& ) = delete;

    ~GeneratorId() { instance_ptr_ = nullptr; }

    static GeneratorId* GetInstance();

    std::string GenerateNewId();

private:
    std::vector<std::string> list_of_id_{};
    static GeneratorId* instance_ptr_;
};

#endif //GENERATOR_ID_H
