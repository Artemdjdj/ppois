/*! \file wheel.h
 *  \brief Заголовочный файл с определением классов для колеса и руля
 */
#ifndef INCLUDE_WHEEL_H
#define INCLUDE_WHEEL_H
#include <vector>
#include <string>
#include "../Include/basic_params.h"
#include "../CarPart/car_part.h"
#include "../Include/settings.h"
/*! \class BaseCircle
 *  \brief Класс для определения базовых параметров круга
 *  \details Класс предоставляет возможность работы с радиусом круга
 */
class BaseCircle {
public:
	/*! \brief Конструктор по умолчанию */
	BaseCircle() {
	}

	/*! \brief Параметризованный конструктор
	*  \param radius Начальный радиус
	*/
	BaseCircle(int radius);

	/*! \brief Установка радиуса
	*  \param r Новое значение радиуса
	*  \return true если установка прошла успешно, false в противном случае
	*/
	bool SetRadius(int r);

	/*! \brief Получение текущего радиуса
	*  \return Радиус
	*/
	int GetRadius() const;

private:
	int radius_{0}; /*!< Радиус круга */
};

/*! \class BrakeShoe
 *  \brief Класс для определения тормозной колодки
 *  \details Класс предоставляет возможность работы с параметрами тормозной колодки
 */
class BrakeShoe : public CarPart, public BasicParams, public Color {
public:
	/*! \brief Переопределение унаследованной функции
	*  \return Описание
	*/
	std::string GetInfoAboutPart() const override {
		return "This detail name is brake shoe";
	}

	/*! \brief Конструктор по умолчанию */
	BrakeShoe();

	/*! \brief Параметризованный конструктор
	*  \param height Высота
	*  \param width Ширина
	*  \param material Материал
	*  \param color Цвет
	*/
	BrakeShoe(int height, int width, std::string material, std::string color);

	/*! \brief Параметризованный конструктор
	*  \param material Материал
	*/
	BrakeShoe(std::string material);

	/*! \brief Установка материала
	*  \param material Новый материал
	*  \return true если установка прошла успешно, false в противном случае
	*/
	bool SetMaterial(std::string material);

	/*! \brief Получение текущего материала
	*  \return Материал
	*/
	std::string GetMaterial();

private:
	/*! \brief Функция для проверки материала
	*  \param material Новый материал
	*/
	void SetMaterialPrivate(std::string material);

private:
	std::string type_of_material_; /*!< Тип материала */
};

/*! \class Wheel
 *  \brief Класс для определения колеса
 *  \details Класс предоставляет возможность работы с параметрами колеса
 */
class Wheel : public CarPart {
public:
	/*! \brief Переопределение унаследованной функции
	*  \return Описание
	*/
	std::string GetInfoAboutPart() const override {
		return "This detail name is wheel";
	}

	/*! \brief Конструктор по умолчанию */
	Wheel();

	/*! \brief Параметризованный конструктор
	*  \param radius Радиус
	*  \param height Высота
	*  \param width Ширина
	*  \param material Материал
	*  \param color Цвет
	*  \param count_of_bolts Количество болтов
	*/
	Wheel(int radius, int height, int width, std::string material, std::string color, int count_of_bolts);

	/*! \brief Установка количества болтов
	*  \param count_of_bolts Новое количество болтов
	*  \return true если установка прошла успешно, false в противном случае
	*/
	bool SetCountOfBolts(int count_of_bolts);

	/*! \brief Получение количества болтов
	*  \return Количество болтов
	*/
	int GetCountOfBolts() const;

	/*! \brief Получение радиуса
	*  \return Радиус
	*/
	int GetRadius() const;

	/*! \brief Установка радиуса
	*  \param radius Новый радиус
	*  \return true если установка прошла успешно, false в противном случае
	*/
	bool SetRadius(int radius);

	/*! \brief Установка материала
	*  \param material Новый материал
	*  \return true если установка прошла успешно, false в противном случае
	*/
	bool SetMaterial(std::string material);

	/*! \brief Установка цвета
	*  \param color Новый цвет
	*  \return true если установка прошла успешно, false в противном случае
	*/
	bool SetColor(std::string color);

