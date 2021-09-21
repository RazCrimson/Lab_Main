from mongo_client import MongoCon
from geojson_converter import geojson_converter

db = MongoCon().get_connection()

# QN 9
selected_states = db.us_states.find()
results = []

def calc_centroid(coordinates):
    centroid_coord = [0, 0]
    for coords in coordinates:
        centroid_coord = [centroid_coord[0] + coords[0], centroid_coord[1] + coords[1]]
    centroid_coord[0] = centroid_coord[0]/len(coordinates)
    centroid_coord[1] = centroid_coord[1]/len(coordinates)
    record = {"type":"Feature","geometry":{"type":"Point","coordinates":centroid_coord}, "properties": { "Center for State":state['properties']['name']}}
    results.append(record)

for state in list(selected_states):
    # Calculating Centroid of Polygon
    for coords in state['geometry']['coordinates']:
            if type(coords[0]) is list and type(coords[0][0]) is list:
                for coord in coords:
                    calc_centroid(coord)
            else:
                calc_centroid(coords)


data = list(results)
geojson_converter(data, file_path="./ps3_09-output.geojson")