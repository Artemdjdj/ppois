/*! \file car_part.h
 *  \brief Заголовочный файл с определением базового абстрактного класса
  *  \details Класс является чисто виртуальным и используется для работы с деталями автомобиля
  */
#ifndef CAR_PART_H
#define CAR_PART_H
#include <string>

/*! \class CarPart
  *  \brief Абстрактный класс для определения детали автомобиля
  */
class CarPart {
public:
	/*! \brief Виртуальный деструктор */
	virtual ~CarPart() = default;

	/*! \brief Чисто виртуальная функция
	*  \return возвращает строку, которая описывает класс(деталь)
	*/
	virtual std::string GetInfoAboutPart() const = 0;
};
#endif //CAR_PART_H
