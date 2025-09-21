/*! \file water_pump.h
 *  \brief Заголовочный файл с определением класса водяного насоса
 */
#ifndef INCLUDE_WATER_PUMP_H
#define INCLUDE_WATER_PUMP_H
#include "../CarPart/car_part.h"
/*! \class WaterPump
 *  \brief Класс для определения базовых параметров водяного насоса
 *  \details Класс предоставляет возможность получения и изменения базовых параметров водяного насоса
 */
class WaterPump:public CarPart{
private:
    int flow_rate{0};/*!< Скорость потока*/;
    int max_pressure{0};/*!< Максимальное давление */;
    int current_pressure{0};/*!< Текущее давление */;
    bool is_working{false};/*!< Включен ли */;
    int resource{0};/*!< Ресурс */;
public:

	/*! \brief Переопределение унаследованной функции
	*  \return Описание
	*/
	std::string get_info_about_part() const override {
		return"This class describes water pump in engine";
	}

    /*! \brief Параметризованный конструктор
	*  \param flow Начальная скорость потока
	*  \param max_pressure Максимальное давление
	*/
    WaterPump(int flow, int max_pressure);

    /*! \brief Запуск водяного насоса
	*  \return true если запуск прошел успешно, false в противном случае
	*/
    bool start_pump();

    /*! \brief Остановка водяного насоса
	*/
    void stop_pump();

    /*! \brief Рассчет текущей скорости потока
    *  \param pressure Текущее давление
	*  \return Скорость потока
	*/
    int calculate_flow(int pressure);

    /*! \brief Рассчет текущей мощности
    *  \param pressure Текущее давление
	*  \return Мощность
	*/
    int calculate_power(int pressure) const;

    /*! \brief Получение текущего ресурса
	*  \return Ресурс
	*/
    int get_resource() const;

    /*! \brief Получение текущего давления
	*  \return Давление
	*/
    int get_current_pressure() const;

    /*! \brief Получение максимального давления
	*  \return Максимальное давление
	*/
    int get_max_pressure() const;

    /*! \brief Получение текущей скорости потока
	*  \return Скорость потока
	*/
    int get_flow_rate() const;

    /*! \brief Работает ли насос
	*  \return true,  если работает, false - в противном случае
	*/
    bool get_working_state() const;
};
#endif //INCLUDE_WATER_PUMP_H
