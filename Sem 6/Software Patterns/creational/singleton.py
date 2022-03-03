# Example 1 - Singleton method on class
class Example1:
    _instance = None

    @classmethod
    def get_instance(cls):
        if not cls._instance:
            cls._instance = cls()
        return cls._instance


# Example 2 - decorator
def singleton(cls_):
    instances = {}

    def get_instance(*args, **kwargs):
        if cls_ not in instances:
            instances[cls_] = cls_(*args, **kwargs)
        return instances[cls_]

    return get_instance


@singleton
class Example2:
    # An example class that who instance creation need to be abstracted
    pass


# Example 3
class Singleton(object):
    _instance = None

    def __new__(class_, *args, **kwargs):
        if not isinstance(class_._instance, class_):
            class_._instance = object.__new__(class_, *args, **kwargs)
        return class_._instance


class Example3(Singleton):
    pass


# Example 4
class SingletonMetaclass(type):
    _instances = {}

    def __call__(cls, *args, **kwargs):
        if cls not in cls._instances:
            cls._instances[cls] = super(SingletonMetaclass, cls).__call__(*args, **kwargs)
        return cls._instances[cls]


class Example4(metaclass=SingletonMetaclass):
    pass


if __name__ == "__main__":
    print("Example1 ")
    x = Example1.get_instance()
    y = Example1.get_instance()
    print("x :", id(x))
    print("y :", id(y))
    assert id(x) == id(y)

    classes = [Example2, Example3, Example4]
    for cls_ in classes:
        x = cls_()
        y = cls_()
        print(cls_.__name__)
        print("x :", id(x))
        print("y :", id(y))
        assert id(x) == id(y)
