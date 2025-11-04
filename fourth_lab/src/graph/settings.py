import logging

POSITIVE_EDGE = 1
NEGATIVE_EDGE = -1
DEFAULT_EDGE = 0


def setup_logger():
    logging.basicConfig(
        level=logging.INFO,
        format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
        filename='app.log'
    )
