
#include "generator_id.h"


GeneratorId* GeneratorId::GetInstance(){
    if (instance_ptr_ == nullptr) {
        instance_ptr_ = new GeneratorId();
    }
    return instance_ptr_;
}

GeneratorId* GeneratorId::instance_ptr_ = nullptr;

