
#ifndef INCLUDE_SPEEDOMETER_H
#define INCLUDE_SPEEDOMETER_H

class DefaultSpeedometer{
private:
    int speed{0};
    int mileage{0};
public:
    DefaultSpeedometer();
    DefaultSpeedometer(int speed,int mileage);
    bool set_speed(int speed);
    bool set_mileage(int mileage);
    int get_speed();
    int get_mileage();
    virtual ~DefaultSpeedometer();
    virtual void check_speed() = 0;
    virtual void check_mileage() = 0;
};

class SpeedometerInKilometers: public DefaultSpeedometer{
public:
    SpeedometerInKilometers();
    SpeedometerInKilometers(int speed, int mileage);
    void check_speed() override;
    void check_mileage() override;
};

class SpeedometerInMiles: public DefaultSpeedometer{
public:
    SpeedometerInMiles();
    SpeedometerInMiles(int speed, int mileage);
    void check_speed() override;
    void check_mileage() override;
};
#endif //INCLUDE_SPEEDOMETER_H
