#ifndef WARE_HOUSE_H
#define WARE_HOUSE_H
#include "../ProductionDepartment/CarPart/car_part.h"
#include <string>
#include <map>

class WareHouse {
public:
    WareHouse();
    void AddNewDetail(CarPart* new_detail);
    void DeleteDetailById(std::string id);
    void FindDetailById(std::string id);

private:
    std::map<std::string, CarPart*> warehouse_;
};



#endif //WARE_HOUSE_H
