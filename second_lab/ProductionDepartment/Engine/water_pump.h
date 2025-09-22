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
class WaterPump : public CarPart {
public:
	/*! \brief Переопределение унаследованной функции
	*  \return Описание
	*/
	std::string GetInfoAboutPart() const override {
		return "This detail name is water pump";
	}

	/*! \brief Параметризованный конструктор
	*  \param flow Начальная скорость потока
	*  \param max_pressure Максимальное давление
	*/
	WaterPump(int flow, int max_pressure);

	/*! \brief Запуск водяного насоса
	*  \return true если запуск прошел успешно, false в противном случае
	*/
	bool StartPump();

	/*! \brief Остановка водяного насоса
	*/
	void StopPump();

	/*! \brief Рассчет текущей скорости потока
	*  \param pressure Текущее давление
	*  \return Скорость потока
	*/
	int CalculateFlow(int pressure);

	/*! \brief Рассчет текущей мощности
	*  \param pressure Текущее давление
	*  \return Мощность
	*/
	int CalculatePower(int pressure) const;

	/*! \brief Получение текущего ресурса
	*  \return Ресурс
	*/
	int GetResource() const;

	/*! \brief Получение текущего давления
	*  \return Давление
	*/
	int GetCurrentPressure() const;

	/*! \brief Получение максимального давления
	*  \return Максимальное давление
	*/
	int GetMaxPressure() const;

	/*! \brief Получение текущей скорости потока
	*  \return Скорость потока
	*/
	int GetFlowRate() const;

	/*! \brief Работает ли насос
	*  \return true,  если работает, false - в противном случае
	*/
	bool GetWorkingState() const;

private:
	int flow_rate_{0};/*!< Скорость потока*/;
	int max_pressure_{0};/*!< Максимальное давление */;
	int current_pressure_{0};/*!< Текущее давление */;
	bool is_working_{false};/*!< Включен ли */;
	int resource_{0};/*!< Ресурс */;
};
#endif //INCLUDE_WATER_PUMP_H
