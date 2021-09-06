from pprint import pprint

import pymongo

from mongo_client import MongoCon

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
pprint(list(result))