	/*! \brief Установка размера
	*  \param height Новая высота
	*  \param width Новая ширина
	*  \return true если установка прошла успешно, false в противном случае
	*/
	bool SetSize(int height, int width);

	/*! \brief Получение типа материала тормозной колодки
	*  \return Тип материала
	*/
	std::string GetTypeOfMaterialToBrakeShoe();

private:
	BaseCircle radius_; /*!< Радиус колеса */
	BrakeShoe brake_shoe_; /*!< Тормозная колодка */
	int count_of_bolts_{0}; /*!< Количество болтов */
};

/*! \class SignalButton
 *  \brief Класс для определения кнопки сигнала
 *  \details Класс предоставляет возможность работы с кнопкой сигнала
 */
class SignalButton {
public:
	/*! \brief Конструктор по умолчанию */
	SignalButton();

	/*! \brief Параметризованный конструктор
	*  \param height Высота
	*  \param width Ширина
	*  \param is_clicked Состояние нажатия
	*/
	SignalButton(int height, int width, bool is_clicked);

	/*! \brief Нажатие кнопки */
	void ClickedButton();

	/*! \brief Получение размеров кнопки
	*/
	void GetSize(int &height, int &width) const;

	/*! \brief Получение состояния нажатия
	*  \return Состояние нажатия
	*/
	bool GetIsClicked() const;

	/*! \brief Установка размера кнопки
	*  \param height Новая высота
	*  \param width Новая ширина
	*  \return true если установка прошла успешно, false в противном случае
	*/
	bool SetSizeForButton(int height, int width);

private:
	BasicParams size_; /*!< Размеры кнопки */
	bool is_clicked_ = false; /*!< Состояние нажатия */
};

/*! \class SteeringWheel
 *  \brief Класс для определения рулевого колеса
 *  \details Класс предоставляет возможность работы с рулевым колесом
 */
class SteeringWheel : public CarPart {
public:
	/*! \brief Переопределение унаследованной функции
	*  \return Описание
	*/
	std::string GetInfoAboutPart() const override {
		return "This detail name is steering wheel";
	}

	/*! \brief Конструктор по умолчанию */
	SteeringWheel();

	/*! \brief Параметризованный конструктор
	*  \param first_radius Радиус руля
	*  \param second_radius Радиус логотипа
	*  \param height_of_button Высота кнопки
	*  \param width_of_button Ширина кнопки
	*  \param is_clicked Состояние нажатия
	*/
	SteeringWheel(int first_radius, int second_radius, int height_of_button, int width_of_button, bool is_clicked);

	/*! \brief Установка радиуса руля
	*  \param radius_of_steering_wheel Новый радиус
	*  \return true если установка прошла успешно, false в противном случае
	*/
	bool SetRadiusOfSteeringWheel(int radius_of_steering_wheel);

	/*! \brief Установка радиуса логотипа
	*  \param radius_of_center_logo Новый радиус
	*  \return true если установка прошла успешно, false в противном случае
	*/
	bool SetRadiusOfCenterLogo(int radius_of_center_logo);

	/*! \brief Получение радиуса руля
	*  \return Радиус
	*/
	int GetRadiusOfSteeringWheel() const;

	/*! \brief Получение радиуса логотипа
	*  \return Радиус логоитпа
	*/
	int GetRadiusOfCenterLogo() const;

	/*! \brief Нажатие кнопки сигнала
	*  \return true если нажатие прошло успешно, false в противном случае
	*/
	bool ClickedButtonToMakeNoise();

	/*! \brief Получение состояния нажатия
	*  \return Состояние нажатия
	*/
	bool GetIsClicked() const;

	/*! \brief Установка размера кнопки
	*  \param height_of_button Новая высота
	*  \param width_of_button Новая ширина
	*  \return true если установка прошла успешно, false в противном случае
	*/
	bool SetSizeForButton(int height_of_button, int width_of_button);

private:
	BaseCircle radius_of_steering_wheel_; /*!< Радиус руля */
	BaseCircle radius_of_center_logo_; /*!< Радиус центрального логотипа */
	SignalButton signal_button_; /*!< Кнопка сигнала */
};
#endif //INCLUDE_WHEEL_H
