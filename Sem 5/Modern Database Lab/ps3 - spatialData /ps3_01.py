import re
from mongo_client import MongoCon
from pprint import pprint

db = MongoCon().get_connection()

# QN 1 - CRUD

# Insert
result = db.us_cities.insert_one({
    "_id": "6126f358347c97a778532e59",
    "geometry": {
        "type": "Point",
        "coordinates": [-70, 40]
    },
    "properties": {
        "name": "Random Name",
        "state": "RN",
        "pop": "0",
        "capital": "0"
    },
    "type": "Feature"
})

# Find
result = db.us_cities.find({"properties.name": "Random Name"})
pprint(list(result))

# Update
db.us_cities.replace_one({"_id": "6126f358347c97a778532e59"},
                         {
                             "geometry": {
                                 "type": "Point",
                                 "coordinates": [-70, 40]
                             },
                             "properties": {
                                 "name": "Random Name",
                                 "state": "RN2",
                                 "pop": "0",
                                 "capital": "0"
                             },
                             "type": "Feature"
                         })

# Delete
db.us_cities.delete_one({"_id": "6126f358347c97a778532e59"})
