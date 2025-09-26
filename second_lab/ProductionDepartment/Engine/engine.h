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
	*/
	Engine(bool is_worked, int engine_life);

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
	*  \return true если установка прошла успешно, false в противном случае
	*/
	bool SetInfoAboutRim(int radius, int thickness, int density);

	/*! \brief Установка параметров зубца
	*  \param first_side Первая сторона
	*  \param second_side Вторая сторона
	*  \param third_side Третья сторона
	*  \param thickness Толщина
	*  \param density Плотность материала
	*  \return true если установка прошла успешно, false в противном случае
	*/
	bool SetInfoAboutProng(int first_side, int second_side, int third_side, int thickness, int density);

	/*! \brief Установка параметров впускного коллектора
	*  \param main_volume Основной объем
	*  \param radius_canal Радиус канала
	*  \param height_canal Высота канала
	*  \param number_of_canals Количество каналов
	*  \return true если установка прошла успешно, false в противном случае
	*/
	bool SetInfoAboutIntakeManifold(int main_volume, int radius_canal, int height_canal, int number_of_canals);

	/*! \brief Установка параметров металлической цепи
	*  \param count_of_metal_links Количество звеньев
	*  \param height_of_plata Высота пластины
	*  \param width_of_plata Ширина пластины
	*  \param radius Радиус
	*  \param height Высота
	*  \param weight Вес
	*  \return true если установка прошла успешно, false в противном случае
	*/
	bool SetInfoAboutMetalChain(int count_of_metal_links, int height_of_plata, int width_of_plata,
								int radius, int height, int weight);

	/*! \brief Установка параметров поршней
	*  \param count_of_pistons Количество поршней
	*  \param diameter Диаметр
	*  \param height Высота
	*  \param compression_height Высота сжатия
	*  \param count_of_cycles Количество циклов
	*  \param weight Вес
	*  \return true если установка прошла успешно, false в противном случае
	*/
	bool SetInfoAboutPistons(int count_of_pistons, int diameter, int height, int compression_height,
							int count_of_cycles, int weight);

	/*! \brief Установка параметров клапанных пружин
	*  \param count_of_valve_springs Количество пружин
	*  \param diameter Диаметр
	*  \param length Длина
	*  \param count_of_coils Количество витков
	*  \return true если установка прошла успешно, false в противном случае
	*/
	bool SetInfoAboutValveSprings(int count_of_valve_springs, int diameter, int length, int count_of_coils);

	/*! \brief Установка параметров трубы
	*  \param radius_tube Радиус трубы
	*  \param height_tube Высота трубы
	*  \return true если установка прошла успешно, false в противном случае
	*/
	bool SetInfoAboutTube(int radius_tube, int height_tube);

	/*! \brief Установка параметров водяного насоса
	*  \param flow Поток
	*  \param max_pressure Максимальное давление
	*/
	void SetInfoAboutWaterPump(int flow, int max_pressure);

	/*! \brief Запуск двигателя */
	void StartEngine();

	/*! \brief Остановка двигателя */
	void StopEngine();

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
};
#endif //ENGINE_H
