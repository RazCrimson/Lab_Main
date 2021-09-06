from pprint import pprint
import pymongo
from mongo_client import MongoCon

db = MongoCon().get_connection()

# QN 3
db.us_cities.create_index([("geometry", pymongo.GEOSPHERE)])
result = db.us_cities.find({
    "geometry": {
        "$geoWithin": {
            "$geometry": {
                "type": "Polygon",
                "coordinates": [[[-78, 36], [-80, 40], [-77, 41], [-78, 36]]]
            }
        }
    }
})
pprint(list(result))
