from pprint import pprint
import pymongo
from mongo_client import MongoCon
from geojson_converter import geojson_converter

db = MongoCon().get_connection()

# QN 5
db.us_cities.create_index([("geometry", pymongo.GEOSPHERE)])
result = db.us_cities.find({
    "geometry": {
        "$geoNear": {
            "$geometry": {
                "type": "Point",
                "coordinates": [-74.015, 41.72]
            }
        }
    }
}).limit(1)

data = list(result)
pprint(data)
db.qn5.drop()
db.qn5.insert_many(data)
geojson_converter(data, file_path="./ps3_05-output.geojson")
