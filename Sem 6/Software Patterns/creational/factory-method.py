from abc import ABC, abstractmethod
from typing import Optional


# Product classes
class Instructor(ABC):
    def __init__(self, subject):
        self.subject = subject

    def get_subject(self):
        return self.subject

    @abstractmethod
    def __str__(self):
        pass


class ArtInstructor(Instructor):
    def __init__(self):
        super().__init__("art")

    def __str__(self):
        return f"<ArtInstructor>"


class ScienceInstructor(Instructor):
    def __init__(self):
        super().__init__("science")

    def __str__(self):
        return f"<ScienceInstructor>"


# Factory class
class InstructorFactory:
    instructors = {
        "art": ArtInstructor,
        "science": ScienceInstructor,
    }

    @classmethod
    def get_instructor(cls, subject: str) -> Optional[Instructor]:
        subject = subject.lower()
        if subject not in cls.instructors:
            return None
        return cls.instructors[subject]()


# Factory user
class Course(ABC):
    def __init__(self, code: str, subject: str):
        self.code = code
        self.subject = subject
        self.instructor = InstructorFactory.get_instructor(subject)

    @abstractmethod
    def __str__(self):
        pass


class ArtCourse(Course):
    def __init__(self, code: str):
        super().__init__(code, "art")

    def __str__(self):
        return f"<ArtCourse: code='{self.code}', instructor={self.instructor}>"


class ScienceCourse(Course):
    def __init__(self, code: str):
        super().__init__(code, "science")

    def __str__(self):
        return f"<ScienceCourse: code='{self.code}', instructor={self.instructor}>"


if __name__ == "__main__":
    art_course = ArtCourse("A01")
    science_course = ScienceCourse("S11")
    print(art_course)
    print(science_course)
