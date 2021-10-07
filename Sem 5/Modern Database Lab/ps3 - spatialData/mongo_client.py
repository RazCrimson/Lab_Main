from pymongo import MongoClient

mongo_user = "test_user"
mongo_password = "test_password"
host_address = "10.15.75.34"
host_port = 27017


class MongoCon(object):
    __db = None

    @classmethod
    def get_connection(cls):
        if cls.__db is None:
            client = MongoClient(
                f"mongodb://{mongo_user}:{mongo_password}@{host_address}:{host_port}/?authSource=admin")
            cls.__db = client.modern_db_ps3
        return cls.__db
