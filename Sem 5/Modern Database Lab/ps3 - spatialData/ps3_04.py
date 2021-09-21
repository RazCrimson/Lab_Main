from pprint import pprint

from mongo_client import MongoCon

db = MongoCon().get_connection()

# QN 4
selected_state = db.us_states.find_one()
states_sharing_border = set()
for coords in selected_state['geometry']['coordinates'][0]:
    states = db.us_states.find({
        "geometry": {
            "$geoIntersects": {
                "$geometry": {
                    "type": "Point",
                    "coordinates": coords
                }
            }
        }
    })
    for state in states:
        states_sharing_border.add(state['properties']['name'])

states_sharing_border.remove(selected_state['properties']['name'])
print("States that share the border with ", selected_state['properties']['name'])
pprint(states_sharing_border)
