class BaseLogger:
    def log(self, message: str) -> None:
        print(f"BaseLogger: {message}")


class FileLogger(BaseLogger):
    def __init__(self, logger: BaseLogger) -> None:
        self._logger = logger

    def log(self, message: str) -> None:
        self._logger.log(message)

        with open(f"{__file__}.log", "a+") as f:
            f.writelines([f"FileLogger: {message}"])


class ColouredLogger:
    def __init__(self, logger: BaseLogger) -> None:
        self._logger = logger

    def log(self, message: str) -> None:
        message = f"\033[92m{message}\033[0m"
        self._logger.log(message)


if __name__ == "__main__":
    logger = BaseLogger()
    logger = ColouredLogger(logger)
    logger = FileLogger(logger)

    logger.log("test message")
