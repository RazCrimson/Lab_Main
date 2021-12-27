from abc import ABC, abstractmethod


class Instructor(ABC):
    def __init__(self, name: str):
        self.name = name
        self.subject = self._get_subject()

    @abstractmethod
    def _get_subject(self):
        pass

    @abstractmethod
    def __str__(self):
        pass


class ArtInstructor(Instructor):
    def _get_subject(self):
        return "Art"

    def __str__(self):
        return f"<ArtInstructor: name='{self.name}'>"


class ScienceInstructor(Instructor):
    def _get_subject(self):
        return "Science"

    def __str__(self):
        return f"<ScienceInstructor: name='{self.name}'>"


class Course(ABC):
    def __init__(self, code: str, teacher_name: str):
        self.code = code
        self.instructor = self._get_instructor(teacher_name)

    @abstractmethod
    def _get_instructor(self, teacher_name: str) -> Instructor:
        pass

    @abstractmethod
    def __str__(self):
        pass


class ArtCourse(Course):
    def _get_instructor(self, teacher_name: str):
        return ArtInstructor(teacher_name)

    def __str__(self):
        return f"<ArtCourse: code='{self.code}', instructor={self.instructor}>"


class ScienceCourse(Course):
    def _get_instructor(self, teacher_name: str):
        return ScienceInstructor(teacher_name)

    def __str__(self):
        return f"<ScienceCourse: code='{self.code}', instructor={self.instructor}>"


if __name__ == "__main__":
    art_course = ArtCourse("A01", "Mr. X")
    science_course = ScienceCourse("S11", "Mr. Y")
    print(art_course)
    print(science_course)
