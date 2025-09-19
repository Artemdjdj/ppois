
#ifndef INCLUDE_SPEEDOMETER_H
#define INCLUDE_SPEEDOMETER_H

class DefaultSpeedometer{
protected:
    int speed{0};
    int mileage{0};
public:
    DefaultSpeedometer();
    DefaultSpeedometer(int speed,int mileage);
    virtual bool set_speed(int speed) = 0;
    virtual bool set_mileage(int mileage) =0;
    int get_speed() const;
    int get_mileage() const;
    virtual ~DefaultSpeedometer()= default;
};

class SpeedometerInKilometers: public DefaultSpeedometer{
public:
    SpeedometerInKilometers();
    SpeedometerInKilometers(int speed,int mileage);
    bool set_speed(int speed) override;
    bool set_mileage(int mileage) override;
};

class SpeedometerInMiles: public DefaultSpeedometer{
public:
    SpeedometerInMiles(int speed, int mileage);
    SpeedometerInMiles();
    bool set_speed(int speed) override;
    bool set_mileage(int mileage) override;
};
#endif //INCLUDE_SPEEDOMETER_H
