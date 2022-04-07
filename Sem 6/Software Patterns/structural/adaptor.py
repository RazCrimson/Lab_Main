from abc import ABC, abstractmethod


class ImageReader(ABC):
    @abstractmethod
    def read_image(self, file: str):
        ...


class ExternalJpegReader:
    def read_jpeg(self, file: str):
        print(f"External JPEG Reader reads {file}")


class ExternalJpegReaderAdaptor(ImageReader, ExternalJpegReader):
    def read_image(self, file: str):
        print(f"ExternalJpegReaderAdaptor executed")
        self.read_jpeg(file)


if __name__ == "__main__":
    image_reader = ExternalJpegReaderAdaptor()
    image_reader.read_image("image_file")
