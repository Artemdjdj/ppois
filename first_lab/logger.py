"""
Этот модуль расширяет возможности логирования в консоль, делает текст более ярким, а также каждый цвет
соответсвует определенному уровню логирования
"""

import logging
from colorama import Fore, Style

class ColoredFormatter(logging.Formatter):
    """Этот класс помогает соуществить цветное логирование в консоль"""
    COLORS = {
        logging.DEBUG: Fore.BLUE,
        logging.INFO: Fore.GREEN,
        logging.WARNING: Fore.YELLOW,
        logging.ERROR: Fore.RED,
        logging.CRITICAL: Fore.RED + Style.BRIGHT,
    }

    def format(self, record):
        """Эта функция меняет цвет текста в зависимости от уровня логирования"""
        if record.levelno in self.COLORS:
            record.levelname = (f"{self.COLORS[record.levelno]}"
                              f"{record.levelname}{Style.RESET_ALL}")
            record.msg = (f"{self.COLORS[record.levelno]}"
                        f"{record.msg}{Style.RESET_ALL}")
        return super().format(record)