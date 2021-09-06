import pymongo
from mongo_client import MongoCon

db = MongoCon().get_connection()

# QN 10
db.us_cities.create_index([("geometry", pymongo.GEOSPHERE)])
db.us_hospitals.create_index([("geometry", pymongo.GEOSPHERE)])
selected_state = db.us_states.find_one()

cities_in_state = db.us_cities.count_documents({
    "geometry": {
        "$geoWithin": {
            "$geometry": selected_state['geometry']

        }
    }
})
print(f"Cities in State: {selected_state['properties']['name']} - {cities_in_state}")

hospitals_in_state = db.us_hospitals.count_documents({
    "geometry": {
        "$geoWithin": {
            "$geometry": selected_state['geometry']

        }
    }
})
print(f"Hospitals in State: {selected_state['properties']['name']} - {hospitals_in_state}")