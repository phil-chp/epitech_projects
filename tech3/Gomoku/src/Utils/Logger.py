##
## EPITECH PROJECT, 2022
## B-AIA-500-NCE-5-1-gomoku-philippe.cheype
## File description:
## Logger
##

import logging

class Logger:
    @staticmethod
    def init(file, level=logging.DEBUG):
        logging.basicConfig(filename=file, level=level, filemode='w', format='[%(asctime)s] - [%(levelname)s] - %(message)s', datefmt='%d/%m/%Y %H:%M:%S')

    @staticmethod
    def logInfo(message):
        logging.info(message)

    @staticmethod
    def logError(message):
        logging.error(message)

    @staticmethod
    def logWarning(message):
        logging.warning(message)

    @staticmethod
    def logDebug(message):
        logging.debug(message)

    @staticmethod
    def logCritical(message):
        logging.critical(message)
