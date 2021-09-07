from mongo_client import MongoCon

db = MongoCon().get_connection()

# QN 9
selected_state = db.us_states.find_one()

# Calculating Centroid of Polygon
centroid_coord = [0, 0]
for coords in selected_state['geometry']['coordinates'][0] :
    centroid_coord = [centroid_coord[0] + coords[0], centroid_coord[1] + coords[1]]
centroid_coord[0] = centroid_coord[0]/len(selected_state['geometry']['coordinates'][0])
centroid_coord[1] = centroid_coord[1]/len(selected_state['geometry']['coordinates'][0])

print(f"Center Coords for {selected_state['properties']['name']}", centroid_coord)