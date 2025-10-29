/*! \file engine.h
 *  \brief Заголовочный файл с определением класса двигателя
 */
#ifndef ENGINE_H
#define ENGINE_H
#include "gear.h"
#include "intake_manifold.h"
#include "metal_links.h"
#include "piston.h"
#include "tube.h"
#include "valve_spring.h"
#include "water_pump.h"
#include <vector>
#include <string>

/*! \class Engine
 *  \brief Класс для определения двигателя
 *  \details Класс предоставляет возможность управления всеми компонентами двигателя
 */
class Engine : public CarPart {
public:
    /*! \brief Параметризованный конструктор
    *  \param is_worked Заведен ли двигаетль
    *  \param engine_life Количество километров
    *  \param rim Обод
    *  \param prong Зубец
    *  \param intake_manifold Впускной коллектор
    *  \param metal_chain Металлическая цепь
    *  \param tube Трубка
    *  \param water_pump Водяной насос
    */
    Engine(bool is_worked, int engine_life, const Rim &rim, const Prong &prong, const IntakeManifold &intake_manifold,
           const MetalChain &metal_chain, const Tube &tube, const WaterPump &water_pump);

    /*! \brief Переопределение унаследованной функции
    *  \return Описание двигателя
    */
    std::string GetInfoAboutPart() const override {
        return "This detail name is engine";
    }

    /*! \brief Установка параметров обода
    *  \param radius Радиус обода
    *  \param thickness Толщина обода
    *  \param density Плотность материала
    */
    void SetInfoAboutRim(int radius, int thickness, int density);

    /*! \brief Установка параметров зубца
    *  \param first_side Первая сторона
    *  \param second_side Вторая сторона
    *  \param third_side Третья сторона
    *  \param thickness Толщина
    *  \param density Плотность материала
    */
    void SetInfoAboutProng(int first_side, int second_side, int third_side, int thickness, int density);

    /*! \brief Установка параметров впускного коллектора
    *  \param main_volume Основной объем
    *  \param radius_canal Радиус канала
    *  \param height_canal Высота канала
    *  \param number_of_canals Количество каналов
    */
    void SetInfoAboutIntakeManifold(int main_volume, int radius_canal, int height_canal, int number_of_canals);

    /*! \brief Установка параметров металлической цепи
    *  \param count_of_metal_links Количество звеньев
    *  \param height_of_plata Высота пластины
    *  \param width_of_plata Ширина пластины
    *  \param radius Радиус
    *  \param height Высота
    *  \param weight Вес
    */
    void SetInfoAboutMetalChain(int count_of_metal_links, int height_of_plata, int width_of_plata,
                                int radius, int height, int weight);

    /*! \brief Установка параметров поршней
    *  \param count_of_pistons Количество поршней
    *  \param diameter Диаметр
    *  \param height Высота
    *  \param compression_height Высота сжатия
    *  \param count_of_cycles Количество циклов
    *  \param weight Вес
    */
    void SetInfoAboutPistons(int count_of_pistons, int diameter, int height, int compression_height,
                             int count_of_cycles, int weight);

    /*! \brief Установка параметров клапанных пружин
    *  \param count_of_valve_springs Количество пружин
    *  \param diameter Диаметр
    *  \param length Длина
    *  \param count_of_coils Количество витков
    */
    void SetInfoAboutValveSprings(int count_of_valve_springs, int diameter, int length, int count_of_coils);

    /*! \brief Установка параметров трубы
    *  \param radius_tube Радиус трубы
    *  \param height_tube Высота трубы
    */
    void SetInfoAboutTube(int radius_tube, int height_tube);

    /*! \brief Установка параметров водяного насоса
    *  \param flow Поток
    *  \param max_pressure Максимальное давление
    */
    void SetInfoAboutWaterPump(int flow, int max_pressure);

    /*! \brief Запуск двигателя */
    void StartEngine();

    /*! \brief Остановка двигателя */
    void StopEngine();

    /*! \brief Установка года производства двигателя
     *  \param year_of_producing Год производства
     */
    void SetYearOfProducing(int year_of_producing);

    /*! \brief Установка срока службы двигателя
     *  \param max_service_life Срок службы в годах
     */
    void SetMaxServiceLife(int max_service_life);

    /*! \brief Установка количества цилиндров
     *  \param count Количество цилиндров
     */
    void SetCountOfCylinders(int count);

    /*! \brief Установка срока гарантии
     *  \param guarantee Срок гарантии в годах
     */
    void SetGuarantee(int guarantee);

    /*! \brief Установка максимальной мощности
     *  \param power Мощность в л.с.
     */
    void SetMaxPower(int power);

    /*! \brief Установка крутящего момента
     *  \param torque Крутящий момент в Н·м
     */
    void SetTorque(int torque);

    /*! \brief Установка рабочего цикла
     *  \param cycle Рабочий цикл
     */
    void SetWorkCycle(int cycle);

    /*! \brief Установка массы двигателя
     *  \param weight Масса в кг
     */
    void SetWeight(int weight);

    /*! \brief Установка расхода топлива
     *  \param consumption Расход топлива л/100км
     */
    void SetFuelConsumption(double consumption);

    /*! \brief Установка скорости вращения коленвала
     *  \param speed Скорость вращения в об/мин
     */
    void SetRotationSpeed(int speed);

    /*! \brief Установка названия компании-производителя
     *  \param company Название компании
     */
    void SetCompany(const std::string &company);

