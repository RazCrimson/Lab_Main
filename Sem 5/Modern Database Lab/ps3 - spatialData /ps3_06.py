from pprint import pprint

import pymongo

from mongo_client import MongoCon
from geojson_converter import geojson_converter


db = MongoCon().get_connection()

# QN 6
db.us_hospitals.create_index([("geometry", pymongo.GEOSPHERE)])
result = db.us_hospitals.aggregate([
    {
        "$geoNear": {
            'near': {'type': "Point", 'coordinates': [-118, 34]},
            'distanceField': "distanceFromPoint",
            'spherical': True
        }
    },
    {
        "$limit": 10
    }
])

data = list(result)
pprint(data)
geojson_converter(data, file_path="./ps3_06-output.geojson")
