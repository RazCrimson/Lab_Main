from pprint import pprint
import pymongo
from mongo_client import MongoCon

db = MongoCon().get_connection()

# QN 2
db.us_cities.create_index([("geometry", pymongo.GEOSPHERE)])
result = db.us_cities.find_one(
    {
        "geometry": {
            "$nearSphere": {
                "$geometry": {
                    "type": "Point",
                    "coordinates": [-73.5, 41]
                }
            }
        }
    },
    {'properties.name': 1})
pprint(result['properties']['name'])