    /*! \brief Установка страны сборки двигателя
     *  \param country Название страны
     */
    void SetCountry(const std::string &country);

    /*! \brief Установка города производства
     *  \param city Название города
     */
    void SetCity(const std::string &city);

    /*! \brief Установка дополнительной информации
     *  \param info Строка с информацией о двигателе
     */
    void SetInformation(const std::string &info);

    /*! \brief Проверка работы двигателя
    *  \return true если двигатель работает, false в противном случае
    */
    bool CheckIsEngineWorking() const;

    /*! \brief Получение информации об ободе
    *  \return Строка с информацией
    */
    std::string GetInfoAboutRim() const;

    /*! \brief Получение информации о зубце
    *  \return Строка с информацией
    */
    std::string GetInfoAboutProng() const;

    /*! \brief Получение информации о впускном коллекторе
    *  \return Строка с информацией
    */
    std::string GetInfoAboutIntakeManifold() const;

    /*! \brief Получение информации о металлической цепи
    *  \return Строка с информацией
    */
    std::string GetInfoAboutMetalChain() const;

    /*! \brief Получение информации о поршнях
    *  \return Строка с информацией
    */
    std::string GetInfoAboutPistons() const;

    /*! \brief Получение информации о клапанных пружинах
    *  \return Строка с информацией
    */
    std::string GetInfoAboutValveSprings() const;

    /*! \brief Получение информации о трубе
    *  \return Строка с информацией
    */
    std::string GetInfoAboutTube() const;

    /*! \brief Получение информации о водяном насосе
    *  \return Строка с информацией
    */
    std::string GetInfoAboutWaterPump() const;

    /*! \brief Получение информации: нужен ли ТО
    *  \return Строка с информацией
    */
    std::string CheckIsEngineShouldBeServed() const;

    /*! \brief Получение информации о пробеге двигателя
    *  \return Пробег
    */
    int GetInfoAboutEngineLife() const;

    /*! \brief Получение информации о текущем пробеге
    *  \return Текущий пробег
    */
    int GetInfoAboutCurrentMileage() const;

    /*! \brief Проехать путь
    *  \param way Путь
    */
    void DriveTheWay(int way);

    /*! \brief Получение года производства двигателя
     *  \return Год производства в виде целого числа
     */
    int GetYearOfProducing() const;

    /*! \brief Получение срока службы двигателя
     *  \return Срок службы в годах
     */
    int GetMaxServiceLife() const;

    /*! \brief Получение количества цилиндров
     *  \return Количество цилиндров двигателя
     */
    int GetCountOfCylinders() const;

    /*! \brief Получение срока гарантии
     *  \return Срок гарантии в годах
     */
    int GetGuarantee() const;

    /*! \brief Получение максимальной мощности
     *  \return Максимальная мощность в лошадиных силах
     */
    int GetMaxPower() const;

    /*! \brief Получение крутящего момента
     *  \return Крутящий момент в Н·м
     */
    int GetTorque() const;

    /*! \brief Получение рабочего цикла двигателя
     *  \return Рабочий цикл
     */
    int GetWorkCycle() const;

    /*! \brief Получение массу двигателя
     *  \return Масса в килограммах
     */
    int GetWeight() const;

    /*! \brief Получение расхода топлива
     *  \return Расход топлива в литрах на 100 км
     */
    double GetFuelConsumption() const;

    /*! \brief Получение скорости вращения коленвала
     *  \return Скорость вращения в об/мин
     */
    int GetRotationSpeed() const;

    /*! \brief Получение названия компании-производителя
     *  \return Название компании
     */
    std::string GetCompany() const;

    /*! \brief Получение страны сборки двигателя
     *  \return Название страны
     */
    std::string GetCountry() const;

    /*! \brief Получение города производства
     *  \return Название города
     */
    std::string GetCity() const;

    /*! \brief Получение дополнительной информации о двигателе
     *  \return Строка с информацией
     */
    std::string GetInformation() const;

private:
    Rim rim_; /*!< Обод */
    Prong prong_; /*!< Зубец */
    IntakeManifold intake_manifold_; /*!< Впускной коллектор */
    MetalChain metal_chain_; /*!< Металлическая цепь */
    std::vector<Piston> pistons_; /*!< Массив поршней */
    std::vector<ValveSpring> valve_springs_; /*!< Массив клапанных пружин */
    Tube tube_; /*!< Труба */
    WaterPump water_pump_; /*!< Водяной насос */
    bool is_worked_; /*!< Работает ли двигателя */
    const int engine_life_{0}; /*!< Количество километров, через которое нужно пройти плановый ремонт */
    int current_mileage_{0}; /*!< Текущий пробег */
    int year_of_producing_{0}; /*!< Год производства */
    int max_service_life_{0}; /*!<  Срок службы */
    int count_of_cylinders_{0}; /*!< Количество цилиндров */
    int guarantee_{0}; /*!< Срок гарантии */
    int max_power_{0}; /*!< Максимальная мощность */
    int torque_{0}; /*!< Крутящий момент */
    int work_cycle_{0}; /*!< Рабочий цикл */
    int weight_{0}; /*!< Масса */
    double fuel_consumption_{0}; /*!< Расход топлива */
    int rotation_speed_{0}; /*!< Скорость вращения */
    std::string company_; /*!< Компания */
    std::string country_; /*!< Страна, в которой собирали двигатель */
    std::string city_; /*!< Город, где двигатель сделан */
    std::string information_; /*!< Информация о двигателе */
};
#endif //ENGINE_H
