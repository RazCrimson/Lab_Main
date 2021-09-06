from pprint import pprint
import pymongo
from mongo_client import MongoCon

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
pprint(list(result))
