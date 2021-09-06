from pprint import pprint

import pymongo

from mongo_client import MongoCon

db = MongoCon().get_connection()

# QN 8
db.us_cities.create_index([("geometry", pymongo.GEOSPHERE)])
selected_cities = db.us_cities.find().limit(2)
start = selected_cities[0]
end = selected_cities[1]

result = db.us_cities.aggregate([
    {
        "$geoNear": {
            'near': start['geometry'],
            'distanceField': "distanceFromPoint",
            'spherical': True
        }
    },
    {
        "$match": { "properties.name": end['properties']['name']}
    }
])
pprint(list(result))
